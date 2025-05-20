//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void calculate_circle();
void calculate_rectangle();
void calculate_triangle();
double get_positive_input(char *prompt);

int main() {
    int choice;

    do {
        printf("\nGeometric Shape Calculator\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_circle();
                break;
            case 2:
                calculate_rectangle();
                break;
            case 3:
                calculate_triangle();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void calculate_circle() {
    double radius = get_positive_input("Enter the radius of the circle: ");
    double area = PI * radius * radius;
    double perimeter = 2 * PI * radius;

    printf("Circle Radius: %.2f\n", radius);
    printf("Area of Circle: %.2f\n", area);
    printf("Perimeter of Circle: %.2f\n", perimeter);
}

void calculate_rectangle() {
    double length = get_positive_input("Enter the length of the rectangle: ");
    double width = get_positive_input("Enter the width of the rectangle: ");
    double area = length * width;
    double perimeter = 2 * (length + width);

    printf("Rectangle Length: %.2f, Width: %.2f\n", length, width);
    printf("Area of Rectangle: %.2f\n", area);
    printf("Perimeter of Rectangle: %.2f\n", perimeter);
}

void calculate_triangle() {
    double base = get_positive_input("Enter the base of the triangle: ");
    double height = get_positive_input("Enter the height of the triangle: ");
    double area = 0.5 * base * height;

    double sideA = get_positive_input("Enter the length of side A: ");
    double sideB = get_positive_input("Enter the length of side B: ");
    double sideC = get_positive_input("Enter the length of side C: ");
    double perimeter = sideA + sideB + sideC;

    printf("Triangle Base: %.2f, Height: %.2f\n", base, height);
    printf("Area of Triangle: %.2f\n", area);
    printf("Perimeter of Triangle: %.2f\n", perimeter);
}

double get_positive_input(char *prompt) {
    double value;
    do {
        printf("%s", prompt);
        scanf("%lf", &value);
        if (value <= 0) {
            printf("Please enter a positive value.\n");
        }
    } while (value <= 0);
    return value;
}