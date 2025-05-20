//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

char pixelArt[HEIGHT][WIDTH + 1] = {
    "                    ",
    "                    ",
    "        **          ",
    "      ******        ",
    "    **      **      ",
    "   **        **     ",
    " *****************   ",
    " ***           ***   ",
    "  ***         ***    ",
    "   ***       ***     ",
    "      ********       ",
    "                    ",
};

void clearScreen() {
    printf("\033[H\033[J");
}

void drawPixelArt() {
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", pixelArt[i]);
    }
}

void randomizePixelArt() {
    srand(time(0));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = (rand() % 2) ? '*' : ' ';
        }
        pixelArt[i][WIDTH] = '\0'; // Null-terminate the string
    }
}

void savePixelArtToFile(const char* filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < HEIGHT; i++) {
        fprintf(file, "%s\n", pixelArt[i]);
    }

    fclose(file);
}

void displayMenu() {
    printf("Pixel Art Generator\n");
    printf("--------------------\n");
    printf("1. Generate Random Pixel Art\n");
    printf("2. Display Pixel Art\n");
    printf("3. Save Pixel Art to File\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    while (1) {
        clearScreen();
        displayMenu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                randomizePixelArt();
                break;
            case 2:
                clearScreen();
                drawPixelArt();
                printf("\nPress enter to return to the menu...");
                while (getchar() != '\n'); // Wait for user to press enter
                getchar(); // Clear the newline
                break;
            case 3: {
                char filename[100];
                printf("Enter filename to save (e.g., pixel_art.txt): ");
                scanf("%s", filename);
                savePixelArtToFile(filename);
                printf("Pixel art saved to %s\nPress enter to return to the menu...", filename);
                getchar(); // Clear the newline
                getchar(); // Wait for user to press enter
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}