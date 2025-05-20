//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    FILE *fp_input, *fp_output;
    char input_file[MAX_SIZE], output_file[MAX_SIZE], watermark[MAX_SIZE], ch;
    int watermark_length = 0;

    printf("Enter the input filename: ");
    scanf("%s", input_file);

    printf("Enter the output filename: ");
    scanf("%s", output_file);

    printf("Enter the watermark: ");
    scanf("%s", watermark);

    watermark_length = strlen(watermark);

    fp_input = fopen(input_file, "r");
    fp_output = fopen(output_file, "w");

    if(fp_input == NULL) {
        printf("Unable to open input file \"%s\"\n", input_file);
        exit(EXIT_FAILURE);
    }

    if(fp_output == NULL) {
        printf("Unable to create output file \"%s\"\n", output_file);
        exit(EXIT_FAILURE);
    }

    // Write the watermark to the output file
    fwrite(watermark, sizeof(char), watermark_length, fp_output);

    while((ch = fgetc(fp_input)) != EOF)
    {
        // Write each character to the output file
        fputc(ch, fp_output);
    }

    printf("Watermark added successfully!\n");

    fclose(fp_input);
    fclose(fp_output);

    return 0;
}