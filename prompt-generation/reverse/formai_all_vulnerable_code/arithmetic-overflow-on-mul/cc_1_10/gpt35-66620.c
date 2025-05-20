//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_LEN 256
#define MAX_IMAGE_WIDTH 1920
#define MAX_IMAGE_HEIGHT 1080
#define MAX_PIXEL_VALUE 255

struct Image
{
    int width;
    int height;
    int** pixel_values;
};

// global variable for ease of use
char file_name[FILE_NAME_LEN];

void load_image(struct Image* img);
void save_image(struct Image* img);
void blur_image(struct Image* img);
void flip_image_horizontal(struct Image* img);
void flip_image_vertical(struct Image* img);
void rotate_image(struct Image* img);

int main()
{
    struct Image img;
    char choice;

    printf("Welcome to the Intelligent C Image Editor!\n");

    do
    {
        printf("\nMenu:\n");
        printf("1. Load Image\n");
        printf("2. Save Image\n");
        printf("3. Blur Image\n");
        printf("4. Flip Image Horizontally\n");
        printf("5. Flip Image Vertically\n");
        printf("6. Rotate Image\n");
        printf("0. Exit Program\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice);

        switch (choice)
        {
            case '1':
                load_image(&img);
                break;
            case '2':
                save_image(&img);
                break;
            case '3':
                blur_image(&img);
                break;
            case '4':
                flip_image_horizontal(&img);
                break;
            case '5':
                flip_image_vertical(&img);
                break;
            case '6':
                rotate_image(&img);
                break;
            case '0':
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != '0');

    printf("Goodbye!\n");

    return 0;
}

void load_image(struct Image* img)
{
    FILE* fp;
    char file_type[3];
    int max_pixel_value;

    printf("\nEnter file name: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        printf("\nError opening file.");
        return;
    }

    fscanf(fp, "%s\n", file_type);

    if (strcmp(file_type, "P2") != 0)
    {
        printf("\nInvalid file type.");
        fclose(fp);
        return;
    }

    fscanf(fp, "%d %d\n", &img->width, &img->height);
    fscanf(fp, "%d\n", &max_pixel_value);

    if (img->width > MAX_IMAGE_WIDTH || img->height > MAX_IMAGE_HEIGHT)
    {
        printf("\nImage too large.");
        fclose(fp);
        return;
    }

    img->pixel_values = malloc(img->height * sizeof(int*));

    for (int i = 0; i < img->height; i++)
    {
        img->pixel_values[i] = malloc(img->width * sizeof(int));

        for (int j = 0; j < img->width; j++)
        {
            fscanf(fp, "%d", &img->pixel_values[i][j]);

            if (img->pixel_values[i][j] > MAX_PIXEL_VALUE)
            {
                printf("\nInvalid pixel value.");
                fclose(fp);
                return;
            }
        }

        fscanf(fp, "\n");
    }

    fclose(fp);

    printf("\nImage loaded successfully!");
}

void save_image(struct Image* img)
{
    FILE* fp;

    printf("\nEnter file name to save as: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "w");

    if (fp == NULL)
    {
        printf("\nError opening file.");
        return;
    }

    fprintf(fp, "P2\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "%d\n", MAX_PIXEL_VALUE);

    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            fprintf(fp, "%d ", img->pixel_values[i][j]);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("\nImage saved successfully!");
}

void blur_image(struct Image* img)
{
    int kernel_size;
    float** kernel;
    int** pixel_values_copy;
    int i, j, k, l;
    float sum, divisor;

    printf("\nEnter kernel size: ");
    scanf("%d", &kernel_size);

    kernel = malloc(kernel_size * sizeof(float*));
    pixel_values_copy = malloc(img->height * sizeof(int*));

    for (i = 0; i < img->height; i++)
    {
        pixel_values_copy[i] = malloc(img->width * sizeof(int));

        for (j = 0; j < img->width; j++)
        {
            pixel_values_copy[i][j] = img->pixel_values[i][j];
        }
    }

    for (i = 0; i < kernel_size; i++)
    {
        kernel[i] = malloc(kernel_size * sizeof(float));

        for (j = 0; j < kernel_size; j++)
        {
            kernel[i][j] = 1.0 / (float)(kernel_size * kernel_size);
        }
    }

    divisor = kernel_size * kernel_size;

    for (i = kernel_size/2; i < img->height - kernel_size/2; i++)
    {
        for (j = kernel_size/2; j < img->width - kernel_size/2; j++)
        {
            sum = 0;

            for (k = i - kernel_size/2; k <= i + kernel_size/2; k++)
            {
                for (l = j - kernel_size/2; l <= j + kernel_size/2; l++)
                {
                    sum += kernel[k - i + kernel_size/2][l - j + kernel_size/2] * (float)pixel_values_copy[k][l];
                }
            }

            img->pixel_values[i][j] = (int)(sum / divisor);
        }
    }

    for (i = 0; i < kernel_size; i++)
    {
        free(kernel[i]);
    }

    free(kernel);

    printf("\nImage blurred successfully!");
}

void flip_image_horizontal(struct Image* img)
{
    int i, j, temp;

    for (i = 0; i < img->height; i++)
    {
        for (j = 0; j < img->width/2; j++)
        {
            temp = img->pixel_values[i][j];
            img->pixel_values[i][j] = img->pixel_values[i][img->width - j - 1];
            img->pixel_values[i][img->width - j - 1] = temp;
        }
    }

    printf("\nImage flipped horizontally successfully!");
}

void flip_image_vertical(struct Image* img)
{
    int i, j, temp;

    for (i = 0; i < img->height/2; i++)
    {
        for (j = 0; j < img->width; j++)
        {
            temp = img->pixel_values[i][j];
            img->pixel_values[i][j] = img->pixel_values[img->height - i - 1][j];
            img->pixel_values[img->height - i - 1][j] = temp;
        }
    }

    printf("\nImage flipped vertically successfully!");
}

void rotate_image(struct Image* img)
{
    int i, j, temp;
    int** new_pixel_values;

    new_pixel_values = malloc(img->width * sizeof(int*));

    for (i = 0; i < img->width; i++)
    {
        new_pixel_values[i] = malloc(img->height * sizeof(int));

        for (j = 0; j < img->height; j++)
        {
            new_pixel_values[i][j] = img->pixel_values[j][img->width - i - 1];
        }
    }

    for (i = 0; i < img->height; i++)
    {
        free(img->pixel_values[i]);
    }

    free(img->pixel_values);

    img->pixel_values = new_pixel_values;

    temp = img->width;
    img->width = img->height;
    img->height = temp;

    printf("\nImage rotated successfully!");
}