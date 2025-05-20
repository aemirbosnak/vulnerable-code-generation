//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

// Function to print the canvas
void printCanvas(char canvas[HEIGHT][WIDTH]) {
    system("clear");  // Use 'cls' on Windows
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}

// Function to create a pixel art canvas
void createPixelArt(char canvas[HEIGHT][WIDTH]) {
    // Filling the canvas with white space
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Drawing a simple sunny scene
    for (int i = 10; i < 30; i++) {
        canvas[5][i] = '*';  // Sun
        canvas[4][i] = '*';
        canvas[6][i] = '*';
        canvas[5][9] = '*';
        canvas[5][20] = '*';
    }

    // Drawing some clouds
    for (int i = 5; i < 12; i++) {
        canvas[2][i] = '*';
    }
    
    // Drawing the ground
    for (int i = 0; i < WIDTH; i++) {
        canvas[HEIGHT - 1][i] = '-';
    }

    // Drawing some trees
    canvas[HEIGHT - 2][5] = '|';
    canvas[HEIGHT - 3][5] = 'A';
    canvas[HEIGHT - 4][5] = 'A';
    
    canvas[HEIGHT - 2][30] = '|';
    canvas[HEIGHT - 3][30] = 'A';
    canvas[HEIGHT - 4][30] = 'A';
}

// Function to generate random pixel art
void generateRandomArt(char canvas[HEIGHT][WIDTH]) {
    srand(time(NULL));  // Seed for random number generation
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int randNum = rand() % 4;
            switch(randNum) {
                case 0:
                    canvas[i][j] = ' ';
                    break;
                case 1:
                    canvas[i][j] = '.';
                    break;
                case 2:
                    canvas[i][j] = '*';
                    break;
                case 3:
                    canvas[i][j] = '#';
                    break;
            }
        }
    }
}

// Main function
int main() {
    char canvas[HEIGHT][WIDTH];
    int choice;

    printf("Welcome to the Pixel Art Generator!\n");
    printf("Choose an option:\n");
    printf("1. Generate a simple sunny scene\n");
    printf("2. Generate random pixel art\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        createPixelArt(canvas);
    } else if (choice == 2) {
        generateRandomArt(canvas);
    } else {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    printCanvas(canvas);
    printf("Press Enter to exit...\n");
    getchar();
    getchar();  // Wait for an input before closing

    return 0;
}