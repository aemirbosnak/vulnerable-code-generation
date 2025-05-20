//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int rand_num(int min, int max) {
    int num = (rand() % (max - min + 1)) + min; 
    return num;
}

// Function to display the Fibonacci sequence as a visualizer
void fibonacci_visualizer(int n) {
    int a = 0, b = 1, c, i;
    int rand_min = 1, rand_max = 10; // Set the range of possible random numbers
    
    printf("\n-- Fibonacci Sequence Visualizer --\n\n");
    
    for (i = 1; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("%d: ", c);
        
        int j;
        for (j = 1; j <= c; j++) {
            int k;
            for (k = 1; k <= c; k++) {
                int random_num = rand_num(rand_min, rand_max);
                if (random_num > (k+j)/2) {
                    printf("*");
                } else {
                    printf("-");
                }
            }
            printf("   ");
        }
        printf("\n");
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);
    fibonacci_visualizer(n); // Call the function to display the visualizer
    
    return 0;
}