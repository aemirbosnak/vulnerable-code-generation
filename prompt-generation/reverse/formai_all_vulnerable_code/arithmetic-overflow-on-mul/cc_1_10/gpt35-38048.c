//FormAI DATASET v1.0 Category: Image Steganography ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_PIXEL 3

typedef struct {
    char message[1000];
    int message_length;
} HiddenMessage;

// loads the image from file and returns its raw pixel data and dimensions
unsigned char* load_image(char *filename, int *width, int *height)
{
    FILE *file;
    unsigned char *image_data;

    file = fopen(filename, "rb");
    if (!file) {
        printf("ERROR: Failed to open file '%s'\n", filename);
        return NULL;
    }

    // read in the file header
    int header_size = 54;
    unsigned char header[header_size];
    fread(header, sizeof(unsigned char), header_size, file);

    // extract the image dimensions from the header
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    int image_size = BYTES_PER_PIXEL * (*width) * (*height);
    image_data = (unsigned char*)malloc(sizeof(unsigned char) * image_size);

    // read in the pixel data
    fseek(file, header_size, SEEK_SET);
    fread(image_data, sizeof(unsigned char), image_size, file);

    fclose(file);
    return image_data;
}

// saves the image to file with the given pixel data and dimensions
void save_image(char *filename, unsigned char *image_data, int width, int height)
{
    FILE *file;
    int image_size = BYTES_PER_PIXEL * width * height;

    file = fopen(filename, "wb");
    if (!file) {
        printf("ERROR: Failed to open file '%s'\n", filename);
        return;
    }

    // write out the file header
    int header_size = 54;
    unsigned char header[header_size];
    for (int i = 0; i < header_size; i++) {
        header[i] = 0;
    }
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = header_size + image_size;
    *(int*)&header[10] = header_size;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = BYTES_PER_PIXEL * 8;
    *(int*)&header[30] = 0;
    *(int*)&header[34] = image_size;
    fwrite(header, sizeof(unsigned char), header_size, file);

    // write out the pixel data
    fwrite(image_data, sizeof(unsigned char), image_size, file);

    fclose(file);
}

// encodes a given message into the least significant bit of each color channel of each pixel in the image
void encode_message(unsigned char *image_data, int width, int height, HiddenMessage message)
{
    int pixel_index = 0;
    int bit_index = 0;

    // loop through each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            // loop through each color channel in the pixel
            for (int c = 0; c < BYTES_PER_PIXEL; c++) {

                // check if we still have a bit to encode
                if (bit_index < message.message_length * 8) {

                    // extract the least significant bit of the pixel channel
                    int pixel_bit = image_data[pixel_index] & 1;

                    // extract the next bit of the message to be encoded
                    int message_bit = (message.message[bit_index / 8] >> (bit_index % 8)) & 1;

                    // replace the least significant bit in the pixel channel with the message bit
                    if (message_bit == 1) {
                        image_data[pixel_index] |= 1;
                    } else {
                        image_data[pixel_index] &= 0xFE;
                    }

                    // increment the bit index
                    bit_index++;

                }

                // increment the pixel index
                pixel_index++;

            }

        }
    }
}

// decodes a message from the least significant bit of each color channel of each pixel in the image
HiddenMessage decode_message(unsigned char *image_data, int width, int height)
{
    HiddenMessage message;
    message.message_length = 0;

    int pixel_index = 0;
    int bit_index = 0;

    // loop through each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            // loop through each color channel in the pixel
            for (int c = 0; c < BYTES_PER_PIXEL; c++) {

                // check if we still have a bit to decode
                if (bit_index < message.message_length * 8) {

                    // extract the least significant bit of the pixel channel
                    int pixel_bit = image_data[pixel_index] & 1;

                    // add the least significant bit to the message
                    message.message[bit_index / 8] |= pixel_bit << (bit_index % 8);

                    // increment the bit index
                    bit_index++;

                } else {
                    // check if we have finished decoding the message
                    if (bit_index >= 8 && !message.message[(bit_index - 1) / 8]) {
                        message.message_length = (bit_index - 1) / 8;
                        return message;
                    }
                }

                // increment the pixel index
                pixel_index++;

            }

        }
    }

    return message;
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Usage: %s input_image output_image\n", argv[0]);
        return 1;
    }

    int width, height;
    unsigned char *image_data = load_image(argv[1], &width, &height);
    if (!image_data) {
        return 1;
    }

    // read in the message to be hidden
    HiddenMessage message;
    printf("Enter a message to hide (max length 1000 characters):\n");
    fgets(message.message, 1000, stdin);
    message.message_length = strlen(message.message) - 1;

    // encode the message into the image
    encode_message(image_data, width, height, message);

    // save the modified image to file
    save_image(argv[2], image_data, width, height);

    printf("Message hidden successfully!\n");

    // decode the message from the image
    unsigned char *encoded_image_data = load_image(argv[2], &width, &height);
    HiddenMessage hidden_message = decode_message(encoded_image_data, width, height);
    printf("Hidden message: %s\n", hidden_message.message);

    free(image_data);
    free(encoded_image_data);

    return 0;
}