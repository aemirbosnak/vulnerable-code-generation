//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random lowercase letter
char random_lower_case_letter() {
    return (char)((rand() % 26) + 97);
}

// Function to generate a random uppercase letter
char random_upper_case_letter() {
    return (char)((rand() % 26) + 65);
}

// Function to generate a random digit
char random_digit() {
    return (char)((rand() % 10) + 48);
}

// Function to generate a random special character
char random_special_char() {
    char special_chars[] = {'@', '#', '$', '%', '&', '?'};
    return special_chars[rand() % 6];
}

// Function to check if password meets requirements
bool meets_requirements(char password[], int length) {
    bool upper_case = false,
         lower_case = false,
         digit = false,
         special_char = false;
    
    for (int i = 0; i < length; ++i) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper_case = true;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lower_case = true;
        } else if (password[i] >= '0' && password[i] <= '9') {
            digit = true;
        } else {
            special_char = true;
        }
    }
    
    return upper_case && lower_case && digit && special_char;
}

int main() {
    int length = 0;
    
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired password length: ");
    scanf("%d", &length);
    
    while (length < 8) {
        printf("Password length must be at least 8 characters long. Please try again: ");
        scanf("%d", &length);
    }
    
    srand(time(NULL));
    
    char password[length + 1];
    
    while (!meets_requirements(password, length)) {
        for (int i = 0; i < length; ++i) {
            int rand_num = rand() % 4;
            if (rand_num == 0) {
                password[i] = random_upper_case_letter();
            } else if (rand_num == 1) {
                password[i] = random_lower_case_letter();
            } else if (rand_num == 2) {
                password[i] = random_digit();
            } else {
                password[i] = random_special_char();
            }
        }
        
        password[length] = '\0';
    }
    
    printf("\nYour secure password is: %s\n", password);
    
    return 0;
}