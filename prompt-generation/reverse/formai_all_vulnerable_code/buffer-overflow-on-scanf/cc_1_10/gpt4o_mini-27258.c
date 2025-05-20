//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 16
#define HEIGHT 16

// Function to print the pixel art
void print_pixel_art(int art[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (art[y][x] == 1) {
                printf("⬜");  // White square for filled pixel
            } else {
                printf("⬛");  // Black square for empty pixel
            }
        }
        printf("\n");
    }
}

// Function to create a simple pixel art of a smiley face
void create_smiley_face(int art[HEIGHT][WIDTH]) {
    // Initializing all pixels to 0 (black)
    memset(art, 0, sizeof(int) * HEIGHT * WIDTH);

    // Drawing the face
    for (int y = 4; y < 12; y++) {
        for (int x = 2; x < 14; x++) {
            art[y][x] = 1;  // Fill the face area
        }
    }

    // Eyes
    art[6][5] = 0; // Left Eye
    art[6][10] = 0; // Right Eye

    // Smile
    for (int x = 5; x <= 10; x++) {
        art[9][x] = 0; // Making a smile
    }
    art[8][5] = 0;  // Left side of the smile
    art[8][10] = 0; // Right side of the smile
}

// Function to create a house pixel art
void create_house(int art[HEIGHT][WIDTH]) {
    // Initializing all pixels to 0 (black)
    memset(art, 0, sizeof(int) * HEIGHT * WIDTH);

    // Drawing the base of the house
    for (int y = 8; y < 12; y++) {
        for (int x = 3; x < 13; x++) {
            art[y][x] = 1;  // Fill the house base
        }
    }

    // Drawing the roof
    for (int y = 4; y < 8; y++) {
        for (int x = 6 - (y - 4); x <= 6 + (y - 4); x++) {
            art[y][x] = 1;  // Fill the roof area
        }
    }

    // Drawing a door
    for (int y = 10; y < 12; y++) {
        for (int x = 6; x < 8; x++) {
            art[y][x] = 0;  // Clear pixels for the door
        }
    }
}

// Function to generate random pixel art
void create_random_art(int art[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            art[y][x] = rand() % 2; // Randomly set pixel
        }
    }
}

// Main function that drives the pixel art creation
int main() {
    int pixel_art[HEIGHT][WIDTH];
    int choice;

    printf("Welcome to the Pixel Art Generator!\n");
    printf("Choose an option:\n");
    printf("1. Smiley Face\n");
    printf("2. House\n");
    printf("3. Random Art\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            create_smiley_face(pixel_art);
            printf("Here is a Smiley Face:\n");
            break;
        case 2:
            create_house(pixel_art);
            printf("Here is a House:\n");
            break;
        case 3:
            create_random_art(pixel_art);
            printf("Here is some Random Art:\n");
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return 1;
    }

    print_pixel_art(pixel_art);
    return 0;
}