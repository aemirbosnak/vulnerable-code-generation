//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number in a given range
int get_random(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// function to generate a random uppercase letter
char random_uppercase() {
    int random_num = get_random(65, 90);
    return (char)random_num;
}

// function to generate a random lowercase letter
char random_lowercase() {
    int random_num = get_random(97, 122);
    return (char)random_num;
}

// function to generate a random digit
char random_digit() {
    int random_num = get_random(48, 57);
    return (char)random_num;
}

// function to generate a random special character
char random_special() {
    int random_num = get_random(33, 47);
    return (char)random_num;
}

// function to generate a secure password
void generate_password(int length) {
    // initialize the password
    char password[length];
    for (int i = 0; i < length; i++) {
        password[i] = '\0';
    }
    
    // create an array of functions to generate the different types of characters
    char (*generate_functions[4]) ();
    generate_functions[0] = &random_uppercase;
    generate_functions[1] = &random_lowercase;
    generate_functions[2] = &random_digit;
    generate_functions[3] = &random_special;
    
    // flags to ensure that all character types are included in the password
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;
    
    // generate the password
    for (int i = 0; i < length; i++) {
        int random_type = get_random(0, 3);
        password[i] = (*generate_functions[random_type]) ();
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }
    
    // check if the password contains all required character types
    if (has_uppercase && has_lowercase && has_digit && has_special) {
        printf("Your secure password is: %s\n", password);
    } else {
        generate_password(length);
    }
}

int main() {
    // ask the user for the desired length of the password
    int length;
    printf("Enter the desired length of your secure password: ");
    scanf("%d", &length);
    
    // generate the password
    generate_password(length);
    
    return 0;
}