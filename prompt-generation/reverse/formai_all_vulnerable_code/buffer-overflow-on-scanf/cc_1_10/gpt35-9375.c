//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function to generate a random number within a given range
int rand_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

//function to generate a random uppercase letter
char rand_upper() {
    return rand_number(65, 90);
}

//function to generate a random lowercase letter
char rand_lower() {
    return rand_number(97, 122);
}

//function to generate a random digit
char rand_digit() {
    return rand_number(48, 57);
}

//function to generate a random symbol
char rand_symbol() {
    char symbols[] = "!@#$%^&*()-_=+/<>,.?;:";
    return symbols[rand_number(0, strlen(symbols) - 1)];
}

//function to shuffle a string
void shuffle_string(char *str) {
    int i, j;
    char temp;
    for (i = strlen(str) - 1; i > 0; i--) {
        j = rand_number(0, i);
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

//function to generate a password
void generate_password(int length, int num_upper, int num_lower, int num_digits, int num_symbols) {
    char password[length];
    int i;
    for (i = 0; i < num_upper; i++) {
        password[i] = rand_upper();
    }
    for (i = num_upper; i < num_upper + num_lower; i++) {
        password[i] = rand_lower();
    }
    for (i = num_upper + num_lower; i < num_upper + num_lower + num_digits; i++) {
        password[i] = rand_digit();
    }
    for (i = num_upper + num_lower + num_digits; i < num_upper + num_lower + num_digits + num_symbols; i++) {
        password[i] = rand_symbol();
    }
    password[length] = '\0';
    shuffle_string(password);
    printf("Generated Password: %s\n", password);
}

int main() {
    int length, num_upper, num_lower, num_digits, num_symbols;
    
    printf("Enter desired password length: ");
    scanf("%d", &length);
    
    printf("Enter number of uppercase letters: ");
    scanf("%d", &num_upper);
    
    printf("Enter number of lowercase letters: ");
    scanf("%d", &num_lower);
    
    printf("Enter number of digits: ");
    scanf("%d", &num_digits);
    
    printf("Enter number of symbols: ");
    scanf("%d", &num_symbols);
    
    srand(time(NULL));
    generate_password(length, num_upper, num_lower, num_digits, num_symbols);

    return 0;
}