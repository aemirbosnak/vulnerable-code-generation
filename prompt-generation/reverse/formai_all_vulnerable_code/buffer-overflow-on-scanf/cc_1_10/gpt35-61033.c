//FormAI DATASET v1.0 Category: QR code reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of the QR code
#define MAX_QR_CODE_LENGTH 100

// Define the maximum length of the file name
#define MAX_FILE_NAME_LENGTH 50

// Define the QR code struct
typedef struct QRCode
{
    char code[MAX_QR_CODE_LENGTH]; // The QR code string
    int length; // The length of the QR code string
} QRCode;

// Function prototypes
void readQRCode(QRCode *qrCode);
void printQRCode(QRCode qrCode);
void saveQRCodeToFile(QRCode qrCode, char *fileName);
int checkIfFileExists(char *fileName);

int main()
{
    QRCode qrCode;
    char fileName[MAX_FILE_NAME_LENGTH];
    
    printf("Welcome to the QR code reader program!\n");
    printf("Please enter the QR code to read:\n");
    readQRCode(&qrCode);
    printf("The QR code you entered is:\n");
    printQRCode(qrCode);
    printf("Please enter a file name to save this QR code to:\n");
    scanf("%s", fileName);
    saveQRCodeToFile(qrCode, fileName);
    printf("The QR code has been saved to the file: %s\n", fileName);
    return 0;
}

// Function to read the QR code string from the user
void readQRCode(QRCode *qrCode)
{
    char input[MAX_QR_CODE_LENGTH];
    scanf("%s", input);
    int length = strlen(input);
    for(int i=0; i<length; i++)
    {
        char c = input[i];
        if(isalnum(c))
        {
            qrCode->code[i] = c; // Only add alphanumeric characters to the QR code
        }
    }
    qrCode->length = strlen(qrCode->code);
}

// Function to print the QR code
void printQRCode(QRCode qrCode)
{
    for(int i=0; i<qrCode.length; i++)
    {
        printf("%c", qrCode.code[i]);
    }
    printf("\n");
}

// Function to save the QR code to a file
void saveQRCodeToFile(QRCode qrCode, char *fileName)
{
    FILE *file;
    int fileExists = checkIfFileExists(fileName);
    if(fileExists)
    {
        file = fopen(fileName, "a");
    }
    else
    {
        file = fopen(fileName, "w");
    }
    fprintf(file, "%s\n", qrCode.code);
    fclose(file);
}

// Function to check if a file exists
int checkIfFileExists(char *fileName)
{
    FILE *file;
    file = fopen(fileName, "r");
    if(file)
    {
        fclose(file);
        return 1; // The file exists
    }
    return 0; // The file does not exist
}