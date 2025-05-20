//FormAI DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to my unique C Educational example program!\n\n");

    //Example 1: Simple Mathematical Operations
    int a = 7, b = 4;
    printf("a = %d, b = %d \n\n", a, b);

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n\n", a / b);

    //Example 2: Using Conditional Statements
    int num = 10;
    printf("Enter any number: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("%d is an even number\n\n", num);
    } else {
        printf("%d is an odd number\n\n", num);
    }

    //Example 3: Using Loops
    int i, j, n = 5;
    printf("Enter the number of rows you want in the pattern: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");

    //Example 4: Working with Arrays
    int arr[5] = {5, 4, 3, 2, 1};

    printf("Elements of the array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    //Example 5: Pointers
    int x = 10;
    int *ptr;

    ptr = &x; //Assigning the address of x to ptr

    printf("The value in x is: %d\n", x);
    printf("The address of x is: %p\n", &x);
    printf("The value of ptr is: %p\n", ptr);
    printf("The value pointed to by ptr is: %d\n\n", *ptr);

    printf("I hope you found this educational program helpful!\n");

    return 0;
}