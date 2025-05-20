//FormAI DATASET v1.0 Category: QR code reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 64

void printSuccess() {
    printf("Wow! You scanned a QR code! :) \n");
}

void printError(char* message) {
    printf("Oops! Something went wrong :( \n");
    printf("Error message: %s \n", message);
}

bool validateQRCodeLength(char* qrCode) {
    return (strlen(qrCode) == MAX_SIZE);
}

bool validateQRCodeFormat(char* qrCode) {
    for(int i = 0; i < MAX_SIZE; i++) {
        if(qrCode[i] != '0' && qrCode[i] != '1') {
            return false;
        }
    }
    return true;
}

bool readQRCode() {
    printf("Please scan the QR code: \n");
    char* qrCode = (char*) malloc(MAX_SIZE * sizeof(char));
    scanf("%s", qrCode);
    printf("\n");

    if(!validateQRCodeLength(qrCode)) {
        printError("QR code is not the correct length!");
        return false;
    }

    if(!validateQRCodeFormat(qrCode)) {
        printError("QR code is not in binary format!");
        return false;
    }

    printSuccess();
    return true;
}

int main() {
    printf("Welcome to the C QR code reader!\n");
    while(!readQRCode()) {}
    printf("Thanks for using our program! \n");
    return 0;
}