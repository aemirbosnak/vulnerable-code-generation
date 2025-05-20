//FormAI DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, result;

    // Taking input from user
    printf("Enter the value of x: ");
    scanf("%d", &x);

    printf("Enter the value of y: ");
    scanf("%d", &y);

    printf("Enter the value of z: ");
    scanf("%d", &z);

    // Performing mathematical calculations
    result = (x + y) * z;

    // Displaying the result
    printf("The result of (%d + %d) * %d is: %d\n", x, y, z, result);

    // Performing another mathematical calculation
    result = x / y + z;

    // Displaying the result
    printf("The result of %d / %d + %d is: %d\n", x, y, z, result);

    // Checking the value of x to ensure it is not zero
    if (x != 0)
    {
        // Performing another mathematical calculation
        result = (x * y) % x;

        // Displaying the result
        printf("The remainder of (%d * %d) divided by %d is: %d\n", x, y, x, result);
    }
    else
    {
        printf("Cannot perform modulus operation as value of x is zero.\n");
    }

    // Using the rand() function to generate a random number
    int random_num = rand() % 100;

    // Displaying the random number
    printf("A random number between 0 and 99 is: %d\n", random_num);

    return 0;
}