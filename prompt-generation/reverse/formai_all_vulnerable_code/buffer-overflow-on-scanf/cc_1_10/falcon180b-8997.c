//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QR_SIZE 10000

// Function to check if a string is a valid QR code
int is_qr_code(char* str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }
    return 1;
}

// Function to read a QR code from a file
void read_qr_code(FILE* fp) {
    char str[MAX_QR_SIZE];
    int len;

    // Read the QR code string from the file
    fgets(str, MAX_QR_SIZE, fp);
    len = strlen(str);

    // Check if the string is a valid QR code
    if (is_qr_code(str)) {
        // Display the string in a peaceful style
        for (int i = 0; i < len; i++) {
            if (isalpha(str[i])) {
                printf("%c", toupper(str[i]));
            } else {
                printf("%c", str[i]);
            }
        }
        printf("\n");
    } else {
        // Display an error message if the string is not a valid QR code
        printf("Invalid QR code\n");
    }
}

int main() {
    FILE* fp;
    char filename[100];

    // Prompt the user to enter the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the QR code from the file
    read_qr_code(fp);

    // Close the file
    fclose(fp);

    return 0;
}