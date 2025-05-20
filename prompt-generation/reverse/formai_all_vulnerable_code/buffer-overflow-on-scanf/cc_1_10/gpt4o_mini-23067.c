//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void welcome_message() {
    printf("=================================\n");
    printf("     A Mathematical Quest       \n");
    printf("      in the Kingdom of C       \n");
    printf("=================================\n");
}

void display_menu() {
    printf("Choose thy quest:\n");
    printf("1. Calculate the sum of a sequence\n");
    printf("2. Find the greatest common divisor\n");
    printf("3. Check if a number is prime\n");
    printf("4. Exit the realm\n");
    printf("Enter thy choice (1-4): ");
}

int sum_of_sequence(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int is_prime(int num) {
    if (num <= 1) return 0; 
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    welcome_message();

    int choice;
    do {
        display_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            int start, end;
            printf("Enter the starting number of thy sequence: ");
            scanf("%d", &start);
            printf("Enter the ending number of thy sequence: ");
            scanf("%d", &end);
            int result = sum_of_sequence(start, end);
            printf("The sum of the sequence from %d to %d is: %d\n", start, end, result);
        } 
        else if (choice == 2) {
            int a, b;
            printf("Enter the first noble number: ");
            scanf("%d", &a);
            printf("Enter the second noble number: ");
            scanf("%d", &b);
            int result = gcd(a, b);
            printf("The greatest common divisor of %d and %d is: %d\n", a, b, result);
        } 
        else if (choice == 3) {
            int num;
            printf("Enter a number to check its primality: ");
            scanf("%d", &num);
            if (is_prime(num)) {
                printf("%d is a prime number, worthy of a knight!\n", num);
            } else {
                printf("%d is not a prime number, unworthy of a quest!\n", num);
            }
        } 
        else if (choice == 4) {
            printf("Farewell, brave adventurer! Until we meet again in the realm of C!\n");
        } 
        else {
            printf("Thy choice is not valid. Choose again!\n");
        }

    } while (choice != 4);

    return 0;
}