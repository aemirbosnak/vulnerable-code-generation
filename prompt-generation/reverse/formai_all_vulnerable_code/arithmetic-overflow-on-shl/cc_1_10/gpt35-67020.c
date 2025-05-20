//FormAI DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 2000
#define MAX_MESSAGE_SIZE 500

void encrypt(char *message, int *image, int width, int height);
void decrypt(int *image, int width, int height);

int main()
{
    char message[MAX_MESSAGE_SIZE] = "The future is now!";
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int width = 1000, height = 1000;

    encrypt(message, (int *)image, width, height);

    decrypt((int *)image, width, height);

    return 0;
}

void encrypt(char *message, int *image, int width, int height)
{
    int i, j, k, message_length, bit_count = 0, bit_plane_count = 0, bit_plane_index = 7;
    int red, green, blue, alpha;

    message_length = strlen(message);

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            red = *(image + i * width + j) & 0xff;
            green = (*(image + i * width + j) >> 8) & 0xff;
            blue = (*(image + i * width + j) >> 16) & 0xff;
            alpha = (*(image + i * width + j) >> 24) & 0xff;

            if(bit_count < message_length * 8)
            {
                int ascii_value = (int) *(message + bit_count / 8);
                int bit_value = (ascii_value >> bit_plane_index) & 1;

                if(bit_value == 1)
                {
                    red = red | 1 << bit_plane_index;
                }
                else
                {
                    red = red & ~(1 << bit_plane_index);
                }

                bit_plane_index--;
                bit_count++;

                if(bit_plane_index < 0)
                {
                    bit_plane_index = 7;
                    bit_plane_count++;

                    if(bit_plane_count == 3)
                    {
                        bit_plane_count = 0;
                        bit_plane_index = 6;
                    }
                }
            }

            *(image + i * width + j) = (alpha << 24) | (blue << 16) | (green << 8) | red;
        }
    }

    printf("Message has been encrypted in the image!\n");
}

void decrypt(int *image, int width, int height)
{
    int i, j, k, bit_count = 0, bit_plane_count = 0, bit_plane_index = 7;
    int red, green, blue, alpha;
    char message[MAX_MESSAGE_SIZE] = "";

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            red = *(image + i * width + j) & 0xff;
            green = (*(image + i * width + j) >> 8) & 0xff;
            blue = (*(image + i * width + j) >> 16) & 0xff;
            alpha = (*(image + i * width + j) >> 24) & 0xff;

            int bit_value = (red >> bit_plane_index) & 1;
            *(message + bit_count / 8) |= (bit_value << (bit_count % 8));

            bit_plane_index--;
            bit_count++;

            if(bit_plane_index < 0)
            {
                bit_plane_index = 7;
                bit_plane_count++;

                if(bit_plane_count == 3)
                {
                    bit_plane_count = 0;
                    bit_plane_index = 6;
                }
            }
        }
    }

    printf("The message hidden in the image is: %s\n", message);
}