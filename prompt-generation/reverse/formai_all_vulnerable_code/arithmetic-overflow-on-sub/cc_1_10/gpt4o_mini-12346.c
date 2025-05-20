//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>

// Function Prototypes
void printFibonacci(int n);
int fibonacci(int n);
void towerOfHanoi(int n, char source, char destination, char auxiliary);
void printReverse(char str[], int index);
void acceptInput();

int main() {
    int choice, n;

    printf("Welcome to the Recursive Function Showcase!\n");
    printf("1. Fibonacci Series\n");
    printf("2. Tower of Hanoi\n");
    printf("3. Print a String in Reverse\n");
    printf("Select a function to demonstrate (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the number of terms in Fibonacci series: ");
            scanf("%d", &n);
            printf("Fibonacci Series: ");
            printFibonacci(n);
            printf("\n");
            break;
        case 2:
            printf("Enter the number of disks for Tower of Hanoi: ");
            scanf("%d", &n);
            printf("Solving Tower of Hanoi for %d disks:\n", n);
            towerOfHanoi(n, 'A', 'C', 'B');
            break;
        case 3:
            acceptInput(); // Function to accept and print user string in reverse
            break;
        default:
            printf("Invalid choice. Exiting!\n");
            break;
    }
    return 0;
}

// Recursive function to print Fibonacci series
void printFibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function for Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Function to input a string and print it in reverse
void acceptInput() {
    char str[100];
    printf("Enter a string to print in reverse: ");
    // Clear the input buffer before reading a string
    getchar(); // Consume any leftover newline character
    fgets(str, sizeof(str), stdin);
    
    // Find the length of the string
    int len = 0;
    while(str[len] != '\0' && str[len] != '\n') {
        len++;
    }
    
    printf("Reversed String: ");
    printReverse(str, len - 1);
    printf("\n");
}

// Recursive function to print a string in reverse
void printReverse(char str[], int index) {
    if (index < 0) return; // Base case
    putchar(str[index]);    // Print the current character
    printReverse(str, index - 1); // Recursive call for the next character
}