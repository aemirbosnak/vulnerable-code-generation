//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>

#define MIN_AGE 18
#define MAX_AGE 120
#define MAX_EMAIL_LENGTH 50

bool validate_age(int age) {
    if (age < MIN_AGE || age > MAX_AGE) {
        printf("Invalid age. Please enter an age between %d and %d.\n", MIN_AGE, MAX_AGE);
        return false;
    }

    return true;
}

bool validate_email(char email[]) {
    int i = 0;
    while (email[i] != '\0') {
        if (i >= MAX_EMAIL_LENGTH) {
            printf("Email is longer than %d characters. Please enter a shorter email.\n", MAX_EMAIL_LENGTH);
            return false;
        }

        if (email[i] == '@') {
            return true;
        }

        i++;
    }

    printf("Invalid email. Please enter a valid email address.\n");
    return false;
}

int main() {
    printf("Welcome to the data validation program!\n");

    char name[20];
    int age;
    char email[MAX_EMAIL_LENGTH];

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your age: ");
    scanf("%d", &age);
    while (!validate_age(age)) {
        printf("Please enter your age: ");
        scanf("%d", &age);
    }

    printf("Please enter your email address: ");
    scanf("%s", email);
    while (!validate_email(email)) {
        printf("Please enter your email address: ");
        scanf("%s", email);
    }

    printf("Congratulations, your data has been validated!\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Email: %s\n", email);

    return 0;
}