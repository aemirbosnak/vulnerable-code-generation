//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 20
#define CHAR_SET_SIZE 10

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    int result;

    // Calculate the range
    result = rand() % (max - min + 1) + min;

    return result;
}

// Function to generate a random character from the given character set
char rand_char(void) {
    int index;
    char set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/~`";

    index = rand_range(0, CHAR_SET_SIZE - 1);

    return set[index];
}

int main() {
    int num_passwords, i, j;
    char password[PASSWORD_LENGTH];
    char** passwords;

    srand(time(NULL)); // Seed the random number generator

    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &num_passwords);

    passwords = (char**)malloc(num_passwords * sizeof(char*));

    for (i = 0; i < num_passwords; i++) {
        passwords[i] = (char*)malloc((PASSWORD_LENGTH + 1) * sizeof(char));

        printf("\nPassword %d:\n", i + 1);

        for (j = 0; j < PASSWORD_LENGTH; j++) {
            password[j] = rand_char();
            printf("%c", password[j]);
        }

        passwords[i][PASSWORD_LENGTH] = '\0'; // Set the null terminator

        strcpy(passwords[i], password); // Copy the password to the array

        printf("\n");
    }

    printf("\nYour %d passwords are generated and stored in the array.\n", num_passwords);

    for (i = 0; i < num_passwords; i++) {
        printf("Password %d: %s\n", i + 1, passwords[i]);
    }

    for (i = 0; i < num_passwords; i++) {
        free(passwords[i]); // Free the memory allocated for each password
    }

    free(passwords); // Free the memory allocated for the array

    return 0;
}