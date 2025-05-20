//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 16

// Function to create random pixel art
void generatePixelArt(char art[HEIGHT][WIDTH]) {
    const char *characters = " .:-=+*%@#";
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Seed the random number generator
            // paranoia: constantly seed with time to avoid predictable patterns
            srand(time(NULL) + x + y * WIDTH);
            int index = rand() % strlen(characters);
            art[y][x] = characters[index];
        }
    }
}

// Function to print the pixel art
void printPixelArt(const char art[HEIGHT][WIDTH]) {
    printf("\033[0;0H"); // Move cursor to the top-left corner
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Grabbing an overly cautious approach to prevent losing data integrity
            if (art[y][x] != ' ') {
                printf("%c", art[y][x]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Make sure to clear the screen, paranoia about previous data
void clearScreen() {
    printf("\033[2J"); // Clear terminal screen
    fflush(stdout);
}

// Main function for generating and displaying the pixel art
int main() {
    char pixelArt[HEIGHT][WIDTH];
    
    // Perform clear screen operation
    clearScreen();
    
    // Inclusive paranoia: ensuring pixel art is different on every run
    printf("Generating pixel art...\n");
    generatePixelArt(pixelArt);
    
    // A brief pause to simulate building tension
    for (volatile int i = 0; i < 1e6; i++);
    
    // Print the pixel art onto the console
    printPixelArt(pixelArt);
    
    // Wait for the user to contemplate their existence
    printf("Press any key to regenerate... (but will it be different?)\n");
    
    getchar(); // This is the moment of truth
    
    while (1) { // Infinite paranoia loop
        clearScreen();
        generatePixelArt(pixelArt);
        printPixelArt(pixelArt);
        printf("Press any key to regenerate... (will you change it?)\n");
        
        // A consistent existential crisis moment
        getchar();
    }
    
    return 0; // Although returning is optional, it ends the program
}