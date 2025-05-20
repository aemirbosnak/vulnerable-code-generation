//FormAI DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option = 1;
    int num1, num2, result;
    
    while (option != 0) {
        printf("Choose an option:\n");
        printf("1. Add two numbers\n");
        printf("2. Subtract two numbers\n");
        printf("3. Multiply two numbers\n");
        printf("4. Divide two numbers\n");
        printf("0. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("Result: %d\n", result);
                break;
                
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;
                
            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;
                
            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Divide by zero\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                }
                break;
                
            case 0:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid option\n");
        }
        
        printf("\n\n");
    }
    
    return 0;
}