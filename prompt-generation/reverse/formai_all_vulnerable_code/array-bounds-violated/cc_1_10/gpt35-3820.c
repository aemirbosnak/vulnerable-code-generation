//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

unsigned char watermark[8] = {'W','A','T','E','R','M','R','K'};
int wLength = 8;
unsigned char fileBuffer[10485760]; //10MB buffer for file read-write operations

int main(int argc, char **argv)
{
    //Check command line arguments
    if(argc < 3)
    {
        printf("Usage: %s <Input File> <Output File>", argv[0]);
        exit(1);
    }

    FILE* inFile = fopen(argv[1], "rb");
    FILE* outFile = fopen(argv[2], "wb");

    if(inFile == NULL || outFile == NULL)
    {
        printf("Could not open input/output file!");
        exit(1);
    }

    //Read file into buffer
    long fileSize;
    fseek(inFile, 0, SEEK_END);
    fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);
    fread(fileBuffer, 1, fileSize, inFile);

    //Generate watermark
    srand(time(NULL));
    int wIndex = rand() % fileSize;
    for(int i=0; i<wLength; i++)
        fileBuffer[wIndex+i] = watermark[i];

    //Write watermarked file to output
    fwrite(fileBuffer, 1, fileSize, outFile);

    printf("Watermarking complete!");
    fclose(inFile);
    fclose(outFile);

    return 0;
}