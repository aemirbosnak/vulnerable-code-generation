//Falcon-180B DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function to print a list in reverse order
void print_list_reverse(int *list, int size) {
    if (size == 0) {
        printf("Empty list.\n");
        return;
    }
    printf("Original list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    // Reverse the list
    for (int i = 0; i < size / 2; i++) {
        int temp = list[i];
        list[i] = list[size - i - 1];
        list[size - i - 1] = temp;
    }

    // Print the reversed list
    printf("Reversed list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Main function
int main() {
    // Example usage of print_list_reverse
    int list1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(list1) / sizeof(list1[0]);
    print_list_reverse(list1, size1);

    // Example usage of factorial
    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d = %d\n", n, factorial(n));

    return 0;
}