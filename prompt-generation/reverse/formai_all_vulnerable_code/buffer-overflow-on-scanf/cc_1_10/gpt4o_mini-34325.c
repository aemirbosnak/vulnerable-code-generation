//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 16
#define HEIGHT 8

// Function to clear the terminal screen
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to print a pixel art character
void print_pixel_art(char art[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (art[i][j] == '#') {
                printf("\033[1;32m#\033[0m"); // Print green for filled pixel
            } else {
                printf(" "); // Print space for empty pixel
            }
        }
        printf("\n");
    }
}

// Function to create a simple pixel art of a heart
void create_heart(char art[HEIGHT][WIDTH]) {
    const char heart[HEIGHT][WIDTH] = {
        "   ##   ##   ",
        " #### #### ## ",
        "##############",
        "##############",
        " #### #### ## ",
        "   ##   ##   ",
        "     # #     ",
        "      #      "
    };
    
    memcpy(art, heart, sizeof(heart));
}

// Function to create a simple pixel art of a smiley face
void create_smiley(char art[HEIGHT][WIDTH]) {
    const char smiley[HEIGHT][WIDTH] = {
        "   #######    ",
        "  #       #   ",
        " #  O   O  #  ",
        "#     ---    # ",
        " #           #  ",
        "   #     #     ",
        "     #####     ",
        "               "
    };
    
    memcpy(art, smiley, sizeof(smiley));
}

// Function to create a simple pixel art of a house
void create_house(char art[HEIGHT][WIDTH]) {
    const char house[HEIGHT][WIDTH] = {
        "     #     ",
        "    ###    ",
        "   #####   ",
        "  ########  ",
        " ###     ### ",
        "###       ###",
        "###  ##  ### ",
        "#############"
    };
    
    memcpy(art, house, sizeof(house));
}

// Function to display the menu for choosing pixel art
void display_menu() {
    printf("Choose Pixel Art to Display:\n");
    printf("1. Heart\n");
    printf("2. Smiley Face\n");
    printf("3. House\n");
    printf("0. Exit\n");
}

int main() {
    char art[HEIGHT][WIDTH] = {0};
    int choice = -1;

    while (choice != 0) {
        clear_screen();
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_heart(art);
                break;
            case 2:
                create_smiley(art);
                break;
            case 3:
                create_house(art);
                break;
            case 0:
                printf("Exiting the program...\n");
                continue;
            default:
                printf("Invalid choice! Please try again.\n");
                continue;
        }

        clear_screen();
        print_pixel_art(art);
        printf("\nPress Enter to go back to the menu...");
        getchar(); // Clear newline left by previous scanf
        getchar(); // Wait for user input
    }

    return 0;
}