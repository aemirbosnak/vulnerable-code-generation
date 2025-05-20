//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *input, *output;
    char input_file_name[100], output_file_name[100];
    int choice;
    int image_width, image_height, max_gray_value, brightness, contrast, i, j;
    unsigned char *image_data, temp;
    char image_format[4];

    printf("Enter the name of the input image file: ");
    scanf("%s", input_file_name);

    input = fopen(input_file_name, "rb");

    if (input == NULL)
    {
        printf("Error: Cannot open %s\n", input_file_name);
        return 1;
    }

    fscanf(input, "%s", image_format);
    fscanf(input, "%d %d %d", &image_width, &image_height, &max_gray_value);

    //Allocate memory for image data
    image_data = (unsigned char*) malloc(sizeof(unsigned char) * image_width * image_height);

    //Read image data from input file
    fread(image_data, sizeof(unsigned char), image_width * image_height, input);

    printf("1. Flip Image Vertically\n");
    printf("2. Flip Image Horizontally\n");
    printf("3. Change Brightness\n");
    printf("4. Change Contrast\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            //Flip image vertically
            for (i = 0; i < image_height / 2; i++)
            {
                for (j = 0; j < image_width; j++)
                {
                    temp = *(image_data + i * image_width + j);
                    *(image_data + i * image_width + j) = *(image_data + (image_height - i - 1) * image_width + j);
                    *(image_data + (image_height - i - 1) * image_width + j) = temp;
                }
            }
            printf("Image flipped vertically successfully!\n");
            break;

        case 2:
            //Flip image horizontally
            for (i = 0; i < image_height; i++)
            {
                for (j = 0; j < image_width / 2; j++)
                {
                    temp = *(image_data + i * image_width + j);
                    *(image_data + i * image_width + j) = *(image_data + i * image_width + (image_width - j - 1));
                    *(image_data + i * image_width + (image_width - j - 1)) = temp;
                }
            }
            printf("Image flipped horizontally successfully!\n");
            break;

        case 3:
            //Change brightness of image
            printf("Enter brightness value (-255 to 255): ");
            scanf("%d", &brightness);

            for (i = 0; i < image_height; i++)
            {
                for (j = 0; j < image_width; j++)
                {
                    if (*(image_data + i * image_width + j) + brightness < 0)
                    {
                        *(image_data + i * image_width + j) = 0;
                    }
                    else if (*(image_data + i * image_width + j) + brightness > 255)
                    {
                        *(image_data + i * image_width + j) = 255;
                    }
                    else
                    {
                        *(image_data + i * image_width + j) += brightness;
                    }
                }
            }
            printf("Brightness changed successfully!\n");
            break;

        case 4:
            //Change contrast of image
            printf("Enter contrast value (-255 to 255): ");
            scanf("%d", &contrast);

            for (i = 0; i < image_height; i++)
            {
                for (j = 0; j < image_width; j++)
                {
                    if (*(image_data + i * image_width + j) + contrast < 0)
                    {
                        *(image_data + i * image_width + j) = 0;
                    }
                    else if (*(image_data + i * image_width + j) + contrast > 255)
                    {
                        *(image_data + i * image_width + j) = 255;
                    }
                    else
                    {
                        *(image_data + i * image_width + j) = *(image_data + i * image_width + j) * (255 + contrast) / 255 - contrast;
                    }
                }
            }
            printf("Contrast changed successfully!\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    output = fopen(output_file_name, "wb");

    if (output == NULL)
    {
        printf("Error: Cannot open %s\n", output_file_name);
        return 1;
    }

    //Write output image data to output file
    fprintf(output, "%s\n", image_format);
    fprintf(output, "%d %d\n%d\n", image_width, image_height, max_gray_value);
    fwrite(image_data, sizeof(unsigned char), image_width * image_height, output);

    printf("Output image written to file %s successfully!\n", output_file_name);

    free(image_data);

    fclose(input);
    fclose(output);

    return 0;
}