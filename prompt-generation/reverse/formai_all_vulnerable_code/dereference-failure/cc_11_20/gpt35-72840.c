//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_MSG_SIZE 100
#define MAX_IMAGE_SIZE 10000

int main()
{
    char message[MAX_MSG_SIZE], input_image[MAX_IMAGE_SIZE], output_image[MAX_IMAGE_SIZE];
    int i, j, k, msg_length, image_length, watermark_length, alpha, beta;
    FILE *fptr1, *fptr2, *fptr3;

    printf("Enter the message to be embedded: ");
    scanf("%[^\n]", message);

    printf("Enter the name of the input image file (with extension): ");
    scanf(" %s", input_image);

    printf("Enter the name of the output image file (with extension): ");
    scanf(" %s", output_image);

    msg_length = strlen(message);

    fptr1 = fopen(input_image, "rb");    //read input image file
    if(fptr1 == NULL)
    {
        printf("Error: Unable to open input image file!");
        return 0;
    }

    fptr2 = fopen(output_image, "wb");   //write output image file
    if(fptr2 == NULL)
    {
        printf("Error: Unable to open output image file!");
        return 0;
    }

    fseek(fptr1, 0, SEEK_END);           //get image file size
    image_length = ftell(fptr1);
    rewind(fptr1);

    char *image_data = (char*) malloc(image_length * sizeof(char));    //allocate memory for image data
    fread(image_data, 1, image_length, fptr1);                          //read image data
    fclose(fptr1);

    watermark_length = msg_length * 8;

    if(watermark_length > (image_length-54)/3)   //check if message can fit in image
    {
        printf("Error: The message cannot be embedded in the image. Try a smaller message or a larger image.");
        free(image_data);
        return 0;
    }

    int *watermark = (int*) malloc(watermark_length * sizeof(int));    //allocate memory for watermark data

    for(i=0, k=0; i<msg_length; i++)    //convert message to binary and store in watermark
    {
        int binary[8], num = message[i];
        for(j=7; j>=0; j--)
        {
            binary[j] = num % 2;
            num /= 2;
        }
        for(j=0; j<8; j++)
        {
            watermark[k] = binary[j];
            k++;
        }
    }

    alpha = image_data[18];         //get alpha value (transparency)

    for(i=54, k=0; k<watermark_length; i+=3, k++)  //embed watermark in image data
    {
        beta = image_data[i] & 0xFE;   //clear LSB
        beta = beta | watermark[k];    //set LSB
        image_data[i] = beta;
        image_data[i+1] = beta;        //apply same values to G and B channels
        image_data[i+2] = alpha;
    }

    fwrite(image_data, 1, image_length, fptr2);   //write processed image data to output image file
    fclose(fptr2);

    fptr3 = fopen(output_image, "rb");    //read output image file to verify watermark
    if(fptr3 == NULL)
    {
        printf("Error: Unable to open output image file!");
        free(image_data);
        free(watermark);
        return 0;
    }

    fseek(fptr3, 0, SEEK_END);
    image_length = ftell(fptr3);
    rewind(fptr3);

    char *output_data = (char*) malloc(image_length * sizeof(char));
    fread(output_data, 1, image_length, fptr3);   //read output image data
    fclose(fptr3);

    int *output_watermark = (int*) malloc(watermark_length * sizeof(int));  //allocate memory for extracted watermark data

    for(i=54, k=0; k<watermark_length; i+=3, k++)   //extract watermark from output image data
    {
        output_watermark[k] = output_data[i] & 0x01;
    }

    char *output_message = (char*) malloc(msg_length * sizeof(char));   //allocate memory for extracted message string

    for(i=0, k=0; i<msg_length; i++)    //convert binary watermark to characters
    {
        int binary[8], num=0;
        for(j=0; j<8; j++)
        {
            binary[j] = output_watermark[k];
            k++;
        }
        for(j=7; j>=0; j--)
        {
            num += binary[j] * pow(2, 7-j);
        }
        output_message[i] = (char) num;
    }

    printf("The message has been embedded and extracted successfully!\nEmbedded message: %s\nExtracted message: %s", message, output_message);

    free(image_data);
    free(watermark);
    free(output_data);
    free(output_watermark);
    free(output_message);

    return 0;
}