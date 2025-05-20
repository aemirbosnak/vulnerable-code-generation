//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    FILE *fp_in, *fp_out;
    char input_file[100], output_file[100];
    int choice, width, height, maxval, i, j, k;
    int **image, **output_image;
    unsigned char byte;
    float factor, brightness_factor, contrast_factor;
    
    printf("Enter the input image file name: ");
    scanf("%s", input_file);
    
    fp_in = fopen(input_file, "rb");
    
    if(fp_in == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    
    //Get the image width, height and maxval
    fscanf(fp_in, "P5 %d %d %d ", &width, &height, &maxval);
    
    //Allocate memory for the image and output image
    image = (int**) malloc(height * sizeof(int*));
    output_image = (int**) malloc(height * sizeof(int*));
    
    for(i = 0; i < height; i++)
    {
        image[i] = (int*) malloc(width * sizeof(int));
        output_image[i] = (int*) malloc(width * sizeof(int));
    }
    
    //Read the pixel values into the image array
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            fread(&byte, 1, 1, fp_in);
            image[i][j] = byte;
        }
    }
    
    fclose(fp_in);
    
    printf("\n\nWhat operation would you like to perform?\n");
    printf("1 - Flip image horizontally\n");
    printf("2 - Flip image vertically\n");
    printf("3 - Increase/Decrease brightness\n");
    printf("4 - Increase/Decrease contrast\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        //Flip image horizontally
        case 1:
            for(i = 0; i < height; i++)
            {
                for(j = 0, k = width-1; j < width; j++, k--)
                {
                    output_image[i][j] = image[i][k];
                }
            }
            strcpy(output_file, "flipped_horizontally.pgm");
            break;
        
        //Flip image vertically
        case 2:
            for(i = 0, k = height-1; i < height; i++, k--)
            {
                for(j = 0; j < width; j++)
                {
                    output_image[i][j] = image[k][j];
                }
            }
            strcpy(output_file, "flipped_vertically.pgm");
            break;
        
        //Increase/Decrease brightness
        case 3:
            printf("\nEnter a brightness factor (0.0 to 2.0): ");
            scanf("%f", &brightness_factor);
            
            for(i = 0; i < height; i++)
            {
                for(j = 0; j < width; j++)
                {
                    output_image[i][j] = image[i][j] * brightness_factor;
                    
                    if(output_image[i][j] > 255)
                    {
                        output_image[i][j] = 255;
                    }
                }
            }
            
            strcpy(output_file, "brightened.pgm");
            break;
        
        //Increase/Decrease contrast
        case 4:
            printf("\nEnter a contrast factor (1.0 to 3.0): ");
            scanf("%f", &contrast_factor);
            
            factor = 1.0 / (float)(width * height);
            
            //Calculate the mean pixel value
            float mean = 0.0;
            for(i = 0; i < height; i++)
            {
                for(j = 0; j < width; j++)
                {
                    mean += (float)image[i][j] * factor;
                }
            }
            
            //Calculate the standard deviation
            float std_dev = 0.0;
            for(i = 0; i < height; i++)
            {
                for(j = 0; j < width; j++)
                {
                    std_dev += pow((float)image[i][j] - mean, 2) * factor;
                }
            }
            std_dev = sqrt(std_dev);
            
            //Calculate the new pixel values
            for(i = 0; i < height; i++)
            {
                for(j = 0; j < width; j++)
                {
                    output_image[i][j] = (int)(contrast_factor * ((float)image[i][j] - mean) / std_dev + mean);
                    
                    if(output_image[i][j] < 0)
                    {
                        output_image[i][j] = 0;
                    }
                    else if(output_image[i][j] > 255)
                    {
                        output_image[i][j] = 255;
                    }
                }
            }
            strcpy(output_file, "contrasted.pgm");
            break;
        
        default:
            printf("\nInvalid choice\n");
            exit(1);
    }
    
    //Write the output image to file
    fp_out = fopen(output_file, "wb");
    fprintf(fp_out, "P5\n%d %d\n%d\n", width, height, maxval);
    
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            byte = output_image[i][j];
            fwrite(&byte, 1, 1, fp_out);
        }
    }
    
    fclose(fp_out);
    
    //Free memory
    for(i = 0; i < height; i++)
    {
        free(image[i]);
        free(output_image[i]);
    }
    free(image);
    free(output_image);
    
    printf("\nOperation completed successfully. Output file: %s\n", output_file);
    
    return 0;
}