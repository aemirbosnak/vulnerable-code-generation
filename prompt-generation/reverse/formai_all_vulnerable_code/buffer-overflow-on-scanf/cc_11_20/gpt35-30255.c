//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

// Function to convert an image to ASCII art
void imageToAscii(char* filename) {
    FILE *fptr;
    char image[MAX_HEIGHT][MAX_WIDTH], ch;
    int x, y;

    // Open the image file
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the image into a 2D array
    for (y = 0; y < MAX_HEIGHT; y++) {
        for (x = 0; x < MAX_WIDTH; x++) {
            ch = fgetc(fptr);
            image[y][x] = ch;
        }
    }

    // Convert each pixel to ASCII art and print to the console
    for (y = 0; y < MAX_HEIGHT; y++) {
        for (x = 0; x < MAX_WIDTH; x++) {
            switch (image[y][x]) {
                case ' ': printf(" "); break;
                case '#': printf("#"); break;
                case '%': printf("%"); break;
                case '&': printf("&"); break;
                case '*': printf("*"); break;
                case '+': printf("+"); break;
                case '-': printf("-"); break;
                case '/': printf("/"); break;
                case ':': printf(":"); break;
                case ';': printf(";"); break;
                case '<': printf("<"); break;
                case '>': printf(">"); break;
                case '?': printf("?"); break;
                case '@': printf("@"); break;
                case 'A': printf("A"); break;
                case 'B': printf("B"); break;
                case 'C': printf("C"); break;
                case 'D': printf("D"); break;
                default: printf(" "); break;
            }
        }
        printf("\n");
    }
    
    // Close the file
    fclose(fptr);
}

int main() {
    char filename[100];

    // Ask the user for the filename of the image
    printf("Enter the filename of the image: ");
    scanf("%s", filename);

    // Convert the image to ASCII art
    imageToAscii(filename);
    
    return 0;
}