//MISTRAL-7B DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 256
#define MIN_NUM 0.0
#define MAX_NUM 1000000.0
#define EPSILON 0.0001

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J");
#endif
}

void print_menu() {
    printf("*************************\n");
    printf("* Welcome to Calculator *\n");
    printf("*************************\n");
    printf("\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Percentage\n");
    printf("6. Quit\n");
}

void add(double num1, double num2) {
    printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
}

void subtract(double num1, double num2) {
    printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
}

void multiply(double num1, double num2) {
    printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
}

void divide(double num1, double num2) {
    if (num2 != 0.0) {
        printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

void percentage(double base, double percent) {
    double result;

    if (base > 0.0 && percent >= 0.0 && percent <= 100.0) {
        result = base * (percent / 100.0);
        printf("%.2lf * %.2lf%% = %.2lf\n", base, percent, result);
    } else {
        printf("Error: Invalid base or percentage value.\n");
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    double num1, num2, result;
    int choice;

    clear_screen();
    print_menu();

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            break;
        }

        printf("Enter the first number: ");
        scanf("%lf", &num1);

        if (choice != 5) {
            printf("Enter the second number: ");
            scanf("%lf", &num2);
        }

        clear_screen();
        print_menu();

        switch (choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            case 5:
                printf("Enter the base number: ");
                scanf("%lf", &num1);
                printf("Enter the percentage: ");
                scanf("%lf", &num2);
                percentage(num1, num2);
                break;
            default:
                printf("Error: Invalid choice.\n");
                break;
        }

        printf("\nPress any key to continue...");
        getchar();
        getchar();
    }

    return 0;
}