//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void cheerfulMessage(const char *message) {
    printf("\n😊✨ %s ✨😊\n", message);
}

int getPositiveInteger() {
    int number;
    cheerfulMessage("Let's enter a positive integer!");

    while (1) {
        printf("Please enter your positive integer: ");
        
        if (scanf("%d", &number) != 1) {
            cheerfulMessage("Oops! That's not a valid number, try again!");
            // Clear the invalid input
            while (getchar() != '\n'); 
            continue;
        }

        if (number <= 0) {
            cheerfulMessage("Hey there! Positive numbers only, buddy!");
            continue;
        }

        break;
    }
    
    return number;
}

float divide(int dividend, int divisor) {
    if (divisor == 0) {
        cheerfulMessage("Oh no! Dividing by zero is like going to the moon without a rocket! 🚀");
        return -1; // Use -1 as a sentinel value for error
    }
    return (float)dividend / divisor;
}

int main() {
    cheerfulMessage("Welcome to the Cheerful Division Program!");

    int dividend = 100; // Let's say we're always dividing 100
    cheerfulMessage("Did you know that we're going to divide 100? 🎉");

    int divisor = getPositiveInteger();

    float result = divide(dividend, divisor);

    if (result != -1) {
        cheerfulMessage("Yay! The division operation was successful!");
        printf("100 divided by %d equals %.2f\n", divisor, result);
    } else {
        cheerfulMessage("Let's try this again, shall we? 😊");
    }

    cheerfulMessage("Thank you for participating!");
    return 0;
}