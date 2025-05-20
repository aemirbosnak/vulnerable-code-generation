//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_TEXT_LENGTH 1000

struct pixel {
    char character;
    int color;
};

void draw_text(char* text, int x, int y, int width, int height, struct pixel* pixels) {
    int text_length = strlen(text);
    int i, j;
    for (i = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            int ascii = tolower(text[i]) - 'a';
            if (ascii >= 0 && ascii < 26) {
                for (j = 0; j < 5; j++) {
                    int row = (i * 5) + j;
                    int col = (ascii * 5) + j;
                    if (row >= 0 && row < height && col >= 0 && col < width) {
                        pixels[(row * width) + col].character = 'A' + ascii;
                        pixels[(row * width) + col].color = 0x000000;
                    }
                }
            }
        }
    }
}

int main() {
    char input_text[MAX_TEXT_LENGTH];
    printf("Enter some text: ");
    fgets(input_text, MAX_TEXT_LENGTH, stdin);
    
    int width, height;
    printf("Enter the width of the image (1-80): ");
    scanf("%d", &width);
    printf("Enter the height of the image (1-25): ");
    scanf("%d", &height);
    
    struct pixel* pixels = malloc(width * height * sizeof(struct pixel));
    if (pixels == NULL) {
        printf("Error: Could not allocate memory.\n");
        return 1;
    }
    
    draw_text(input_text, 0, 0, width, height, pixels);
    
    printf("ASCII art:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            struct pixel pixel = pixels[(i * width) + j];
            if (pixel.character!= '\0') {
                printf("%c", pixel.character);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    free(pixels);
    return 0;
}