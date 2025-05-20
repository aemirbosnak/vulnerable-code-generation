//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_SIZE 100

void display(int array[], int size);
int add(int array[], int size);
int subtract(int array[], int size);
int multiply(int array[], int size);
float divide(int array[], int size);

int main() {
    int array[MAX_SIZE];
    int size, choice;
    float result;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Input %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Display Elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = add(array, size);
                printf("Sum of elements = %.2f\n", result);
                break;
            case 2:
                result = subtract(array, size);
                printf("Result of subtraction from first element = %.2f\n", result);
                break;
            case 3:
                result = multiply(array, size);
                printf("Product of elements = %.2f\n", result);
                break;
            case 4:
                result = divide(array, size);
                if (result == -1) {
                    printf("Division by zero encountered!\n");
                } else {
                    printf("Result of division = %.2f\n", result);
                }
                break;
            case 5:
                display(array, size);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 6);

    return 0;
}

void display(int array[], int size) {
    printf("Elements in the array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int add(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int subtract(int array[], int size) {
    int result = array[0];
    for (int i = 1; i < size; i++) {
        result -= array[i];
    }
    return result;
}

int multiply(int array[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= array[i];
    }
    return product;
}

float divide(int array[], int size) {
    if (size < 2) {
        printf("Not enough elements to divide!\n");
        return -1;
    }

    float result = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] == 0) {
            return -1; // To handle division by zero
        }
        result /= array[i];
    }
    return result;
}