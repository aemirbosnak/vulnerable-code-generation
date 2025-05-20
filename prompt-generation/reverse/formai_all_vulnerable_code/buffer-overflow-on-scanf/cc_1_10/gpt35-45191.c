//FormAI DATASET v1.0 Category: QR code reader ; Style: Ada Lovelace
/* QR Code Reader program by Ada Lovelace */

#include <stdio.h>
#include <stdlib.h>

#define QR_MAX_SIZE 500
#define QR_MIN_SIZE 21

int main()
{
    char QR_code[QR_MAX_SIZE][QR_MAX_SIZE];
    int QR_size;

    printf("Welcome to the QR Code Reader program by Ada Lovelace.\n");
    printf("Please enter the size of the QR code (21 to 500): ");
    scanf("%d", &QR_size);

    if(QR_size >= QR_MIN_SIZE && QR_size <= QR_MAX_SIZE)
    {
        printf("Please enter the QR code, row by row: \n");

        //Read the QR code, row by row
        int i,j;
        for(i=0; i < QR_size; i++)
        {
            for(j=0; j < QR_size; j++)
            {
                scanf(" %c", &QR_code[i][j]);
            }
        }

        //Print the QR code, row by row
        printf("\nQR code read successfully!\n");
        printf("The QR code is: \n");
        for(i=0; i < QR_size; i++)
        {
            for(j=0; j < QR_size; j++)
            {
                printf("%c ", QR_code[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Invalid size of QR code! Please enter a size between %d and %d.\n", QR_MIN_SIZE, QR_MAX_SIZE);
    }

    return 0;
}