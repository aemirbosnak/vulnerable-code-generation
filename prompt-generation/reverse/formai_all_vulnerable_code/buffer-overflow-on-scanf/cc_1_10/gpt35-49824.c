//FormAI DATASET v1.0 Category: Educational ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

// function to calculate factorial of a number
int Factorial(int num) {
    int fact = 1;
    for(int i=2; i<=num; i++) {
        fact *= i;
    }
    return fact;
}

// function to calculate sum of numbers in an array
int ArraySum(int arr[], int size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum += arr[i];
    }
    return sum;
}

// function to print ASCII values of characters in a string
void PrintAscii(char str[]) {
    printf("ASCII values of characters in the string are:\n");
    for(int i=0; str[i]!='\0'; i++) {
        printf("%c -> %d\n", str[i], str[i]);
    }
}

int main() {
    // declare variables
    int num, fact, size;
    int arr[100];
    char str[100];
    
    // ask user for input
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter %d numbers to calculate their sum:\n", size);
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    
    // call functions
    fact = Factorial(num);
    int sum = ArraySum(arr, size);
    PrintAscii(str);
    
    // print results
    printf("Factorial of %d is: %d\n", num, fact);
    printf("Sum of numbers in the array is: %d\n", sum);
    
    return 0;
}