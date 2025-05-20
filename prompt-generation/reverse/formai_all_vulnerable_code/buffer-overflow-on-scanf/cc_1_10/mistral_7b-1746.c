//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_AGE 0
#define MAX_AGE 100

void get_fortune(int age);

int main() {
    int age;

    // Initialize random seed
    srand(time(NULL));

    printf("Welcome to the C Automated Fortune Teller!\n");
    printf("Please enter your age: ");
    scanf("%d", &age);

    // Check if age is valid
    if (age < MIN_AGE || age > MAX_AGE) {
        printf("Invalid age! Exiting...\n");
        return 1;
    }

    // Generate and print fortune based on age
    get_fortune(age);

    return 0;
}

void get_fortune(int age) {
    int random_number;

    // Generate random number between 0 and 4
    random_number = rand() % 5;

    switch (random_number) {
        case 0:
            printf("You will find happiness in unexpected places.\n");
            break;
        case 1:
            printf("Success will come to you in the form of a friend.\n");
            break;
        case 2:
            printf("Your hard work will pay off soon.\n");
            break;
        case 3:
            printf("You will encounter challenges, but you will overcome them.\n");
            break;
        case 4:
            printf("Prepare for a surprise that will change your life.\n");
            break;
        default:
            printf("An error occurred. Please try again.\n");
            break;
    }
}