//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

// Function to convert a decimal number to binary
void decToBinary(int n, int binaryArray[])
{
    int i = 0;
    while (n > 0) {
        binaryArray[i] = n % 2;
        n = n / 2;
        i++;
    }
}

// Function to convert a binary number to decimal
int binaryToDec(int binaryArray[])
{
    int decimal = 0;
    for (int i = 0; i < 8; i++)
        decimal += binaryArray[i] * pow(2, i);
    return decimal;
}

// Function to perform digital watermarking
void digitalWatermarking(char* message, char* key)
{
    int binaryMessage[MAX_LENGTH], binaryKey[MAX_LENGTH], watermarked[MAX_LENGTH];
    int messageLength = strlen(message), keyLength = strlen(key);

    // Convert message and key to binary arrays
    for (int i = 0; i < messageLength; i++)
        decToBinary((int)message[i], &binaryMessage[i * 8]);

    for (int i = 0; i < keyLength; i++)
        decToBinary((int)key[i], &binaryKey[i * 8]);

    // Watermark the message with the key
    for (int i = 0; i < messageLength * 8; i++)
        watermarked[i] = (binaryMessage[i] + binaryKey[i]) % 2;

    // Convert watermarked message back to original characters
    char watermarkedMessage[MAX_LENGTH] = { 0 };
    for (int i = 0; i < messageLength; i++)
        watermarkedMessage[i] = (char)binaryToDec(&watermarked[i * 8]);

    printf("Original Message: %s\n", message);
    printf("Watermarked Message: %s\n", watermarkedMessage);
}

int main()
{
    char message[] = "Hello World";
    char key[] = "Secret Key";
    digitalWatermarking(message, key);

    return 0;
}