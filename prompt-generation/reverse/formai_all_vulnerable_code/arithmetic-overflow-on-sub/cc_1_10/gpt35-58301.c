//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include<stdio.h> 

int main()
{
    char input_file[] = "original_image.bmp"; //name of the input file which has to be watermarked
    FILE *fp1 = fopen(input_file, "rb"); //opening the input file in binary mode to read
    if(fp1 == NULL)
    {
        printf("Error: Cannot open file %s\n", input_file);
        return -1;
    }

    char output_file[] = "watermarked_image.bmp"; //name of the output file which will have the watermarked image
    FILE *fp2 = fopen(output_file, "wb"); //opening the output file in binary mode to write
    if(fp2 == NULL)
    {
        printf("Error: Cannot create file %s\n", output_file); 
        fclose(fp1);
        return -1;
    }

    int width, height;
    fseek(fp1, 18, SEEK_SET); //move 18 bytes to reach the width of the image
    fread(&width, sizeof(int), 1, fp1); //read the width of the image
    fread(&height, sizeof(int), 1, fp1); //read the height of the image

    int size = width*height*3; //size of the image in bytes
    char *buffer = (char*)malloc(size); //create a buffer to store the image
    if(buffer == NULL)
    {
        printf("Error: Memory allocation failed\n");
        fclose(fp1);
        fclose(fp2);
        return -1;
    }

    fseek(fp1, 54, SEEK_SET); //move 54 bytes to reach the pixel data of the image
    fread(buffer, sizeof(char), size, fp1); //read the pixel data of the image

    char watermark[] = "Digital Watermarking Example"; //the watermark to be embedded
    int watermark_size = sizeof(watermark); //size of the watermark in bytes
    int watermark_position = size - watermark_size; //position where watermark will start
    for(int i = 0; i < watermark_size; i++)
        buffer[watermark_position + i] = (char)(watermark[i] + 1); //embed the watermark

    fwrite(buffer, sizeof(char), size, fp2); //write the watermarked image to the output file

    free(buffer);
    fclose(fp1);
    fclose(fp2);

    printf("Watermarking done successfully!\n");

    return 0;
}