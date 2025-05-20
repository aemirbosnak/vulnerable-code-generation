//FormAI DATASET v1.0 Category: QR code reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QR_CODE_SIZE 1000

void readQRCode(char qrCode[][MAX_QR_CODE_SIZE], int qrCodeSize);
void displayQRCode(char qrCode[][MAX_QR_CODE_SIZE], int qrCodeSize);
bool isQRCodeValid(char qrCode[][MAX_QR_CODE_SIZE], int qrCodeSize);
void decodeQRCode(char qrCode[][MAX_QR_CODE_SIZE], int qrCodeSize);

int main()
{
    char qrCode[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE];
    int qrCodeSize;

    printf("Welcome to the QR Code Reader program in Post-Apocalyptic style!\n");
    printf("Please enter the size of the QR code (maximum size is %d): ", MAX_QR_CODE_SIZE);
    scanf("%d", &qrCodeSize);

    if(qrCodeSize > MAX_QR_CODE_SIZE)
    {
        printf("Invalid QR code size! Please try again.\n");
        exit(0);
    }

    readQRCode(qrCode, qrCodeSize);

    if(isQRCodeValid(qrCode, qrCodeSize))
    {
        printf("QR code is valid.\n");
        decodeQRCode(qrCode, qrCodeSize);
    }
    else
    {
        printf("Invalid QR code! Please try again.\n");
    }

    return 0;
}

void readQRCode(char qrCode[][MAX_QR_CODE_SIZE], int qrCodeSize)
{
    printf("Please enter the QR code:\n");

    for(int i=0; i<qrCodeSize; i++)
    {
        scanf("%s", qrCode[i]);
    }
}

void displayQRCode(char qrCode[][MAX_QR_CODE_SIZE], int qrCodeSize)
{
    printf("The decoded QR code is:\n");

    for(int i=0; i<qrCodeSize; i++)
    {
        printf("%s\n", qrCode[i]);
    }
}

bool isQRCodeValid(char qrCode[][MAX_QR_CODE_SIZE], int qrCodeSize)
{
    // In Post-Apocalyptic world, QR code can only consist of letters A-E and numbers 0-9
    for(int i=0; i<qrCodeSize; i++)
    {
        for(int j=0; qrCode[i][j]!='\0'; j++)
        {
            if((qrCode[i][j]<'A' || qrCode[i][j]>'E') && (qrCode[i][j]<'0' || qrCode[i][j]>'9'))
            {
                return false;
            }
        }
    }
    return true;
}

void decodeQRCode(char qrCode[][MAX_QR_CODE_SIZE], int qrCodeSize)
{
    char decodedMessage[MAX_QR_CODE_SIZE*MAX_QR_CODE_SIZE];
    int currentIndex = 0;

    for(int i=0; i<qrCodeSize; i++)
    {
        for(int j=0; qrCode[i][j]!='\0'; j++)
        {
            int currentChar = qrCode[i][j];
            if(currentChar >= '0' && currentChar <= '9')
            {
                decodedMessage[currentIndex++] = currentChar - '0' + 'A';
            }
            else
            {
                decodedMessage[currentIndex++] = currentChar;
            }
        }
    }

    decodedMessage[currentIndex] = '\0';
    printf("The decoded message is: %s\n", decodedMessage);
}