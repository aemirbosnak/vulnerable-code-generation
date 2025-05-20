//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

double calculate_sum(int count);
double calculate_average(int count, double sum);
void calculate_factorials(int n);
void display_results(double sum, double average, int n);

int main() {
    int count;
    printf("Welcome to the Surprising Arithmetic Adventure!\n");
    
    // Asking for number of values to sum
    printf("Please enter the number of values you want to sum (between 1 and 10): ");
    scanf("%d", &count);

    // Input validation
    while(count < 1 || count > 10) {
        printf("That's not a valid number! Please enter a value between 1 and 10: ");
        scanf("%d", &count);
    }

    double sum = calculate_sum(count);
    double average = calculate_average(count, sum);

    // Let's get a little factorial while we're at it
    int n;
    printf("Now, let's calculate some factorials! Please enter a positive integer (0 to exit): ");
    scanf("%d", &n);

    while (n < 0) {
        printf("Negative numbers are not allowed! Please enter a non-negative integer: ");
        scanf("%d", &n);
    }

    // Factorial calculations till user wants more
    calculate_factorials(n);

    // Finally, let's display the results
    display_results(sum, average, n);

    return 0;
}

double calculate_sum(int count) {
    double sum = 0.0;
    double value;

    for (int i = 1; i <= count; i++) {
        printf("Enter value %d: ", i);
        scanf("%lf", &value);
        sum += value;
    }

    printf("Surprising Sum Calculation Completed!\n");
    return sum;
}

double calculate_average(int count, double sum) {
    double average = sum / count;
    printf("Surprising Average Calculation Completed!\n");
    return average;
}

void calculate_factorials(int n) {
    printf("Calculating factorials from 0 to %d:\n", n);
    for (int i = 0; i <= n; i++) {
        unsigned long long factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }
        printf("%d! = %llu\n", i, factorial);
    }
}

void display_results(double sum, double average, int n) {
    printf("***************************************\n");
    printf("Here are your results from the Surprising Arithmetic Adventure!\n");
    printf("Total Sum: %.2lf\n", sum);
    printf("Average: %.2lf\n", average);
    printf("Factorials calculated up to: %d\n", n);
    printf("Thank you for joining the arithmetic adventure! Until next time...\n");
    printf("***************************************\n");
}