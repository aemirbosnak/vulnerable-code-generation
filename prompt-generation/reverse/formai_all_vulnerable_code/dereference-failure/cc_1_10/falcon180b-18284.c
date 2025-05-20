//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int rand_special_char() {
    char special_chars[] = "!@#$%^&*()_+-=[]{}\\|;':\",./<>?";
    return rand() % 62; // 62 special characters in total
}

int rand_digit() {
    return rand() % 10;
}

int rand_lowercase() {
    return rand() % 26;
}

int rand_uppercase() {
    return rand() % 26;
}

void generate_password(int length, char *password) {
    int i;
    for (i = 0; i < length; i++) {
        switch (rand() % 5) {
            case 0:
                // lowercase letter
                password[i] = rand_lowercase() + 'a';
                break;
            case 1:
                // uppercase letter
                password[i] = rand_uppercase() + 'A';
                break;
            case 2:
                // digit
                password[i] = rand_digit() + '0';
                break;
            case 3:
                // special character
                password[i] = rand_special_char();
                break;
            default:
                // any character
                password[i] = rand_int(0, 3);
        }
    }
    password[length - 1] = '\0';
}

int main() {
    int length;
    char password[50];

    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    srand(time(0));
    generate_password(length, password);

    printf("Your new password is: %s\n", password);

    return 0;
}