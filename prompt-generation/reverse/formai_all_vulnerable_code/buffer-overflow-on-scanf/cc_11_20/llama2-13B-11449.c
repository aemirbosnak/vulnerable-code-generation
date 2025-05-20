//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
    int age, name_length;
    char name[MAX_NAME_LENGTH];
    struct {
        int error_code;
        char error_message[100];
    } errors[3];

    // Initialize errors
    for (int i = 0; i < 3; i++) {
        errors[i].error_code = 0;
        errors[i].error_message[0] = '\0';
    }

    // Get name and age
    printf("What is your name? ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[MAX_NAME_LENGTH - 1] = '\0'; // Truncate newlines

    printf("How old are you? ");
    scanf("%d", &age);

    // Check for invalid input
    if (age < 0 || age > MAX_AGE) {
        errors[0].error_code = 1;
        sprintf(errors[0].error_message, "Age must be between 0 and %d", MAX_AGE);
    }

    // Check for too-long name
    if (strlen(name) > MAX_NAME_LENGTH) {
        errors[1].error_code = 2;
        sprintf(errors[1].error_message, "Name too long (max %d characters)", MAX_NAME_LENGTH);
    }

    // Check for empty name
    if (strlen(name) == 0) {
        errors[2].error_code = 3;
        sprintf(errors[2].error_message, "Name cannot be empty");
    }

    // Print errors and exit
    if (errors[0].error_code || errors[1].error_code || errors[2].error_code) {
        printf("Error(s):\n");
        for (int i = 0; i < 3; i++) {
            if (errors[i].error_code) {
                printf("  %d: %s\n", errors[i].error_code, errors[i].error_message);
            }
        }
        exit(EXIT_FAILURE);
    }

    // Success! Print name and age
    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0;
}