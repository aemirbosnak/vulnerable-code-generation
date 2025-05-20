//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to add two numbers with a funny message
int add_numbers(int num1, int num2) {
    int sum = num1 + num2;
    printf("Ha ha! You added %d and %d, and look what we got!\n", num1, num2);
    return sum;
}

// Function to subtract two numbers with a funny message
int subtract_numbers(int num1, int num2) {
    int difference = num1 - num2;
    printf("He he! You subtracted %d from %d, and voila!\n", num2, num1);
    return difference;
}

// Function to multiply two numbers with a funny message
int multiply_numbers(int num1, int num2) {
    int product = num1 * num2;
    printf("Hoo hoo! You multiplied %d by %d, and ta-da!\n", num1, num2);
    return product;
}

// Function to divide two numbers with a funny message
int divide_numbers(int num1, int num2) {
    if (num2 != 0) {
        int quotient = num1 / num2;
        printf("Hee hee! You divided %d by %d, and here's your answer!\n", num1, num2);
        return quotient;
    } else {
        printf("Oopsie daisy! Cannot divide by zero.\n");
        exit(1);
    }
}

int main() {
    int num1, num2, choice;

    srand(time(NULL));

    printf("Welcome to the Arithmagic Show!\n");
    printf("Let's perform some funny arithmetic tricks!\n");

    do {
        printf("Please enter the first number: ");
        scanf("%d", &num1);
        printf("Please enter the second number: ");
        scanf("%d", &num2);

        printf("\nWhat operation would you like to see?\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_numbers(num1, num2);
                break;
            case 2:
                subtract_numbers(num1, num2);
                break;
            case 3:
                multiply_numbers(num1, num2);
                break;
            case 4:
                divide_numbers(num1, num2);
                break;
            case 5:
                printf("Goodbye and thanks for watching!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress ENTER to continue...\n");
        getchar();
        system("clear"); // For Unix-based systems
        // or system("cls"); // For Windows systems
    } while (1);

    return 0;
}