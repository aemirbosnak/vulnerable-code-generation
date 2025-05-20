//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
#define MAX_ATTEMPTS 3

void printWelcomeMessage() {
    printf("=====================================\n");
    printf(" Welcome to the Area Calculator 3000!\n");
    printf(" Where Geometry Meets Hilarity!\n");
    printf("=====================================\n");
}

void printGoodbyeMessage() {
    printf("=====================================\n");
    printf(" Thanks for using the Area Calculator!\n");
    printf(" Remember: Math is fun, but so is cake!\n");
    printf("=====================================\n");
}

float calculateCircleArea(float radius) {
    return PI * radius * radius;
}

float calculateSquareArea(float side) {
    return side * side;
}

float calculateTriangleArea(float base, float height) {
    return (base * height) / 2;
}

float calculateRectangleArea(float length, float width) {
    return length * width;
}

void menu() {
    printf("Choose a shape to calculate the area:\n");
    printf("1. Circle\n");
    printf("2. Square\n");
    printf("3. Triangle\n");
    printf("4. Rectangle\n");
    printf("5. Exit\n");
}

int main() {
    printWelcomeMessage();

    int choice;
    float area;
    float radius, side, base, height, length, width;

    while (1) {
        menu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Great choice! How big is your circle? (Enter radius): ");
                scanf("%f", &radius);
                area = calculateCircleArea(radius);
                printf("The area of a circle with radius %.2f is %.2f.\n", radius, area);
                break;

            case 2:
                printf("You chose a square! What's the length of a side? ");
                scanf("%f", &side);
                area = calculateSquareArea(side);
                printf("The area of a square with side %.2f is %.2f.\n", side, area);
                break;

            case 3:
                printf("Triangle time! What's the base length? ");
                scanf("%f", &base);
                printf("And the height? ");
                scanf("%f", &height);
                area = calculateTriangleArea(base, height);
                printf("The area of a triangle with base %.2f and height %.2f is %.2f.\n", base, height, area);
                break;

            case 4:
                printf("Rectangle alert! Enter the length: ");
                scanf("%f", &length);
                printf("Now, what's the width? ");
                scanf("%f", &width);
                area = calculateRectangleArea(length, width);
                printf("The area of a rectangle with length %.2f and width %.2f is %.2f.\n", length, width, area);
                break;

            case 5:
                printGoodbyeMessage();
                exit(0);

            default:
                printf("Oops! That's not a valid choice. Try again!\n");
        }

        printf("\nWould you like to calculate another area? (y/n): ");
        char response;
        int attempts = 0;
        
        while (attempts < MAX_ATTEMPTS) {
            scanf(" %c", &response);
            if (response == 'y' || response == 'Y') {
                printf("Awesome! Let's keep calculating!\n");
                break;
            } else if (response == 'n' || response == 'N') {
                printGoodbyeMessage();
                exit(0);
            } else {
                attempts++;
                printf("That's not a 'y' or 'n'! Try again (Attempt %d of %d): ", attempts, MAX_ATTEMPTS);
            }
        }
        
        if (attempts == MAX_ATTEMPTS) {
            printf("Too many invalid attempts! Exiting...\n");
            break;
        }
    }

    return 0;
}