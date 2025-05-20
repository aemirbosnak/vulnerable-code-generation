//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function prototype for digital watermarking
void digitalWatermark(char *message);

int main()
{
    // Allocate memory for message
    char *message = malloc(MAX_SIZE * sizeof(char));
    
    // Take user input for message
    printf("Enter message:\n");
    scanf("%[^\n]s", message);

    // Call digital watermarking function
    digitalWatermark(message);

    // Print the digital watermarked message
    printf("Digital Watermarked message:\n%s\n", message);

    // Free the memory allocated for message
    free(message);

    return 0;
}

void digitalWatermark(char *message)
{
    int i = 0;

    // Generate a random key for watermarking
    int key = rand() % 128;

    // Iterate over the message characters
    while (message[i] != '\0')
    {
        // Apply bitwise XOR operation with the key
        message[i] = message[i] ^ key;

        // Move to next character
        i++;
    }

    // Append the key at the end of the message
    message[i] = key;
    message[i+1] = '\0';
}