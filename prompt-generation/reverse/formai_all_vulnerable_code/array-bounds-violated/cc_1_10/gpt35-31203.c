//FormAI DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_LEN 100
#define HEADER_SIZE 54
#define BYTE_SIZE 8

void print_separator() {
    printf("\n-------------------------------------------------\n\n");
}

void print_header(unsigned char *header) {
    for (int i = 0; i < HEADER_SIZE; i++) {
        printf("%02x ", header[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
}

void hide_message(unsigned char *header, unsigned char *image, char *message) {
    unsigned int message_len = strlen(message);
    unsigned int bit_count = 0;
    unsigned char current_byte;
    unsigned int bit_pos = 0;

    for (int i = HEADER_SIZE; i < HEADER_SIZE + message_len * BYTE_SIZE; i++) {
        current_byte = image[i];

        if (bit_count < message_len * BYTE_SIZE) {
            unsigned char bit = message[bit_count/BYTE_SIZE] >> (bit_count % BYTE_SIZE) & 1;
            current_byte = (current_byte & ~1) | bit;
            bit_count++;
        } else {
            current_byte = current_byte & ~1;
        }

        image[i] = current_byte;
    }

    printf("Message %s successfully hidden in the image.\n", message);
}

void extract_message(unsigned char *header, unsigned char *image, char *message, unsigned int message_len) {
    unsigned int bit_count = 0;
    unsigned char current_byte;

    for (int i = HEADER_SIZE; i < HEADER_SIZE + message_len * BYTE_SIZE; i++) {
        current_byte = image[i];
        unsigned char bit = current_byte & 1;
        message[bit_count/BYTE_SIZE] |= bit << (bit_count % BYTE_SIZE);
        bit_count++;
    }

    message[message_len] = '\0';
    printf("Extracted message: %s\n", message);
}

int main() {
    int selection;
    char file_name[FILE_NAME_LEN];
    char message[FILE_NAME_LEN];
    unsigned char *header, *image;
    unsigned int image_size = 0;
    unsigned int message_len = 0;

    printf("Welcome to Image Steganography.\n");
    print_separator();

    do {
        printf("Please select an option:\n");
        printf("1. Hide message in image\n");
        printf("2. Extract message from image\n");
        printf("3. Exit\n");
        printf("Your selection: ");

        scanf("%d", &selection);
        getchar();

        switch (selection) {
            case 1:
                printf("\nEnter the image file name: ");
                fgets(file_name, FILE_NAME_LEN, stdin);
                file_name[strlen(file_name)-1] = '\0'; // remove the \n character at the end

                printf("Enter the message to hide: ");
                fgets(message, FILE_NAME_LEN, stdin);
                message_len = strlen(message) - 1; // remove the \n character at the end

                // read image file
                FILE *file_image = fopen(file_name, "rb");
                fseek(file_image, 0, SEEK_END);
                image_size = ftell(file_image);
                fseek(file_image, 0, SEEK_SET);

                header = (unsigned char *) malloc(HEADER_SIZE);
                image = (unsigned char *) malloc(image_size);

                fread(header, HEADER_SIZE, 1, file_image);
                fread(image, image_size, 1, file_image);

                fclose(file_image);

                hide_message(header, image, message);

                // write image file
                FILE *file_image_out = fopen("output.bmp", "wb");
                fwrite(header, HEADER_SIZE, 1, file_image_out);
                fwrite(image, image_size, 1, file_image_out);
                fclose(file_image_out);

                free(header);
                free(image);

                print_separator();
                break;

            case 2:
                printf("\nEnter the image file name: ");
                fgets(file_name, FILE_NAME_LEN, stdin);
                file_name[strlen(file_name)-1] = '\0'; // remove the \n character at the end

                // read image file
                FILE *file_image2 = fopen(file_name, "rb");
                fseek(file_image2, 0, SEEK_END);
                image_size = ftell(file_image2);
                fseek(file_image2, 0, SEEK_SET);

                header = (unsigned char *) malloc(HEADER_SIZE);
                image = (unsigned char *) malloc(image_size);

                fread(header, HEADER_SIZE, 1, file_image2);
                fread(image, image_size, 1, file_image2);

                fclose(file_image2);

                extract_message(header, image, message, message_len);

                free(header);
                free(image);

                print_separator();
                break;

            case 3:
                printf("\nBye!\n");
                break;

            default:
                printf("\nError: invalid option.\n");
                print_separator();
        }
    } while (selection != 3);

    return 0;
}