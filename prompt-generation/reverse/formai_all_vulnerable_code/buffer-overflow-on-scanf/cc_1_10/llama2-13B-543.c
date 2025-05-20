//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

int main() {
    struct person person;
    int result;

    // Ask the user for their name and age
    printf("What is your name? ");
    fgets(person.name, MAX_NAME_LENGTH, stdin);
    printf("How old are you? ");
    scanf("%d", &person.age);

    // Check for invalid input
    if (person.age < 0 || person.age > MAX_AGE) {
        printf("Invalid age. Please enter a positive integer less than or equal to %d.\n", MAX_AGE);
        return 1;
    }

    // Check if the name is too long
    if (strlen(person.name) > MAX_NAME_LENGTH - 1) {
        printf("Name too long. Please enter a name with a maximum of %d characters.\n", MAX_NAME_LENGTH);
        return 1;
    }

    // Check if the age is valid
    result = validate_age(person.age);
    if (result != 0) {
        printf("Invalid age. Please enter a positive integer less than or equal to %d.\n", MAX_AGE);
        return 1;
    }

    // Print a success message
    printf("Hello, %s! You are %d years old.\n", person.name, person.age);

    return 0;
}

int validate_age(int age) {
    // Check if the age is valid
    if (age < 0 || age > MAX_AGE) {
        return 1; // Return 1 if the age is invalid
    }

    // Check if the age is a prime number
    if (is_prime(age)) {
        return 0; // Return 0 if the age is a prime number
    }

    // Return 1 if the age is not a prime number
    return 1;
}

int is_prime(int num) {
    if (num <= 1) {
        return 0; // 0 and 1 are not prime
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }

    return 1; // Prime
}