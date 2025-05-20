//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random uppercase letter
char random_uppercase() {
    return (char) (rand() % 26 + 65);
}

// Function to generate a random lowercase letter
char random_lowercase() {
    return (char) (rand() % 26 + 97);
}

// Function to generate a random digit
char random_digit() {
    return (char) (rand() % 10 + 48);
}

// Function to generate a random special character
char random_special() {
    char special[] = "!@#$%^&*()[]{}<>,.?/~_+|\\:";
    return special[rand() % 23];
}

// Function to generate a random character based on the given type
char random_character(int type) {
    switch(type) {
        case 0:
            return random_uppercase();
        case 1:
            return random_lowercase();
        case 2:
            return random_digit();
        case 3:
            return random_special();
        default:
            return random_uppercase();
    }
}

// Function to generate a secure password
void generate_password(char password[], int length) {
    srand(time(NULL));
    int type;
    for(int i=0; i<length; i++) {
        type = rand() % 4;
        password[i] = random_character(type);
    }
    password[length] = '\0';
}

int main() {
    int length;
    printf("Enter the length of password: ");
    scanf("%d", &length);

    char password[length+1];
    generate_password(password, length);

    printf("Your secure password is: %s\n", password);

    return 0;
}