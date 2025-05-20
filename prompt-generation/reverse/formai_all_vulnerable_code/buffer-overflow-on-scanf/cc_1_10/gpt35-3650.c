//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Shape Shifting Circuit Simulator!\n");
    printf("Please select a circuit component:\n1. Resistor\n2. Capacitor\n3. Inductor\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You have selected the Resistor.\n");
            printf("Please enter the resistance value in Ohms: ");
            double resistance;
            scanf("%lf", &resistance);
            printf("The resistance value is %.2lf Ohms.\n", resistance);
            break;
        case 2:
            printf("You have selected the Capacitor.\n");
            printf("Please enter the capacitance value in Farads: ");
            double capacitance;
            scanf("%lf", &capacitance);
            printf("The capacitance value is %.2lf Farads.\n", capacitance);
            break;
        case 3:
            printf("You have selected the Inductor.\n");
            printf("Please enter the inductance value in Henries: ");
            double inductance;
            scanf("%lf", &inductance);
            printf("The inductance value is %.2lf Henries.\n", inductance);
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    printf("Would you like to shape shift this component? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'y') {
        printf("Please select a shape:\n1. Cylinder\n2. Cube\n3. Sphere\n");
        int shape;
        scanf("%d", &shape);

        switch (shape) {
            case 1:
                printf("You have selected the Cylinder.\n");
                printf("Please enter the radius: ");
                double radius;
                scanf("%lf", &radius);
                printf("Please enter the height: ");
                double height;
                scanf("%lf", &height);
                printf("The cylinder's shape is now R=%.2lf, L=%.2lf.\n", radius, height);
                break;
            case 2:
                printf("You have selected the Cube.\n");
                printf("Please enter the side length: ");
                double side_length;
                scanf("%lf", &side_length);
                printf("The cube's shape is now L=%.2lf.\n", side_length);
                break;
            case 3:
                printf("You have selected the Sphere.\n");
                printf("Please enter the radius: ");
                double sphere_radius;
                scanf("%lf", &sphere_radius);
                printf("The sphere's shape is now R=%.2lf.\n", sphere_radius);
                break;
            default:
                printf("Invalid choice.\n");
                return 0;
        }
    }

    printf("Thank you for using the Shape Shifting Circuit Simulator!\n");
    return 0;
}