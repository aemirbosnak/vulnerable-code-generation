//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_SIZE 100

/* Function to convert string to binary */
void strToBinary(char str[], char binary[])
{
    int len = strlen(str);
    int i, j, k;

    for(i=0, k=0; i<len; i++)
    {
        for(j=7; j>=0; j--, k++ )
            binary[k] = ((str[i] & (1<<j)) ? '1' : '0');
    }
    binary[k] = '\0';
}

/* Function to convert binary to string */
void binaryToStr(char binary[], char str[])
{
    int len = strlen(binary);
    int i, j, k;

    for(i=0, k=0; i<len; i+=8, k++)
    {
        int sum = 0;
        for(j=7; j>=0; j--)
            if(binary[i+j]=='1')
                sum += 1<<abs(j-7);
        str[k] = (char)(sum);
    }
    str[k] = '\0';
}

/* Main function */
int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Usage: %s input_file output_file watermark_string\n", argv[0] );
        return 1;
    }

    char *in_file = argv[1];
    char *out_file = argv[2];
    char *watermark_str = argv[3];

    /* Convert watermark string to binary */
    char watermark_bin[MAX_WATERMARK_SIZE*8+1];
    strToBinary(watermark_str, watermark_bin);

    /* Open input file */
    FILE *fin = fopen(in_file, "rb");
    if(fin == NULL)
    {
        printf("Failed to open input file.\n");
        return 2;
    }

    /* Determine length of input file */
    fseek(fin, 0L, SEEK_END);
    int file_size = ftell(fin);
    fseek(fin, 0L, SEEK_SET);

    /* Allocate memory for input data */
    unsigned char *data = (unsigned char*)malloc(file_size * sizeof(unsigned char));
    if(data == NULL)
    {
        printf("Failed to allocate memory for input data.\n");
        return 3;
    }

    /* Read input data into memory */
    fread(data, sizeof(unsigned char), file_size, fin);
    fclose(fin);

    /* Prompt user for bit position to embed watermark */
    int bit_pos;
    printf("Enter bit position to embed watermark (0-7): ");
    scanf("%d", &bit_pos);

    if(bit_pos < 0 || bit_pos > 7)
    {
        printf("Invalid bit position.\n");
        return 4;
    }

    /* Embed watermark */
    int i, j;
    for(i=0; i<MAX_WATERMARK_SIZE*8 && i<file_size*8; i++)
    {
        int byte_idx = i/8;             /* byte index in data array */
        int bit_idx = i%8;              /* bit index in byte */
        int bit = watermark_bin[i]-'0'; /* bit to embed */

        /* Apply bit manipulation */
        if(bit)
            data[byte_idx] |= (1<<bit_pos);
        else
            data[byte_idx] &= ~(1<<bit_pos);
    }

    /* Write modified data to output file */
    FILE *fout = fopen(out_file, "wb");
    if(fout == NULL)
    {
        printf("Failed to open output file.\n");
        return 5;
    }

    fwrite(data, sizeof(unsigned char), file_size, fout);
    fclose(fout);

    /* Free memory */
    free(data);

    printf("Watermark embedded successfully.\n");
    return 0;
}