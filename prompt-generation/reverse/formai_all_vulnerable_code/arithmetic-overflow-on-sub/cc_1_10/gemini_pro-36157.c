//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdbool.h>
#include <stdio.h>

// A recursive function to solve the Tower of Hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    // If only one disk is left, move it to the destination rod
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    // Move the top n-1 disks from the from rod to the auxiliary rod
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Move the remaining disk from the from rod to the destination rod
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    // Move the n-1 disks from the auxiliary rod to the destination rod
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    // Get the number of disks from the user
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Solve the Tower of Hanoi puzzle
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}

// A function to check if a number is a power of 2

bool isPowerOfTwo(int n) 
{ 
    if (n == 0) 
        return false; 
  
    while (n != 1) 
    { 
        if (n % 2 != 0) 
            return false; 
        n = n / 2; 
    } 
    return true; 
}

// A function to print the binary representation of a number
void printBinary(int n) 
{ 
    if (n == 0) { 
        printf("0"); 
        return; 
    } 
  
    printBinary(n / 2); 
    printf("%d", n % 2); 
} 

// A function to print the hexadecimal representation of a number
void printHexadecimal(int n) 
{ 
    if (n == 0) { 
        printf("0"); 
        return; 
    } 
  
    printHexadecimal(n / 16); 
    printf("%x", n % 16); 
} 

// A function to print the octal representation of a number
void printOctal(int n) 
{ 
    if (n == 0) { 
        printf("0"); 
        return; 
    } 
  
    printOctal(n / 8); 
    printf("%o", n % 8); 
} 

// A function to calculate the factorial of a number
int factorial(int n) 
{
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// A function to calculate the n-th Fibonacci number
int fibonacci(int n) 
{
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}