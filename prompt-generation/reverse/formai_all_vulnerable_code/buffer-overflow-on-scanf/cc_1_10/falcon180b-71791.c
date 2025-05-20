//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MIN_ASCII 32
#define MAX_ASCII 126

typedef struct {
    char ascii;
    char color;
} pixel;

pixel *generate_ascii_art(int width, int height) {
    srand(time(NULL));
    pixel *art = (pixel *)malloc(sizeof(pixel) * width * height);
    for (int i = 0; i < width * height; i++) {
        art[i].ascii = rand() % (MAX_ASCII - MIN_ASCII + 1) + MIN_ASCII;
        art[i].color = rand() % 7;
    }
    return art;
}

void print_ascii_art(pixel *art, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", art[y * width + x].ascii);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    printf("Enter the width of the ASCII art (1-100): ");
    scanf("%d", &width);
    printf("Enter the height of the ASCII art (1-100): ");
    scanf("%d", &height);

    if (width < 1 || width > MAX_WIDTH || height < 1 || height > MAX_HEIGHT) {
        printf("Invalid dimensions!\n");
        return 1;
    }

    pixel *art = generate_ascii_art(width, height);
    print_ascii_art(art, width, height);

    free(art);
    return 0;
}