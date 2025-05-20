//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 30

void printAsciiArt(char text[]);
int randomRange(int min, int max);
void printRow(char row[], int length);

int main() {

    char userText[100];
    printf("Please enter the text (max 100 chars): ");
    scanf("%[^\n]s", userText);

    printAsciiArt(userText);

    return 0;
}

// Generates and prints the ASCII art for a given text
void printAsciiArt(char text[]) {
    int length = strlen(text);
    char asciiArt[HEIGHT][WIDTH];
    int row, column, charIndex, asciiValue;

    for (row = 0; row < HEIGHT; row++) {
        for (column = 0; column < WIDTH; column++) {
            asciiArt[row][column] = ' ';
        }
    }

    for (charIndex = 0; charIndex < length; charIndex++) {
        asciiValue = (int) text[charIndex];
        if (asciiValue >= 33 && asciiValue <= 126) {
            int imageWidth = randomRange(8, 16);
            int imageHeight = randomRange(8, 16);

            char image[imageHeight][imageWidth];
            for (row = 0; row < imageHeight; row++) {
                for (column = 0; column < imageWidth; column++) {
                    image[row][column] = randomRange(33, 126);
                }
            }

            int x = randomRange(0, WIDTH - imageWidth);
            int y = randomRange(0, HEIGHT - imageHeight);
            for (row = 0; row < imageHeight; row++) {
                for (column = 0; column < imageWidth; column++) {
                    asciiArt[y + row][x + column] = image[row][column];
                }
            }
        }
    }

    for (row = 0; row < HEIGHT; row++) {
        printRow(asciiArt[row], WIDTH);
    }
}

// Generates a random number between min and max (inclusive)
int randomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Prints a single row of the ASCII art with proper formatting
void printRow(char row[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        putchar(row[i]);
    }
    putchar('\n');
}