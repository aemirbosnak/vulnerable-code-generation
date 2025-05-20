//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

// Function to print vibrant spiral pattern
void print_spiral(int n) {
    int i, j, k = 1;
    int max_chars = 2 * n - 1;

    for (i = 0; i < max_chars; i++) {
        for (j = 0; j < max_chars; j++) {
            if (j == i || j == max_chars - i - 1) {
                // Print the outer diamonds
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to print mesmerizing wave pattern
void print_wave(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 20; j++) {
            int wave = (i + j) % 4;
            if (wave == 0) {
                printf(" * ");
            } else if (wave == 1) {
                printf("    ");
            } else if (wave == 2) {
                printf(" ~ ");
            } else {
                printf(" ~ ");
            }
        }
        printf("\n");
    }
}

// Function to print a joyful square pattern
void print_square(int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf(" # ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, size;

    // Welcome message
    printf("Welcome to the Exciting Pattern Printer!\n");
    printf("Choose a pattern to print:\n");
    printf("1. Spiral Pattern\n");
    printf("2. Wave Pattern\n");
    printf("3. Square Pattern\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    // Get the size of the pattern from the user
    printf("Enter the size (odd number preferred for Spiral): ");
    scanf("%d", &size);

    switch (choice) {
        case 1:
            printf("\nHere is your Spiral Pattern:\n");
            print_spiral(size);
            break;
        case 2:
            printf("\nHere is your Wave Pattern:\n");
            print_wave(size);
            break;
        case 3:
            printf("\nHere is your Joyful Square Pattern:\n");
            print_square(size);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    // Closing message
    printf("\nThank you for using the Exciting Pattern Printer! Hope you enjoyed! Bye!\n");
    
    return 0;
}