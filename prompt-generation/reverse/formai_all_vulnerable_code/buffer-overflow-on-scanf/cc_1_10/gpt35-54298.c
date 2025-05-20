//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QR_SIZE 21
#define QR_MODULE_SIZE 3

static char *QR[] = {
    "000000000000000", 
    "000000000000000", 
    "000000000000000", 
    "000000011110000", 
    "000000110011000", 
    "000001100001100", 
    "000001100001100", 
    "000011000000110", 
    "000011000000110", 
    "000011111110110", 
    "000110110110000", 
    "000110110110000",
    "001100000011000", 
    "001100000011000",
    "001111111111000", 
    "011000110000000", 
    "011000110000000", 
    "011110000000000", 
    "110011000000000", 
    "110011000000000",
    "111111111111111"
};

void print_qr(char qr_code[MAX_QR_SIZE][MAX_QR_SIZE], int size)
{
    int i,j;

    system("cls");

    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(qr_code[i][j] == '1')
            {
                printf("%c", 219);
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}

void generate_qr(char qr_code[MAX_QR_SIZE][MAX_QR_SIZE], int size, char data[])
{
    int i,j,x,y;
    int data_length = strlen(data);

    // Set the QR code to 0's
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            qr_code[i][j] = '0';
        }
    }

    // Add the QR code format information
    for(i=0; i<6; i++)
    {
        qr_code[size-1-i][8] = (i & 1) + '0';
        qr_code[8][i] = (i & 1) + '0';
    }

    for(i=0; i<data_length; i++)
    {
        x = i / QR_MODULE_SIZE;
        y = i % QR_MODULE_SIZE;

        for(j=0; j<QR_MODULE_SIZE; j++)
        {
            if(QR[(int)data[i]][j + (y * QR_MODULE_SIZE)] == '1')
            {
                qr_code[size-11+(j*2)][2+x*3+y] = '1';
                qr_code[size-10+(j*2)][2+x*3+y] = '1';

                qr_code[2+x*3+y][size-11+(j*2)] = '1';
                qr_code[2+x*3+y][size-10+(j*2)] = '1';
            }
        }
    }

    // Add the timing patterns
    for(i=8; i<size-8; i++)
    {
        if(i%2 == 0)
        {
            qr_code[i][6] = '1';
            qr_code[6][i] = '1';
        }
    }

    // Add the finder patterns
    for(i=0; i<7; i+=6)
    {
        for(j=0; j<7; j+=6)
        {
            for(x=0; x<5; x++)
            {
                for(y=0; y<5; y++)
                {
                    qr_code[i+x][j+y] = '1';
                }
            }

            qr_code[i+1][j+1] = '0';
            qr_code[i+1][j+5] = '0';
            qr_code[i+5][j+1] = '0';
        }
    }

    // Add the dark module
    qr_code[size-9][8] = '1';

    // Add the quiet zone
    for(i=0; i<4; i++)
    {
        for(j=0; j<size; j++)
        {
            qr_code[i][j] = '1';
            qr_code[size-1-i][j] = '1';
            qr_code[j][i] = '1';
            qr_code[j][size-1-i] = '1';
        }
    }
}

int main()
{
    char qr_code[MAX_QR_SIZE][MAX_QR_SIZE];
    char data[100];
    int size;
    time_t t;

    srand((unsigned) time(&t));

    printf("Enter data to encode: ");
    scanf("%s", data);

    size = strlen(data) * QR_MODULE_SIZE + 17;

    generate_qr(qr_code, size, data);

    print_qr(qr_code, size);

    return 0;
}