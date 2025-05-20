//FormAI DATASET v1.0 Category: QR code reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to represent a QR code */
struct QR_Code {
    char type[10];
    char data[100];
};

/* Function to read a QR code from a file */
struct QR_Code readQRCode(FILE *file) {
    struct QR_Code code;
    fscanf(file, "%s %s", code.type, code.data);
    return code;
}

/* Function to check if a string is a number */
int isNumber(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] < 48 || str[i] > 57)
            return 0;
    }
    return 1;
}

int main() {
    FILE *file;
    struct QR_Code code;

    // Open the file
    file = fopen("qrcode.txt", "r");
    if(file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read the first code
    code = readQRCode(file);

    // Loop through the file and read each code
    int i = 1;
    while(!feof(file)) {
        // If the code is a number, print it
        if(isNumber(code.data)) {
            printf("Code %d: %s\n", i, code.data);
            i++;
        }

        // Read the next code
        code = readQRCode(file);
    }

    // Close the file
    fclose(file);

    return 0;
}