//FormAI DATASET v1.0 Category: Image Editor ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Functions Declaration
void grayscale(char*);
void sepia(char*);
void invertneg(char*);
int validateImage(char*);

int main(){
    char filename[100];
    printf("Enter the filename (including extension) of the image to be edited:\n");
    scanf("%s", filename);

    int isValid = validateImage(filename);

    if (isValid){
        printf("Select the operation to be performed on the selected image:\n");
        printf("1. Convert to Grayscale\n");
        printf("2. Convert to Sepia\n");
        printf("3. Invert Negative\n");

        int choice;
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                grayscale(filename);
                break;
            case 2:
                sepia(filename);
                break;
            case 3:
                invertneg(filename);
                break;
            default:
                printf("Invalid choice. Please choose between 1, 2, and 3.\n");
                break;
        }
    }
    else{
        printf("Invalid image file. Please provide a valid image file. Supported formats are .jpg and .png.\n");
    }

    return 0;
}

void grayscale(char* filename){
    FILE *image, *output;
    char newfile[100];

    sprintf(newfile, "Grayscale_%s", filename);

    int width, height, max;
    char ptype[3];

    image = fopen(filename, "r");
    output = fopen(newfile, "w");

    // Reading the header of the image file
    fscanf(image, "%s %d %d %d", ptype, &width, &height, &max);

    // Writing the header in the output file
    fprintf(output, "%s\n%d %d\n%d\n", ptype, width, height, max);

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int r, g, b;
            fscanf(image, "%d %d %d", &r, &g, &b);

            // Converting to grayscale
            int avg = (r + g + b) / 3;

            // Writing the pixel in the output file
            fprintf(output, "%d %d %d ", avg, avg, avg);
        }
        fprintf(output, "\n"); // New line
    }

    printf("Grayscale conversion completed successfully. The output file is %s.\n", newfile);

    fclose(image);
    fclose(output);
}

void sepia(char* filename){
    FILE *image, *output;
    char newfile[100];

    sprintf(newfile, "Sepia_%s", filename);

    int width, height, max;
    char ptype[3];

    int r, g, b, sr, sg, sb;

    image = fopen(filename, "r");
    output = fopen(newfile, "w");

    // Reading the header of the image file
    fscanf(image, "%s %d %d %d", ptype, &width, &height, &max);

    // Writing the header in the output file
    fprintf(output, "%s\n%d %d\n%d\n", ptype, width, height, max);

    // Performing the sepia filter
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            fscanf(image, "%d %d %d", &r, &g, &b);

            sr = (0.393 * r) + (0.769 * g) + (0.189 * b);
            sg = (0.349 * r) + (0.686 * g) + (0.168 * b);
            sb = (0.272 * r) + (0.534 * g) + (0.131 * b);

            // Checking for values above 255 due to rounding errors
            sr = sr > max ? max : sr;
            sg = sg > max ? max : sg;
            sb = sb > max ? max : sb;

            // Writing the pixel in the output file
            fprintf(output, "%d %d %d ", sr, sg, sb);
        }
        fprintf(output, "\n"); // New line
    }

    printf("Sepia conversion completed successfully. The output file is %s.\n", newfile);

    fclose(image);
    fclose(output);
}

void invertneg(char* filename){
    FILE *image, *output;
    char newfile[100];

    sprintf(newfile, "InvertNeg_%s", filename);

    int width, height, max;
    char ptype[3];

    image = fopen(filename, "r");
    output = fopen(newfile, "w");

    // Reading the header of the image file
    fscanf(image, "%s %d %d %d", ptype, &width, &height, &max);

    // Writing the header in the output file
    fprintf(output, "%s\n%d %d\n%d\n", ptype, width, height, max);

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int r, g, b;
            fscanf(image, "%d %d %d", &r, &g, &b);

            // Inverting the colors
            fprintf(output, "%d %d %d ", max - r, max - g, max - b);
        }
        fprintf(output, "\n"); // New line
    }

    printf("Invert negative conversion completed successfully. The output file is %s.\n", newfile);

    fclose(image);
    fclose(output);
}

// Validate if the image file is supported by the program (The program supports PNG and JPG)
int validateImage(char* filename){
    char* ext = strrchr(filename, '.');
    if (ext != NULL){
        if (strcmp(ext, ".png") == 0 || strcmp(ext, ".jpg") == 0){
            return 1;
        }
    }
    return 0;
}