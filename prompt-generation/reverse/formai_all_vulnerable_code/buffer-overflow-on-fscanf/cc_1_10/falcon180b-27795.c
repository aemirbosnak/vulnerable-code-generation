//Falcon-180B DATASET v1.0 Category: Password management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

typedef struct {
    char password[PASSWORD_LENGTH];
    int id;
} password_t;

void generate_password(char *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_size = strlen(charset);

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int rand_index = rand() % charset_size;
        password[i] = charset[rand_index];
    }
}

int compare_passwords(const void *a, const void *b) {
    const password_t *p1 = (const password_t *)a;
    const password_t *p2 = (const password_t *)b;

    return strcmp(p1->password, p2->password);
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    FILE *file = fopen("passwords.txt", "r");
    if (file!= NULL) {
        while (fscanf(file, "%s %d\n", passwords[num_passwords].password, &passwords[num_passwords].id)!= EOF) {
            num_passwords++;
        }

        fclose(file);
    }

    char new_password[PASSWORD_LENGTH + 1];
    generate_password(new_password);

    passwords[num_passwords] = (password_t) {
       .password = strdup(new_password),
       .id = num_passwords + 1
    };

    qsort(passwords, num_passwords + 1, sizeof(password_t), compare_passwords);

    file = fopen("passwords.txt", "w");
    if (file!= NULL) {
        for (int i = 0; i < num_passwords + 1; i++) {
            fprintf(file, "%s %d\n", passwords[i].password, passwords[i].id);
        }

        fclose(file);
    }

    return 0;
}