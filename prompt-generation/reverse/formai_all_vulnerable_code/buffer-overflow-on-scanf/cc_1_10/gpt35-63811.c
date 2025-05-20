//FormAI DATASET v1.0 Category: QR code reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 100

void read_QR_code(char qr_code[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE], int n) {
    // function to read the QR code from stdin
    
    printf("Input the QR code:\n");
    for (int i = 0; i < n; i++) {
        fgets(qr_code[i], MAX_QR_CODE_SIZE, stdin);
        qr_code[i][strcspn(qr_code[i], "\n")] = 0; // remove newline character
    }
}

void print_QR_code(char qr_code[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE], int n) {
    // function to print the QR code
    
    for (int i = 0; i < n; i++) {
        printf("%s\n", qr_code[i]);
    }
}

void decode_QR_code(char qr_code[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE], int n) {
    // function to decode the QR code
    
    char decoded_str[MAX_QR_CODE_SIZE * MAX_QR_CODE_SIZE] = "";
    int pos = 0;
    
    // loop through each cell of the QR code
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // check if the current cell is a black pixel
            if (qr_code[i][j] == '#') {
                // check if the previous character was also a black pixel
                if (decoded_str[pos-1] == '#') {
                    decoded_str[pos] = '1';
                } else {
                    decoded_str[pos] = '0';
                }
                pos++;
            }
        }
    }
    
    printf("Decoded string: %s\n", decoded_str);
}

int main() {
    char qr_code[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE];
    int n;
    
    printf("Enter the size of the QR code: ");
    scanf("%d", &n);
    getchar(); // consume newline character
    
    read_QR_code(qr_code, n);
    printf("QR code:\n");
    print_QR_code(qr_code, n);
    
    decode_QR_code(qr_code, n);
    
    return 0;
}