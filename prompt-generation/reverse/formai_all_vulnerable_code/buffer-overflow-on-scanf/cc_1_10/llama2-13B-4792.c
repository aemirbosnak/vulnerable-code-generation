//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STR_LEN 100
#define MAX_NUM_LEN 10

// Gratitude function to print a thank you message
void gratitude(const char *message) {
    printf("Thank you for using my program! %s\n", message);
}

int main() {
    // Gratitude message for program usage
    gratitude("You're using this program! 😊");

    // Ask user for their name
    printf("What's your name? ");
    char name[MAX_STR_LEN];
    scanf("%s", name);

    // Check if name is valid
    if (strlen(name) > MAX_STR_LEN) {
        printf("Name is too long! 😔\n");
        return 1;
    }

    // Ask user for their favorite number
    printf("What's your favorite number? ");
    int num;
    scanf("%d", &num);

    // Check if number is valid
    if (num < 0 || num > 100) {
        printf("Invalid number! 😔\n");
        return 1;
    }

    // Calculate the factorial of the number
    int fact = factorial(num);

    // Print the result
    printf("The factorial of %d is %d! 😊\n", num, fact);

    return 0;
}

// Function to calculate the factorial of a number
int factorial(int num) {
    int fact = 1;

    for (int i = 1; i <= num; i++) {
        fact *= i;
    }

    return fact;
}