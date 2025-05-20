//FormAI DATASET v1.0 Category: QR code generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate random character
char randomCharacter() {
    char randomChar = 'A' + (rand() % 26);
    return randomChar;
}

// Function to generate a random string of length n
char* generateRandomString(int n) {
    char* str = (char*)malloc((n+1)*sizeof(char));
    for(int i=0; i<n; i++) {
        str[i] = randomCharacter();
    }
    str[n] = '\0';
    return str;
}


// Function to generate QR code with paranoid encoding
char* generateQRCode(char* data, int length) {
    char* encData = (char*)malloc((length+1)*sizeof(char));
    for(int i=0; i<length; i++) {
        encData[i] = data[i] ^ (i % 256);   // paranoid encoding
    }
    encData[length] = '\0';
    return encData;
}

int main() {
    int n;
    printf("Enter the length of the string: ");
    scanf("%d", &n);

    char* data = generateRandomString(n);

    char* QRcode = generateQRCode(data, n);

    // Printing original string and QR code
    printf("Original string: %s\n", data);
    printf("QR code: %s\n", QRcode);

    // Freeing the memory allocated for data and QR code
    free(data);
    free(QRcode);

    return 0;
}