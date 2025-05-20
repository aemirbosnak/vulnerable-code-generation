//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void welcomeMessage();
int menu();
void calculateArea();
void calculatePerimeter();
void calculateVolume();
void calculateRoots();
void exitProgram();

int main() {
    int choice;

    welcomeMessage();

    do {
        choice = menu();

        switch (choice) {
            case 1:
                calculateArea();
                break;
            case 2:
                calculatePerimeter();
                break;
            case 3:
                calculateVolume();
                break;
            case 4:
                calculateRoots();
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}

void welcomeMessage() {
    printf("=========================================\n");
    printf("        Welcome to Math Operations      \n");
    printf("=========================================\n");
}

int menu() {
    int choice;

    printf("\nSelect an operation to perform:\n");
    printf("1. Calculate Area\n");
    printf("2. Calculate Perimeter\n");
    printf("3. Calculate Volume\n");
    printf("4. Calculate Roots of a Quadratic Equation\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    
    return choice;
}

void calculateArea() {
    int shape;

    printf("\nSelect shape for area calculation:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &shape);

    switch (shape) {
        case 1: {
            float radius;
            printf("Enter radius of the circle: ");
            scanf("%f", &radius);
            printf("Area of the circle: %.2f\n", M_PI * radius * radius);
            break;
        }
        case 2: {
            float length, width;
            printf("Enter length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            printf("Area of the rectangle: %.2f\n", length * width);
            break;
        }
        case 3: {
            float base, height;
            printf("Enter base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            printf("Area of the triangle: %.2f\n", 0.5 * base * height);
            break;
        }
        default:
            printf("Invalid shape choice!\n");
            break;
    }
}

void calculatePerimeter() {
    int shape;

    printf("\nSelect shape for perimeter calculation:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &shape);

    switch (shape) {
        case 1: {
            float radius;
            printf("Enter radius of the circle: ");
            scanf("%f", &radius);
            printf("Perimeter of the circle: %.2f\n", 2 * M_PI * radius);
            break;
        }
        case 2: {
            float length, width;
            printf("Enter length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            printf("Perimeter of the rectangle: %.2f\n", 2 * (length + width));
            break;
        }
        case 3: {
            float side1, side2, side3;
            printf("Enter length of all three sides of the triangle: ");
            scanf("%f %f %f", &side1, &side2, &side3);
            printf("Perimeter of the triangle: %.2f\n", side1 + side2 + side3);
            break;
        }
        default:
            printf("Invalid shape choice!\n");
            break;
    }
}

void calculateVolume() {
    int shape;

    printf("\nSelect shape for volume calculation:\n");
    printf("1. Cylinder\n");
    printf("2. Cuboid\n");
    printf("3. Cone\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &shape);

    switch (shape) {
        case 1: {
            float radius, height;
            printf("Enter radius and height of the cylinder: ");
            scanf("%f %f", &radius, &height);
            printf("Volume of the cylinder: %.2f\n", M_PI * radius * radius * height);
            break;
        }
        case 2: {
            float length, width, height;
            printf("Enter length, width, and height of the cuboid: ");
            scanf("%f %f %f", &length, &width, &height);
            printf("Volume of the cuboid: %.2f\n", length * width * height);
            break;
        }
        case 3: {
            float radius, height;
            printf("Enter radius and height of the cone: ");
            scanf("%f %f", &radius, &height);
            printf("Volume of the cone: %.2f\n", (1.0/3.0) * M_PI * radius * radius * height);
            break;
        }
        default:
            printf("Invalid shape choice!\n");
            break;
    }
}

void calculateRoots() {
    float a, b, c, discriminant, root1, root2;
    
    printf("Enter coefficients a, b and c of the quadratic equation (ax^2 + bx + c = 0): ");
    scanf("%f %f %f", &a, &b, &c);
    
    discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different:\nRoot 1: %.2f\nRoot 2: %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Roots are real and the same:\nRoot: %.2f\n", root1);
    } else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and different:\nRoot 1: %.2f + %.2fi\nRoot 2: %.2f - %.2fi\n", 
                realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

void exitProgram() {
    printf("Thank you for using the Math Operations program. Goodbye!\n");
}