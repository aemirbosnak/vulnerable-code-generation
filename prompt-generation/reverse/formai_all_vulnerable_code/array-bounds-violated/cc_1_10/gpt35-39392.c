//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random uppercase letter
char random_uppercase() {
    return rand() % 26 + 'A';
}

// Function to generate a random lowercase letter
char random_lowercase() {
    return rand() % 26 + 'a';
}

// Function to generate a random digit
char random_digit() {
    return rand() % 10 + '0';
}

// Function to generate a random special character
char random_special() {
    char special[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '{', '}', '[', ']', '|', '\\', ';', ':', '\'', '"', ',', '.', '/', '<', '>', '?'};
    return special[rand() % 30];
}

// Function to generate a random password
void generate_password(char password[], int length) {
    // Generate a random password of the specified length
    for (int i = 0; i < length; i++) {
        int choice = rand() % 4;
        if (choice == 0) {
            password[i] = random_uppercase();
        } else if (choice == 1) {
            password[i] = random_lowercase();
        } else if (choice == 2) {
            password[i] = random_digit();
        } else {
            password[i] = random_special();
        }
    }
    // Add null terminator to password
    password[length] = '\0';
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    int length;
    printf("How long should the password be? ");
    scanf("%d", &length);

    if (length <= 0) {
        printf("Invalid password length!\n");
        return 1;
    }

    char password[length + 1];
    generate_password(password, length);
    printf("Your password is: %s\n", password);

    return 0;
}