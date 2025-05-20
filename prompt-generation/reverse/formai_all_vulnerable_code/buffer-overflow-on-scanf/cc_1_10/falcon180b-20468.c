//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 64

// Define the color codes
#define BLACK 0
#define WHITE 7
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define CYAN 5
#define MAGENTA 6

int main() {
    char color_name[MAX_COLOR_NAME_LENGTH];
    int color_code;

    // Get the color name from the user
    printf("Enter a color name: ");
    scanf("%s", color_name);

    // Convert the color name to uppercase
    for (int i = 0; i < strlen(color_name); i++) {
        color_name[i] = toupper(color_name[i]);
    }

    // Convert the color name to a color code
    if (strcmp(color_name, "BLACK") == 0) {
        color_code = BLACK;
    } else if (strcmp(color_name, "WHITE") == 0) {
        color_code = WHITE;
    } else if (strcmp(color_name, "RED") == 0) {
        color_code = RED;
    } else if (strcmp(color_name, "GREEN") == 0) {
        color_code = GREEN;
    } else if (strcmp(color_name, "BLUE") == 0) {
        color_code = BLUE;
    } else if (strcmp(color_name, "YELLOW") == 0) {
        color_code = YELLOW;
    } else if (strcmp(color_name, "CYAN") == 0) {
        color_code = CYAN;
    } else if (strcmp(color_name, "MAGENTA") == 0) {
        color_code = MAGENTA;
    } else {
        printf("Invalid color name!\n");
        return 1;
    }

    // Print the color code
    printf("The color code for %s is %d\n", color_name, color_code);

    return 0;
}