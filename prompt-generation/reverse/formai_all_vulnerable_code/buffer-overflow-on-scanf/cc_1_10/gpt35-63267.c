//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

char lowercase_alphabets[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase_alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char special_characters[] = "!@#$%^&*()_+=-[]}{|;':\",./?><";

char generate_random_character(char *characters, int length) {
    int random_number = rand() % length;
    return characters[random_number];
}

char generate_random_lowercase_alphabet() {
    return generate_random_character(lowercase_alphabets, 26);
}

char generate_random_uppercase_alphabet() {
    return generate_random_character(uppercase_alphabets, 26);
}

char generate_random_number() {
    return generate_random_character(numbers, 10);
}

char generate_random_special_character() {
    return generate_random_character(special_characters, 30);
}

char generate_random_password_character() {
    int random_number = rand() % 4;
    if (random_number == 0) {
        return generate_random_lowercase_alphabet();
    } else if (random_number == 1) {
        return generate_random_uppercase_alphabet();
    } else if (random_number == 2) {
        return generate_random_number();
    } else {
        return generate_random_special_character();
    }
}

void generate_secure_password(int length) {
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Password length must be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return;
    }

    char password[length];

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        password[i] = generate_random_password_character();
    }

    password[length] = '\0';

    printf("Your super secure password is: %s\n", password);
}

int main() {
    int password_length;

    printf("Enter your desired password length between %d and %d: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    generate_secure_password(password_length);

    return 0;
}