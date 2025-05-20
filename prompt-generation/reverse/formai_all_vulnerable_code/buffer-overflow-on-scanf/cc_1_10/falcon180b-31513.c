//Falcon-180B DATASET v1.0 Category: Recursive ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to calculate the factorial using recursion
long long factorial(int n){
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

//Function to calculate the power using recursion
double power(double base, int exponent){
    if(exponent == 0)
        return 1;
    else if(exponent < 0)
        return 1/power(base, -exponent);
    else
        return base * power(base, exponent-1);
}

//Function to calculate the Fibonacci series using recursion
int fibonacci(int n){
    if(n == 0 || n == 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

//Function to calculate the sum of even numbers in an array using recursion
int sum_of_even(int arr[], int size){
    if(size == 0)
        return 0;
    else if(arr[0] % 2 == 0)
        return arr[0] + sum_of_even(arr+1, size-1);
    else
        return sum_of_even(arr+1, size-1);
}

//Main function
int main(){
    //Testing the factorial function
    printf("Factorial of 5 is %lld\n", factorial(5));

    //Testing the power function
    printf("10 raised to the power 3 is %f\n", power(10, 3));

    //Testing the Fibonacci series function
    int n;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("%d ", fibonacci(i));
    }

    //Testing the sum of even numbers function
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Sum of even numbers in the array is %d\n", sum_of_even(arr, size));

    return 0;
}