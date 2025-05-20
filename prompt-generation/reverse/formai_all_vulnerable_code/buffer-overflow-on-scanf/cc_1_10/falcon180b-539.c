//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char* str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if a string is a valid QR code
int isQRCode(char* str) {
    int length = strlen(str);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }
    return 1;
}

// Function to read a QR code from a file
void readQRCode(char* filename) {
    FILE* file;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Read the first line of the file
    line = malloc(1024);
    if (line == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }
    read = getline(&line, &len, file);
    if (read <= 0) {
        printf("Error: could not read line from file '%s'\n", filename);
        exit(1);
    }

    // Check if the line is a valid QR code
    if (isQRCode(line)) {
        printf("Valid QR code:\n%s\n", line);
    } else {
        printf("Invalid QR code:\n%s\n", line);
    }

    // Close the file
    fclose(file);
}

int main() {
    // Read a QR code from a file
    char filename[1024];
    printf("Enter the filename of the QR code: ");
    scanf("%s", filename);
    readQRCode(filename);

    return 0;
}