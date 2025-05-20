//FormAI DATASET v1.0 Category: Educational ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to C Educational Example Program!\n");
    printf("Get ready to learn something new!\n");
    
    //declaring variables
    int num1, num2, sum;
    
    //taking input from user
    printf("Please enter two numbers: \n");
    scanf("%d %d", &num1, &num2);
    
    //calculating sum of two numbers
    sum = num1 + num2;
    
    //printing the result
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    
    //checking if the sum is even or odd
    if(sum%2 == 0)
    {
        printf("Wow! The sum is even!\n");
    }
    else
    {
        printf("Oh no! The sum is odd!\n");
    }
    
    //declaring and initializing a character variable
    char letter = 'x';
    
    //printing the ASCII value of the character
    printf("The ASCII value of %c is %d.\n", letter, letter);
    
    //declaring and initializing an array of 5 integers
    int arr[5] = {1, 3, 5, 7, 9};
    
    //printing the array elements using loop
    printf("The array elements are: \n");
    for(int i=0; i<5; i++)
    {
        printf("%d ", arr[i]);
    }
    
    //declaring and initializing a pointer variable
    int *ptr;
    ptr = &arr[0];
    
    //printing the value and address of the pointer
    printf("\n\nThe value of the pointer is %p.\n", ptr);
    printf("The address of the pointer is %p.\n", &ptr);
    
    //deallocating the memory allocated to the pointer
    free(ptr);
    
    printf("\n\nCongratulations! You have successfully completed the C Educational Example Program!\n");
    
    return 0;
}