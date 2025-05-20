//Falcon-180B DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid integer
int isInteger(char* str) {
    int i = 0;
    while(str[i]!= '\0') {
        if(str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    int choice;
    char input[100];
    int num1 = 0, num2 = 0;

    // Prompt user for choice
    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    // Prompt user for input
    printf("Enter the first integer: ");
    scanf("%s", input);

    // Check if input is a valid integer
    if(!isInteger(input)) {
        printf("Error: Invalid input\n");
        exit(1);
    }

    // Convert input to integer
    num1 = atoi(input);

    // Prompt user for second input
    printf("Enter the second integer: ");
    scanf("%s", input);

    // Check if input is a valid integer
    if(!isInteger(input)) {
        printf("Error: Invalid input\n");
        exit(1);
    }

    // Convert input to integer
    num2 = atoi(input);

    // Perform chosen operation
    switch(choice) {
        case 1:
            printf("The result is %d\n", num1 + num2);
            break;
        case 2:
            printf("The result is %d\n", num1 - num2);
            break;
        case 3:
            printf("The result is %d\n", num1 * num2);
            break;
        case 4:
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            printf("The result is %.2f\n", (float)num1 / num2);
            break;
        default:
            printf("Error: Invalid choice\n");
            exit(1);
    }

    return 0;
}