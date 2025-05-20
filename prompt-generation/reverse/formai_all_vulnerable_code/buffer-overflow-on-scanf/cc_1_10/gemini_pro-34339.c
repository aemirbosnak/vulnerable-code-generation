//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Flower colors
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"

// Flower types
#define ROSE "🌹"
#define LILY "🌷"
#define SUNFLOWER "🌻"
#define DAISY "🌼"
#define VIOLET "🌺"

// Garden size
#define GARDEN_SIZE 10

// Initialize the garden
char garden[GARDEN_SIZE][GARDEN_SIZE];

// Function to plant a flower
void plantFlower(int x, int y, char type) {
    // Check if the location is valid
    if (x < 0 || x >= GARDEN_SIZE || y < 0 || y >= GARDEN_SIZE) {
        printf("Invalid location! Please choose a location within the garden.\n");
        return;
    }

    // Plant the flower
    switch (type) {
        case 'r':
            garden[x][y] = RED ROSE;
            break;
        case 'g':
            garden[x][y] = GREEN LILY;
            break;
        case 'y':
            garden[x][y] = YELLOW SUNFLOWER;
            break;
        case 'b':
            garden[x][y] = BLUE DAISY;
            break;
        case 'm':
            garden[x][y] = MAGENTA VIOLET;
            break;
        default:
            printf("Invalid flower type! Please choose a valid flower type (r/g/y/b/m).\n");
            return;
    }

    // Print a success message
    printf("You planted a beautiful %s at location (%d, %d).\n", garden[x][y], x, y);
}

// Function to display the garden
void displayGarden() {
    // Clear the screen
    system("clear");

    // Print the garden
    printf("\nYour cheerful garden:\n\n");
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            printf("%s ", garden[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the garden with empty spaces
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            garden[i][j] = ' ';
        }
    }

    // Welcome message
    printf("\nWelcome to your virtual garden! Let's make it bloom with beautiful flowers.\n\n");

    // Plant some flowers
    plantFlower(2, 3, 'r');  // Red rose at (2, 3)
    plantFlower(5, 7, 'g');  // Green lily at (5, 7)
    plantFlower(1, 8, 'y');  // Yellow sunflower at (1, 8)
    plantFlower(7, 2, 'b');  // Blue daisy at (7, 2)
    plantFlower(3, 6, 'm');  // Magenta violet at (3, 6)

    // Display the garden
    displayGarden();

    // Invite the user to plant more flowers
    int x, y;
    char type;
    while (1) {
        printf("\nWould you like to plant another flower? (y/n) ");
        char choice = getchar();
        getchar();  // Consume the newline character

        if (choice == 'y') {
            printf("Enter the x coordinate: ");
            scanf("%d", &x);
            printf("Enter the y coordinate: ");
            scanf("%d", &y);
            printf("Enter the flower type (r/g/y/b/m): ");
            scanf(" %c", &type);
            plantFlower(x, y, type);
            displayGarden();
        } else if (choice == 'n') {
            printf("\nThank you for gardening with us! Enjoy the beauty of your virtual garden.\n");
            break;
        } else {
            printf("Invalid choice! Please enter 'y' or 'n'.\n");
        }
    }

    return 0;
}