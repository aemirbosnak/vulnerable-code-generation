//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    FILE *infile, *outfile;
    int i, j;
    int watermark_length = 0;
    int watermark_index = 0;
    int watermark_byte;
    BYTE watermark[100];
    BYTE file_data[10000];
    char filename[20];

    // Check command line arguments
    if (argc!= 2)
    {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    // Read input file
    sprintf(filename, "%s", argv[1]);
    infile = fopen(filename, "rb");
    if (infile == NULL)
    {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Read watermark
    watermark_length = 0;
    while (1)
    {
        watermark_byte = getc(stdin);
        if (watermark_byte == EOF)
            break;
        watermark[watermark_length++] = watermark_byte;
    }
    watermark_byte = 0;
    watermark_length = 0;

    // Read input file data
    for (i = 0; i < 10000; i++)
    {
        file_data[i] = getc(infile);
    }

    // Insert watermark
    for (i = 0; i < watermark_length; i++)
    {
        file_data[watermark_index++] = watermark[i];
    }

    // Write output file
    sprintf(filename, "%s.wm", argv[1]);
    outfile = fopen(filename, "wb");
    if (outfile == NULL)
    {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    for (i = 0; i < 10000; i++)
    {
        fputc(file_data[i], outfile);
    }
    fclose(outfile);

    // Print watermark
    printf("Watermark: ");
    for (i = 0; i < watermark_length; i++)
    {
        printf("%02X ", watermark[i]);
    }
    printf("\n");

    return 0;
}