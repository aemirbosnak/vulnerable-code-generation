//FormAI DATASET v1.0 Category: QR code reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_LEN 500
#define MAX_SYMBOL_SIZE 50

void printQRCode(char qrCode[][MAX_SYMBOL_SIZE], int size)
{
    printf("\nQR Code Pattern:\n");

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%c ",qrCode[i][j]);
        }

        printf("\n");
    }
}

bool isValidQRCode(char qrCode[][MAX_SYMBOL_SIZE], int size)
{
    bool isValid=true;

    // Check if the QR code has at least 3 horizontal symbols and 3 vertical symbols
    if(size<3)
    {
        isValid=false;
        printf("Invalid QR Code Pattern! Size is less than 3x3!\n");
        return isValid;
    }

    // Check if each symbol is an upper case or lower case English letter
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if((qrCode[i][j]<'A' || qrCode[i][j]>'Z') && (qrCode[i][j]<'a' || qrCode[i][j]>'z'))
            {
                isValid=false;
                printf("Invalid QR Code Pattern! Symbol (%d,%d) is not an English letter!\n",i,j);
                return isValid;
            }
        }
    }

    // Check if the first and last symbol in each row and column are the same letter
    for(int i=0;i<size;i++)
    {
        if(qrCode[i][0]!=qrCode[i][size-1])
        {
            isValid=false;
            printf("Invalid QR Code Pattern! First and last symbol in row %d are not the same letter!\n",i);
            return isValid;
        }
        if(qrCode[0][i]!=qrCode[size-1][i])
        {
            isValid=false;
            printf("Invalid QR Code Pattern! First and last symbol in column %d are not the same letter!\n",i);
            return isValid;
        }
    }

    return isValid;
}

int main()
{
    char qrCode[MAX_QR_CODE_LEN][MAX_SYMBOL_SIZE];
    int numSymbols=0, symbolSize=0, qrSize=0;

    printf("Enter Number of Symbols in QR Code Pattern (max %d): ",MAX_QR_CODE_LEN);
    scanf("%d",&numSymbols);

    printf("\nEnter Size of Each Symbol in QR Code Pattern (max %d): ",MAX_SYMBOL_SIZE);
    scanf("%d",&symbolSize);

    qrSize=numSymbols*symbolSize;

    // Check if QR code size is greater than max size
    if(qrSize>MAX_QR_CODE_LEN)
    {
        printf("Invalid QR Code Pattern Size! Maximum allowed size is %d!\n",MAX_QR_CODE_LEN);
        return -1;
    }

    printf("\nEnter QR Code Pattern by Entering Each Symbol from Left to Right for Each Row:\n");

    for(int i=0;i<qrSize;i++)
    {
        for(int j=0;j<symbolSize;j++)
        {
            scanf(" %c",&qrCode[i][j]);
        }
    }

    printQRCode(qrCode,qrSize);

    if(isValidQRCode(qrCode,qrSize))
    {
        printf("\nQR Code Pattern is Valid!\n");
    }

    return 0;
}