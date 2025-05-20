//FormAI DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>

int main(){
    //Initializing variables
    int a, b, choice, result;
    
    //Displaying menu
    printf("Basic Calculator\n");
    printf("--------------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("--------------------------\n");
    
    //Taking input from user
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);
    
    //Evaluating result based on user's choice
    switch (choice){
        case 1:
            result = a + b;
            printf("Sum of %d and %d is %d\n", a, b, result);
            break;
        case 2:
            result = a - b;
            printf("Difference of %d and %d is %d\n", a, b, result);
            break;
        case 3:
            result = a * b;
            printf("Product of %d and %d is %d\n", a, b, result);
            break;
        case 4:
            if (b != 0){
                float fresult = (float) a / b;
                printf("Division of %d by %d is %f\n", a, b, fresult);
            }
            else{
                printf("Undefined\n");
            }
            break;
        default:
            printf("Invalid Choice\n");
    }
    
    return 0;
}