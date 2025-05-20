//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100

// Function to generate a random password
void generate_password(char* password, int length) {
    const char* chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}|:<>?-=[]\\;',./";
    int chars_length = strlen(chars);
    for(int i=0; i<length; i++) {
        password[i] = chars[rand() % chars_length];
    }
    password[length] = '\0';
}

// Function to check password strength
int check_password_strength(char* password) {
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;
    int special_count = 0;
    int length = strlen(password);

    // Count the number of lowercase letters
    for(int i=0; i<length; i++) {
        if(islower(password[i])) {
            lowercase_count++;
        }
    }

    // Count the number of uppercase letters
    for(int i=0; i<length; i++) {
        if(isupper(password[i])) {
            uppercase_count++;
        }
    }

    // Count the number of digits
    for(int i=0; i<length; i++) {
        if(isdigit(password[i])) {
            digit_count++;
        }
    }

    // Count the number of special characters
    for(int i=0; i<length; i++) {
        if(!isalnum(password[i])) {
            special_count++;
        }
    }

    // Calculate the password strength
    int strength = 0;
    if(length >= 8) {
        strength++;
    }
    if(lowercase_count > 0) {
        strength++;
    }
    if(uppercase_count > 0) {
        strength++;
    }
    if(digit_count > 0) {
        strength++;
    }
    if(special_count > 0) {
        strength++;
    }

    return strength;
}

int main() {
    srand(time(NULL));

    // Prompt user for password length
    int length;
    printf("Enter password length (between 8 and 100): ");
    scanf("%d", &length);

    // Check if password length is valid
    if(length < 8 || length > 100) {
        printf("Invalid password length.\n");
        return 1;
    }

    // Generate a random password
    char password[MAX_PASSWORD_LENGTH];
    generate_password(password, length);

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Check password strength
    int strength = check_password_strength(password);
    printf("Password strength: %d\n", strength);

    return 0;
}