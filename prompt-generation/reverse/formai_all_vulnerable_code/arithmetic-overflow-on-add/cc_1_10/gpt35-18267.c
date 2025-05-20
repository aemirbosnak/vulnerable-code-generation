//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: careful
#include <stdio.h>
#include <string.h>

// function to embed digital watermark in image
void digitalWatermark(char* imagePath, char* watermarkText)
{
    FILE *fptr = fopen(imagePath, "r+");
    if(fptr == NULL)
    {
        printf("Error! Unable to open file.\n");
        return;
    }

    // seek to end of file
    fseek(fptr, 0, SEEK_END);

    // calculate file size in bytes
    int fileSize = ftell(fptr);

    // move file pointer to the beginning of file
    rewind(fptr);

    // read image data into buffer
    unsigned char imageData[fileSize];
    fread(imageData, sizeof(unsigned char), fileSize, fptr);

    // seek to the end of file, before any metadata starts
    fseek(fptr, -4, SEEK_END);

    // write watermark length to metadata
    int watermarkLength = strlen(watermarkText);
    fwrite(&watermarkLength, sizeof(int), 1, fptr);

    // move file pointer forward to write watermark text
    fseek(fptr, 0, SEEK_END);

    // convert watermark text to binary format and write to file
    for(int i = 0; i < watermarkLength; i++)
        fwrite(&watermarkText[i], sizeof(char), 1, fptr);

    // close file pointer
    fclose(fptr);

    printf("Digital watermark embedded successfully!\n");
}

// function to extract digital watermark from image
void extractWatermark(char* imagePath)
{
    FILE *fptr = fopen(imagePath, "r");
    if(fptr == NULL)
    {
        printf("Error! Unable to open file.\n");
        return;
    }

    // seek to the end of file
    fseek(fptr, 0, SEEK_END);

    // calculate file size in bytes
    int fileSize = ftell(fptr);

    // move file pointer to the beginning of metadata
    fseek(fptr, -4, SEEK_END);

    // read length of watermark
    int watermarkLength;
    fread(&watermarkLength, sizeof(int), 1, fptr);

    // move file pointer to the beginning of watermark
    fseek(fptr, -(4+watermarkLength), SEEK_END);

    // read watermark text from file
    char watermarkText[watermarkLength];
    fread(&watermarkText, sizeof(char), watermarkLength, fptr);

    printf("Extracted watermark: %s\n", watermarkText);

    // close file pointer
    fclose(fptr);
}

int main()
{
    char imagePath[] = "image.png";
    char watermarkText[] = "Secret Message";

    // embed digital watermark in image
    digitalWatermark(imagePath, watermarkText);

    // extract digital watermark from image
    extractWatermark(imagePath);

    return 0;
}