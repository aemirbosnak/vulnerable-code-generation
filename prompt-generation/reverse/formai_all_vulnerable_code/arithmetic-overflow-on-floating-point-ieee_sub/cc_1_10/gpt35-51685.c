//FormAI DATASET v1.0 Category: Educational ; Style: futuristic
#include<stdio.h>

int main(){
    // Welcome message
    printf("Welcome to the Future of C Programming.\n");
    printf("This program will demonstrate the power of Artificial Intelligence in C Programming.\n\n");

    // Input variables
    float a, b;
    char operator;

    // Taking inputs from the user
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter the first number: ");
    scanf("%f", &a);

    printf("Enter the second number: ");
    scanf("%f", &b);

    // Variables for the result
    float result;
    char message[100];

    // AI powered calculation of the result
    switch(operator){
        case '+': 
            result = a + b;
            sprintf(message, "The sum of %.2f and %.2f is %.2f", a, b, result);
            break;
        case '-': 
            result = a - b;
            sprintf(message, "The difference between %.2f and %.2f is %.2f", a, b, result);
            break;
        case '*': 
            result = a * b;
            sprintf(message, "The product of %.2f and %.2f is %.2f", a, b, result);
            break;
        case '/': 
            result = a / b;
            sprintf(message, "%.2f divided by %.2f is %.2f", a, b, result);
            break;
        default:
            sprintf(message, "Invalid operator. Please try again.");
    }

    // Printing the result
    printf("\nCalculating. Please wait...\n\n");
    printf("%s\n", message);

    return 0;
}