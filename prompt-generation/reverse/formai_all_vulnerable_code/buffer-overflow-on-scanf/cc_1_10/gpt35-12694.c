//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    FILE *file_in, *file_out;
    unsigned char data[MAX_SIZE];
    int i, j, bit_count, watermark_len;
    char watermark[MAX_SIZE];

    // read input file
    file_in = fopen("input.bmp", "rb");
    if (!file_in)
    {
        printf("Error opening input file!\n");
        return 1;
    }

    // read watermark
    printf("Enter watermark (max %d characters): ", MAX_SIZE - 1);
    scanf("%s", watermark);
    watermark_len = strlen(watermark);

    // generate bit sequence from watermark
    unsigned char bits[watermark_len * 8];
    for (i = 0; i < watermark_len; i++)
    {
        unsigned char c = watermark[i];
        for (j = 0; j < 8; j++)
        {
            bits[i * 8 + j] = (c >> j) & 1;
        }
    }
    bit_count = watermark_len * 8;

    // modify input file with watermark
    file_out = fopen("output.bmp", "wb");
    if (!file_out)
    {
        printf("Error opening output file!\n");
        return 1;
    }
    for (i = 0; i < 54; i++)
    {
        // copy header
        fread(&data[i], sizeof(unsigned char), 1, file_in);
        fwrite(&data[i], sizeof(unsigned char), 1, file_out);
    }
    for (i = 54; i < MAX_SIZE; i++)
    {
        // modify pixel values
        fread(&data[i], sizeof(unsigned char), 1, file_in);
        if (i - 54 < bit_count)
        {
            data[i] = (data[i] >> 1 << 1) | bits[i - 54];
        }
        fwrite(&data[i], sizeof(unsigned char), 1, file_out);
    }

    fclose(file_in);
    fclose(file_out);

    printf("Watermarking done!\n");

    return 0;
}