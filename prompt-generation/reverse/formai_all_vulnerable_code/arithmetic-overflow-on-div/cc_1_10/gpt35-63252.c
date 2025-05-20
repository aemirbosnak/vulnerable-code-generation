//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>

// A function to calculate the factorial of a number
int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    int num1, num2, choice, result;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    printf("Enter your choice:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Factorial\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            result = num1 + num2;
            printf("The sum of %d and %d is %d\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("The difference between %d and %d is %d\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("%d multiplied by %d is %d\n", num1, num2, result );
            break;
        case 4:
            if(num2 != 0){
                result = num1 / num2;
                printf("%d divided by %d is %d\n", num1, num2, result);
            }
            else{
                printf("Cannot divide by zero\n");
            }
            break;
        case 5:
            printf("Factorial of %d is %d\n", num1, factorial(num1));
            printf("Factorial of %d is %d\n", num2, factorial(num2));
            break;
        default:
            printf("Invalid Choice");
            break;
    }
    return 0;
}