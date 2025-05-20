//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_IMAGE_WIDTH 100
#define MAX_IMAGE_HEIGHT 100

char ascii[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};

void convertToASCII(unsigned char image[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH], 
                    int height, int width, char asciiArt[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH]) {
    int range_size = 256 / 10; // divide the range in 10 equal parts
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int idx = image[i][j] / range_size; // calculate the index of the character
            asciiArt[i][j] = ascii[idx];
        }
    }
}

int main() {
    char fileName[MAX_FILE_NAME_SIZE];

    printf("Enter the file name: ");
    fgets(fileName, MAX_FILE_NAME_SIZE, stdin);
    fileName[strcspn(fileName, "\n")] = 0;

    FILE* inFile = fopen(fileName, "rb");

    if(inFile == NULL) {
        printf("Error: Could not open file '%s'\n", fileName);
        return 1;
    }

    unsigned char image[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH];
    int height = 0, width = 0;
    char line[MAX_IMAGE_WIDTH*2]; // store the line as a string, which can be parsed later

    while(fgets(line, MAX_IMAGE_WIDTH*2, inFile)) {
        if(line[0] == '\n') continue; // skip empty lines

        char* ptr = line;
        int val;
        width = 0;

        while(sscanf(ptr, "%d", &val) == 1) {
            image[height][width++] = (unsigned char)val;
            ptr = strchr(ptr, ' '); // move to the next space
            if(ptr == NULL) break;
            ptr++; // skip the space
        }
        height++;
    }

    fclose(inFile);

    char asciiArt[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH];
    convertToASCII(image, height, width, asciiArt);

    printf("\n ASCII Art: \n");

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}