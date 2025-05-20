//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} PIXEL;

typedef struct
{
    int width;
    int height;
    PIXEL *pixels;
} IMAGE;

IMAGE* read_bmp(char* filename)
{
    FILE* f = fopen(filename, "rb");
    if(f == NULL)
    {
        perror("Error opening file");
        return NULL;
    }
    IMAGE *image = malloc(sizeof(IMAGE));
    if(image == NULL)
    {
        perror("Error allocating memory");
        return NULL;
    }
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f);
    image->width = *(int*)&info[18];
    image->height = *(int*)&info[22];
    int size = image->width * image->height;
    image->pixels = malloc(sizeof(PIXEL) * size);
    if(image->pixels == NULL)
    {
        perror("Error allocating memory");
        return NULL;
    }
    int padding = (4 - (image->width * sizeof(PIXEL)) % 4) % 4;
    unsigned char single_pixel[3];
    for(int i = 0; i < image->height; i++)
    {
        for(int j = 0; j < image->width; j++)
        {
            fread(single_pixel, sizeof(unsigned char), 3, f);
            image->pixels[(image->height - i - 1) * image->width + j].red = single_pixel[2];
            image->pixels[(image->height - i - 1) * image->width + j].green = single_pixel[1];
            image->pixels[(image->height - i - 1) * image->width + j].blue = single_pixel[0];
        }
        fseek(f, padding, SEEK_CUR);
    }
    fclose(f);
    return image;
}

int write_bmp(IMAGE* image, char* filename)
{
    FILE* f = fopen(filename, "wb");
    if(f == NULL)
    {
        perror("Error opening file");
        return -1;
    }
    unsigned char info[54] = {0};
    info[0] = 'B';
    info[1] = 'M';
    int file_size = 54 + 3 * image->width * image->height;
    *(int*)&info[2] = file_size;
    *(int*)&info[10] = 54;
    *(int*)&info[14] = 40;
    *(int*)&info[18] = image->width;
    *(int*)&info[22] = image->height;
    *(int*)&info[26] = 1;
    *(int*)&info[28] = 24;
    fwrite(info, sizeof(unsigned char), 54, f);
    int padding = (4 - (image->width * sizeof(PIXEL)) % 4) % 4;
    unsigned char padding_data[3] = {0};
    for(int i = 0; i < image->height; i++)
    {
        for(int j = 0; j < image->width; j++)
        {
            unsigned char single_pixel[3];
            single_pixel[0] = image->pixels[(image->height - i - 1) * image->width + j].blue;
            single_pixel[1] = image->pixels[(image->height - i - 1) * image->width + j].green;
            single_pixel[2] = image->pixels[(image->height - i - 1) * image->width + j].red;
            fwrite(single_pixel, sizeof(unsigned char), 3, f);
        }
        fwrite(padding_data, sizeof(unsigned char), padding, f);
    }
    fclose(f);
    printf("Image saved successfully\n");
    return 0;
}

void flip_image(IMAGE* image)
{
    PIXEL temp;
    for(int i = 0; i < image->height / 2; i++)
    {
        for(int j = 0; j < image->width; j++)
        {
            temp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[(image->height - i - 1) * image->width + j];
            image->pixels[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

void change_brightness(IMAGE* image, int brightness)
{
    for(int i = 0; i < image->height; i++)
    {
        for(int j = 0; j < image->width; j++)
        {
            int red = image->pixels[i * image->width + j].red + brightness;
            int green = image->pixels[i * image->width + j].green + brightness;
            int blue = image->pixels[i * image->width + j].blue + brightness;
            if(red > 255) red = 255;
            else if(red < 0) red = 0;
            if(green > 255) green = 255;
            else if(green < 0) green = 0;
            if(blue > 255) blue = 255;
            else if(blue < 0) blue = 0;
            image->pixels[i * image->width + j].red = (unsigned char)red;
            image->pixels[i * image->width + j].green = (unsigned char)green;
            image->pixels[i * image->width + j].blue = (unsigned char)blue;
        }
    }
}

void change_contrast(IMAGE* image, float contrast)
{
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(int i = 0; i < image->height; i++)
    {
        for(int j = 0; j < image->width; j++)
        {
            int red = (int)(factor * (image->pixels[i * image->width + j].red - 128) + 128);
            int green = (int)(factor * (image->pixels[i * image->width + j].green - 128) + 128);
            int blue = (int)(factor * (image->pixels[i * image->width + j].blue - 128) + 128);
            if(red > 255) red = 255;
            else if(red < 0) red = 0;
            if(green > 255) green = 255;
            else if(green < 0) green = 0;
            if(blue > 255) blue = 255;
            else if(blue < 0) blue = 0;
            image->pixels[i * image->width + j].red = (unsigned char)red;
            image->pixels[i * image->width + j].green = (unsigned char)green;
            image->pixels[i * image->width + j].blue = (unsigned char)blue;
        }
    }
}

int main()
{
    char filename[100];
    printf("Enter BMP image filename: ");
    scanf("%s", filename);
    IMAGE *image = read_bmp(filename);
    if(image == NULL)
    {
        return -1;
    }
    int choice;
    printf("1. Flip image horizontally\n");
    printf("2. Change brightness\n");
    printf("3. Change contrast\n");
    printf("4. Save modified image\n");
    printf("5. Quit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                flip_image(image);
                printf("Image flipped horizontally!\n");
                break;
            case 2:
                {
                    int brightness;
                    printf("Enter brightness value (-255 to 255): ");
                    scanf("%d", &brightness);
                    change_brightness(image, brightness);
                    printf("Brightness changed!\n");
                    break;
                }
            case 3:
                {
                    float contrast;
                    printf("Enter contrast value (-255 to 255): ");
                    scanf("%f", &contrast);
                    change_contrast(image, contrast);
                    printf("Contrast changed!\n");
                    break;
                }
            case 4:
                {
                    char new_filename[100];
                    printf("Enter new filename: ");
                    scanf("%s", new_filename);
                    write_bmp(image, new_filename);
                    break;
                }
            case 5:
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);
    free(image->pixels);
    free(image);
    return 0;
}