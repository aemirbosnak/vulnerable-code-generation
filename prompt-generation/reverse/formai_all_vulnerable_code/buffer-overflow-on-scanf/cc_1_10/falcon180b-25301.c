//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 16
#define CHARACTER_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<?>/~"

int main() {
    char password[PASSWORD_LENGTH + 1] = {0};
    int i, j;
    int uppercase = 0;
    int lowercase = 0;
    int number = 0;
    int special = 0;

    printf("Welcome to the Secure Password Generator!\n");
    printf("How many passwords would you like to generate? ");
    scanf("%d", &i);

    srand(time(NULL));

    for (j = 0; j < i; j++) {
        password[0] = CHARACTER_SET[rand() % strlen(CHARACTER_SET)];
        uppercase = rand() % 2;
        lowercase = rand() % 2;
        number = rand() % 2;
        special = rand() % 2;

        int k = 1;
        while (k < PASSWORD_LENGTH) {
            if (uppercase) {
                password[k] = toupper(CHARACTER_SET[rand() % strlen(CHARACTER_SET)]);
                uppercase = 0;
            } else if (lowercase) {
                password[k] = tolower(CHARACTER_SET[rand() % strlen(CHARACTER_SET)]);
                lowercase = 0;
            } else if (number) {
                password[k] = CHARACTER_SET[rand() % strlen(CHARACTER_SET)];
                number = 0;
            } else if (special) {
                password[k] = CHARACTER_SET[rand() % strlen(CHARACTER_SET)];
                special = 0;
            } else {
                password[k] = CHARACTER_SET[rand() % strlen(CHARACTER_SET)];
            }

            k++;
        }

        printf("Password #%d: %s\n", j + 1, password);
    }

    return 0;
}