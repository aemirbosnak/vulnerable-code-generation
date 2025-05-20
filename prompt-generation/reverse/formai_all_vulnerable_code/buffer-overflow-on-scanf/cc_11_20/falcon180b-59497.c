//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

int main() {
    FILE *inputFile;
    FILE *outputFile;

    char inputFileName[50];
    char outputFileName[50];

    printf("Enter the name of the input image file: ");
    scanf("%s", inputFileName);

    printf("Enter the name of the output ASCII art file: ");
    scanf("%s", outputFileName);

    // Open input file
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Get input file size
    fseek(inputFile, 0, SEEK_END);
    long inputFileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate memory for input file contents
    unsigned char *inputBuffer = malloc(inputFileSize);

    // Read input file into buffer
    fread(inputBuffer, inputFileSize, 1, inputFile);

    // Close input file
    fclose(inputFile);

    // Open output file
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        free(inputBuffer);
        return 1;
    }

    // Convert image to ASCII art
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int brightness = (int) (inputBuffer[y * WIDTH + x] * 0.3 + 0.5);
            switch (brightness) {
                case 0:
                    fprintf(outputFile, "  ");
                    break;
                case 1:
                    fprintf(outputFile, ".");
                    break;
                case 2:
                    fprintf(outputFile, ":");
                    break;
                case 3:
                    fprintf(outputFile, "-");
                    break;
                case 4:
                    fprintf(outputFile, "=");
                    break;
                case 5:
                    fprintf(outputFile, "+");
                    break;
                case 6:
                    fprintf(outputFile, "&");
                    break;
                case 7:
                    fprintf(outputFile, "*");
                    break;
                case 8:
                    fprintf(outputFile, "#");
                    break;
                default:
                    fprintf(outputFile, ".");
                    break;
            }
        }
        fprintf(outputFile, "\n");
    }

    // Close output file
    fclose(outputFile);

    // Free memory
    free(inputBuffer);

    printf("ASCII art created successfully!\n");

    return 0;
}