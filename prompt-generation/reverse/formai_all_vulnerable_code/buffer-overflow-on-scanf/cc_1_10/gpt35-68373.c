//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000   // Maximum length of message

void readMessage(char *message) {
    printf("Enter message to be watermarked:\n");
    fgets(message, MAXLEN, stdin);
}

void readKey(int *key) {
    printf("Enter a key (between 1 and 255):\n");
    scanf("%d", key);
}

void generateWatermark(char *watermark, char *message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        watermark[i] = message[i] ^ key;   // XOR operation
    }
}

void printMessage(char *message) {
    printf("Original message: %s", message);
}

void printWatermark(char *watermark) {
    printf("Watermark: ");
    for (int i = 0; i < strlen(watermark); i++) {
        printf("%02x ", (unsigned char)watermark[i]);   // Print each byte in hexadecimal format
    }
    printf("\n");
}

void extractWatermark(char *watermark, char *message, int key) {
    int len = strlen(watermark);
    for (int i = 0; i < len; i++) {
        message[i] = watermark[i] ^ key;   // XOR operation
    }
}

int main() {
    char message[MAXLEN];
    char watermark[MAXLEN];
    int key;
    readMessage(message);
    readKey(&key);
    generateWatermark(watermark, message, key);
    printf("Watermarking done!\n");
    printf("----------------------------------\n");
    printMessage(message);
    printWatermark(watermark);
    printf("----------------------------------\n");
    extractWatermark(watermark, message, key);
    printf("Watermark extraction done!\n");
    printf("----------------------------------\n");
    printWatermark(watermark);
    printMessage(message);
    printf("----------------------------------\n");
    return 0;
}