//FormAI DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, char *message) {
    // read input image
    FILE *fp_input = fopen(input, "rb");
    if (!fp_input) {
        printf("Failed to open input image %s\n", input);
        return;
    }

    // read output image
    FILE *fp_output = fopen(output, "wb");
    if (!fp_output) {
        printf("Failed to open output image %s\n", output);
        return;
    }

    // write header to output image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp_input);
    fwrite(header, sizeof(unsigned char), 54, fp_output);

    // read message
    FILE *fp_message = fopen(message, "rb");
    if (!fp_message) {
        printf("Failed to open message file %s\n", message);
        return;
    }

    // get message size
    fseek(fp_message, 0, SEEK_END);
    size_t message_size = ftell(fp_message);
    fseek(fp_message, 0, SEEK_SET);

    // allocate buffer for message content
    char *message_content = malloc(message_size);
    fread(message_content, sizeof(char), message_size, fp_message);

    // write message size to output image
    unsigned char message_size_bytes[4];
    for (int i = 0; i < 4; i++) {
        message_size_bytes[i] = (message_size >> (i * 8)) & 0xff;
    }
    fwrite(message_size_bytes, sizeof(unsigned char), 4, fp_output);

    // write message content to output image
    int buffer;
    for (int i = 0; i < message_size; i++) {
        fread(&buffer, sizeof(char), 1, fp_input);
        buffer &= 0xfc;
        buffer |= (message_content[i] >> 6) & 0x03;
        fwrite(&buffer, sizeof(char), 1, fp_output);

        fread(&buffer, sizeof(char), 1, fp_input);
        buffer &= 0xfc;
        buffer |= (message_content[i] >> 4) & 0x03;
        fwrite(&buffer, sizeof(char), 1, fp_output);

        fread(&buffer, sizeof(char), 1, fp_input);
        buffer &= 0xfc;
        buffer |= (message_content[i] >> 2) & 0x03;
        fwrite(&buffer, sizeof(char), 1, fp_output);

        fread(&buffer, sizeof(char), 1, fp_input);
        buffer &= 0xfc;
        buffer |= message_content[i] & 0x03;
        fwrite(&buffer, sizeof(char), 1, fp_output);
    }

    // write remaining content from input image to output image
    while (fread(&buffer, sizeof(char), 1, fp_input) > 0) {
        fwrite(&buffer, sizeof(char), 1, fp_output);
    }

    fclose(fp_input);
    fclose(fp_output);
    fclose(fp_message);
    free(message_content);
}

void decrypt(char *input, char *message) {
    // read input image
    FILE *fp_input = fopen(input, "rb");
    if (!fp_input) {
        printf("Failed to open input image %s\n", input);
        return;
    }

    // read message size
    unsigned char message_size_bytes[4];
    fseek(fp_input, 54, SEEK_SET);
    fread(message_size_bytes, sizeof(unsigned char), 4, fp_input);
    size_t message_size = 0;
    for (int i = 0; i < 4; i++) {
        message_size |= message_size_bytes[i] << (i * 8);
    }

    // allocate buffer for message content
    char *message_content = malloc(message_size);

    // read message content
    int buffer;
    for (int i = 0; i < message_size; i++) {
        fread(&buffer, sizeof(char), 1, fp_input);
        message_content[i] = (buffer & 0x03) << 6;

        fread(&buffer, sizeof(char), 1, fp_input);
        message_content[i] |= (buffer & 0x03) << 4;

        fread(&buffer, sizeof(char), 1, fp_input);
        message_content[i] |= (buffer & 0x03) << 2;

        fread(&buffer, sizeof(char), 1, fp_input);
        message_content[i] |= buffer & 0x03;
    }

    // write message content to output file
    FILE *fp_message = fopen(message, "wb");
    if (!fp_message) {
        printf("Failed to open message file %s\n", message);
        return;
    }
    fwrite(message_content, sizeof(char), message_size, fp_message);
    fclose(fp_input);
    fclose(fp_message);
    free(message_content);
}

int main() {
    char input_image[] = "input.bmp";
    char output_image[] = "output.bmp";
    char message[] = "message.txt";
    char decrypted_message[] = "decrypted_message.txt";
    char user_input;

    printf("Welcome to the Image Steganography example program!\n\n");
    printf("Please select an option:\n");
    printf("1. Encrypt a message into an image\n");
    printf("2. Decrypt a message from an image\n");

    scanf("%c", &user_input);

    switch (user_input) {
        case '1': {
            printf("Encrypting message into image...\n");
            encrypt(input_image, output_image, message);
            printf("Message encrypted successfully!\n");
            break;
        }
        case '2': {
            printf("Decrypting message from image...\n");
            decrypt(output_image, decrypted_message);
            printf("Message decrypted successfully!\n");
            break;
        }
        default: {
            printf("Invalid option selected. Please try again.\n");
            break;
        }
    }

    return 0;
}