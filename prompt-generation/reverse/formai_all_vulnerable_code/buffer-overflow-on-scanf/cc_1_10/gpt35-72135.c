//FormAI DATASET v1.0 Category: Educational ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to determine if a number is even or odd
int even_odd(int num) {
    if (num % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char str[100];
    int choice, num, i, j, size, count;
    int array[50];
    float sum, average;

    printf("Welcome to the Even-Odd Analyzer Program!\n");
    printf("Please choose an option from the menu below:\n");
    printf("1. Analyze a single integer\n");
    printf("2. Analyze an array of integers\n");
    printf("3. Exit the program\n");

    scanf("%d", &choice);

    while (choice != 3) {
        switch(choice) {
            case 1:
                // analyze a single integer
                printf("Enter an integer to analyze: ");
                scanf("%d", &num);
                if (even_odd(num) == 1) {
                    printf("%d is even.\n", num);
                }
                else {
                    printf("%d is odd.\n", num);
                }
                break;
            case 2:
                // analyze an array of integers
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                printf("Enter the elements of the array:\n");
                for (i = 0; i < size; i++) {
                    scanf("%d", &array[i]);
                }
                printf("The even elements of the array are:\n");
                count = 0;
                for (i = 0; i < size; i++) {
                    if (even_odd(array[i]) == 1) {
                        printf("%d ", array[i]);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("None\n");
                }
                else {
                    printf("\n");
                }
                printf("The odd elements of the array are:\n");
                count = 0;
                for (i = 0; i < size; i++) {
                    if (even_odd(array[i]) == 0) {
                        printf("%d ", array[i]);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("None\n");
                }
                else {
                    printf("\n");
                }
                sum = 0;
                for (i = 0; i < size; i++) {
                    sum += array[i];
                }
                average = sum / size;
                printf("The average of the elements in the array is: %.2f\n", average);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("Please choose an option from the menu below:\n");
        printf("1. Analyze a single integer\n");
        printf("2. Analyze an array of integers\n");
        printf("3. Exit the program\n");

        scanf("%d", &choice);
    }

    printf("Thank you for using Even-Odd Analyzer Program!\n");

    return 0;
}