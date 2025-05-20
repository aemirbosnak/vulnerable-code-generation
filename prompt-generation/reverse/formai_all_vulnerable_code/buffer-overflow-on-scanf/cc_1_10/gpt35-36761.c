//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_GRAYSCALE 255
#define MAX_ASCII 70

void convertImageToAscii(char asciiImg[MAX_HEIGHT][MAX_WIDTH], int img[MAX_HEIGHT][MAX_WIDTH], int height, int width);
char mapGrayToAscii(int gray);

int main()
{
    FILE* fp;
    char filename[100];
    int img[MAX_HEIGHT][MAX_WIDTH];
    char asciiImg[MAX_HEIGHT][MAX_WIDTH];
    int height = 0, width = 0;

    printf("Enter the filename of the image to convert: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp)
    {
        char magicNum[3];
        fscanf(fp, "%s\n", magicNum);
        fscanf(fp, "%d %d\n", &width, &height);
        int maxVal;
        fscanf(fp, "%d\n", &maxVal);

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                fscanf(fp, "%d ", &img[i][j]);
            }
            fscanf(fp, "\n");
        }
        fclose(fp);

        convertImageToAscii(asciiImg, img, height, width);

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                printf("%c", asciiImg[i][j]);
            }
            printf("\n");
        }
    }
}

void convertImageToAscii(char asciiImg[MAX_HEIGHT][MAX_WIDTH], int img[MAX_HEIGHT][MAX_WIDTH], int height, int width)
{
    if (height <= 0 || width <= 0) return;

    convertImageToAscii(asciiImg, img, height-1, width);
    if (height-1 >= 0) {
        for (int i = 0; i < width; i++)
        {
            asciiImg[height-1][i] = mapGrayToAscii(img[height-1][i]);
        }
    }
}

char mapGrayToAscii(int gray) {
    int index = gray / (MAX_GRAYSCALE / MAX_ASCII);
    switch (index)
    {
    case 0: return ' ';
    case 1: return '.';
    case 2: return ':';
    case 3: return '-';
    case 4: return '=';
    case 5: return '+';
    case 6: return '*';
    case 7: return '#';
    case 8: return '%';
    case 9: return '@';
    default: return '@'; // can't go beyond 10
    }
}