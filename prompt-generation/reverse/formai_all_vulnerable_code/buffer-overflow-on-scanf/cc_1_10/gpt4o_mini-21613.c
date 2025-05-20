//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

typedef struct {
    char name[50];
    float area; // area for this type of flower
    float unit_soil; // soil per unit area needed
} Flower;

float calculate_circle_area(float radius) {
    return PI * radius * radius;
}

float calculate_rectangle_area(float length, float width) {
    return length * width;
}

void display_flower_info(Flower flower) {
    printf("Flower: %s\n", flower.name);
    printf("Area: %.2f\n", flower.area);
    printf("Amount of soil needed: %.2f cubic meters\n", flower.area * flower.unit_soil);
}

int main() {
    int option;
    float length, width, radius;
    Flower flower;

    printf("Welcome to the Garden Layout Planner!\n");
    printf("This program will help you calculate the area needed for your flowers.\n");

    // Flower information
    printf("Enter the flower name: ");
    scanf("%s", flower.name);
    printf("Enter the soil needed per square meter (in cubic meters): ");
    scanf("%f", &flower.unit_soil);
    
    while (1) {
        printf("\nSelect the shape for planting:\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter the radius of the circle (in meters): ");
                scanf("%f", &radius);
                flower.area = calculate_circle_area(radius);
                display_flower_info(flower);
                break;

            case 2:
                printf("Enter the length of the rectangle (in meters): ");
                scanf("%f", &length);
                printf("Enter the width of the rectangle (in meters): ");
                scanf("%f", &width);
                flower.area = calculate_rectangle_area(length, width);
                display_flower_info(flower);
                break;

            case 3:
                printf("Exiting the program. Happy gardening!\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}