//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu();
void grayscale(int* pixel);
void sepia(int* pixel);

int main() {
    int option;
    int pixel[3];
    char title[100], filename[100], outfilename[100];
    FILE* infile;
    FILE* outfile;

    while (1) {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);
                infile = fopen(filename, "rb");
                if (infile == NULL) {
                    printf("Could not open file.\n");
                    break;
                }
                printf("Enter the title of the image: ");
                scanf("%s", title);
                sprintf(outfilename, "%s_edited.bmp", title);
                outfile = fopen(outfilename, "wb");
                if (outfile == NULL) {
                    printf("Could not create output file.\n");
                    fclose(infile);
                    break;
                }
                fseek(infile, 0, SEEK_SET);
                unsigned char header[54];
                fread(header, sizeof(unsigned char), 54, infile);
                fwrite(header, sizeof(unsigned char), 54, outfile);

                while (!feof(infile)) {
                    fread(pixel, sizeof(int), 3, infile);
                    if (!feof(infile)) {
                        grayscale(pixel);
                        fwrite(pixel, sizeof(int), 3, outfile);
                    }
                }
                printf("Image processed successfully.\n");
                fclose(infile);
                fclose(outfile);
                break;
            case 2:
                printf("Enter the filename: ");
                scanf("%s", filename);
                infile = fopen(filename, "rb");
                if (infile == NULL) {
                    printf("Could not open file.\n");
                    break;
                }
                printf("Enter the title of the image: ");
                scanf("%s", title);
                sprintf(outfilename, "%s_edited.bmp", title);
                outfile = fopen(outfilename, "wb");
                if (outfile == NULL) {
                    printf("Could not create output file.\n");
                    fclose(infile);
                    break;
                }
                fseek(infile, 0, SEEK_SET);
                unsigned char header2[54];
                fread(header2, sizeof(unsigned char), 54, infile);
                fwrite(header2, sizeof(unsigned char), 54, outfile);

                while (!feof(infile)) {
                    fread(pixel, sizeof(int), 3, infile);
                    if (!feof(infile)) {
                        sepia(pixel);
                        fwrite(pixel, sizeof(int), 3, outfile);
                    }
                }
                printf("Image processed successfully.\n");
                fclose(infile);
                fclose(outfile);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

void printMenu() {
    printf("\nMedieval Image Editor\n");
    printf("---------------------\n");
    printf("1. Grayscale\n");
    printf("2. Sepia\n");
    printf("3. Exit\n");
    printf("---------------------\n");
    printf("Enter your choice: ");
}

void grayscale(int* pixel) {
    unsigned char gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
    pixel[0] = gray;
    pixel[1] = gray;
    pixel[2] = gray;
}

void sepia(int* pixel) {
    unsigned char r = pixel[2];
    unsigned char g = pixel[1];
    unsigned char b = pixel[0];
    pixel[2] = r * 0.393 + g * 0.769 + b * 0.189;
    pixel[1] = r * 0.349 + g * 0.686 + b * 0.168;
    pixel[0] = r * 0.272 + g * 0.534 + b * 0.131;
}