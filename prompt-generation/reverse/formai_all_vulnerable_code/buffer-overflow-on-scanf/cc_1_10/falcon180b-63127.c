//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

typedef struct {
    char password[PASSWORD_LENGTH];
    time_t timestamp;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(char *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]:;?><,./-=";
    int len = strlen(charset);

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % len];
    }
}

int main() {
    srand(time(NULL));

    while (1) {
        printf("Enter your master password: ");
        char masterPassword[PASSWORD_LENGTH];
        scanf("%s", masterPassword);

        if (numPasswords == 0) {
            generatePassword(masterPassword);
            printf("Master password generated: %s\n", masterPassword);
        } else {
            int found = 0;

            for (int i = 0; i < numPasswords; i++) {
                if (strcmp(masterPassword, passwords[i].password) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Invalid master password\n");
            } else {
                printf("Enter website: ");
                char website[50];
                scanf("%s", website);

                generatePassword(passwords[numPasswords].password);
                strcpy(passwords[numPasswords].password, masterPassword);
                strcat(passwords[numPasswords].password, website);
                passwords[numPasswords].timestamp = time(NULL);
                numPasswords++;

                printf("Generated password for %s: %s\n", website, passwords[numPasswords-1].password);
            }
        }
    }

    return 0;
}