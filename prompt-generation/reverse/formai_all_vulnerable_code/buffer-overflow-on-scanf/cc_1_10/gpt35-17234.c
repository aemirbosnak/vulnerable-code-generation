//FormAI DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

void hideMessage(char *carrierImageFilename, char *secretMsgFilename);
void extractMessage(char *stegoImageFilename);

int main()
{
    int option;
    char *carrierImageFilename = "carrier.bmp";
    char *secretMsgFilename = "secret.txt";
    char *stegoImageFilename = "stego.bmp";
    
    printf("\n========== IMAGE STEGANOGRAPHY ==========\n\n");
    printf("Choose an option:\n\n");
    printf("1. Hide a secret message into an image\n");
    printf("2. Extract a message from an image\n\n");
    printf("Option: ");
    scanf("%d", &option);
    
    switch (option)
    {
        case 1:
            hideMessage(carrierImageFilename, secretMsgFilename);
            break;
            
        case 2:
            extractMessage(stegoImageFilename);
            break;
            
        default:
            printf("Invalid option! Program terminated.\n");
            exit(1);
    }
    
    return 0;
}

void hideMessage(char *carrierImageFilename, char *secretMsgFilename)
{
    FILE *carrierFile, *secretMsgFile, *stegoFile;
    unsigned char carrier[MAX_SIZE][MAX_SIZE][3], secretMsg[MAX_SIZE];
    int i, j, k, msgLength, bitCount = 0;
    char bit;
    
    carrierFile = fopen(carrierImageFilename, "rb");
    secretMsgFile = fopen(secretMsgFilename, "r");
    stegoFile = fopen("stego.bmp", "wb");
    
    if (carrierFile == NULL || secretMsgFile == NULL || stegoFile == NULL)
    {
        printf("An error occurred! Could not open files.\n");
        exit(1);
    }
    
    printf("\nHiding message into image...\n");
    
    // Read carrier image header
    unsigned char header[54];
    for (i=0; i<54; i++)
    {
        header[i] = getc(carrierFile);
    }
    fwrite(header, sizeof(unsigned char), 54, stegoFile);
    
    // Read carrier image pixels
    for (i=0; i<MAX_SIZE; i++)
    {
        for (j=0; j<MAX_SIZE; j++)
        {
            for (k=0; k<3; k++)
            {
                carrier[i][j][k] = getc(carrierFile);
            }
        }
    }
    
    // Read secret message
    fgets(secretMsg, MAX_SIZE, secretMsgFile);
    msgLength = strlen(secretMsg);
    
    // Hide secret message bits into carrier image pixels
    for (i=0; i<MAX_SIZE; i++)
    {
        for (j=0; j<MAX_SIZE; j++)
        {
            for (k=0; k<3; k++)
            {
                if (bitCount < msgLength * 8)
                {
                    bit = (secretMsg[bitCount/8] >> (bitCount % 8)) & 1;
                    carrier[i][j][k] = (carrier[i][j][k] & 0xFE) | bit;
                    bitCount++;
                }
            }
        }
    }
    
    // Write stego image pixels
    for (i=0; i<MAX_SIZE; i++)
    {
        for (j=0; j<MAX_SIZE; j++)
        {
            for (k=0; k<3; k++)
            {
                putc(carrier[i][j][k], stegoFile);
            }
        }
    }
    
    fclose(carrierFile);
    fclose(secretMsgFile);
    fclose(stegoFile);
    
    printf("Message hidden successfully!\n");
}

void extractMessage(char *stegoImageFilename)
{
    FILE *stegoFile;
    unsigned char stego[MAX_SIZE][MAX_SIZE][3];
    int i, j, k, bitCount = 0;
    char msgChar = 0, bit;
    
    stegoFile = fopen(stegoImageFilename, "rb");
    
    if (stegoFile == NULL)
    {
        printf("An error occurred! Could not open stego file.\n");
        exit(1);
    }
    
    printf("\nExtracting message from image...\n");
    
    // Read stego image header
    unsigned char header[54];
    for (i=0; i<54; i++)
    {
        header[i] = getc(stegoFile);
    }
    
    // Read stego image pixels
    for (i=0; i<MAX_SIZE; i++)
    {
        for (j=0; j<MAX_SIZE; j++)
        {
            for (k=0; k<3; k++)
            {
                stego[i][j][k] = getc(stegoFile);
                bit = ((stego[i][j][k] & 1) << (bitCount % 8));
                msgChar |= bit;
                bitCount++;
                if (bitCount % 8 == 0)
                {
                    if (msgChar == '\0')
                    {
                        fclose(stegoFile);
                        printf("Message extracted successfully!\n");
                        return;
                    }
                    printf("%c", msgChar);
                    msgChar = 0;
                }
            }
        }
    }
    
    fclose(stegoFile);
    
    printf("Message extracted successfully!\n");
}