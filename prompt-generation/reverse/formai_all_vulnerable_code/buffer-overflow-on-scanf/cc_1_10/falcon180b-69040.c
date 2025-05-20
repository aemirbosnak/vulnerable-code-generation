//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

// Function to print the color code in a cheerful style
void print_color_code(int color_code) {
    switch(color_code) {
        case BLACK:
            printf("\e[30m");
            break;
        case RED:
            printf("\e[31m");
            break;
        case GREEN:
            printf("\e[32m");
            break;
        case YELLOW:
            printf("\e[33m");
            break;
        case BLUE:
            printf("\e[34m");
            break;
        case MAGENTA:
            printf("\e[35m");
            break;
        case CYAN:
            printf("\e[36m");
            break;
        case WHITE:
            printf("\e[37m");
            break;
        default:
            printf("\e[0m");
            break;
    }
}

int main() {
    int choice;
    char input_string[100];

    // Get user input for the string to convert
    printf("Enter a string to convert to color code: ");
    scanf("%s", input_string);

    // Convert the string to color code
    for(int i=0; i<strlen(input_string); i++) {
        if(input_string[i] == '\n') {
            printf("\n");
        } else {
            printf("\e[0m%c", input_string[i]);
        }
    }

    // Print the color code in a cheerful style
    printf("\n\n\e[0m");
    printf("BLACK\e[30m\e[0m");
    printf("RED\e[31m\e[0m");
    printf("GREEN\e[32m\e[0m");
    printf("YELLOW\e[33m\e[0m");
    printf("BLUE\e[34m\e[0m");
    printf("MAGENTA\e[35m\e[0m");
    printf("CYAN\e[36m\e[0m");
    printf("WHITE\e[37m\e[0m");

    // Get user input for the color code
    printf("\n\nEnter the color code to use: ");
    scanf("%d", &choice);

    printf("\n\nThe color code for %s is: ", input_string);
    print_color_code(choice);
    printf("%s\e[0m\n", input_string);

    return 0;
}