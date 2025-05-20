//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32

void generate_password(char* password, int length) {
    const char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    const char numeric_chars[] = "0123456789";
    const char special_chars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    char* chars = (char*) malloc(sizeof(char) * strlen(uppercase_chars) +
                                 sizeof(char) * strlen(lowercase_chars) +
                                 sizeof(char) * strlen(numeric_chars) +
                                 sizeof(char) * strlen(special_chars));

    strcat(chars, uppercase_chars);
    strcat(chars, lowercase_chars);
    strcat(chars, numeric_chars);
    strcat(chars, special_chars);

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int rand_index = rand() % (strlen(chars));
        password[i] = chars[rand_index];
    }

    password[length] = '\0';
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter the desired password length (between 8 and 32 characters): ");
    scanf("%d", &length);

    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }

    generate_password(password, length);

    printf("Generated password: %s\n", password);

    return 0;
}