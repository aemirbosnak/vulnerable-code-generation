//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: puzzling
#include <stdio.h>
#include <math.h>

void displayWelcome() {
    printf("Welcome to the Area Explorer!\n");
    printf("Dare to enter the realm of shapes and discover their areas?\n");
}

void drawChoices() {
    printf("Choose your mystical shape:\n");
    printf("1. Circle\n");
    printf("2. Triangle\n");
    printf("3. Rectangle\n");
    printf("4. Square\n");
    printf("5. Exit\n");
}

float calculateCircleArea(float radius) {
    return M_PI * radius * radius;
}

float calculateTriangleArea(float base, float height) {
    return (base * height) / 2;
}

float calculateRectangleArea(float length, float width) {
    return length * width;
}

float calculateSquareArea(float side) {
    return side * side;
}

void processChoice(int choice) {
    switch (choice) {
        case 1: {
            float radius;
            printf("Ah, the circle! Please unveil its radius: ");
            scanf("%f", &radius);
            printf("The area of your circle is: %.2f\n", calculateCircleArea(radius));
            break;
        }
        case 2: {
            float base, height;
            printf("The triangle, a symbol of balance! Provide base and height: ");
            scanf("%f %f", &base, &height);
            printf("The area of your triangle is: %.2f\n", calculateTriangleArea(base, height));
            break;
        }
        case 3: {
            float length, width;
            printf("A rectangle, so intriguing! Please share the length and width: ");
            scanf("%f %f", &length, &width);
            printf("The area of your rectangle is: %.2f\n", calculateRectangleArea(length, width));
            break;
        }
        case 4: {
            float side;
            printf("The square, so perfect in symmetry! Reveal the side length: ");
            scanf("%f", &side);
            printf("The area of your square is: %.2f\n", calculateSquareArea(side));
            break;
        }
        case 5:
            printf("Retreating from the land of shapes... Until we meet again!\n");
            break;
        default:
            printf("Alas! An unrecognized choice! Please try again.\n");
    }
}

int main() {
    displayWelcome();

    int choice = -1;
    while (choice != 5) {
        drawChoices();
        printf("What is your choice, brave explorer? ");
        scanf("%d", &choice);
        processChoice(choice);
    }

    return 0;
}