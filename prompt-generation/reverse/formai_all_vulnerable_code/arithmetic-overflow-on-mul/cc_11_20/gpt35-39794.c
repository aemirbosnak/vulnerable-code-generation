//FormAI DATASET v1.0 Category: Image Editor ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int height, width, choice, i, j, r, g, b, rgba_input, rgba_output, pixel_count, ch;
    unsigned char *image_data;

    // Reading image height and width
    printf("Enter image height and width: ");
    scanf("%d %d", &height, &width);

    // Allocating memory dynamically
    pixel_count = height * width;
    image_data = (unsigned char*)calloc(pixel_count, 4);

    // Reading image file
    FILE *input = fopen("input_file_path", "rb");
    fread(&image_data[0], pixel_count, 4, input);
    fclose(input);

    // Menu
    printf("\n~~~~~~ Image Editor ~~~~~~\n");
    printf("1. Invert colors\n");
    printf("2. Convert to grayscale\n");
    printf("3. Sepia\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Image processing logic
    switch(choice)
    {
        case 1:
            for(i=0; i<pixel_count; i++)
            {
                rgba_input = i * 4;
                rgba_output = i * 4;
                image_data[rgba_output] = 255 - image_data[rgba_input]; // Inverting R
                image_data[rgba_output+1] = 255 - image_data[rgba_input+1]; // Inverting G
                image_data[rgba_output+2] = 255 - image_data[rgba_input+2]; // Inverting B
                image_data[rgba_output+3] = image_data[rgba_input+3]; // Keeping Alpha
            }
            break;

        case 2:
            for(i=0; i<pixel_count; i++)
            {
                rgba_input = i * 4;
                rgba_output = i * 4;
                r = image_data[rgba_input];
                g = image_data[rgba_input+1];
                b = image_data[rgba_input+2];
                image_data[rgba_output] = 0.2989 * r + 0.5870 * g + 0.1140 * b; // Converting to grayscale
                image_data[rgba_output+1] = 0.2989 * r + 0.5870 * g + 0.1140 * b;
                image_data[rgba_output+2] = 0.2989 * r + 0.5870 * g + 0.1140 * b;
                image_data[rgba_output+3] = image_data[rgba_input+3]; // Keeping Alpha
            }
            break;

        case 3:
            for(i=0; i<pixel_count; i++)
            {
                rgba_input = i * 4;
                rgba_output = i * 4;
                r = image_data[rgba_input];
                g = image_data[rgba_input+1];
                b = image_data[rgba_input+2];
                image_data[rgba_output] = 0.393 * r + 0.769 * g + 0.189 * b; // Converting to sepia
                image_data[rgba_output+1] = 0.349 * r + 0.686 * g + 0.168 * b;
                image_data[rgba_output+2] = 0.272 * r + 0.534 * g + 0.131 * b;
                image_data[rgba_output+3] = image_data[rgba_input+3]; // Keeping Alpha
            }
            break;

        default:
            printf("Invalid choice\n");
            return 0;
    }

    // Writing output file
    FILE *output = fopen("output_file_path", "wb");
    fwrite(&image_data[0], pixel_count, 4, output);
    fclose(output);

    // Checking if user wants to view the output image
    printf("\nDo you want to view the output image? (Y/N): ");
    scanf(" %c", &ch);
    if(ch=='Y' || ch=='y')
    {
        // Reading output file and displaying the image
        FILE *output = fopen("output_file_path", "rb");
        unsigned char *output_image_data = (unsigned char*)calloc(pixel_count, 4);
        fread(&output_image_data[0], pixel_count, 4, output);
        fclose(output);

        printf("\n\n");
        for(i=0; i<height; i++)
        {
            for(j=0; j<width; j++)
            {
                rgba_output = (i * width + j) * 4;
                printf("(%d,%d,%d,%d)\t", output_image_data[rgba_output], output_image_data[rgba_output+1], output_image_data[rgba_output+2], output_image_data[rgba_output+3]);
            }
            printf("\n\n");
        }
    }

    free(image_data);

    return 0;
}