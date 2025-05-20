//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_MESSAGE_SIZE 100
#define MAX_IMAGE_SIZE 100000

void replace_pixels(unsigned char *image, unsigned char *message, int len);
void stegano(unsigned char *image, unsigned char *message);
void extract(unsigned char *image, unsigned char *message);

int main(void)
{
    int message_size;
    unsigned char image[MAX_IMAGE_SIZE], message[MAX_MESSAGE_SIZE];

    // Read message and store it in memory
    printf("Enter the message: ");
    scanf("%d", &message_size);
    scanf("%s", message);

    // Convert message to binary
    for (int i = 0; i < message_size; i++)
    {
        message[i] = message[i] - 'a';
    }

    // Read image and store it in memory
    printf("Enter the image: ");
    scanf("%s", image);

    // Replace pixels with message
    stegano(image, message);

    // Extract message from image
    printf("Extracted message: %s\n", message);

    return 0;
}

void replace_pixels(unsigned char *image, unsigned char *message, int len)
{
    // Read image data
    unsigned char *p = image;
    for (int i = 0; i < MAX_IMAGE_SIZE; i++)
    {
        printf("%d ", *p);
        p++;
    }

    // Replace pixels with message data
    unsigned char *q = message;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < MAX_IMAGE_SIZE; j++)
        {
            if (*q == '1')
            {
                *p = 0xFF;
            }
            else
            {
                *p = 0x00;
            }
            q++;
            p++;
        }
    }

    // Display modified image
    printf("\nModified image: ");
    p = image;
    for (int i = 0; i < MAX_IMAGE_SIZE; i++)
    {
        printf("%d ", *p);
        p++;
    }
}

void stegano(unsigned char *image, unsigned char *message)
{
    replace_pixels(image, message, strlen(message));
}

void extract(unsigned char *image, unsigned char *message)
{
    unsigned char *p = message;
    for (int i = 0; i < MAX_IMAGE_SIZE; i++)
    {
        if (*p == '0')
        {
            *p = 'a';
        }
        p++;
    }
}