//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>

int main() {

    // Begin the battle!
    printf("Welcome to Brave Arithmetic!\n\n");
    
    // Declare the variables
    int num1, num2, num3, sum, difference, product;
    float quotient, remainder;
    
    // Ask for user input
    printf("Enter your first number: ");
    scanf("%d", &num1);
    printf("Enter your second number: ");
    scanf("%d", &num2);
    printf("Enter your third number: ");
    scanf("%d", &num3);
    
    // Perform calculations
    sum = num1 + num2 + num3;
    difference = num1 - num2 - num3;
    product = num1 * num2 * num3;
    quotient = (float) num1 / (float) num2;
    remainder = num1 % num2;
    
    // Display the results
    printf("\n\nBATTLE RESULTS:\n");
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %.2f\n", quotient);
    printf("Remainder: %.2f\n\n", remainder);
    
    // Challenge the user
    printf("Do you want to continue the battle?\n");
    printf("Enter 'Yes' or 'No': ");
    
    // Declare the string variable
    char response[10];
    
    // Read the user's response
    scanf("%s", response);
    
    // Check the user's response
    if(response[0] == 'Y' || response[0] == 'y') {
        printf("\n\nBRAVE WARRIOR!\n");
    } else {
        printf("Thank you for playing Brave Arithmetic. Goodbye!");
    }
    
    // End the battle
    return 0;
}