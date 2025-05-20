//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Function to check if the name is valid
int is_name_valid(const char *name) {
    int len = strlen(name);
    if (len < 1 || len > MAX_NAME_LEN) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isalnum(name[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to check if the age is valid
int is_age_valid(int age) {
    if (age < 0 || age > MAX_AGE) {
        return 0;
    }

    return 1;
}

int main() {
    // Get the name from the user
    printf("Enter your name: ");
    char name[MAX_NAME_LEN];
    fgets(name, MAX_NAME_LEN, stdin);

    // Check if the name is valid
    if (!is_name_valid(name)) {
        printf("Invalid name. Please enter a valid name again.\n");
        return 1;
    }

    // Get the age from the user
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check if the age is valid
    if (!is_age_valid(age)) {
        printf("Invalid age. Please enter a valid age again.\n");
        return 1;
    }

    // Do something with the name and age
    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0;
}