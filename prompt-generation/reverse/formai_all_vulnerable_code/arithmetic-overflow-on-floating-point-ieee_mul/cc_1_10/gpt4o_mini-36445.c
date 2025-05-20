//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double calculate_area(double radius);
double calculate_perimeter(double radius);
void display_menu();
void clear_buffer();

int main() {
    int choice;
    double radius, area, perimeter;

    while (1) {
        display_menu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            clear_buffer();
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                if (scanf("%lf", &radius) != 1) {
                    clear_buffer();
                    printf("Invalid input! Please enter a valid number.\n");
                    continue;
                }
                area = calculate_area(radius);
                printf("Area of the circle with radius %.2f is: %.2f\n", radius, area);
                break;

            case 2:
                printf("Enter the radius of the circle: ");
                if (scanf("%lf", &radius) != 1) {
                    clear_buffer();
                    printf("Invalid input! Please enter a valid number.\n");
                    continue;
                }
                perimeter = calculate_perimeter(radius);
                printf("Perimeter of the circle with radius %.2f is: %.2f\n", radius, perimeter);
                break;

            case 3:
                printf("Exiting the program.\n");
                return 0;

            case 4:
                printf("Enter the radius of the circle: ");
                if (scanf("%lf", &radius) != 1) {
                    clear_buffer();
                    printf("Invalid input! Please enter a valid number.\n");
                    continue;
                }
                area = calculate_area(radius);
                perimeter = calculate_perimeter(radius);
                printf("Circle with radius %.2f has area: %.2f and perimeter: %.2f\n", radius, area, perimeter);
                break;

            case 5:
                printf("Enter the radius of the circle: ");
                if (scanf("%lf", &radius) != 1) {
                    clear_buffer();
                    printf("Invalid input! Please enter a valid number.\n");
                    continue;
                }
                area = calculate_area(radius);
                printf("Circle's characteristics:\n");
                printf("Radius: %.2f\n", radius);
                printf("Area: %.2f\n", area);
                printf("Perimeter: %.2f\n", calculate_perimeter(radius));
                printf("Diameter: %.2f\n", 2 * radius);
                printf("Circumference: %.2f\n", calculate_perimeter(radius));
                break;

            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
                break;
        }
    }

    return 0;
}

// Function to calculate the area of a circle
double calculate_area(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate the perimeter (circumference) of a circle
double calculate_perimeter(double radius) {
    return 2 * M_PI * radius;
}

// Function to display the menu
void display_menu() {
    printf("\n******** Circle Calculator ********\n");
    printf("1. Calculate area of circle\n");
    printf("2. Calculate perimeter of circle\n");
    printf("3. Exit\n");
    printf("4. Calculate both area and perimeter\n");
    printf("5. Display circle characteristics\n");
}

// Function to clear the input buffer
void clear_buffer() {
    while (getchar() != '\n'); // Clear input buffer until newline
}