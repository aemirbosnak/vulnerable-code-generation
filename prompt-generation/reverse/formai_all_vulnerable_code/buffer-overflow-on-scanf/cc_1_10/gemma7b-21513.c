//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1024

int main()
{
    int i, j, k, l, n, m, flag = 0;
    char img[MAX], msg[MAX], secret[MAX], cover[MAX];
    FILE *fp;

    // Open the image file
    fp = fopen("image.jpg", "rb");
    if (fp == NULL)
    {
        printf("Error opening file");
        return 1;
    }

    // Read the image file
    fread(img, MAX, 1, fp);

    // Close the image file
    fclose(fp);

    // Convert the image file into a binary string
    for (i = 0; img[i] != '\0'; i++)
    {
        sprintf(secret, "%03x ", img[i]);
        strcat(cover, secret);
    }

    // Get the message from the user
    printf("Enter your message: ");
    scanf("%s", msg);

    // Hide the message in the image
    n = strlen(msg);
    for (i = 0; i < n; i++)
    {
        k = msg[i] - 'a';
        l = (k + flag) % MAX;
        img[l] ^= 0x55;
        flag = (flag + 1) % MAX;
    }

    // Save the modified image file
    fp = fopen("image.jpg", "wb");
    if (fp == NULL)
    {
        printf("Error saving file");
        return 1;
    }

    fwrite(img, MAX, 1, fp);

    fclose(fp);

    // Print a confirmation message
    printf("Message hidden successfully!");

    return 0;
}