//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void flip(char *filename, char *new_filename);
void change_brightness_contrast(char *filename, int brightness, int contrast);

int main()
{
    char filename[50], new_filename[50];
    int brightness, contrast, choice;

    printf("\n\t\t***Welcome to Happy Image Processing***\n\n");
    printf("Please enter the image filename: ");
    scanf("%s", filename);

    printf("\n\nPlease select one of the following options:\n");
    printf("1. Flip the Image\n2. Change Brightness and Contrast\n3. Exit\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\n\nWe are flipping your image....CHEERS!!!");
            flip(filename, new_filename);
            printf("\n\nFlipping complete. Please check the new file %s.\n", new_filename);
            break;
        case 2:
            printf("\n\nEnter brightness adjustment (-255 to 255): ");
            scanf("%d", &brightness);
            printf("\nEnter contrast adjustment (-127 to 127): ");
            scanf("%d", &contrast);
            printf("\n\nChanging brightness and contrast....YAY!!!");
            change_brightness_contrast(filename, brightness, contrast);
            printf("\n\nBrightness and Contrast change complete. Please check the file %s.\n", filename);
            break;
        case 3:
            printf("\n\nThank you for using Happy Image Processing!!! :D\n");
            break;
        default:
            printf("\n\nInvalid choice. Please try again.\n");
    }

    return 0;
}

void flip(char *filename, char *new_filename)
{
    //Open input file
    FILE *fp; 
    fp = fopen(filename, "rb");
    if(!fp)
    {
        printf("Error opening file.");
        return;
    }
    
    //Get image width and height
    int width, height;
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    
    //Allocate memory for image data
    int size = width * height * 3;
    unsigned char *data = (unsigned char*) malloc(size * sizeof(unsigned char));
    fseek(fp, 54, SEEK_SET);
    fread(data, sizeof(unsigned char), size, fp);
    
    //Close input file
    fclose(fp);
    
    //Open output file and write image data in reverse order
    char extension[4];
    int i, j, k, index1, index2;
    for(i = 0; i < 3; i++)
    {
        new_filename[i] = filename[i];
        extension[i] = filename[strlen(filename)-3+i];
    }
    new_filename[3] = '_';
    new_filename[4] = 'f';
    new_filename[5] = 'l';
    new_filename[6] = 'i';
    new_filename[7] = 'p';
    new_filename[8] = '.';
    new_filename[9] = extension[0];
    new_filename[10] = extension[1];
    new_filename[11] = extension[2];
    new_filename[12] = '\0';
    
    fp = fopen(new_filename, "wb");
    if(!fp)
    {
        printf("Error opening file.");
        return;
    }
    
    for(i = height-1; i >= 0; i--)
    {
        for(j = 0; j < width; j++)
        {
            for(k = 0; k < 3; k++)
            {
                index1 = (i*width + j)*3 + k;
                index2 = ((height-1-i)*width + j)*3 + k;
                fwrite(&data[index1], sizeof(unsigned char), 1, fp);
                data[index1] = data[index2];
            }
        }
    }
    
    //Close output file and free memory
    fclose(fp);
    free(data);
}

void change_brightness_contrast(char *filename, int brightness, int contrast)
{
    //Open input file
    FILE *fp; 
    fp = fopen(filename, "rb");
    if(!fp)
    {
        printf("Error opening file.");
        return;
    }
    
    //Get image width and height
    int width, height;
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    
    //Allocate memory for image data
    int size = width * height * 3;
    unsigned char *data = (unsigned char*) malloc(size * sizeof(unsigned char));
    fseek(fp, 54, SEEK_SET);
    fread(data, sizeof(unsigned char), size, fp);
    
    //Close input file
    fclose(fp);
    
    //Calculate brightness and contrast factors
    float bright_factor = (float)(brightness + 255) / 255;
    float cont_factor = (float)(contrast + 127) / 127;
    
    //Apply brightness and contrast adjustments to image data
    int i, j, k, val;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            for(k = 0; k < 3; k++)
            {
                val = (int)data[(i*width + j)*3 + k];
                val = (int)(bright_factor * (val - 128) + 128 + 128 * (cont_factor - 1));
                if(val < 0)
                    val = 0;
                if(val > 255)
                    val = 255;
                data[(i*width + j)*3 + k] = (unsigned char)val;
            }
        }
    }
    
    //Open output file and write modified image data
    fp = fopen(filename, "wb");
    if(!fp)
    {
        printf("Error opening file.");
        return;
    }
    
    fseek(fp, 54, SEEK_SET);
    fwrite(data, sizeof(unsigned char), size, fp);
    
    //Close output file and free memory
    fclose(fp);
    free(data);
}