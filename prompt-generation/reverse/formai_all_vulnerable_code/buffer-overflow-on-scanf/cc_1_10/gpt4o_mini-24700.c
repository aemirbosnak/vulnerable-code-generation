//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void print_with_color(const char* text, const char* color) {
    // Print text in specified color
    printf("%s%s\033[0m", color, text);
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void generate_primes(int limit, FILE* file) {
    const char* color_red = "\033[31m";
    const char* color_green = "\033[32m";
    
    print_with_color("Generating prime numbers...\n", color_green);
    fprintf(file, "Prime numbers up to %d:\n", limit);
    
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            // Print the prime number in red
            printf("%s%d ", color_red, num);
            fprintf(file, "%d\n", num);
        }
    }
    printf("\n");
    print_with_color("Prime numbers have been saved to file.\n", color_green);
}

void display_menu() {
    printf("----- Prime Number Generator -----\n");
    printf("1. Generate prime numbers\n");
    printf("2. Exit\n");
    printf("---------------------------------\n");
}

int main() {
    int choice = 0;
    int limit;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the limit to generate prime numbers: ");
                scanf("%d", &limit);
                
                if (limit < 2) {
                    printf("Please enter a limit greater than 1.\n");
                    break;
                }

                // Open the file to save prime numbers
                FILE* file = fopen("prime_numbers.txt", "w");
                if (!file) {
                    printf("Error opening file!\n");
                    return -1;
                }

                generate_primes(limit, file);
                fclose(file);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}