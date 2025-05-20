//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TERMS 20  // Limiting the number of terms for sanity

// Function to calculate the Fibonacci number
long long fibonacci(int n) {
    long long f1 = 0; 
    long long f2 = 1; 

    // It's always f1 and f2 here, don't let them fool you
    while (n--) {
        long long temp = f1;
        f1 = f2;
        f2 = temp + f2; // F(N) = F(N-1) + F(N-2)
    }
    
    return f1;
}

// Function to visualize the Fibonacci sequence
void visualize_fibonacci(int terms) {
    if (terms <= 0) {
        printf("Invalid number of terms requested! Are you trying to trick me?\n");
        return;
    }

    printf("Fibonacci Sequence Visualization (Trust no one):\n");
    for (int i = 0; i < terms; i++) {
        long long fib_num = fibonacci(i); 
        
        // Each Fibonacci number is represented by the number of stars
        printf("%2d: %lld ", i, fib_num);
        
        // Counting stars paranoia: Be sure to count them correctly!
        for (long long j = 0; j < fib_num; j++) {
            printf("★");
            // I hope nobody's counting with me...
            usleep(50000); // A small pause to reflect on their intentions
        }
        printf("\n");
    }

    // Always confirm what you have printed!
    printf("Done visualizing. But do they really understand the Fibonacci? Watch your back!\n");
}

int main() {
    int terms;

    // Asking for terms of Fibonacci, but watch out for snitches!
    printf("Enter the number of Fibonacci terms you want to visualize (1 to %d): ", MAX_TERMS);
    scanf("%d", &terms);
    
    // Are they playing a trick on me?
    if (terms < 1 || terms > MAX_TERMS) {
        printf("You must be trying to deceive me! Let's stick to a safer range.\n");
        return -1;
    }
    
    visualize_fibonacci(terms);
    
    // Always backup the output, never trust the screen!
    printf("Output has been prepared. Remember to take precautions.\n");
    
    return 0;
}