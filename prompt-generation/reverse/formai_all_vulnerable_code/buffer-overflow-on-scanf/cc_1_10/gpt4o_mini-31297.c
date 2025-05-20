//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Not a prime number
    }
    return 1; // Number is prime
}

// Function to find all prime numbers up to a limit
void find_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

// Function to calculate the average of found primes
double calculate_average(int limit) {
    int sum = 0;
    int count = 0;
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            sum += num;
            count++;
        }
    }
    return (count > 0) ? (double)sum / count : 0;
}

// Main function
int main() {
    int limit;
    char choice;
    
    do {
        // Prompt user for input
        printf("Enter the upper limit to find prime numbers: ");
        scanf("%d", &limit);
        
        // Find and display prime numbers
        find_primes(limit);
        
        // Calculate and display the average
        double average = calculate_average(limit);
        printf("The average of prime numbers up to %d is: %.2f\n", limit, average);
        
        // Ask user if they want to continue
        printf("Would you like to enter another limit? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any newline character
        
    } while(choice == 'y' || choice == 'Y');
    
    printf("Thank you for using the prime finder!\n");
    return 0;
}