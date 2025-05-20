//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s <image_file> <watermark_text>\n", argv[0]);
        return 1;
    }

    char *image_file = argv[1];
    char *watermark_text = argv[2];

    FILE *input_file, *output_file;
    input_file = fopen(image_file, "rb");
    output_file = fopen("watermarked.jpg", "wb");

    if (input_file == NULL || output_file == NULL)
    {
        printf("Failed to open files.\n");
        return 1;
    }

    unsigned char input_data[1024];
    int input_data_size = fread(input_data, 1, sizeof(input_data), input_file);
    if (input_data_size!= sizeof(input_data))
    {
        printf("Failed to read input file.\n");
        return 1;
    }

    unsigned char *watermark_data = (unsigned char *)malloc(strlen(watermark_text) + 1);
    strcpy(watermark_data, watermark_text);

    unsigned char *watermarked_data = (unsigned char *)malloc(input_data_size + strlen(watermark_data));
    int watermarked_data_size = input_data_size;
    int watermark_index = 0;

    for (int i = 0; i < input_data_size; i++)
    {
        if (input_data[i] == 0xFF && i + 1 < input_data_size && input_data[i + 1] == 0xD8)
        {
            watermarked_data[watermark_index++] = input_data[i];
            watermarked_data[watermark_index++] = input_data[i + 1];
            watermarked_data[watermark_index++] = input_data[i + 2];
            watermarked_data[watermark_index++] = input_data[i + 3];
        }
        else if (input_data[i] == 0xD8 && i + 1 < input_data_size && input_data[i + 1] == 0xFF)
        {
            watermarked_data[watermark_index++] = input_data[i];
            watermarked_data[watermark_index++] = input_data[i + 1];
        }
        else
        {
            watermarked_data[watermark_index++] = input_data[i];
        }
    }

    strcat(watermarked_data, watermark_data);

    watermarked_data_size += strlen(watermark_data);

    if (watermarked_data_size!= input_data_size + strlen(watermark_data))
    {
        printf("Failed to watermark image.\n");
        return 1;
    }

    fwrite(watermarked_data, 1, watermarked_data_size, output_file);

    fclose(input_file);
    fclose(output_file);

    free(watermark_data);
    free(watermarked_data);

    return 0;
}