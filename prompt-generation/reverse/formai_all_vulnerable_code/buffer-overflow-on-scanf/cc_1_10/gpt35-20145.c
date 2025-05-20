//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 20 // Maximum password length

// Function to generate a random number within a range
int rand_range(int min, int max) {
    return rand() % (max - min) + min;
}

// Function to generate a random lowercase letter
char rand_lower() {
    return (char)rand_range(97, 123);
}

// Function to generate a random uppercase letter
char rand_upper() {
    return (char)rand_range(65, 91);
}

// Function to generate a random digit
char rand_digit() {
    return (char)rand_range(48, 58);
}

// Function to generate a random special character
char rand_special() {
    char specials[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '{', '}', '[', ']', '|', '\\', ';', ':', '\'', '\"', ',', '.', '<', '>', '?', '/'};
    return specials[rand_range(0, 31)];
}

// Function to generate a random password
void generate_password(int length, int num_lower, int num_upper, int num_digits, int num_special, char* password) {
    int i, j;
    char ch;

    // Initialize the password string
    memset(password, 0, length+1);

    // Generate the required number of lowercase letters
    for (i = 0; i < num_lower; ++i) {
        password[i] = rand_lower();
    }

    // Generate the required number of uppercase letters
    for (j = 0; j < num_upper; ++j, ++i) {
        password[i] = rand_upper();
    }

    // Generate the required number of digits
    for (j = 0; j < num_digits; ++j, ++i) {
        password[i] = rand_digit();
    }

    // Generate the required number of special characters
    for (j = 0; j < num_special; ++j, ++i) {
        password[i] = rand_special();
    }

    // Shuffle the characters of the password string
    for (i = 0; i < length; ++i) {
        j = rand_range(i, length);
        ch = password[i];
        password[i] = password[j];
        password[j] = ch;
    }
}

int main() {
    srand((unsigned int)time(NULL)); // Seed the random number generator

    int length;
    printf("Enter the length of the password (maximum %d): ", MAX_LENGTH);
    scanf("%d", &length);

    if (length > MAX_LENGTH || length < 1) {
        printf("Invalid password length.\n");
        return 1;
    }

    int num_upper, num_lower, num_digits, num_special;
    printf("Enter the number of lowercase letters: ");
    scanf("%d", &num_lower);
    printf("Enter the number of uppercase letters: ");
    scanf("%d", &num_upper);
    printf("Enter the number of digits: ");
    scanf("%d", &num_digits);
    printf("Enter the number of special characters: ");
    scanf("%d", &num_special);

    if (num_lower + num_upper + num_digits + num_special != length) {
        printf("Invalid parameters.\n");
        return 1;
    }

    char password[MAX_LENGTH+1];
    generate_password(length, num_lower, num_upper, num_digits, num_special, password);
    printf("Generated password: %s\n", password);

    return 0;
}