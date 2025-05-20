//FormAI DATASET v1.0 Category: QR code reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isQRCode(char *str)
{
    if (strlen(str) > 1 &&
        str[0] == 'Q' &&
        str[1] == 'R')
        return true;
    return false;
}

void readQRCode(char *code) 
{
    printf("Scan QR Code: ");
    scanf("%s", code);
}

void displayQRData(char *data) 
{
    printf("\n\nQR Data: %s", data);
}

int main()
{
    char QRCode[MAX_SIZE];
    bool validCode = false;

    while (!validCode)
    {
        readQRCode(QRCode);
        if (isQRCode(QRCode))
        {
            validCode = true;
            break;
        }
        printf("Invalid QR Code! Please enter a valid QR code.\n");
    }

    //process data
    char QRData[MAX_SIZE];
    strncpy(QRData, QRCode + 2, strlen(QRCode) - 2);
    displayQRData(QRData);

    return EXIT_SUCCESS;
}