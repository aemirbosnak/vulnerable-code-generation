//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 8
#define HEIGHT 8

void clearScreen() {
    printf("\033[2J"); // Clear the entire screen
}

void setCursorPosition(int x, int y) {
    printf("\033[%d;%dH", y, x); // Move the cursor to the specified position
}

void drawPixel(int x, int y, char color) {
    setCursorPosition(x, y);
    printf("\033[%dm%s", color, "█"); // Print the pixel with the chosen color
}

void drawRectangle(int x, int y, int width, int height, char fill, char border) {
    for (int i = 0; i < height; i++) {
        drawPixel(x, y + i, border);
        for (int j = 0; j < width; j++) {
            if (i < height - 1 || j < width - 1) {
                drawPixel(x + j, y + i, fill);
            }
        }
    }

    for (int i = 0; i < height; i++) {
        drawPixel(x + width, y + i, border);
    }
}

int main() {
    char userColor;
    int userX, userY;

    clearScreen();

    // Draw a blank canvas
    drawRectangle(1, 1, WIDTH, HEIGHT, ' ', ' ');

    while (1) {
        printf("\033[1;1H"); // Move the cursor to the top-left corner
        printf("Enter the x and y coordinates of the pixel you want to color (or q to quit): ");
        scanf("%d %d", &userX, &userY);

        if (userX < 1 || userX > WIDTH || userY < 1 || userY > HEIGHT) {
            printf("Invalid coordinates. Please try again.\n");
            continue;
        }

        printf("Enter the color for the pixel (enter a number from 0-7): ");
        scanf(" %c", &userColor);

        if (userColor < '0' || userColor > '7') {
            printf("Invalid color. Please try again.\n");
            continue;
        }

        // Clear the old pixel
        drawPixel(userX, userY, ' ');

        // Set the new pixel
        drawPixel(userX, userY, userColor + 48);
    }

    return 0;
}