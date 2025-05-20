//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_MODULES 100

// Function to read QR code image and return its data
char* readQRCode(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* data = malloc(filesize + 1);
    int i = 0;
    while ((data[i] = fgetc(file))!= EOF) {
        i++;
    }
    data[i] = '\0';
    fclose(file);

    return data;
}

// Function to parse QR code data and return its message
char* parseQRCode(char* data) {
    int length = strlen(data);
    int modules = length / 8;
    if (length % 8!= 0) {
        printf("Error: Invalid QR code data\n");
        exit(1);
    }

    char* message = malloc(MAX_LENGTH);
    int index = 0;

    for (int i = 0; i < modules; i++) {
        int mask = 1 << 7;
        int value = 0;

        for (int j = 0; j < 8; j++) {
            char c = tolower(data[i * 8 + j]);
            if (c == '1') {
                value |= mask;
            }
            mask >>= 1;
        }

        if (value == 0) {
            printf("Error: Invalid QR code data\n");
            exit(1);
        }

        message[index++] = value;
    }

    message[index] = '\0';
    return message;
}

// Function to print QR code message in a surrealist style
void printQRCode(char* message) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <QR code image file>\n", argv[0]);
        exit(1);
    }

    char* data = readQRCode(argv[1]);
    char* message = parseQRCode(data);
    free(data);

    printQRCode(message);

    return 0;
}