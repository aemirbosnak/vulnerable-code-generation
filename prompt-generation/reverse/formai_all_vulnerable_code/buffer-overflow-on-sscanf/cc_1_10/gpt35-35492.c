//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define our custom error handling function
void handle_error(int error_code) {
    switch(error_code) {
        case 1:
            printf("Error: Division by zero!");
            break;
        case 2:
            printf("Error: Square root of a negative number!");
            break;
        case 3:
            printf("Error: Input is not a number!");
            break;
        default:
            printf("Unknown error!");
            break;
    }
    exit(error_code);
}

int main() {
    double x, y, z;
    char input[50];
    int error_code = 0;
    
    printf("Enter a number: ");
    fgets(input, 50, stdin);
    if(sscanf(input, "%lf", &x) != 1) {
        handle_error(3);
    }
    
    printf("Enter another number: ");
    fgets(input, 50, stdin);
    if(sscanf(input, "%lf", &y) != 1) {
        handle_error(3);
    }
    
    if(y == 0) {
        handle_error(1);
    }
    
    z = sqrt(x / y);
    
    if(isnan(z)) {
        handle_error(2);
    }
    
    printf("The result is: %.2lf", z);
    
    return 0;
}