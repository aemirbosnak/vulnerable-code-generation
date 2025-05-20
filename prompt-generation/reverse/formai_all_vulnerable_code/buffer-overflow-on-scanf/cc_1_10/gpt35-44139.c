//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random Fibonacci numbers
int fibonacci(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

// function to generate random color values
char *randomColor() {
    char *color = (char *)malloc(7*sizeof(char));
    srand(time(0));
    for (int i=0; i<6; i++) {
        int r = rand()%16;
        if(r < 10)
            color[i] = r + '0';
        else
            color[i] = r - 10 + 'A';
    }
    color[6] = '\0';
    return color;
}

int main() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");

    // prompt user for input
    int n;
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);

    // generate and display the sequence
    printf("The Fibonacci sequence is: ");
    for (int i=0; i<n; i++) {
        int num = fibonacci(i);
        printf("%d ", num);

        // set color based on last digit of the number
        char *color = randomColor();
        if (num%10 == 0) {
            printf("\033[1;37m"); // white
        }
        else if (num%2 == 0) {
            printf("\033[1;34m"); // blue
        }
        else {
            printf("\033[1;31m"); // red
        }

        // print the number in color
        printf("%d", num);
        printf("\033[0m"); // reset color
        printf(" ");
    }

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}