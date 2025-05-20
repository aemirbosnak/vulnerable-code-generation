//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

// Define a pixel structure
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Create a simple image
Pixel image[HEIGHT][WIDTH];

// Function prototypes
void load_image();
void display_image(int x1, int y1, int x2, int y2);
void apply_filter(int choice, int x1, int y1, int x2, int y2);
void change_color(int x, int y, unsigned char r, unsigned char g, unsigned char b);
void process_choice();

int main() {
    load_image();
    process_choice();
    return 0;
}

// Load the image with some default colors
void load_image() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x].r = (unsigned char)(x * 51); // Red gradient
            image[y][x].g = (unsigned char)(y * 51); // Green gradient
            image[y][x].b = 0; // No blue for simplicity
        }
    }
}

// Display the portion of the image defined by (x1, y1) and (x2, y2) recursively
void display_image(int x1, int y1, int x2, int y2) {
    if (y1 > y2) return; // Base case for row limit
    if (x1 <= x2) {
        printf("RGB(%d, %d, %d) ", image[y1][x1].r, image[y1][x1].g, image[y1][x1].b);
        display_image(x1 + 1, y1, x2, y2); // Recursive call moving to the next column
    } else {
        printf("\n");
        display_image(0, y1 + 1, x2, y2); // Move to the next row
    }
}

// Function to apply a filter to the image based on user choice
void apply_filter(int choice, int x1, int y1, int x2, int y2) {
    if (y1 > y2) return; // Base case for row limit
    if (x1 <= x2) {
        if (choice == 1) { // Grayscale filter
            unsigned char gray = (image[y1][x1].r + image[y1][x1].g + image[y1][x1].b) / 3;
            change_color(x1, y1, gray, gray, gray);
        } else if (choice == 2) { // Inversion filter
            change_color(x1, y1, 255 - image[y1][x1].r, 255 - image[y1][x1].g, 255 - image[y1][x1].b);
        }
        apply_filter(choice, x1 + 1, y1, x2, y2); // Recursive call moving to the next column
    } else {
        apply_filter( choice, 0, y1 + 1, x2, y2); // Move to the next row
    }
}

// Change the color of a single pixel
void change_color(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    image[y][x].r = r;
    image[y][x].g = g;
    image[y][x].b = b;
}

// Get user choice for the operation
void process_choice() {
    int choice;
    printf("Welcome to the Simple Image Editor!\n");
    printf("Choose an operation:\n");
    printf("1. Display Image\n");
    printf("2. Apply Grayscale Filter\n");
    printf("3. Apply Inversion Filter\n");
    printf("0. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("Displaying Image:\n");
                display_image(0, 0, WIDTH - 1, HEIGHT - 1);
                break;
            case 2:
                apply_filter(1, 0, 0, WIDTH - 1, HEIGHT - 1);
                printf("Applied Grayscale Filter. New Image:\n");
                display_image(0, 0, WIDTH - 1, HEIGHT - 1);
                break;
            case 3:
                apply_filter(2, 0, 0, WIDTH - 1, HEIGHT - 1);
                printf("Applied Inversion Filter. New Image:\n");
                display_image(0, 0, WIDTH - 1, HEIGHT - 1);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}