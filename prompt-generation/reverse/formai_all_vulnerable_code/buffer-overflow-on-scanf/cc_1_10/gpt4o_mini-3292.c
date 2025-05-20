//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>

void shocked_statement(char *message) {
    printf("\n😱 SHOCKING REVEAL: %s\n", message);
}

int main() {
    int num1, num2;
    int sum, difference, product, quotient, remainder;

    // Introductory part
    printf("********************************************\n");
    printf("🚀 Welcome to the Arithmetic Shock Experiment! 🚀\n");
    printf("********************************************\n\n");
    
    // Taking input from user
    printf("Please enter the first number (int): ");
    scanf("%d", &num1);
    shocked_statement("You've entered the first number!");

    printf("Please enter the second number (int): ");
    scanf("%d", &num2);
    shocked_statement("You've entered the second number!");

    // Performing operations
    sum = num1 + num2;
    shocked_statement("Performing addition...");

    difference = num1 - num2;
    shocked_statement("Performing subtraction...");

    product = num1 * num2;
    shocked_statement("Performing multiplication...");

    if(num2 != 0) {
        quotient = num1 / num2;
        shocked_statement("Performing division...");
        remainder = num1 % num2; 
        shocked_statement("Calculating modulus...");
    } else {
        shocked_statement("🚫 Division by zero is a BIG NO-NO!");
        quotient = 0;
        remainder = 0;
    }

    // Displaying results with flair
    printf("\n🤯 The shocking results are in! 🤯\n");
    printf("============================================\n");
    printf("✨ Sum (n1 + n2): %d\n", sum);
    printf("💔 Difference (n1 - n2): %d\n", difference);
    printf("🌟 Product (n1 * n2): %d\n", product);

    if(num2 != 0) {
        printf("🚀 Quotient (n1 / n2): %d\n", quotient);
        printf("💥 Remainder (n1 %% n2): %d\n", remainder);
    }
    
    printf("============================================\n");
    printf("🤔 What an experience! Thank you for participating!\n");
    printf("********************************************\n");
    
    return 0;
}