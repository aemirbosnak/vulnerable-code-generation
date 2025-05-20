//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

// Function to print the ASCII art
void print_ascii(char* ascii_art) {
    int i = 0;
    while (ascii_art[i]!= '\0') {
        printf("%c", ascii_art[i]);
        i++;
    }
}

// Function to clear the console
void clear_console() {
    system("clear");
}

// Function to get user input for width and height
void get_input(int* width, int* height) {
    char input[10];
    printf("Enter the width (1-80): ");
    scanf("%s", input);
    *width = atoi(input);

    printf("Enter the height (1-25): ");
    scanf("%s", input);
    *height = atoi(input);
}

// Function to generate the ASCII art
void generate_ascii(char* ascii_art, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ascii_art[i * width + j] = rand() % 94 + 33; // ASCII art characters are between 33 and 126
        }
    }
}

int main() {
    int width, height;
    char ascii_art[MAX_WIDTH * MAX_HEIGHT];

    get_input(&width, &height);

    clear_console();

    generate_ascii(ascii_art, width, height);

    printf("ASCII art generated:\n");
    print_ascii(ascii_art);

    return 0;
}