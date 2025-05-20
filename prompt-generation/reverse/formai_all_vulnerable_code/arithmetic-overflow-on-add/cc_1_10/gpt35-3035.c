//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random lowercase letter
char rand_lowercase() {
    int random_num = rand() % 26;
    char letter = 'a' + random_num;
    return letter;
}

// Function to generate a random uppercase letter
char rand_uppercase() {
    int random_num = rand() % 26;
    char letter = 'A' + random_num;
    return letter;
}

// Function to generate a random digit
char rand_digit() {
    int random_num = rand() % 10;
    char digit = '0' + random_num;
    return digit;
}

// Function to generate a random special character
char rand_special() {
    int random_num = rand() % 4;
    char special_char;
    switch(random_num) {
        case 0:
            special_char = '!';
            break;
        case 1:
            special_char = '@';
            break;
        case 2:
            special_char = '#';
            break;
        case 3:
            special_char = '$';
            break;
    }
    return special_char;
}

// Function to generate a random password
void generate_password(char password[], int length) {
    int i;
    for(i=0; i<length; i++) {
        int random_num = rand() % 4;
        switch(random_num) {
            case 0:
                password[i] = rand_lowercase();
                break;
            case 1:
                password[i] = rand_uppercase();
                break;
            case 2:
                password[i] = rand_digit();
                break;
            case 3:
                password[i] = rand_special();
                break;
        }
    }
    password[length] = '\0';
}

int main() {
    int password_length;

    // Get desired password length from user
    printf("Enter desired length of password: ");
    scanf("%d", &password_length);

    char password[password_length+1];
    srand(time(NULL));
    generate_password(password, password_length);

    // Print generated password
    printf("Generated password: %s\n", password);

    return 0;
}