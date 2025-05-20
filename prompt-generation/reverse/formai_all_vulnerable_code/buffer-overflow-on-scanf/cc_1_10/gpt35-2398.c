//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int num1 = rand() % 10 + 1; // generate a random number between 1 and 10
    int num2 = rand() % 10 + 1; // generate a second random number between 1 and 10
    
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    int quotient = num1 / num2;
    int remainder = num1 % num2;
    
    printf("Welcome to the Math Exercise Generator!\n\n");
    printf("Your numbers are %d and %d.\n\n", num1, num2);
    
    printf("What is the sum of %d and %d? ", num1, num2);
    int userSum;
    scanf("%d", &userSum);
    if (userSum == sum) {
        printf("Correct!\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", sum);
    }
    
    printf("What is the difference between %d and %d? ", num1, num2);
    int userDifference;
    scanf("%d", &userDifference);
    if (userDifference == difference) {
        printf("Correct!\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", difference);
    }
    
    printf("What is the product of %d and %d? ", num1, num2);
    int userProduct;
    scanf("%d", &userProduct);
    if (userProduct == product) {
        printf("Correct!\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", product);
    }
    
    printf("What is the quotient when %d is divided by %d? ", num1, num2);
    int userQuotient;
    scanf("%d", &userQuotient);
    if (userQuotient == quotient) {
        printf("Correct!\n");
    } else {
        printf("Sorry, the correct answer is %d with a remainder of %d.\n", quotient, remainder);
    }
    
    printf("\nThanks for playing Math Exercise Generator!\n");
    
    return 0;
}