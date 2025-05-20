//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to convert image to ascii
void imageToASCII(char *filename, int width, int height) {
    FILE *fp;
    char ch;
    int i, j, k, count = 0;
    char *buffer;

    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (char *) malloc(size);
    if(buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    fread(buffer, size, 1, fp);
    fclose(fp);

    printf("Image converted to ASCII:\n");
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            k = i * width + j;
            ch = buffer[k];
            if(ch < 32) {
                printf(" ");
            } else if(ch > 126) {
                printf("*");
            } else {
                printf("%c", ch);
            }
        }
        printf("\n");
    }

    free(buffer);
}

//Main function
int main() {
    char filename[100];
    int width, height;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    imageToASCII(filename, width, height);

    return 0;
}