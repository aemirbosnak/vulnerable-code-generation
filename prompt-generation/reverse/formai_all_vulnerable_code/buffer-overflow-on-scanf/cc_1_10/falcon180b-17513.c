//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>

// Define color codes
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

// Function to print color code
void print_color(int color_code) {
    switch(color_code) {
        case BLACK:
            printf("\033[0;30m"); // Black color code
            break;
        case RED:
            printf("\033[0;31m"); // Red color code
            break;
        case GREEN:
            printf("\033[0;32m"); // Green color code
            break;
        case YELLOW:
            printf("\033[0;33m"); // Yellow color code
            break;
        case BLUE:
            printf("\033[0;34m"); // Blue color code
            break;
        case MAGENTA:
            printf("\033[0;35m"); // Magenta color code
            break;
        case CYAN:
            printf("\033[0;36m"); // Cyan color code
            break;
        case WHITE:
            printf("\033[0;37m"); // White color code
            break;
        default:
            printf("\033[0m"); // Reset color code
            break;
    }
}

int main() {
    int color_code = WHITE; // Set default color code to white
    char input[100]; // Declare input string

    // Prompt user to enter text
    printf("Enter text: ");
    scanf("%[^\n]", input);

    // Print input text with color code
    printf("\n");
    print_color(color_code);
    printf("Color Code Converter\n");
    printf("\n");
    printf("Original Text:\n");
    printf("\033[0m%s\n", input);

    // Convert input text to uppercase
    for(int i=0; input[i]!='\0'; i++) {
        input[i] = toupper(input[i]);
    }

    // Print converted text with color code
    printf("\n");
    print_color(color_code);
    printf("Converted Text:\n");
    printf("\033[0m%s\n", input);

    return 0;
}