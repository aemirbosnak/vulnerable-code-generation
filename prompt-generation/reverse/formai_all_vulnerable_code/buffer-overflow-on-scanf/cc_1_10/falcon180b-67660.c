//Falcon-180B DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define SALT_LENGTH 16

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    time_t creation_time;
    time_t last_update_time;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_salt(char salt[SALT_LENGTH]) {
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = 'a' + rand() % 26;
    }
}

int compare_passwords(const Password *p1, const Password *p2) {
    return strcmp(p1->password, p2->password) == 0;
}

void sort_passwords() {
    qsort(passwords, num_passwords, sizeof(Password), compare_passwords);
}

int main() {
    srand(time(NULL));

    char input[MAX_PASSWORD_LENGTH + 1];
    while (1) {
        printf("Enter a website or application name: ");
        scanf("%s", input);

        int found = 0;
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(passwords[i].password, input) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Enter a new password for %s: ", input);
            scanf("%s", input);

            generate_salt(passwords[num_passwords].password);
            strncpy(passwords[num_passwords].password + SALT_LENGTH, input, MAX_PASSWORD_LENGTH - SALT_LENGTH);
            passwords[num_passwords].password[MAX_PASSWORD_LENGTH - 1] = '\0';

            passwords[num_passwords].creation_time = time(NULL);
            passwords[num_passwords].last_update_time = time(NULL);

            num_passwords++;

            sort_passwords();

            printf("Password saved for %s.\n", input);
        } else {
            printf("Password already exists for %s.\n", input);
        }
    }

    return 0;
}