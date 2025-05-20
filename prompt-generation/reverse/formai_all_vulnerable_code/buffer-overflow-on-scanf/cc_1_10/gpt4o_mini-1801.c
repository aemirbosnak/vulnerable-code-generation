//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void visualize_fibonacci(int n) {
    unsigned long long int a = 0, b = 1, c;
    printf("\n");
    for (int i = 0; i < n; i++) {
        // Startle the user with the impending Fibonacci value!
        printf("Calculating Fibonacci number %d...\n", i);
        // Create a delay for dramatic effect!
        usleep(500000); // Sleep for half a second
        printf("------> F(%d): %llu\n", i, a);
        // Here comes the twist, dreading how big this number can get!
        c = a + b; 
        a = b; 
        b = c;
    }
}

void print_intro() {
    printf("****************************************\n");
    printf("!!! Welcome to the Fibonacci Fright !!!\n");
    printf("****************************************\n");
    printf("Prepare yourself for a wildly growing sequence...\n");
    printf("Enter the number of terms you wish to see!\n");
    printf("****************************************\n");
}

int main() {
    int n;
    
    print_intro();

    // Get number of terms from the user
    printf("How many Fibonacci numbers do you want to visualize? (max 94)\n");
    printf(">>> ");
    scanf("%d", &n);
    
    if (n < 1 || n > 94) {
        printf("Whoa there! Please enter a number between 1 and 94.\n");
        return 1;
    }

    // Let the visualization begin!
    printf("Brace yourself!\n");
    visualize_fibonacci(n);
    
    // Closing remark to make the exit feel impactful!
    printf("The Fibonacci sequence has been visualized. You made it! 🎉 \n");
    printf("Remember, with great Fibonacci comes great responsibility! Use wisely.\n");
    
    return 0;
}