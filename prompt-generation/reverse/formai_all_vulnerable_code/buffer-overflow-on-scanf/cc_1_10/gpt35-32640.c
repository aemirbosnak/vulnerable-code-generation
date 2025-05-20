//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ascii[10] = 
{
    " ", "*", "*", "*", "*", "*", " ", " ", " ", " ",
    "*", "*", " ", " ", " ", " ", "*", "*", " ", " ",
    "*", "*", " ", " ", " ", " ", "*", "*", " ", " ",
    "*", "*", "*", "*", "*", "*", "*", "*", " ", " ",
    "*", "*", " ", " ", "*", "*", " ", "*", "*", " ",
    "*", "*", " ", " ", "*", "*", " ", "*", "*", " ",
    " ", "*", "*", "*", "*", "*", "*", "*", " ", " ",
    " ", " ", " ", " ", "*", "*", " ", " ", " ", " ",
    " ", " ", " ", " ", "*", "*", " ", " ", " ", " ",
    " ", " ", " ", " ", "*", "*", " ", " ", " ", " "
};

void convert_to_ascii(const char* file_path)
{
    FILE *image_file = fopen(file_path, "rb");
    if (image_file == NULL) {
        printf("File not found");
        return;
    }

    //determine the size of the image
    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    rewind(image_file);

    //allocating memory for image buffer
    unsigned char *image_buffer = (unsigned char*) malloc(sizeof(unsigned char) * image_size);

    //read the image bytes
    fread(image_buffer, 1, image_size, image_file);

    fclose(image_file);

    //printing the image as ascii art
    int width = 0;
    for (long i = 0; i < image_size; i += 3) {
        int r = image_buffer[i];
        int g = image_buffer[i + 1];
        int b = image_buffer[i + 2];
        int brightness = ((r + g + b) / 3) / 255;

        printf("%s", ascii[brightness]);
        width++;
        if (width > 100) {
            printf("\n");
            width = 0;
        }
    }

    free(image_buffer);
}

int main()
{
    char file_path[100];
    printf("Enter image file path: ");
    scanf("%s",file_path);

    convert_to_ascii(file_path);

    return 0;
}