//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

char asciiChars[11] = {'@', '#', 'S', '%', '?', '*', '+', ',', '.', ' '};
int charBrightness[11] = {256, 192, 128, 96, 64, 48, 32, 24, 16, 8};

int main()
{
    FILE *imageFile, *asciiFile;
    char imageFileName[100], asciiFileName[100];
    int imageWidth, imageHeight, pixelSize, i, j, k, currentPixel;
    unsigned char *imageData;
    char asciiArt[MAX_HEIGHT][MAX_WIDTH+1];
    int charIndex;

    printf("Enter image file name: ");
    scanf("%s", imageFileName);

    imageFile = fopen(imageFileName, "rb");
    if(imageFile == NULL)
    {
        printf("Unable to open image file! Please check the file name and try again.\n");
        exit(1);
    }

    fseek(imageFile, 18, SEEK_SET);
    fread(&imageWidth, sizeof(int), 1, imageFile);
    fread(&imageHeight, sizeof(int), 1, imageFile);

    fseek(imageFile, 28, SEEK_SET);
    fread(&pixelSize, sizeof(short int), 1, imageFile);

    if(pixelSize != 24)
    {
        printf("Invalid image format! This program only supports 24-bit color depth.\n");
        exit(1);
    }

    imageData = (unsigned char*) malloc(imageWidth * imageHeight * 3);
    fread(imageData, sizeof(unsigned char), imageWidth * imageHeight * 3, imageFile);

    fclose(imageFile);

    for(i=0; i<imageHeight; i++)
    {
        for(j=0; j<imageWidth; j++)
        {
            currentPixel = i * imageWidth * 3 + j * 3;
            charIndex = 0;
            for(k=1; k<10; k++)
            {
                if(abs(imageData[currentPixel] - charBrightness[k]) < abs(imageData[currentPixel] - charBrightness[charIndex]))
                {
                    charIndex = k;
                }
            }
            asciiArt[i][j] = asciiChars[charIndex];
        }
        asciiArt[i][imageWidth] = '\0';

        // Print each line of ASCII art
        printf("%s\n", asciiArt[i]);
    }

    printf("Do you want to save the ASCII art to a file? (Y/N): ");
    char saveChoice;
    scanf(" %c", &saveChoice);

    if(saveChoice == 'Y' || saveChoice == 'y')
    {
        printf("Enter ASCII art file name: ");
        scanf("%s", asciiFileName);

        asciiFile = fopen(asciiFileName, "w");
        if(asciiFile == NULL)
        {
            printf("Unable to create ASCII art file! Please check the file name and try again.\n");
            exit(1);
        }

        for(i=0; i<imageHeight; i++)
        {
            fprintf(asciiFile, "%s", asciiArt[i]);
            if(i<imageHeight-1)
            {
                fprintf(asciiFile, "\n");
            }
        }

        fclose(asciiFile);
        printf("ASCII art saved successfully!\n");
    }

    return 0;
}