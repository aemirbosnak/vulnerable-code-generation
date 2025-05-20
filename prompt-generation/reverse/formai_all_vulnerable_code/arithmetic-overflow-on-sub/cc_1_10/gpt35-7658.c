//FormAI DATASET v1.0 Category: Image Steganography ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_MSG_LEN 120

/*
 * Function to convert a decimal number to a binary array (reverse order)
 */
void decToBin(int n, int* binArr) {
    int i = 0;
    while (n > 0) {
        binArr[i++] = n % 2;
        n /= 2;
    }
}

/*
 * Function to convert a binary array (reverse order) to a decimal number
 */
int binToDec(int* binArr, int binArrLen) {
    int dec = 0, p = 1;
    for (int i = 0; i < binArrLen; i++) {
        dec += binArr[i] * p;
        p *= 2;
    }
    return dec;
}

/*
 * Function to hide a message inside an image file
 */
void hideMessage(char* imgFilename, char* msg) {
    // Open image file in read-write binary mode
    FILE* imgFile = fopen(imgFilename, "rb+");
    if (imgFile == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }

    // Get size of image file
    fseek(imgFile, 0, SEEK_END);
    int imgFileSize = ftell(imgFile);
    fseek(imgFile, 0, SEEK_SET);

    // Calculate maximum size of message that can be hidden in the image
    int maxMsgSize = (imgFileSize - 54) / 8; // 54 is the size of the BMP header
    if (strlen(msg) > maxMsgSize) {
        printf("Error: Message too long to hide in the image.\n");
        exit(1);
    }

    // Read BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imgFile);

    // Set pointer to the start of the image data
    fseek(imgFile, 54, SEEK_SET);

    // Convert message to binary array (reverse order)
    int msgLen = strlen(msg);
    int msgBinArr[8 * msgLen];
    for (int i = 0; i < msgLen; i++) {
        decToBin(msg[i], &msgBinArr[i * 8]);
    }

    // Write message binary array to image
    int msgBinArrLen = 8 * msgLen;
    for (int i = 0; i < msgBinArrLen; i++) {
        // Read pixel value (blue component only)
        int b = fgetc(imgFile);
        if (b == EOF) {
            printf("Error: Image file is too small to hide the message.\n");
            exit(1);
        }

        // Modify LSB of blue component to hide message
        int bit = msgBinArr[i];
        if (bit != (b & 1)) {
            b ^= 1;
            fseek(imgFile, -1, SEEK_CUR); // Move back to previous position to write modified value
            fputc(b, imgFile); // Write modified value
        }
    }

    printf("Message hidden successfully.\n");

    // Close image file
    fclose(imgFile);
}

/*
 * Function to extract a hidden message from an image file
 */
void extractMessage(char* imgFilename, char* msg) {
    // Open image file in read-only binary mode
    FILE* imgFile = fopen(imgFilename, "rb");
    if (imgFile == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }

    // Read BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imgFile);

    // Set pointer to the start of the image data
    fseek(imgFile, 54, SEEK_SET);

    // Extract message binary array (reverse order)
    int msgBinArr[MAX_MSG_LEN * 8];
    int i = 0;
    while (1) {
        // Read pixel value (blue component only)
        int b = fgetc(imgFile);
        if (b == EOF) {
            printf("Error: No hidden message found.\n");
            exit(1);
        }

        // Extract LSB of blue component
        int bit = b & 1;
        msgBinArr[i++] = bit;

        // If we've extracted enough bits for the message, stop reading from the file
        if (i >= MAX_MSG_LEN * 8 || (i % 8 == 0 && binToDec(&msgBinArr[i - 8], 8) == 0)) {
            break;
        }
    }

    // Convert message binary array to string (reverse order)
    int msgLen = i / 8; // i is the actual number of bits extracted
    for (int i = 0; i < msgLen; i++) {
        msg[i] = binToDec(&msgBinArr[i * 8], 8);
    }
    msg[msgLen] = '\0';

    printf("Message extracted successfully:\n%s\n", msg);

    // Close image file
    fclose(imgFile);
}

int main() {
    // Get image filename from user
    char imgFilename[MAX_FILENAME_LEN];
    printf("Enter image filename: ");
    fgets(imgFilename, MAX_FILENAME_LEN, stdin);
    imgFilename[strcspn(imgFilename, "\r\n")] = '\0'; // Remove newline

    // Get mode from user (hide or extract)
    int mode;
    printf("Enter mode (1 = hide, 2 = extract): ");
    scanf("%d", &mode);
    getchar(); // Consume newline

    // Process user input
    if (mode == 1) {
        // Get message from user
        char msg[MAX_MSG_LEN];
        printf("Enter message to hide: ");
        fgets(msg, MAX_MSG_LEN, stdin);
        msg[strcspn(msg, "\r\n")] = '\0'; // Remove newline

        // Hide message in image
        hideMessage(imgFilename, msg);
    } else if (mode == 2) {
        // Extract message from image
        char msg[MAX_MSG_LEN];
        extractMessage(imgFilename, msg);
    } else {
        printf("Invalid mode.\n");
        exit(1);
    }

    return 0;
}