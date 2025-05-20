//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define W 512
#define H 512

#define BLOCK_SIZE 8
#define PIXEL_VALUE_RANGE 256

unsigned char image[W*H];

void add_watermark(unsigned char* watermark, int watermark_size)
{
    int i, j, k;
    for(i=0; i<H; i+=BLOCK_SIZE)
    {
        for(j=0; j<W; j+=BLOCK_SIZE)
        {
            for(k=0; k<BLOCK_SIZE; k++)
            {
                image[(i+k)*W+(j+k)] = watermark[k] + image[(i+k)*W+(j+k)];
            }
        }
    }
}

void read_image(FILE* fp)
{
    int i;
    for(i=0; i<H*W; i++)
    {
        fscanf(fp, "%c", &image[i]);
    }
}

void write_image(FILE* fp)
{
    int i;
    for(i=0; i<H*W; i++)
    {
        fprintf(fp, "%c", image[i]);
    }
}

int main()
{
    FILE* fp;
    unsigned char watermark[100];
    int watermark_size;

    fp = fopen("image.bmp", "r+b");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    read_image(fp);

    printf("Enter watermark message: ");
    scanf("%s", watermark);

    watermark_size = strlen(watermark);
    if(watermark_size > 100)
    {
        printf("Watermark message too long\n");
        exit(1);
    }

    add_watermark(watermark, watermark_size);

    write_image(fp);

    fclose(fp);

    printf("Watermark added successfully\n");

    return 0;
}