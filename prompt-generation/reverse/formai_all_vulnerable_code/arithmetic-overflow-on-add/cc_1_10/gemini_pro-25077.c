//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_MSG_LEN 1024

int main() {
    // Open the image file
    FILE *imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    // Check the image file header
    struct bmp_header {
        uint16_t type; // Magic number
        uint32_t size; // Size of the file in bytes
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t offset; // Offset to the start of the image data
    };
    struct bmp_header header;
    fread(&header, sizeof(struct bmp_header), 1, imageFile);
    if (header.type != 0x4D42) {
        fprintf(stderr, "Error: Invalid image file format\n");
        fclose(imageFile);
        return EXIT_FAILURE;
    }

    // Read the message from the user
    char message[MAX_MSG_LEN + 1];
    printf("Enter your message (max %d characters): ", MAX_MSG_LEN);
    fgets(message, MAX_MSG_LEN + 1, stdin);

    // Hide the message in the image
    int msgIdx = 0;
    for (int i = header.offset; i < header.size; i++) {
        // Read the pixel value
        uint8_t pixel;
        fread(&pixel, 1, 1, imageFile);

        // Hide the message bit in the least significant bit of the pixel
        if (msgIdx < (int)strlen(message)) {
            pixel &= 0b11111110;
            pixel |= (message[msgIdx] >> 7) & 0b00000001;
            msgIdx++;
        }

        // Write the modified pixel value back to the image
        fseek(imageFile, i, SEEK_SET);
        fwrite(&pixel, 1, 1, imageFile);
    }

    // Close the image file
    fclose(imageFile);

    // Tell the user that the message has been hidden
    printf("Message hidden successfully!\n");

    return EXIT_SUCCESS;
}