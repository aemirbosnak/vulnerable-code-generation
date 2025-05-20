//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *input_file_pointer, *output_file_pointer;
    char input_file_name[100], output_file_name[100], watermark[100], ch;
    int watermark_length, choice, i = 0;

    printf("Enter the name of input file\n");
    scanf("%s", input_file_name);

    input_file_pointer = fopen(input_file_name, "r");

    if(input_file_pointer == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    printf("Enter the name of output file\n");
    scanf("%s", output_file_name);

    output_file_pointer = fopen(output_file_name, "w");

    if(output_file_pointer == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    printf("Enter the watermark\n");
    scanf("%s", watermark);

    watermark_length = strlen(watermark);

    printf("\nMENU\n");
    printf("1. Embed watermark\n");
    printf("2. Extract watermark\n");
    printf("Enter your choice\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            fputc('0', output_file_pointer);
            fputc(watermark_length + '0', output_file_pointer);
            fputs(watermark, output_file_pointer);

            while((ch = fgetc(input_file_pointer)) != EOF)
            {
                fputc(ch, output_file_pointer);
            }

            printf("Watermark has been embedded in output file\n");
            break;

        case 2:
            ch = fgetc(input_file_pointer);

            if(ch != '0')
            {
                printf("Watermark not found in file\n");
                exit(0);
            }

            ch = fgetc(input_file_pointer);
            watermark_length = ch - '0';

            while(i < watermark_length)
            {
                ch = fgetc(input_file_pointer);
                watermark[i] = ch;
                i++;
            }

            watermark[i] = '\0';

            printf("The watermark is %s\n", watermark);

            while((ch = fgetc(input_file_pointer)) != EOF)
            {
                fputc(ch, output_file_pointer);
            }

            printf("Watermark has been extracted from input file and written to output file\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    fclose(input_file_pointer);
    fclose(output_file_pointer);

    return 0;
}