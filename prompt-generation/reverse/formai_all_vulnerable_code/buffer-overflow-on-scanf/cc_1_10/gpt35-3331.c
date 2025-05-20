//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned int pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE]; // pixels of the image
} Image;

// function to read the image from a file
void read_image(char* filename, Image* img)
{
    FILE* fp;
    char buff[16];
    int max_gray;

    fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // read type of image (P2) and dimensions
    fgets(buff, sizeof(buff), fp);
    if (buff[0] != 'P' || buff[1] != '2')
    {
        printf("Error: invalid image type %s\n", buff);
        exit(1);
    }
    fscanf(fp, "%d %d", &img->width, &img->height);

    // read max gray value
    fscanf(fp, "%d", &max_gray);
    if (max_gray > 255)
    {
        printf("Error: grayscale value exceeds 255\n");
        exit(1);
    }

    // read pixels
    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            fscanf(fp, "%d", &img->pixels[i][j]);
            if (img->pixels[i][j] > max_gray)
            {
                printf("Error: pixel grayscale value exceeds %d\n", max_gray);
                exit(1);
            }
        }
    }

    fclose(fp);
}

// function to write image to a file
void write_image(char* filename, Image* img)
{

    FILE* fp;

    fp = fopen(filename, "w");
    if (!fp)
    {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // write type of image (P2) and dimensions
    fprintf(fp, "P2\n%d %d\n255\n", img->width, img->height);

    // write pixels
    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            fprintf(fp, "%d ", img->pixels[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// function to apply a filter to the image
void apply_filter(char* filter_name, Image* img)
{
    // code to apply the specified filter to the image
    // for example, we can apply a simple filter that inverts the colors:
    if (strcmp(filter_name, "invert") == 0)
    {
        for (int i = 0; i < img->height; i++)
        {
            for (int j = 0; j < img->width; j++)
            {
                img->pixels[i][j] = 255 - img->pixels[i][j];
            }
        }
    }
}

int main()
{
    Image img;
    char filename[512];
    char filter_name[512];

    printf("Enter filename: ");
    scanf("%s", filename);

    read_image(filename, &img);

    printf("Enter filter name: ");
    scanf("%s", filter_name);

    apply_filter(filter_name, &img);

    printf("Enter output filename: ");
    scanf("%s", filename);

    write_image(filename, &img);

    printf("Done.\n");

    return 0;
}