//FormAI DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512
#define HEADER_SIZE 54

int main(int argc, char *argv[]) {

    if (argc != 4) {
        fprintf(stderr, "Invalid arguments!\nUsage: %s <input-image> <output-image> <secret-message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *message = argv[3];

    FILE *input_ptr = fopen(input_file, "rb");
    FILE *output_ptr = fopen(output_file, "wb");

    if (!input_ptr || !output_ptr) {
        fprintf(stderr, "Failed to open files!\n");
        exit(EXIT_FAILURE);
    }

    // calculate image size
    int image_size = 0;
    fseek(input_ptr, 0L, SEEK_END);
    image_size = ftell(input_ptr);
    rewind(input_ptr);

    // read image header
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, input_ptr);

    // write header to output file
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, output_ptr);

    // read message
    int message_length = strlen(message);
    int current_bit = 0;
    unsigned char buffer[BUFFER_SIZE];

    for (int i = 0; i < message_length; i++) {

        unsigned char char_code = message[i];

        // encode each bit of the char
        for (int j = 0; j < 8; j++) {

            // read a chunk of the image data
            fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input_ptr);

            // modify the last bit of each byte chunk to hold the bit from the message
            for (int k = 0; k < BUFFER_SIZE; k++) {
                if (current_bit < 8) {
                    buffer[k] = (buffer[k] & 0xFE) | ((char_code & (1 << current_bit)) >> current_bit);
                    current_bit++;
                }
            }

            // write the modified chunk to the output file
            fwrite(buffer, sizeof(unsigned char), BUFFER_SIZE, output_ptr);

            if (feof(input_ptr)) {
                break;
            }
        }

        if (feof(input_ptr)) {
            break;
        }
    }

    // copy the rest of the image data to the output file
    while (!feof(input_ptr)) {
        fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input_ptr);
        fwrite(buffer, sizeof(unsigned char), BUFFER_SIZE, output_ptr);
    }

    fclose(input_ptr);
    fclose(output_ptr);

    printf("Message successfully encoded!\n");

    return EXIT_SUCCESS;
}