//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void calculate_area_perimeter();
void math_quiz();
void generate_random_numbers();

int main() {
    int choice;

    while (1) {
        printf("\n--- Math Exercise Program ---\n");
        printf("1. Calculate Area and Perimeter\n");
        printf("2. Math Quiz\n");
        printf("3. Generate Random Numbers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_area_perimeter();
                break;
            case 2:
                math_quiz();
                break;
            case 3:
                generate_random_numbers();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void calculate_area_perimeter() {
    int shape_choice;
    float area, perimeter;

    printf("\nChoose a shape:\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    printf("Enter your choice: ");
    scanf("%d", &shape_choice);

    switch (shape_choice) {
        case 1: // Rectangle
            {
                float length, width;
                printf("Enter length: ");
                scanf("%f", &length);
                printf("Enter width: ");
                scanf("%f", &width);
                area = length * width;
                perimeter = 2 * (length + width);
                printf("Area of Rectangle: %.2f\n", area);
                printf("Perimeter of Rectangle: %.2f\n", perimeter);
            }
            break;
        case 2: // Circle
            {
                float radius;
                printf("Enter radius: ");
                scanf("%f", &radius);
                area = 3.14159 * radius * radius;
                perimeter = 2 * 3.14159 * radius;
                printf("Area of Circle: %.2f\n", area);
                printf("Circumference of Circle: %.2f\n", perimeter);
            }
            break;
        case 3: // Triangle
            {
                float base, height, side1, side2;
                printf("Enter base: ");
                scanf("%f", &base);
                printf("Enter height: ");
                scanf("%f", &height);
                printf("Enter side1: ");
                scanf("%f", &side1);
                printf("Enter side2: ");
                scanf("%f", &side2);
                area = (base * height) / 2;
                perimeter = base + side1 + side2;
                printf("Area of Triangle: %.2f\n", area);
                printf("Perimeter of Triangle: %.2f\n", perimeter);
            }
            break;
        default:
            printf("Invalid shape choice.\n");
    }
}

void math_quiz() {
    int answer, score = 0;

    printf("\n--- Math Quiz ---\n");

    printf("1. What is 5 + 7? ");
    scanf("%d", &answer);
    if (answer == 12) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is 12.\n");
    }

    printf("2. What is 9 * 3? ");
    scanf("%d", &answer);
    if (answer == 27) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is 27.\n");
    }

    printf("3. What is 15 / 5? ");
    scanf("%d", &answer);
    if (answer == 3) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is 3.\n");
    }

    printf("You scored %d out of 3.\n", score);
}

void generate_random_numbers() {
    int count, i;

    printf("\nHow many random numbers do you want to generate? ");
    scanf("%d", &count);
    
    // Seed the random number generator
    srand(time(NULL));

    printf("Generating %d random numbers between 1 and 100:\n", count);
    for (i = 0; i < count; i++) {
        int random_number = (rand() % 100) + 1; // Generate number between 1 and 100
        printf("%d ", random_number);
    }
    printf("\n");
}