//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 32
#define HEIGHT 16
#define ASCII_CHARS " .:-=+*%@#"

typedef struct {
    char canvas[HEIGHT][WIDTH];
} PixelArt;

void drawPixelArt(PixelArt *art) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(art->canvas[y][x]);
        }
        putchar('\n');
    }
}

void clearCanvas(PixelArt *art) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            art->canvas[y][x] = ' ';
        }
    }
}

void setPixel(PixelArt *art, int x, int y, char c) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        art->canvas[y][x] = c;
    }
}

void generateRandomArt(PixelArt *art) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int randomIndex = rand() % (sizeof(ASCII_CHARS) - 1);
            art->canvas[y][x] = ASCII_CHARS[randomIndex];
        }
    }
}

void createGradientArt(PixelArt *art) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int brightness = (x * 255 / (WIDTH - 1)) * (y * 255 / (HEIGHT - 1)) / 65535;
            int index = brightness * (sizeof(ASCII_CHARS) - 1) / 255;
            art->canvas[y][x] = ASCII_CHARS[index];
        }
    }
}

void createCustomPattern(PixelArt *art) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if ((x + y) % 2 == 0) {
                setPixel(art, x, y, '@');
            } else {
                setPixel(art, x, y, '.');
            }
        }
    }
}

int main() {
    PixelArt art;
    int choice;

    srand(time(NULL));

    while (1) {
        printf("Pixel Art Generator:\n");
        printf("1. Random Art\n");
        printf("2. Gradient Art\n");
        printf("3. Custom Pattern\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        
        clearCanvas(&art);
        
        switch (choice) {
            case 1:
                generateRandomArt(&art);
                break;
            case 2:
                createGradientArt(&art);
                break;
            case 3:
                createCustomPattern(&art);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }
        
        drawPixelArt(&art);
        printf("\nPress Enter to continue...\n");
        while(getchar() != '\n'); // Flush input buffer
        getchar(); // Wait for user to press Enter
    }

    return 0;
}