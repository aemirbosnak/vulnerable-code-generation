//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 100

char ascii[MAX_HEIGHT][MAX_WIDTH + 1];

int get_pixel_brightness(int r, int g, int b){
    return (int)((0.2126 * r) + (0.7152 * g) + (0.0722 * b));
}

void write_ascii(char* filename, int width, int height){
    FILE* fptr = fopen(filename, "w");
    int i, j;

    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            fputc(ascii[i][j], fptr);
        }
        fputc('\n', fptr);
    }
    fclose(fptr);
}

void convert_to_ascii(char* input_file, char* output_file){
    FILE* fptr = fopen(input_file, "rb");

    if (fptr == NULL)
    {
        printf("Error: Unable to open image file.");
        return;
    }

    unsigned char buffer[54];
    int i, j;

    //read the BITMAP file header
    fread(buffer, sizeof(unsigned char), 54, fptr);

    //check if its a valid BMP file
    if (buffer[0] != 'B' || buffer[1] != 'M')
    {
        printf("Error: File format not recognized.");
        return;
    }

    //read important values from the header
    int offset = *(int*)&buffer[10];
    int width = *(int*)&buffer[18];
    int height = *(int*)&buffer[22];
    int padding = 0;

    //calculate the amount of padding in the image file
    while ((width * 3 + padding) % 4 != 0){
        padding++;
    }

    //calculate the actual width of the image in bytes
    int width_bytes = (width * 3) + padding;

    //declare a buffer for the image data
    unsigned char image_data[MAX_HEIGHT][MAX_WIDTH][3];

    //read in the image data
    fseek(fptr, offset, SEEK_SET);
    for (i = 0; i < height; i++){
        fread(image_data[i], sizeof(unsigned char), width_bytes, fptr);
    }
    fclose(fptr);

    //convert the image data to ASCII characters
    for (i = 0; i < height; i++){
        for (j = 0; j < width_bytes; j += 3){
            int brightness = get_pixel_brightness(image_data[i][j+2], image_data[i][j+1], image_data[i][j]);
            if (brightness < 50){
                ascii[i][j/3] = '#';
            }
            else if (brightness < 100){
                ascii[i][j/3] = 'X';
            }
            else if (brightness < 150){
                ascii[i][j/3] = '=';
            }
            else if (brightness < 200){
                ascii[i][j/3] = '+';
            }
            else if (brightness < 255){
                ascii[i][j/3] = '-';
            }
            else{
                ascii[i][j/3] = ' ';
            }
        }
    }

    //write the ASCII art to a file
    write_ascii(output_file, width, height);

    printf("Conversion successful. ASCII art saved to %s.\n", output_file);
}

int main()
{
    char input_file[50];
    char output_file[50];

    printf("Enter the name of the image file: ");
    fgets(input_file, 50, stdin);
    input_file[strlen(input_file) - 1] = '\0';

    printf("Enter the name of the output file: ");
    fgets(output_file, 50, stdin);
    output_file[strlen(output_file) - 1] = '\0';

    convert_to_ascii(input_file, output_file);

    return 0;
}