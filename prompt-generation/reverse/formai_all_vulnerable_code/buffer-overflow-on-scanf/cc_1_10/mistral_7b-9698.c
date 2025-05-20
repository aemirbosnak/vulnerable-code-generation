//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

// Function to print ASCII art of a hand clapping
void clap() {
    printf("\033[1;31m"); // Set color to red
    printf(" _______       _______\n");
    printf("|\\   ___  \\     |\\   ___  \\ \n");
    printf("| \\_/   \\_|\\_   | \\_/   \\_| \n");
    printf("|  ______   _|  |  ______  \n");
    printf("| |\\  ___  || |  | |\\  ___  |\n");
    printf("| |\\_/   \\_||_|  | |\\_/   \\_| \n");
    printf("| |     |  |  _|  | |     | \n");
    printf("| |     |  |_|   _| |     | \n");
    printf("|_|     |_|   |_|   |_|     |\n");
    printf("                           \n");
    printf("\033[0m"); // Reset color
}

// Function to calculate factorial using recursion
unsigned long long int factorial(unsigned int n) {
    if (n > 22) {
        printf("Error: Factorial not supported for numbers greater than 22.\n");
        exit(1);
    }
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    unsigned int num;
    clock_t start, end;

    printf("\033[1;34m"); // Set color to blue
    printf("\n_______________\n");
    printf("|              |\n");
    printf("| Factorial Fun | \n");
    printf("|              |\n");
    printf("|_______________|\n");
    printf("\033[0m"); // Reset color

    printf("\nEnter a number: ");
    scanf("%u", &num);

    start = clock();
    clap();
    printf("\nCalculating factorial of %u...\n", num);
    unsigned long long int result = factorial(num);
    end = clock();

    printf("\nFactorial of %u is: ", num);
    printf("%llu\n", result);
    printf("Time taken: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}