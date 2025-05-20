//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: surprised
#include <stdio.h>

// Function to convert RGB values to grayscale
int makeGray(int r, int g, int b)
{
    return (0.21*r + 0.72*g + 0.07*b);
}

// Function to convert grayscale value to ASCII character
char getAscii(int grayValue)
{
    if (grayValue >= 230)
        return ' ';
    else if (grayValue >= 200 && grayValue < 230)
        return '.';
    else if (grayValue >= 180 && grayValue < 200)
        return ':';
    else if (grayValue >= 160 && grayValue < 180)
        return 'o';
    else if (grayValue >= 130 && grayValue < 160)
        return '&';
    else if (grayValue >= 100 && grayValue < 130)
        return '8';
    else if (grayValue >= 70 && grayValue < 100)
        return '#';
    else if (grayValue >= 50 && grayValue < 70)
        return '*';
    else if (grayValue >= 30 && grayValue < 50)
        return 'i';
    else
        return '@';
}

int main()
{
    // Opening the image file
    FILE *imgFile;
    imgFile = fopen("image.jpg", "rb");

    // Seeking and getting the height and width of the image
    fseek(imgFile, 0x0012, SEEK_SET);
    int width, height;
    fread(&width, sizeof(width), 1, imgFile);
    fread(&height, sizeof(height), 1, imgFile);

    // Creating a buffer to store the image data
    int imgSize = width * height;
    unsigned char data[imgSize*3];
    fseek(imgFile, 0x007A, SEEK_SET);
    fread(data, sizeof(unsigned char), imgSize*3, imgFile);

    // Closing the image file
    fclose(imgFile);

    // Looping through each pixel and converting it to ASCCI art
    int index = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int r = data[index];
            int g = data[index+1];
            int b = data[index+2];

            int grayValue = makeGray(r, g, b);
            char asciiChar = getAscii(grayValue);

            printf("%c", asciiChar);

            index += 3;
        }
        printf("\n");
    }

    return 0;
}