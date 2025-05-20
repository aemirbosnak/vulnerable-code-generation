//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void display_menu() {
    printf("Geometric Area Calculator\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

float calculate_rectangle_area(float width, float height) {
    return width * height;
}

float calculate_circle_area(float radius) {
    return PI * radius * radius;
}

float calculate_triangle_area(float base, float height) {
    return 0.5 * base * height;
}

int main() {
    int choice;
    float width, height, radius, base, area;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Rectangle
                printf("Enter width of rectangle: ");
                scanf("%f", &width);
                printf("Enter height of rectangle: ");
                scanf("%f", &height);
                area = calculate_rectangle_area(width, height);
                printf("Area of rectangle: %.2f\n", area);
                break;
                
            case 2: // Circle
                printf("Enter radius of circle: ");
                scanf("%f", &radius);
                area = calculate_circle_area(radius);
                printf("Area of circle: %.2f\n", area);
                break;
                
            case 3: // Triangle
                printf("Enter base of triangle: ");
                scanf("%f", &base);
                printf("Enter height of triangle: ");
                scanf("%f", &height);
                area = calculate_triangle_area(base, height);
                printf("Area of triangle: %.2f\n", area);
                break;
                
            case 4: // Exit
                printf("Exiting the program. Thank you!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}