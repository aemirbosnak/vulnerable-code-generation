//FormAI DATASET v1.0 Category: Educational ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z;
    printf("Enter any two numbers: ");
    scanf("%d %d", &x, &y);
    z = x + y;
    printf("Sum of %d and %d is: %d\n", x, y, z);
    
    if (x < y) {
        printf("%d is less than %d\n", x, y);
    } else {
        printf("%d is greater than %d\n", x, y);
    }
    
    if (z % 2 == 0) {
        printf("The sum is even\n");
    } else {
        printf("The sum is odd\n");
    }
    
    printf("Enter a number to find its factorial: ");
    int n;
    scanf("%d", &n);
    int fact = 1;
    for (int i = n; i >= 1; i--) {
        fact *= i; 
    }
    printf("Factorial of %d is: %d\n", n, fact);
    
    int arr[5];
    printf("Enter 5 integers for an array: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The array is: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int temp;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted array is: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Enter a number to check if it's prime: ");
    int num;
    scanf("%d", &num);
    int flag = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        printf("%d is a prime number\n", num);
    } else {
        printf("%d is not a prime number\n", num);
    }
    
    printf("Enter any three numbers to find the largest: ");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b && a > c) {
        printf("%d is the largest\n", a);
    } else if (b > c) {
        printf("%d is the largest\n", b);
    } else {
        printf("%d is the largest\n", c);
    }
    return 0;
}