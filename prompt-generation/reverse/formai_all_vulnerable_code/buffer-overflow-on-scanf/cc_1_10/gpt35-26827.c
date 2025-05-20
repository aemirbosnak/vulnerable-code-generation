//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random uppercase letter
char generate_random_uppercase() {
    return rand() % 26 + 65;
}

// Function to generate a random lowercase letter
char generate_random_lowercase() {
    return rand() % 26 + 97;
}

// Function to generate a random digit
char generate_random_digit() {
    return rand() % 10 + 48;
}

// Function to generate a random special character
char generate_random_special() {
    char special_characters[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_',
                                  '+', '-', '=', '{', '}', '[', ']', ';', ':', '<', '>', ',', '.', '?'};
    return special_characters[rand() % 23];
}

// Function to generate a secure password of a given length
char *generate_secure_password(int length) {
    char *password = (char*) malloc(length * sizeof(char));
    srand(time(NULL));
    int i;
    for(i = 0; i < length; i++) {
        int choice = rand() % 4;
        switch(choice) {
            // Generate a random uppercase letter
            case 0:
                password[i] = generate_random_uppercase();
                break;
            // Generate a random lowercase letter
            case 1:
                password[i] = generate_random_lowercase();
                break;
            // Generate a random digit
            case 2:
                password[i] = generate_random_digit();
                break;
            // Generate a random special character
            case 3:
                password[i] = generate_random_special();
                break;
        }
    }
    password[length] = '\0'; // Append NULL character to the end of the string
    return password;
}

int main() {
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    char *password = generate_secure_password(length);
    printf("Your secure password is: %s\n", password);
    free(password);
    return 0;
}