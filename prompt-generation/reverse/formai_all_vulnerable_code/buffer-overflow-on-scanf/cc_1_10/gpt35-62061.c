//FormAI DATASET v1.0 Category: QR code reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QR_CODE_LENGTH 256

// Function to check if the character is a Hexadecimal
bool isHex(char c)
{
    if (c >= '0' && c <= '9' || c >= 'A' && c <= 'F')
        return true;
    else
        return false;
}

// Function to convert QR code in HEX format to character format
char hexToChar(char hex[2])
{
    int first = hex[0] - '0';
    int second = hex[1] - '0';
    int hexVal = first * 16 + second;
    return (char)hexVal;
}

// Main function to read QR code
int main()
{
    char qrCode[QR_CODE_LENGTH+1];
    printf("Enter QR code : ");
    scanf("%s", qrCode);

    //check QR code length
    if(strlen(qrCode) != QR_CODE_LENGTH)
    {
        printf("Invalid QR code length. Please enter a %d-character QR code.\n", QR_CODE_LENGTH);
        return 1;
    }

    //check if QR code only contains hexadecimal characters
    for(int i=0; i<QR_CODE_LENGTH; i+=2)
    {
        if(!isHex(qrCode[i]) || !isHex(qrCode[i+1]))
        {
            printf("Invalid QR code format. Please enter a %d-character QR code containing only hexadecimal characters.\n", QR_CODE_LENGTH);
            return 1;
        }
    }

    //convert QR code to character format
    char qrCodeChar[QR_CODE_LENGTH/2 + 1];
    for(int i=0; i<QR_CODE_LENGTH; i+=2)
    {
        char hex[2] = {qrCode[i], qrCode[i+1]};
        qrCodeChar[i/2] = hexToChar(hex);
    }
    qrCodeChar[QR_CODE_LENGTH/2] = '\0';

    //print the converted QR code
    printf("QR code in character format : %s\n", qrCodeChar);

    return 0;
}