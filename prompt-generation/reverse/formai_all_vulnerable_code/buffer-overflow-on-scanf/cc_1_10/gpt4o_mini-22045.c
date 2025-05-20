//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 128
#define MIN_LENGTH 8

void generate_password(char *password, int length, int use_upper, int use_lower, int use_numbers, int use_special) {
    const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lower[] = "abcdefghijklmnopqrstuvwxyz";
    const char numbers[] = "0123456789";
    const char special[] = "!@#$%^&*()-_=+[]{};:,.<>?";

    char pool[MAX_LENGTH];
    int pool_size = 0;

    if (use_upper) {
        strcpy(pool + pool_size, upper);
        pool_size += strlen(upper);
    }
    if (use_lower) {
        strcpy(pool + pool_size, lower);
        pool_size += strlen(lower);
    }
    if (use_numbers) {
        strcpy(pool + pool_size, numbers);
        pool_size += strlen(numbers);
    }
    if (use_special) {
        strcpy(pool + pool_size, special);
        pool_size += strlen(special);
    }

    // Check if at least one character type is selected
    if (pool_size == 0) {
        fprintf(stderr, "At least one character type must be selected.\n");
        exit(EXIT_FAILURE);
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the password
    for (int i = 0; i < length; i++) {
        password[i] = pool[rand() % pool_size];
    }
    password[length] = '\0'; // Null-terminate the string
}

int main() {
    int length;
    int use_upper, use_lower, use_numbers, use_special;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired length of the password (%d - %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        fprintf(stderr, "Error: Password length must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return EXIT_FAILURE;
    }

    printf("Include uppercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &use_upper);
    printf("Include lowercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &use_lower);
    printf("Include numbers? (1 for Yes, 0 for No): ");
    scanf("%d", &use_numbers);
    printf("Include special characters? (1 for Yes, 0 for No): ");
    scanf("%d", &use_special);

    char password[MAX_LENGTH + 1];
    generate_password(password, length, use_upper, use_lower, use_numbers, use_special);

    printf("Generated Password: %s\n", password);
    return EXIT_SUCCESS;
}