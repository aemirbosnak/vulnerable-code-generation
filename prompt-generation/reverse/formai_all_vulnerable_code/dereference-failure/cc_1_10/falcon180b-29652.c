//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1024*1024
#define WATERMARK_SIZE 64

int main(int argc, char* argv[])
{
    if(argc!= 3)
    {
        printf("Usage: watermark input_file output_file\n");
        exit(1);
    }

    FILE* input_file = fopen(argv[1], "rb");
    if(input_file == NULL)
    {
        printf("Error: Failed to open input file.\n");
        exit(1);
    }

    FILE* output_file = fopen(argv[2], "wb");
    if(output_file == NULL)
    {
        printf("Error: Failed to open output file.\n");
        fclose(input_file);
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);

    unsigned char* input_buffer = (unsigned char*)malloc(file_size);
    fread(input_buffer, file_size, 1, input_file);
    fclose(input_file);

    unsigned char* watermark_buffer = (unsigned char*)malloc(WATERMARK_SIZE);
    srand(time(NULL));
    for(int i=0; i<WATERMARK_SIZE; i++)
        watermark_buffer[i] = rand() % 256;

    int watermark_position = rand() % file_size;

    for(int i=0; i<WATERMARK_SIZE; i++)
        input_buffer[watermark_position+i] ^= watermark_buffer[i];

    output_file = fopen(argv[2], "wb");
    fwrite(input_buffer, file_size, 1, output_file);
    fclose(output_file);

    free(input_buffer);
    free(watermark_buffer);

    return 0;
}