//FormAI DATASET v1.0 Category: QR code reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_SIZE 1000

bool isValidQR(char *qr) {
    // Checking if the QR code has valid format
    if (strlen(qr) != 101 || qr[0] != 'C' || qr[1] != ':' || qr[4] != ':' || qr[7] != ':' || qr[29] != ':' || qr[52] != ':' || qr[75] != ':') {
        return false;
    }
    
    // Checking if the QR code has valid characters
    for (int i=0; i<101; i++) {
        if (qr[i] < 32 || qr[i] > 126) {
            return false;
        }
    }
    
    return true;
}

int decodeQR(char *qr, char *decodedString) {
    // Reading the data from the QR code
    char data[51];
    int startIndexes[6] = {2, 5, 8, 30, 53, 76};
    for (int i=0; i<6; i++) {
        strncpy(data + i*8, qr+ startIndexes[i], 8);
    }
    data[50] = '\0';
    
    // Decoding the data into a string
    char decoded[41];
    for (int i=0; i<40; i++) {
        char c = 0;
        for (int j=0; j<5; j++) {
            c |= ((data[i*5 + j] - '0') << (4-j));
        }
        decoded[i] = c;
    }
    decoded[40] = '\0';
    
    // Copying the decoded string to output variable
    strncpy(decodedString, decoded, 41);
    return 0;
}

int main() {
    char qr[MAX_QR_SIZE];
    char decodedString[41];

    // Reading QR code from user input
    printf("Scan the C QR Code:\n");
    gets(qr);
    
    // Checking if the QR code is valid
    if (!isValidQR(qr)) {
        printf("Invalid QR Code!\n");
        return 1;
    }
    
    // Decoding the QR code
    decodeQR(qr, decodedString);
    
    // Printing the decoded string
    printf("QR Code Decoded: %s\n", decodedString);
    
    return 0;
}