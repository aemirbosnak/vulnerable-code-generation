//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

int main(int argc, char* argv[])
{
    FILE* fp;
    char filename[20];
    int width, height, i, j, k, count = 0;
    char ch;
    unsigned char *image;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("Error: File not found.\n");
        exit(0);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    image = (unsigned char*)malloc(width*height*sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width*height, fp);

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            if(image[i*width+j] == 0)
                printf("  ");
            else if(image[i*width+j] == 1)
                printf(". ");
            else if(image[i*width+j] == 2)
                printf(" o ");
            else if(image[i*width+j] == 3)
                printf(" O ");
        }
        printf("\n");
    }

    free(image);
    fclose(fp);

    return 0;
}