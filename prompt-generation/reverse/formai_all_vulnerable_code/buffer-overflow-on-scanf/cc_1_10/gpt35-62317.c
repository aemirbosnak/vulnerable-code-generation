//FormAI DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <string.h>

/*
* Function to convert character to binary
*/
void char_to_bin(char c, char bin[]) {
    int i;
    for (i = 7; i >= 0; --i) {
        bin[7 - i] = ((c & (1 << i)) ? '1' : '0');
    }
    bin[8] = '\0';
}

/*
* Function to embed secret message into image
*/
void embed_message(FILE *fptr, char* message) {
    char c, bin[9], temp;
    int i = 0, j = 0;
    while ((c = fgetc(fptr)) != EOF && i < strlen(message)) {
        char_to_bin(c, bin);
        temp = bin[7];
        bin[7] = message[i++];
        if (i > strlen(message)) break;
        fputc(strtol(bin, NULL, 2), fptr);
        bin[7] = temp;
    }
}

/*
* Function to extract secret message from image
*/
void extract_message(FILE *fptr, int length) {
    char c, bin[9], message[length + 1];
    int i = 0, j = 0;
    while ((c = fgetc(fptr)) != EOF && i < length) {
        char_to_bin(c, bin);
        message[i++] = bin[7];
    }
    message[length] = '\0';
    printf("Secret Message: %s\n", message);
}

int main(void) {
    char filename[20], message[100];
    int length;
    printf("Enter the name of the input image file: ");
    scanf("%s", filename);
    FILE *fptr = fopen(filename, "r+");
    if (fptr == NULL) {
        printf("Unable to open file.");
        return 1;
    }
    printf("Enter the secret message you want to hide: ");
    scanf("%s", message);
    length = strlen(message);
    if (length * 8 > fptr->_IO_buf_end - fptr->_IO_buf_base) {
        printf("Image file is not large enough to store secret message.");
        return 1;
    }
    embed_message(fptr, message);
    printf("Message has been successfully embedded into the image.\n");
    printf("Enter the name of the output image file: ");
    scanf("%s", filename);
    freopen(filename, "w", fptr);
    extract_message(fptr, length);
    fclose(fptr);
    return 0;
}