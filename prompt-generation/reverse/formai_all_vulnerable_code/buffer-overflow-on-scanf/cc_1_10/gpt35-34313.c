//FormAI DATASET v1.0 Category: QR code reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct QRCode {
    char code[20];
};

typedef struct QRCode QRCode;

void readQRCode(char* code) {
    printf("Please scan the QR Code:\n");
    scanf("%s", code);
    printf("Scanned Code: %s\n", code);
}

bool validateQRCode(char* code) {
    int len = strlen(code);
    if (len != 20) {
        printf("Invalid QR Code. Code length should be 20 characters.\n");
        return false;
    }
    
    for (int i=0; i<len; i++) {
        if ((code[i] < 'A' || code[i] > 'Z') && (code[i] < '0' || code[i] > '9')) {
            printf("Invalid QR Code. Only uppercase letters and numbers are allowed.\n");
            return false;
        }
    }
    
    return true;
}

void displayLoveMessage() {
    printf("\n\n");
    printf("             ********                                   ********\n");
    printf("          ***        ***                             ***        ***\n");
    printf("        ***              ***                       ***              ***\n");
    printf("      ***         I      LOVE     YOU        ***\n");
    printf("    ***                         ***           ***                          ***\n");
    printf("  ***                              ***     ***                              ***\n");
    printf(" ***                                   *****                                   ***\n");
    printf(" ***                                   *****                                   ***\n");
    printf("  ***                              ***     ***                              ***\n");
    printf("    ***                         ***           ***                          ***\n");
    printf("      ***         YOU    ARE     MY    **  ***\n");
    printf("        ***                        LOVE     **                     ***\n");
    printf("          ***            ********       ********            ***\n");
    printf("             ********\n");
    printf("\n\n");
}

int main() {
    QRCode code;
    bool isValid = false;
    
    do {
        readQRCode(code.code);
        isValid = validateQRCode(code.code);
    } while (!isValid);
    
    displayLoveMessage();
    return 0;
}