//FormAI DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000 //maximum size of the image

int main()
{
    FILE *fptr;
    char filename[100], data; 

    printf("Enter the filename of the image: ");
    scanf("%s", filename);

    //open the image file in binary mode
    fptr = fopen(filename, "rb");
    if (fptr == NULL)
    {
        printf("Unable to open image file!");
        exit(1); //exit the program
    }

    //initialize the image buffer for steganography
    char buffer[MAX_SIZE];
    int count = 0;
    while (count < MAX_SIZE)
    {
        data = fgetc(fptr);
        if (feof(fptr))
            break;
        buffer[count++] = data;
    }

    //close the image file
    fclose(fptr);

    //get the message to be hidden in the image
    char message[MAX_SIZE];
    printf("\nEnter the message to be hidden in the image: ");
    scanf("%s", message);

    //get the length of the message
    int message_len = strlen(message);

    //check if the message length is less than or equal to the available buffer size
    if (message_len * 8 > MAX_SIZE)
    {
        printf("Error: Message is too large to hide in the image!");
        exit(1); //exit the program
    }

    //initialize the binary message buffer
    char binary_message[MAX_SIZE*8];
    int index = 0;
    for (int i = 0; i < message_len; i++)
    {
        int curr_char = message[i];
        for (int j = 7; j >= 0; j--)
        {
            binary_message[index++] = ((curr_char >> j) & 1) + '0';
        }
    }

    //hide the binary message in the image buffer
    int message_index = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (message_index < message_len*8)
        {
            buffer[i] = buffer[i] & ~1 | (binary_message[message_index++] - '0');
        }
        else
        {
            break;
        }
    }

    //create a new image file with the hidden message
    char new_filename[100];
    sprintf(new_filename, "hidden_%s", filename);
    fptr = fopen(new_filename, "wb");
    fwrite(buffer, sizeof(buffer), 1, fptr);
    fclose(fptr);

    printf("\nMessage hidden successfully in the image!");

    return 0;
}