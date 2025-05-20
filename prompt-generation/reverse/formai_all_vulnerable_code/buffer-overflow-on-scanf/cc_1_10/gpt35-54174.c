//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Welcome to Digital Watermarking Program!\n");
    printf("Please enter the name of your file with extension: ");
    char file_name[50];
    scanf("%s", file_name);

    FILE *input_file = fopen(file_name, "rb"); //Opening the input file in read binary mode
    if(input_file == NULL)
    {
        printf("Error in opening the file! Please check if the file exists.\n");
        exit(0);
    }

    fseek(input_file, 0, SEEK_END); //Moving the file pointer to the end
    int file_size = ftell(input_file); //Calculating the size of the file
    fseek(input_file, 0, SEEK_SET); //Moving the file pointer to the beginning

    char watermark[50];
    printf("\nEnter the text to be watermarked: ");
    scanf("%s", watermark);

    char *input_data = (char*)malloc(sizeof(char)*file_size); //Allocating memory dynamically to store data from input file
    fread(input_data, sizeof(char), file_size, input_file); //Reading data from input file

    int watermark_len = strlen(watermark);
    int i = 0, j = 0, flag = 0;

    for(i = 0; i < file_size; i++)
    {
        if(input_data[i] == watermark[j])
        {
            j++;
            if(j == watermark_len)
            {
                flag = 1;
                break;
            }
        }
        else
        {
            j = 0;
        }
    }

    if(flag)
    {
        printf("\nWatermark already exists in the file.\n");
        exit(0);
    }

    char *output_data = (char*)malloc(sizeof(char)*file_size); //Allocating memory dynamically to store data in output file
    memcpy(output_data, input_data, file_size);

    int watermark_pos = rand()%(file_size-watermark_len); //Generating a random position to embed the watermark
    for(i = watermark_pos, j = 0; j < watermark_len; i++, j++)
    {
        output_data[i] = watermark[j];
    }

    FILE *output_file = fopen("watermarked_file.txt", "wb"); //Opening the output file in write binary mode
    if(output_file == NULL)
    {
        printf("Error in creating the watermarked file!");
        exit(0);
    }

    fwrite(output_data, sizeof(char), file_size, output_file); //Writing data to output file
    printf("\nWatermark successfully embedded in the file!\n");

    fclose(input_file);
    fclose(output_file);
    free(input_data);
    free(output_data);

    return 0;
}