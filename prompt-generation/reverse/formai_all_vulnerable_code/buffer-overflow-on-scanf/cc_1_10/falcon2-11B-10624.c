//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include <stdio.h> 
#include <stdlib.h> 

// Function to calculate factorial of a number 
int factorial(int num) 
{ 
    // Initialize result 
    int result = 1; 

    // Calculate factorial 
    while (num > 1) 
    { 
        result *= num; 
        num--; 
    } 

    // Return result 
    return result; 
} 

int main() 
{ 
    int num; 
    printf("Enter a positive integer: "); 
    scanf("%d", &num); 

    // Check if input is a negative number 
    if (num < 0) 
    { 
        printf("Error: Input is a negative number.\n"); 
        exit(1); 
    } 

    // Check if input is zero 
    if (num == 0) 
    { 
        printf("Error: Input is zero.\n"); 
        exit(1); 
    } 

    // Check if input is a non-integer 
    while (scanf("%d", &num)!= 1) 
    { 
        printf("Error: Input is not a positive integer.\n"); 
        scanf("%d", &num); 
    } 

    // Calculate factorial and display result 
    printf("Factorial of %d is %d.\n", num, factorial(num)); 

    return 0; 
}