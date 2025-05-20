//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WATERMARK_LENGTH 256
#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// Function prototypes
void add_watermark(char* input_file, char* output_file, char* watermark);
void extract_watermark(char* input_file, char* watermark, int watermark_length);

// Main function
int main()
{
    char input_file[MAX_FILENAME_LENGTH];
    char output_file[MAX_FILENAME_LENGTH];
    char watermark[MAX_WATERMARK_LENGTH];
    int choice, watermark_length;

    printf("Enter the input file name:\n");
    scanf("%s", input_file);
    
    printf("Enter the output file name:\n");
    scanf("%s", output_file);

    printf("Enter the watermark:\n");
    scanf("%s", watermark);
    watermark_length = strlen(watermark);

    printf("Choose an operation:\n");
    printf("1. Add watermark\n");
    printf("2. Extract watermark\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            add_watermark(input_file, output_file, watermark);
            break;

        case 2:
            extract_watermark(input_file, watermark, watermark_length);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

// Function to add a digital watermark to a file
void add_watermark(char* input_file, char* output_file, char* watermark)
{
    FILE* input_fp = fopen(input_file, "r");
    FILE* output_fp = fopen(output_file, "w");

    if (input_fp == NULL)
    {
        perror("Error: ");
        return;
    }

    if (output_fp == NULL)
    {
        perror("Error: ");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    int watermark_pos = 0;
    int watermark_length = strlen(watermark);

    while (fgets(buffer, MAX_LINE_LENGTH, input_fp) != NULL)
    {
        if (watermark_pos < watermark_length)
        {
            int len = strlen(buffer);

            if (len > 0)
            {
                buffer[len-1] = watermark[watermark_pos];
                watermark_pos++;
            }
        }

        fprintf(output_fp, "%s", buffer);
    }

    fclose(input_fp);
    fclose(output_fp);

    printf("Watermark added to file successfully\n");
}

// Function to extract a digital watermark from a file
void extract_watermark(char* input_file, char* watermark, int watermark_length)
{
    FILE* input_fp = fopen(input_file, "r");

    if (input_fp == NULL)
    {
        perror("Error: ");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    int watermark_pos = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, input_fp) != NULL)
    {
        int len = strlen(buffer);

        if (len > 0)
        {
            char last_char = buffer[len-1];
            if (watermark_pos < watermark_length && last_char == watermark[watermark_pos])
            {
                watermark_pos++;
            }
        }
    }

    fclose(input_fp);

    if (watermark_pos == watermark_length)
    {
        printf("Watermark extracted successfully\n");
    }
    else
    {
        printf("Watermark not found in file\n");
    }
}