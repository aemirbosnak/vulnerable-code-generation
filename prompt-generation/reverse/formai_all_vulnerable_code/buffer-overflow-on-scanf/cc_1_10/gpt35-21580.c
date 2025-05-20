//FormAI DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define color codes
#define BLACK "\x1B[30m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

// Function to print out color options
void displayMenu() {
    printf("\nChoose a color to convert to medieval style:\n");
    printf("1. Black\n2. Red\n3. Green\n4. Yellow\n5. Blue\n6. Magenta\n7. Cyan\n8. White\n9. Exit\n");
}

// Function to convert color code to medieval style
char* convertToMedieval(char* color) {
    char* newColor = (char*)malloc(sizeof(char) * strlen(color));
    int i;

    for(i=0; i<strlen(color); i++) {
        newColor[i] = color[i] + 50; // add 50 to each character
    }

    newColor[i] = '\0'; // add null terminator

    return newColor;
}

// Main function
int main() {
    int choice;

    printf("Welcome to the Medieval Color Code Converter!\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Medieval Black: %s%s%s\n", convertToMedieval(BLACK), "█████", WHITE);
                break;
            case 2:
                printf("Medieval Red: %s%s%s\n", convertToMedieval(RED), "█████", WHITE);
                break;
            case 3:
                printf("Medieval Green: %s%s%s\n", convertToMedieval(GREEN), "█████", WHITE);
                break;
            case 4:
                printf("Medieval Yellow: %s%s%s\n", convertToMedieval(YELLOW), "█████", WHITE);
                break;
            case 5:
                printf("Medieval Blue: %s%s%s\n", convertToMedieval(BLUE), "█████", WHITE);
                break;
            case 6:
                printf("Medieval Magenta: %s%s%s\n", convertToMedieval(MAGENTA), "█████", WHITE);
                break;
            case 7:
                printf("Medieval Cyan: %s%s%s\n", convertToMedieval(CYAN), "█████", WHITE);
                break;
            case 8:
                printf("Medieval White: %s%s%s\n", convertToMedieval(WHITE), "█████", WHITE);
                break;
            case 9:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1-9.\n");
                break;
        }
    } while(choice != 9);

    return 0;
}