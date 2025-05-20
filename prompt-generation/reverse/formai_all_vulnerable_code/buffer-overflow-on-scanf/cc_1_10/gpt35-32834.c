//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>

#define WATERMARK "This is a digital watermark"

// Function to embed the watermark into the given image
void embedWatermark(char *imageFileName)
{
    FILE *imageFile = fopen(imageFileName, "rb");

    if (imageFile == NULL)
    {
        printf("Error: Unable to open image file\n");
        return;
    }

    // Analyzing image data and embedding watermark in it

    FILE *markedFile = fopen("markedImage.jpg", "wb");

    if (markedFile == NULL)
    {
        printf("Error: Unable to create marked (watermarked) image file\n");
        fclose(imageFile);
        return;
    }

    // Writing the watermark to the marked image file

    fwrite(WATERMARK, sizeof(WATERMARK), 1, markedFile);

    char ch;

    // Copying the remaining image data from original file to marked image file

    while ((ch = fgetc(imageFile)) != EOF)
    {
        fputc(ch, markedFile);
    }

    fclose(imageFile);
    fclose(markedFile);

    printf("Watermark has been successfully embedded in the given image.\n");
}

// Function to detect the watermark from the given image
void detectWatermark(char *imageFileName)
{
    FILE *imageFile = fopen(imageFileName, "rb");

    if (imageFile == NULL)
    {
        printf("Error: Unable to open image file\n");
        return;
    }

    // Analyzing image data and detecting watermark in it

    int watermarkLength = sizeof(WATERMARK) - 1; // Excluding the null character

    char imageBuffer[watermarkLength];

    fread(imageBuffer, watermarkLength, 1, imageFile);

    if (strcmp(imageBuffer, WATERMARK) == 0)
    {
        printf("\nThe given image has a digital watermark.\n");
    }
    else
    {
        printf("\nThe given image does not have a digital watermark.\n");
    }

    fclose(imageFile);
}

int main()
{
    char imageFileName[100];

    printf("Enter the name of the image file: ");
    scanf("%s", imageFileName);

    printf("\nEmbedding watermark in the given image...\n");
    embedWatermark(imageFileName);

    printf("\nDetecting watermark from the given image...\n");
    detectWatermark(imageFileName);

    return 0;
}