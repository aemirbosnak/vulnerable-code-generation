//FormAI DATASET v1.0 Category: QR code reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_INPUT_SIZE 1024
#define MAX_QR_CODE_SIZE 256

// Function to check if the given input is a valid QR code
bool isQRCode(char *input)
{
    int len = strlen(input);
    if (len != MAX_QR_CODE_SIZE)
        return false;

    for (int i = 0; i < len; i++)
    {
        if (input[i] != '0' && input[i] != '1')
            return false;
    }

    return true;
}

// Function to generate a random QR code
void generateQRCode(char *qrCode)
{
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < MAX_QR_CODE_SIZE; i++)
    {
        qrCode[i] = rand() % 2 == 0 ? '0' : '1';
    }
}

int main()
{
    char input[MAX_INPUT_SIZE];
    char qrCode[MAX_QR_CODE_SIZE];

    printf("Welcome to the QR Code Reader!\n");

    // Main loop for reading QR codes
    while (true)
    {
        printf("Please enter a valid QR code or type 'generate' to randomly generate one: ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove the newline character at the end of the input
        int len = strlen(input);
        if (input[len-1] == '\n')
            input[len-1] = '\0';

        // Check if the user wants to generate a QR code
        if (strcmp(input, "generate") == 0)
        {
            generateQRCode(qrCode);
            printf("Generated QR code: %s\n", qrCode);
            continue;
        }

        // Check if the input is a valid QR code
        if (isQRCode(input))
        {
            printf("Valid QR code detected!\n");
        }
        else
        {
            printf("Invalid QR code. Please try again.\n");
        }
    }

    return 0;
}