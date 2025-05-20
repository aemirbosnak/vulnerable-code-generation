//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Define our error handling function
void handle_error(int err_num) {
    printf("Oh no! Something went wrong.\n");

    switch(err_num) {
        case EACCES:
            printf("Permission denied - please check your privileges.\n");
            break;
        case EINVAL:
            printf("Invalid argument - please check your input.\n");
            break;
        case ENOMEM:
            printf("Out of memory - please allocate more memory.\n");
            break;
        default:
            printf("Unknown error - please consult the manual.\n");
            break;
    }

    exit(1);
}

// Main program
int main() {
    // Declare our variables
    int num1, num2, result;

    // Get input from the user
    printf("Please enter two numbers to divide: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        handle_error(errno);
    }

    // Check for divide-by-zero error and handle gracefully
    if (num2 == 0) {
        printf("Thank you for trying to divide by zero.\n");
        exit(0);
    }

    // Perform division operation and handle any other errors
    result = num1 / num2;
    if (result < 0) {
        handle_error(errno);
    }

    // Output the result
    printf("The result of %d divided by %d is %d.\n", num1, num2, result);

    return 0;
}