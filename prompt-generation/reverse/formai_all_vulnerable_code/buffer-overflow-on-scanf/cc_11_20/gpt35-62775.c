//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    int length, i, choice;

    printf("Choose a password length:\n");
    scanf("%d", &length);

    char password[length];

    printf("Choose a password type:\n[1] Alphanumeric\n[2] Alphabetic\n[3] Numeric\n");
    scanf("%d", &choice);

    if (choice == 1) {
        for (i = 0; i < length; i++) {
            int r = rand() % 3;

            if (r == 0) {
                password[i] = rand() % 26 + 97;
            } else if (r == 1) {
                password[i] = rand() % 26 + 65;
            } else {
                password[i] = rand() % 10 + 48;
            }
        }
    } else if (choice == 2) {
        for (i = 0; i < length; i++) {
            int r = rand() % 2;

            if (r == 0) {
                password[i] = rand() % 26 + 97;
            } else {
                password[i] = rand() % 26 + 65;
            }
        }
    } else if (choice == 3) {
        for (i = 0; i < length; i++) {
            password[i] = rand() % 10 + 48;
        }
    } else {
        printf("Invalid choice\n");
        return 0;
    }

    printf("Generated password: ");
    for (i = 0; i < length; i++) {
        printf("%c", password[i]);
    }
    printf("\n");

    return 0;
}