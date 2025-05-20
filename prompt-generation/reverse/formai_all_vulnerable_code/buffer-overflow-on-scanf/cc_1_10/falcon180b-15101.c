//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int n;
    double x, y, result;
    char choice;

    printf("Welcome to the C Math Exercise Program!\n");
    printf("This program will generate random math problems for you to solve.\n");
    printf("Choose a difficulty level (1-3): ");
    scanf("%d", &n);

    srand(time(NULL));
    int operators[] = {1, 2, 3, 4}; // 1: addition, 2: subtraction, 3: multiplication, 4: division
    int num_operators = sizeof(operators) / sizeof(operators[0]);

    while (1) {
        printf("Generating problem...\n");
        x = rand() % 100 + 1;
        y = rand() % 100 + 1;
        result = x + y;
        printf("Solve for: %d %c %d = ", x, operators[rand() % num_operators], y);

        switch (n) {
            case 1:
                printf("%d\n", result);
                break;
            case 2:
                printf("%.2f\n", result);
                break;
            case 3:
                printf("%.4f\n", result);
                break;
            default:
                printf("Invalid choice.\n");
                return 0;
        }

        printf("Enter your answer: ");
        scanf("%lf", &result);

        if (abs(result - x + y) <= 0.01) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %.2f.\n", result);
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}