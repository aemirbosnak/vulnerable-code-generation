//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 64

char *generate_password(int length) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        return NULL;
    }

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int character = rand() % 94 + 33;
        if ((character >= 48 && character <= 57) || (character >= 65 && character <= 90) || (character >= 97 && character <= 122)) {
            password[i] = (char) character;
        } else {
            i--;
        }
    }

    password[length] = '\0';

    return password;
}

int main() {
    int length;

    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);

    if (length < 1 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Please enter a length between 1 and %d.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    char *password = generate_password(length);
    if (password == NULL) {
        printf("Error generating password. Please try again.\n");
        return 1;
    }

    printf("Your password is: %s\n", password);

    free(password);

    return 0;
}