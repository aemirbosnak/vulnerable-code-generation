//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define CHAR_SET_SIZE 62
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?`~"

// Function to generate a random string of given length
char* generate_random_string(int length) {
    char* result = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        result[i] = CHAR_SET[rand() % CHAR_SET_SIZE];
    }
    result[length] = '\0';
    return result;
}

// Function to print the ASCII art
void print_ascii_art(char* ascii_art, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", ascii_art[y * width + x]);
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get user input for width and height
    int width, height;
    printf("Enter the width and height of the ASCII art (between 1 and %d): ", MAX_WIDTH);
    scanf("%d %d", &width, &height);
    if (width <= 0 || width > MAX_WIDTH || height <= 0 || height > MAX_HEIGHT) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Generate the ASCII art
    char* ascii_art = malloc(width * height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char c = CHAR_SET[rand() % CHAR_SET_SIZE];
            ascii_art[y * width + x] = c;
        }
    }

    // Print the ASCII art
    printf("Your ASCII art:\n");
    print_ascii_art(ascii_art, width, height);

    free(ascii_art);
    return 0;
}