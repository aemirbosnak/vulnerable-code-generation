//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_NAME_SIZE 1000
#define MAX_WATERMARK_SIZE 1000

//Function to get the size of a file
int getFileSize(FILE *f)
{
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f, 0, SEEK_SET);
    return size;
}

//Function to read the file data into a buffer
void readFileData(FILE *f, char *buffer)
{
    int i = 0;
    char ch;
    while((ch = fgetc(f)) != EOF)
    {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
}

//Function to write the file data from a buffer
void writeFileData(char *buffer, int size, char *fileName)
{
    FILE *f = fopen(fileName, "w");
    int i;
    for(i=0; i<size; i++)
    {
        fputc(buffer[i], f);
    }
    fclose(f);
}

//Function to add a watermark to a file
void addWatermarkToFile(char *fileName, char *watermark)
{
    FILE *f = fopen(fileName, "r");

    int fileSize = getFileSize(f);
    char *fileBuffer = (char*)malloc(fileSize+1);  

    readFileData(f, fileBuffer);
    fclose(f);

    strcat(fileBuffer, watermark);
    int newSize = strlen(fileBuffer);

    writeFileData(fileBuffer, newSize, fileName);

    free(fileBuffer);
}

//Function to check if a watermark exists in a file
int doesWatermarkExist(char *fileName, char *watermark)
{
    FILE *f = fopen(fileName, "r");

    int fileSize = getFileSize(f);
    char *fileBuffer = (char*)malloc(fileSize+1);  

    readFileData(f, fileBuffer);
    fclose(f);

    if(strstr(fileBuffer, watermark) != NULL)
    {
        printf("Watermark exists in the file!\n");
        return 1;
    }
    else
    {
        printf("Watermark does not exist in the file!\n");
        return 0;
    }

    free(fileBuffer);
}

int main()
{
    char fileName[MAX_FILE_NAME_SIZE];
    char watermark[MAX_WATERMARK_SIZE];

    printf("Enter file name: ");
    fgets(fileName, MAX_FILE_NAME_SIZE, stdin);

    printf("Enter watermark: ");
    fgets(watermark, MAX_WATERMARK_SIZE, stdin);

    //Removing the newline character from the end of the strings
    fileName[strcspn(fileName, "\n")] = '\0';
    watermark[strcspn(watermark, "\n")] = '\0';

    addWatermarkToFile(fileName, watermark);

    printf("Watermark added to file!\n");

    doesWatermarkExist(fileName, watermark);

    return 0;
}