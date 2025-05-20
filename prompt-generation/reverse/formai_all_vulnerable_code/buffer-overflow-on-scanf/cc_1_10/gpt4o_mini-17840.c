//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: funny
#include <stdio.h>

// This is the Great Fibonacci Circus! Prepare to be amazed!
#define MAX_LENGTH 15

void printSpaces(int count) {
    for (int i = 0; i < count; i++)
        putchar(' '); // Space between the numbers, much like flying trapeze artists!
}

// Function to generate Fibonacci sequence
void generateFibonacci(int n, long long fib[]) {
    // Starting the show with the first two acts
    fib[0] = 0;
    fib[1] = 1;
    
    // Preparing for a grand entrance of the Fibonacci numbers
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; // The magic trick of Fibonacci!
    }
}

// Function to visualize the Fibonacci numbers in a funny way
void visualizeFibonacci(int n, long long fib[]) {
    printf("\nWelcome to the Great Fibonacci Circus, where numbers become stars!\n");
    printf("---------------------------------------------------------------\n");
   
    for (int i = 0; i < n; i++) {
        printf("Act %d: ", i + 1);
        if (fib[i] < 10) {
            printSpaces(4); // A bit of extra space for the little ones!
        } else if (fib[i] < 100) {
            printSpaces(3); // They grow fast, just like the audience's anticipation!
        } else {
            printSpaces(2); // Big boys need less space to show off!
        }
        
        printf("✨ %lld ✨\n", fib[i]); // Sparkle, sparkle, shine!
    }
    
    printf("---------------------------------------------------------------\n");
    printf("And that concludes our show! Remember, Fibonacci was here.🎩\n");
}

int main() {
    long long fibonacci[MAX_LENGTH];
    
    printf("How many acts do you want to see in the Fibonacci Circus? (Max %d): ", MAX_LENGTH);
    int n;
    scanf("%d", &n);
    
    if (n > MAX_LENGTH) {
        printf("Whoa there, friend! That's a bit too many acts! We'll stick with %d.\n", MAX_LENGTH);
        n = MAX_LENGTH; // Reining you in like a stubborn circus elephant!
    } else if (n < 1) {
        printf("Come on! At least one act is needed for a circus! Let's go with 1.\n");
        n = 1; // Making a solitary lion act, as minimum as it gets!
    }
    
    generateFibonacci(n, fibonacci);
    visualizeFibonacci(n, fibonacci);
    
    return 0; // The end of the show, exit stage left!
}