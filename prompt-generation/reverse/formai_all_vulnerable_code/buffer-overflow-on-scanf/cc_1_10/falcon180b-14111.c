//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

char *generate_password(int length) {
    char *password = malloc(MAX_PASSWORD_LENGTH * sizeof(char));
    int i;

    for (i = 0; i < length; i++) {
        int random_index = rand() % 4;

        switch (random_index) {
            case 0:
                password[i] = 'a' + rand() % 26;
                break;

            case 1:
                password[i] = 'A' + rand() % 26;
                break;

            case 2:
                password[i] = '0' + rand() % 10;
                break;

            case 3:
                password[i] = '!' + rand() % 6;
                break;
        }
    }

    password[length] = '\0';

    return password;
}

int main() {
    srand(time(NULL));

    int password_length;

    printf("Enter the desired password length: ");
    scanf("%d", &password_length);

    if (password_length > MAX_PASSWORD_LENGTH || password_length < 1) {
        printf("Invalid password length.\n");
        return 1;
    }

    char *password = generate_password(password_length);

    printf("Your password is: %s\n", password);

    free(password);

    return 0;
}