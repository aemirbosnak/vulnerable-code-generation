//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>

#define MAX_NUMBERS 10

void printMenu() {
    printf("\nWelcome to the Magical Arithmetic Adventure!\n");
    printf("==============================================\n");
    printf("Choose an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("==============================================\n");
}

void performAddition(int numbers[], int count) {
    int result = 0;
    for(int i = 0; i < count; i++) {
        result += numbers[i];
    }
    printf("The result of addition is: %d\n", result);
}

void performSubtraction(int numbers[], int count) {
    int result = numbers[0];
    for(int i = 1; i < count; i++) {
        result -= numbers[i];
    }
    printf("The result of subtraction is: %d\n", result);
}

void performMultiplication(int numbers[], int count) {
    int result = 1;
    for(int i = 0; i < count; i++) {
        result *= numbers[i];
    }
    printf("The result of multiplication is: %d\n", result);
}

void performDivision(int numbers[], int count) {
    if (count == 0) {
        printf("Cannot divide by zero!\n");
        return;
    }
    float result = (float) numbers[0];
    for(int i = 1; i < count; i++) {
        if (numbers[i] == 0) {
            printf("Cannot divide by zero!\n");
            return; 
        }
        result /= numbers[i];
    }
    printf("The result of division is: %.2f\n", result);
}

int main() {
    int choice;
    int numbers[MAX_NUMBERS];
    int count = 0;
    
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting the Magical Arithmetic Adventure! Bye!\n");
            break;
        }
        
        printf("How many numbers do you want to enter (max %d)? ", MAX_NUMBERS);
        scanf("%d", &count);
        
        if (count < 1 || count > MAX_NUMBERS) {
            printf("Invalid count. Please enter a number between 1 and %d.\n", MAX_NUMBERS);
            continue;
        }

        printf("Enter %d numbers (space-separated): ", count);
        for(int i = 0; i < count; i++) {
            scanf("%d", &numbers[i]);
        }

        switch(choice) {
            case 1:
                performAddition(numbers, count);
                break;
            case 2:
                performSubtraction(numbers, count);
                break;
            case 3:
                performMultiplication(numbers, count);
                break;
            case 4:
                performDivision(numbers, count);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}