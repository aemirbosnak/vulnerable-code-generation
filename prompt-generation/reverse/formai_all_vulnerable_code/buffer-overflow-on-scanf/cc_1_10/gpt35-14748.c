//FormAI DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QR_SIZE 21

void generateQR(char qr[QR_SIZE][QR_SIZE], char code[])
{
    int i, j;
    int len = strlen(code);

    // fill the QR code matrix with random characters
    for (i = 0; i < QR_SIZE; i++)
    {
        for (j = 0; j < QR_SIZE; j++)
        {
            qr[i][j] = rand() % 2 ? '1' : '0';
        }
    }

    // place the code in the center of the matrix
    int x = QR_SIZE / 2 - len / 2;
    int y = QR_SIZE / 2 - len / 2;
    for (i = 0; i < len; i++)
    {
        qr[x][y] = code[i];
        x++;
    }

    // print the QR code
    printf("Unique QR Code:\n");
    for (i = 0; i < QR_SIZE; i++)
    {
        printf("   ");
        for (j = 0; j < QR_SIZE; j++)
        {
            printf("%c", qr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char code[10];

    // ask user for input
    printf("Please enter a code to generate a unique QR code: ");
    scanf("%s", code);

    // seed random number generator
    srand(time(NULL));

    // generate the QR code
    char qr[QR_SIZE][QR_SIZE];
    generateQR(qr, code);

    return 0;
}