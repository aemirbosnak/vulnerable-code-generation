//FormAI DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 800*800*3

typedef unsigned char byte;

int main()
{
    char filename[100];
    printf("Welcome to the happy steganography program! \n");
    printf("Enter the name of the input image file: ");
    scanf("%s", &filename);

    FILE *image_file = fopen(filename, "rb");
    if (image_file == NULL) {
        printf("File error! Could not open image file!\n");
        exit(1);
    }

    byte image_data[MAX_IMAGE_SIZE];

    int image_size = fread(image_data, sizeof(byte), MAX_IMAGE_SIZE, image_file);
    fclose(image_file);

    printf("Successfully read image file!\n");
    printf("Enter the message you want to hide: ");
    char message[1000];
    scanf("%s", &message);

    int message_size = 0;
    for (int i = 0; message[i] != '\0'; i++) message_size++;

    int encoded_data_size = (message_size + 1) * 8;
    printf("Total bits required for encoding data: %d\n", encoded_data_size);

    int image_bit_size = image_size * 8;
    if (encoded_data_size > image_bit_size) {
        printf("Error: Input image too small to hide the message data!\n");
        exit(1);
    }

    int bit_index = 0;
    for (int i = 0; i < message_size; i++) {
        byte character = message[i];
        for (int bit_pos = 7; bit_pos >= 0; bit_pos--) {
            int bit = (character >> bit_pos) & 1;

            image_data[bit_index] = (image_data[bit_index] & 0xFE) | bit;
            bit_index++;
        }
    }

    byte end_of_message = '\0';
    for (int bit_pos = 7; bit_pos >= 0; bit_pos--) {
        int bit = (end_of_message >> bit_pos) & 1;

        image_data[bit_index] = (image_data[bit_index] & 0xFE) | bit;
        bit_index++;
    }

    printf("Message successfully encoded into image data!\n");

    char output_filename[100];
    printf("Enter the name of the output image file: ");
    scanf("%s", &output_filename);

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("File error! Could not create output image file!\n");
        exit(1);
    }

    fwrite(image_data, sizeof(byte), image_size, output_file);
    fclose(output_file);

    printf("Message successfully encoded into image file!\n");

    return 0;
}