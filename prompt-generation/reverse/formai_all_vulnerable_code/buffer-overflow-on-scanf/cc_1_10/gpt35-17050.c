//FormAI DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include<stdio.h>

// Function to convert decimal to binary
void decToBin(int num, int binaryNum[])
{
    int temp[1000], i = 0;
    while (num > 0)
    {
        temp[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        binaryNum[i - 1 - j] = temp[j];
    }
}

// Function to hide message in image
void hideMessageInImage(char imgFileName[], char message[])
{
    FILE* fptr1 = fopen(imgFileName, "rb");
    FILE* fptr2 = fopen("temp.jpg", "wb");

    int ch, byteCount = 0, bitCount = 0, binaryMessage[1000];
    char tempCharacter;

    // Convert message to binary
    for (int i = 0; message[i] != '\0'; i++)
    {
        decToBin((int)message[i], &binaryMessage[8 * i]);
    }

    // Add null character at the end of binary message
    int arrSize = sizeof(binaryMessage) / sizeof(int);
    binaryMessage[arrSize - 1] = '\0';

    // Loop through image file and hide message in LSB of each pixel
    while (1)
    {
        ch = getc(fptr1);

        if (ch == EOF)
        {
            break;
        }

        if (byteCount < arrSize)
        {
            // Modify last bit of each byte
            int binaryCh[8];
            decToBin((int)ch, binaryCh);
            binaryCh[7] = binaryMessage[byteCount * 8 + bitCount];
            int modifiedCh = 0;
            for (int i = 0; i < 8; i++)
            {
                modifiedCh += binaryCh[i] * pow(2, 7 - i);
            }
            putc(modifiedCh, fptr2);

            bitCount++;
            if (bitCount == 8)
            {
                byteCount++;
                bitCount = 0;
            }
        }
        else
        {
            putc(ch, fptr2);
        }
    }

    fclose(fptr1);
    fclose(fptr2);

    // Replace original image with modified image
    remove(imgFileName);
    rename("temp.jpg", imgFileName);
}

// Function to extract hidden message from image
void extractMessageFromImage(char imgFileName[], char extractedMessage[])
{
    FILE* fptr = fopen(imgFileName, "rb");

    int ch, byteCount = 0, bitCount = 0, binaryCh[8], binaryMessage[1000], msgIndex = 0;

    // Loop through image file and extract LSB of each pixel
    while (1)
    {
        ch = getc(fptr);

        if (ch == EOF)
        {
            break;
        }

        // Get last bit of each byte
        decToBin((int)ch, binaryCh);
        binaryMessage[byteCount * 8 + bitCount] = binaryCh[7];

        bitCount++;
        if (bitCount == 8)
        {
            byteCount++;
            bitCount = 0;
        }
    }

    // Convert binary message to text
    for (int i = 0; i < byteCount * 8; i += 8)
    {
        int ascii = 0;
        for (int j = 0; j < 8; j++)
        {
            ascii += binaryMessage[i + j] * pow(2, 7 - j);
        }
        extractedMessage[msgIndex++] = (char)ascii;
    }

    extractedMessage[msgIndex] = '\0';
    fclose(fptr);
}

int main()
{
    char imgFileName[100], message[1000], extractedMessage[1000];
    printf("Enter name of image file (with extension): ");
    scanf("%s", imgFileName);
    getchar();
    printf("Enter message to hide in image: ");
    fgets(message, 1000, stdin);

    hideMessageInImage(imgFileName, message);
    printf("Message hidden successfully!\n");

    extractMessageFromImage(imgFileName, extractedMessage);
    printf("Extracted message: %s\n", extractedMessage);

    return 0;
}