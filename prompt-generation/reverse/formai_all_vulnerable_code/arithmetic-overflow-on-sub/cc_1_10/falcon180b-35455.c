//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_QR_SIZE 64

// Function to check if a string is a valid QR code
bool is_valid_qr(char *qr_str) {
    int i,j;
    for(i=0,j=0; i<MAX_QR_SIZE; i++) {
        if(qr_str[i] == '1' && j > 0) j++;
        else if(qr_str[i] == '0' && j > 0) j--;
        else if(qr_str[i]!= '0' && qr_str[i]!= '1') return false;
    }
    return j == 0;
}

// Function to read a QR code from a file
char *read_qr_from_file(char *filename) {
    FILE *fp;
    char *qr_str = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file '%s'.\n", filename);
        return NULL;
    }

    while ((read = getline(&qr_str, &len, fp))!= -1) {
        qr_str[read-1] = '\0'; // Replace newline character with null terminator
    }

    fclose(fp);
    return qr_str;
}

// Function to print a QR code in a matrix format
void print_qr_matrix(char *qr_str) {
    int i,j;
    int qr_size = strlen(qr_str);

    for(i=0; i<qr_size; i++) {
        for(j=0; j<qr_size; j++) {
            printf("%c", qr_str[i*qr_size+j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char *filename;
    char *qr_str;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Read QR code from file
    qr_str = read_qr_from_file(filename);
    if(qr_str == NULL) return 1;

    // Check if QR code is valid
    if(!is_valid_qr(qr_str)) {
        printf("Error: Invalid QR code.\n");
        return 1;
    }

    // Print QR code in matrix format
    printf("QR code:\n");
    print_qr_matrix(qr_str);

    return 0;
}