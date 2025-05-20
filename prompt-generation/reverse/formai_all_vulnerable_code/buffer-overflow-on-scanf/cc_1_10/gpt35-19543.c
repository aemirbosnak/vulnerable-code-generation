//FormAI DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// LSB encoding
void encode(char *message, char *filename) {

    FILE *file = fopen(filename, "rb+");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    unsigned char c;
    int size;

    // Find the end position of the image file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    // Check if message fits in the image
    if(strlen(message)*8 > size) {
        printf("Error: Image file is not big enough!\n");
        exit(1);
    }

    int i = 0, j = 0, bit = 0;

    // Iterate through the message
    while(message[i] != '\0') {

        // Iterate through each bit of the character
        for(bit = 7; bit >= 0; bit--) {

            // Read in a byte of the image
            fread(&c, sizeof(char), 1, file);

            // Turn the selected bit on/off
            c = (c & (0xFE)) | ((message[i] >> bit) & 0x01);

            // Write the byte back to the image
            fseek(file, ftell(file)-1, SEEK_SET);
            fwrite(&c, sizeof(char), 1, file);
            j++;

            // Exit the loop if the entire message has been encoded
            if(j == strlen(message)*8) {
                fclose(file);
                return;
            }
        }

        i++;
    }

    fclose(file);
}

// LSB decoding
char *decode(char *filename) {

    FILE *file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    unsigned char c;
    int size;

    // Find the end position of the image file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    char *message = (char *)malloc(sizeof(char)*size/8);
    int i = 0, j = 0, bit = 0;

    // Iterate through the bytes of the image
    for(i = 0; i < size; i++) {

        // Read in a byte of the image
        fread(&c, sizeof(char), 1, file);

        // Iterate through each bit of the byte
        for(bit = 7; bit >= 0; bit--) {

            // Check if the last bit of the byte is 1
            if((c >> bit) & 0x01) {
                message[j/8] |= 1 << (j%8);
            } else {
                message[j/8] &= ~(1 << (j%8));
            }

            j++;

            // Exit the loop if the end of the message has been found
            if(j == size*8) {
                fclose(file);
                return message;
            }
        }
    }

    fclose(file);
    return NULL;
}

int main() {

    char filename[256], message[256];
    printf("Enter the filename of the image to hide the message: ");
    scanf("%s", filename);
    printf("Enter the message to be hidden: ");
    scanf("%s", message);

    encode(message, filename);

    char *hiddenMessage = decode(filename);
    printf("Hidden message: %s\n", hiddenMessage);

    free(hiddenMessage);

    return 0;
}