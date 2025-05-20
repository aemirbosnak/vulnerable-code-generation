//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define color codes
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

// Function to convert color code to color name
char* color_code_to_name(int code) {
    switch (code) {
        case BLACK:
            return "BLACK";
        case RED:
            return "RED";
        case GREEN:
            return "GREEN";
        case YELLOW:
            return "YELLOW";
        case BLUE:
            return "BLUE";
        case MAGENTA:
            return "MAGENTA";
        case CYAN:
            return "CYAN";
        case WHITE:
            return "WHITE";
        default:
            return "UNKNOWN";
    }
}

// Function to convert color name to color code
int name_to_color_code(char* name) {
    if (strcmp(name, "BLACK") == 0) {
        return BLACK;
    } else if (strcmp(name, "RED") == 0) {
        return RED;
    } else if (strcmp(name, "GREEN") == 0) {
        return GREEN;
    } else if (strcmp(name, "YELLOW") == 0) {
        return YELLOW;
    } else if (strcmp(name, "BLUE") == 0) {
        return BLUE;
    } else if (strcmp(name, "MAGENTA") == 0) {
        return MAGENTA;
    } else if (strcmp(name, "CYAN") == 0) {
        return CYAN;
    } else if (strcmp(name, "WHITE") == 0) {
        return WHITE;
    } else {
        return -1;
    }
}

int main() {
    int choice;
    char input[20];

    do {
        printf("C Color Code Converter\n");
        printf("1. Convert color code to color name\n");
        printf("2. Convert color name to color code\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter color code: ");
                scanf("%s", input);
                printf("Color name: %s\n", color_code_to_name(atoi(input)));
                break;
            case 2:
                printf("Enter color name: ");
                scanf("%s", input);
                printf("Color code: %d\n", name_to_color_code(input));
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}