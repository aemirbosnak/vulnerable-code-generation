//FormAI DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>

int main()
{
    // Welcome message to user
    printf("Welcome to this educational program on C programming!\n");

    // Declaring a variable
    int num;

    // Asking user for input
    printf("Please enter a number: ");
    scanf("%d", &num);

    // Checking if number is even or odd
    if(num % 2 == 0)
    {
        printf("%d is an even number.\n", num);
    }
    else
    {
        printf("%d is an odd number.\n", num);
    }

    // Declaring an array of characters
    char name[20];

    // Asking user for input
    printf("Please enter your name: ");
    scanf("%s", name);

    // Printing out user's name
    printf("Hello, %s!\n", name);

    // Declaring a float variable
    float radius;

    // Asking user for input
    printf("Please enter the radius of a circle: ");
    scanf("%f", &radius);

    // Calculating and printing the circumference of the circle
    float circumference = 2 * 3.14 * radius;
    printf("The circumference of a circle with radius %.2f is %.2f.\n", radius, circumference);

    // Declaring an int variable
    int startingNumber = 1;

    // Using a while loop to print out the first 10 even numbers starting from 1
    printf("The first 10 even numbers are: ");

    while(startingNumber <= 20)
    {
        printf("%d ", startingNumber);
        startingNumber += 2;
    }

    printf("\nThank you for using this educational program on C programming!\n");

    return 0;
}