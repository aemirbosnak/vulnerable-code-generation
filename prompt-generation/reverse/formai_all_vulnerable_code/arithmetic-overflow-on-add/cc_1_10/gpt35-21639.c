//FormAI DATASET v1.0 Category: Image Steganography ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

/* Function to set the least significant bit of a byte to a given value */
void setLSB(unsigned char *byte, int bit){
    *byte = (*byte & 0xFE) | (bit & 1);
}

/* Function to extract the least significant bit of a byte */
int getLSB(unsigned char byte){
    return (byte & 1);
}

/* Function to encode a message in an image */
void encode(FILE *image_file, FILE *message_file, FILE *output_file){
    int message_bit, image_byte, i;
    char message_char;

    while ((message_char = fgetc(message_file)) != EOF) {   // loop through message characters
        for (i = 7; i >= 0; i--) {                          // loop through bits in each character
            message_bit = (message_char >> i) & 1;           // get current bit
            image_byte = fgetc(image_file);                  // read byte from image
            setLSB(&image_byte, message_bit);                // set least significant bit to message bit
            fputc(image_byte, output_file);                  // write byte to output file
        }
    }
}

/* Function to decode a message from an image */
void decode(FILE *image_file, FILE *output_file){
    int image_byte, i, message_bit, message_char = 0;

    while ((image_byte = fgetc(image_file)) != EOF) {       // loop through bytes in image
        message_bit = getLSB(image_byte);                    // get least significant bit
        message_char = (message_char << 1) | message_bit;    // shift message left and add new bit
        if (i == 7) {                                       // if a full character has been read
            fputc(message_char, output_file);                // write character to output file
            message_char = 0;                                // reset message character
            i = 0;                                          // reset bit count
        } else {
            i++;                                            // increment bit count
        }
    }
}

int main(){
    FILE *image_file, *message_file, *output_file;
    char option, image_file_name[50], message_file_name[50], output_file_name[50];

    printf("Welcome to the image steganography program!\n");
    printf("Would you like to encode or decode a message? (e/d): ");
    scanf("%c", &option);

    printf("Input the name of the image file: ");
    scanf("%s", image_file_name);

    printf("Input the name of the message file: ");
    scanf("%s", message_file_name);

    printf("Input the name of the output file: ");
    scanf("%s", output_file_name);

    image_file = fopen(image_file_name, "rb");
    message_file = fopen(message_file_name, "r");
    output_file = fopen(output_file_name, "wb");

    if (!image_file || !message_file || !output_file) {
        printf("Error opening files\n");
        return 1;
    }

    if (option == 'e') {
        encode(image_file, message_file, output_file);
        printf("Message encoded successfully!\n");
    } else if (option == 'd') {
        decode(image_file, output_file);
        printf("Message decoded successfully!\n");
    } else {
        printf("Invalid option\n");
        return 1;
    }

    fclose(image_file);
    fclose(message_file);
    fclose(output_file);

    return 0;
}