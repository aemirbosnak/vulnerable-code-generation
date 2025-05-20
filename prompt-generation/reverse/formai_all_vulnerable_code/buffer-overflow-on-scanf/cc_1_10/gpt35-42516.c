//FormAI DATASET v1.0 Category: QR code reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CODE_LENGTH 500

// Function to check if the given string is a valid QR code
bool isValidQRCode(char qrCode[])
{
    int codeLength = strlen(qrCode);

    // A valid QR code should always begin and end with '*'
    if(qrCode[0] != '*' || qrCode[codeLength-1] != '*')
        return false;

    // A valid QR code should contain only '1's and '0's and '*'
    for(int i=1; i<codeLength-1; i++)
    {
        if(qrCode[i] != '1' && qrCode[i] != '0' && qrCode[i] != '*')
            return false;
    }

    return true;
}

// Main function to read QR code from input and decode it
int main()
{
    printf("Please scan your QR code:\n");

    char qrCode[MAX_CODE_LENGTH];

    scanf("%s", qrCode);

    if(!isValidQRCode(qrCode))
    {
        printf("Invalid QR code, please scan a valid QR code.\n");
        return 0;
    }

    printf("QR code scanned successfully.\n\n");
    printf("Decoding QR code...\n\n");

    // Removing the first and last '*' characters from QR code
    int codeLength = strlen(qrCode);
    char qrCodeStripped[codeLength-1];
    strncpy(qrCodeStripped, qrCode+1, codeLength-2);
    qrCodeStripped[codeLength-2] = '\0';

    // Splitting up QR code into groups of 8 bits
    int numGroups = strlen(qrCodeStripped) / 8;
    char *bitGroups[numGroups];
    for(int i=0; i<numGroups; i++)
    {
        bitGroups[i] = malloc(9);
        strncpy(bitGroups[i], qrCodeStripped+i*8, 8);
        bitGroups[i][8] = '\0';
    }

    printf("QR code decoded successfully.\n\n");

    // Printing the decoded QR code
    printf("QR code data:\n");
    for(int i=0; i<numGroups; i++)
        printf("%c", strtol(bitGroups[i], NULL, 2));

    return 0;
}