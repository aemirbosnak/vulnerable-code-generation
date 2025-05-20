//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
    // Initialize variables
    int age, name_length;
    char name[MAX_NAME_LENGTH];
    struct tm *time_info;

    // Get the current time
    time_t now = time(NULL);
    time_info = localtime(&now);

    // Get the user's name and age
    printf("What is your name? ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name_length = strlen(name);
    printf("How old are you? ");
    scanf("%d", &age);

    // Check if the name is valid
    if (name_length > MAX_NAME_LENGTH) {
        printf("Error: Name too long (max %d characters)\n", MAX_NAME_LENGTH);
        return 1;
    }

    // Check if the age is valid
    if (age < 0 || age > MAX_AGE) {
        printf("Error: Age must be between 0 and %d\n", MAX_AGE);
        return 2;
    }

    // Print the user's information
    printf("Hello, %s! You are %d years old.\n", name, age);

    // Generate a random number between 1 and 10
    int random_num = rand() % 10 + 1;

    // Check if the random number is prime
    if (random_num == 1 || random_num == 2 || random_num % 2 == 0) {
        printf("Error: Random number %d is not prime\n", random_num);
        return 3;
    }

    // Print the result
    printf("Congratulations, %s! You are %d years old and the random number is prime.\n", name, age);

    return 0;
}