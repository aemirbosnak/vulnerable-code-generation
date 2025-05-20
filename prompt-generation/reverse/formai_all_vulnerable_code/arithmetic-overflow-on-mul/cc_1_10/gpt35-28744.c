//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genious
#include <stdio.h>
#include <stdlib.h>

//Function prototypes
void flip_image(char* image_path);
void change_brightness(char* image_path, int brightness_change);
void change_contrast(char* image_path, float contrast_factor);

int main()
{
    char img_path[100];
    int choice;
    int brightness_change;
    float contrast_factor;

    printf("Enter the path of the image: ");
    scanf("%s", img_path);

    printf("\n1. Flip Image\t2. Change Brightness\t3. Change Contrast\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: 
            flip_image(img_path);
            break;
        case 2:
            printf("Enter the change in brightness (-255 to 255): ");
            scanf("%d", &brightness_change);
            change_brightness(img_path, brightness_change);
            break;
        case 3:
            printf("Enter the contrast factor (between 0.1 to 10): ");
            scanf("%f", &contrast_factor);
            change_contrast(img_path, contrast_factor);
            break;
        default:
            printf("Invalid Choice!\n");
            exit(0);
    }

    return 0;
}

//Function to flip the image
void flip_image(char* image_path)
{
    FILE* fp_in = fopen(image_path, "rb");
    FILE* fp_out = fopen("flipped_image.bmp", "wb");

    if(fp_in == NULL || fp_out == NULL)
    {
        printf("Error: Unable to open file!");
        exit(0);
    }

    //Reading image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp_in);

    //Extracting image height and width from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    //Allocating memory for image data
    unsigned char* img_data = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);

    //Reading image data
    fread(img_data, sizeof(unsigned char), width * height * 3, fp_in);

    //Flipping image
    for(int i = 0; i < height/2; i++)
    {
        for(int j = 0; j < width * 3; j++)
        {
            unsigned char temp = img_data[i * width * 3 + j];
            img_data[i * width * 3 + j] = img_data[(height - 1 - i) * width * 3 + j];
            img_data[(height - 1 - i) * width * 3 + j] = temp;
        }
    }

    //Writing flipped image to file
    fwrite(header, sizeof(unsigned char), 54, fp_out);
    fwrite(img_data, sizeof(unsigned char), width * height * 3, fp_out);

    //Closing files and freeing memory
    free(img_data);
    fclose(fp_in);
    fclose(fp_out);

    printf("Image flipped successfully and saved as flipped_image.bmp.\n");
}

//Function to change the brightness of image
void change_brightness(char* image_path, int brightness_change)
{
    FILE* fp_in = fopen(image_path, "rb");
    FILE* fp_out = fopen("brightness_changed_image.bmp", "wb");

    if(fp_in == NULL || fp_out == NULL)
    {
        printf("Error: Unable to open file!");
        exit(0);
    }

    //Reading image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp_in);

    //Extracting image height and width from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    //Allocating memory for image data
    unsigned char* img_data = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);

    //Reading image data
    fread(img_data, sizeof(unsigned char), width * height * 3, fp_in);

    //Changing brightness of image
    for(int i = 0; i < height * width * 3; i++)
    {
        int pixel_value = img_data[i] + brightness_change;
        if(pixel_value < 0)
            img_data[i] = 0;
        else if(pixel_value > 255)
            img_data[i] = 255;
        else
            img_data[i] = pixel_value;
    }

    //Writing brightness changed image to file
    fwrite(header, sizeof(unsigned char), 54, fp_out);
    fwrite(img_data, sizeof(unsigned char), width * height * 3, fp_out);

    //Closing files and freeing memory
    free(img_data);
    fclose(fp_in);
    fclose(fp_out);

    printf("Image brightness changed successfully and saved as brightness_changed_image.bmp.\n");
}

//Function to change the contrast of image
void change_contrast(char* image_path, float contrast_factor)
{
    FILE* fp_in = fopen(image_path, "rb");
    FILE* fp_out = fopen("contrast_changed_image.bmp", "wb");

    if(fp_in == NULL || fp_out == NULL)
    {
        printf("Error: Unable to open file!");
        exit(0);
    }

    //Reading image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp_in);

    //Extracting image height and width from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    //Allocating memory for image data
    unsigned char* img_data = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);

    //Reading image data
    fread(img_data, sizeof(unsigned char), width * height * 3, fp_in);

    //Changing contrast of image
    for(int i = 0; i < height * width * 3; i++)
    {
        int pixel_value = contrast_factor * (img_data[i] - 128) + 128;
        if(pixel_value < 0)
            img_data[i] = 0;
        else if(pixel_value > 255)
            img_data[i] = 255;
        else
            img_data[i] = pixel_value;
    }

    //Writing contrast changed image to file
    fwrite(header, sizeof(unsigned char), 54, fp_out);
    fwrite(img_data, sizeof(unsigned char), width * height * 3, fp_out);

    //Closing files and freeing memory
    free(img_data);
    fclose(fp_in);
    fclose(fp_out);

    printf("Image contrast changed successfully and saved as contrast_changed_image.bmp.\n");
}