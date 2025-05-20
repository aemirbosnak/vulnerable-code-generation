//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void set_color(int color_code);
void reset_color();

int main() {
    int choice;
    char input_text[100];

    do {
        printf("\n\nWelcome to the Color Code Converter!\n");
        printf("Enter your text (up to 100 characters): ");
        scanf("%s", input_text);

        printf("Enter your desired color code (0-7): ");
        scanf("%d", &choice);

        set_color(choice);
        printf("%s", input_text);
        reset_color();

        printf("\n\nDo you want to try again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Function to set color
void set_color(int color_code) {
    switch (color_code) {
        case 0:
            printf("\033[0m"); // Reset color
            break;
        case 1:
            printf("\033[1m"); // Bold
            break;
        case 2:
            printf("\033[2m"); // Dim
            break;
        case 3:
            printf("\033[3m"); // Italic
            break;
        case 4:
            printf("\033[4m"); // Underline
            break;
        case 5:
            printf("\033[5m"); // Blink
            break;
        case 6:
            printf("\033[6m"); // Reverse
            break;
        case 7:
            printf("\033[7m"); // Hidden
            break;
        default:
            printf("\033[0m"); // Reset color
    }
}

// Function to reset color
void reset_color() {
    printf("\033[0m"); // Reset color
}