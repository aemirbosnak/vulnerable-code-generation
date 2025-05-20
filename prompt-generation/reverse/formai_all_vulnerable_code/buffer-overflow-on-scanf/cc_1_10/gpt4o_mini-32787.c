//GPT-4o-mini DATASET v1.0 Category: Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHAPES 4
#define NAME_LENGTH 20

void greet();
void display_menu();
void shape_functionality(const char *shape);
void shape_selection();

void greet() {
    printf("Welcome to the Shape Shifter Game!\n");
    printf("You can change your shape and accomplish different tasks.\n");
}

void display_menu() {
    printf("\nAvailable Shapes:\n");
    printf("1. Circle\n");
    printf("2. Square\n");
    printf("3. Triangle\n");
    printf("4. Star\n");
    printf("5. Exit\n");
}

void shape_functionality(const char *shape) {
    if (strcmp(shape, "Circle") == 0) {
        printf("You are now a Circle! Rolling through the obstacles...\n");
        printf("You can roll over small barriers and pass smoothly!\n");
    } else if (strcmp(shape, "Square") == 0) {
        printf("You are now a Square! Sturdy and strong...\n");
        printf("You can build structures and provide stability!\n");
    } else if (strcmp(shape, "Triangle") == 0) {
        printf("You are now a Triangle! Sharp and pointy...\n");
        printf("You can navigate through narrow spaces and pierce through the darkness!\n");
    } else if (strcmp(shape, "Star") == 0) {
        printf("You are now a Star! Bright and shining...\n");
        printf("You can light up dark areas and guide the way!\n");
    } else {
        printf("Unknown shape!\n");
    }
}

void shape_selection() {
    int choice;
    const char *shapes[MAX_SHAPES] = {"Circle", "Square", "Triangle", "Star"};

    while (1) {
        display_menu();
        printf("Select your shape (1-5): ");
        scanf("%d", &choice);
        
        if (choice == 5) {
            printf("Thank you for playing the Shape Shifter Game!\n");
            break;
        } else if (choice >= 1 && choice <= MAX_SHAPES) {
            shape_functionality(shapes[choice - 1]);
        } else {
            printf("Invalid choice! Please choose again.\n");
        }
    }
}

int main() {
    greet();
    shape_selection();
    
    return 0;
}