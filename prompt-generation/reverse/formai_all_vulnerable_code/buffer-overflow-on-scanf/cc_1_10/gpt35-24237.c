//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random upper case alphabet
char random_uppercase_letter() {
    return rand() % 26 + 'A';
}

// Function to generate a random lower case alphabet
char random_lowercase_letter() {
    return rand() % 26 + 'a';
}

// Function to generate a random digit
char random_digit() {
    return rand() % 10 + '0';
}

// Function to generate a random special character
char random_special_char() {
    char special_chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '\"', '\'', '<', '>', ',', '.', '/', '?'};
    return special_chars[rand() % 28];
}

// Function to generate a random character based on the specified type
char generate_random_char(int type) {
    switch (type) {
        case 0:
            return random_uppercase_letter();
        case 1:
            return random_lowercase_letter();
        case 2:
            return random_digit();
        case 3:
            return random_special_char();
        default:
            return ' ';
    }
}

// Function to generate a random secure password of the specified length
void generate_secure_password(int length) {
    srand(time(NULL));

    if (length < 8) {
        printf("Password length too short! Please choose a length of at least 8 characters.\n");
        return;
    }

    int num_uppercase = length / 4;
    int num_lowercase = length / 4;
    int num_digits = length / 4;
    int num_special_chars = length - num_uppercase - num_lowercase - num_digits;

    char password[length];

    for (int i = 0; i < num_uppercase; i++) {
        password[i] = generate_random_char(0);
    }

    for (int i = num_uppercase; i < num_uppercase + num_lowercase; i++) {
        password[i] = generate_random_char(1);
    }

    for (int i = num_uppercase + num_lowercase; i < num_uppercase + num_lowercase + num_digits; i++) {
        password[i] = generate_random_char(2);
    }

    for (int i = num_uppercase + num_lowercase + num_digits; i < length; i++) {
        password[i] = generate_random_char(3);
    }

    // Shuffle the password
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    printf("Your secure password is: ");
    for (int i = 0; i < length; i++) {
        printf("%c", password[i]);
    }
    printf("\n");
}

int main() {
    int length;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired length of your password: ");
    scanf("%d", &length);

    generate_secure_password(length);

    return 0;
}