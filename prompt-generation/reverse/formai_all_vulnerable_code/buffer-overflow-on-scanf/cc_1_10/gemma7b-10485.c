//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1024

int main()
{
    char data[MAX_DATA_SIZE];
    int data_size = 0;
    char message[MAX_DATA_SIZE];
    int message_size = 0;

    // Get the data from the user
    printf("Enter the data (in binary): ");
    scanf("%s", data);

    // Calculate the data size
    for (int i = 0; data[i] != '\0'; i++)
    {
        data_size++;
    }

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%s", message);

    // Calculate the message size
    for (int i = 0; message[i] != '\0'; i++)
    {
        message_size++;
    }

    // Hide the message in the data
    int i = 0;
    for (int j = 0; j < message_size; j++)
    {
        if (data_size - i - 1 >= message_size)
        {
            data[i] = (message[j] & 0x1) << 7 | data[i] & 0x7F;
            i++;
        }
    }

    // Print the stego data
    printf("Stego data: ");
    for (int i = 0; data[i] != '\0'; i++)
    {
        printf("%x ", data[i]);
    }

    return 0;
}