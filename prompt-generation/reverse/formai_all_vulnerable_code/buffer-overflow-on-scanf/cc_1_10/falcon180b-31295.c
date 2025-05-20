//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8
#define NUM_SPECIAL_CHARS 5
#define NUM_UPPER_CASE_CHARS 5
#define NUM_LOWER_CASE_CHARS 5
#define NUM_NUMBERS 5

// Function to generate a random password
void generate_password(int length, char *password) {
    int i;
    char special_chars[] = "!@#$%^&*()_+";
    char upper_case_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower_case_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";

    // Initialize the password with random characters
    for(i=0; i<length; i++) {
        password[i] = rand() % 62 + 'a';
    }

    // Add special characters
    for(i=0; i<NUM_SPECIAL_CHARS; i++) {
        int index = rand() % strlen(special_chars);
        password[rand() % length] = special_chars[index];
    }

    // Add upper case characters
    for(i=0; i<NUM_UPPER_CASE_CHARS; i++) {
        int index = rand() % strlen(upper_case_chars);
        password[rand() % length] = upper_case_chars[index];
    }

    // Add lower case characters
    for(i=0; i<NUM_LOWER_CASE_CHARS; i++) {
        int index = rand() % strlen(lower_case_chars);
        password[rand() % length] = lower_case_chars[index];
    }

    // Add numbers
    for(i=0; i<NUM_NUMBERS; i++) {
        int index = rand() % strlen(numbers);
        password[rand() % length] = numbers[index];
    }
}

int main() {
    int length;
    char password[MAX_PASSWORD_LENGTH];

    // Get password length from user
    printf("Enter password length (minimum %d, maximum %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);

    // Generate password
    srand(time(NULL));
    generate_password(length, password);

    // Print password
    printf("Password: %s\n", password);

    return 0;
}