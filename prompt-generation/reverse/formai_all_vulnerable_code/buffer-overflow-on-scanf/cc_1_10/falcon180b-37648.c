//Falcon-180B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100

typedef struct {
    char name[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
    time_t last_changed;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void load_passwords() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        return;
    }

    while (fscanf(file, "%s %s %ld\n", passwords[num_passwords].name, passwords[num_passwords].password, &passwords[num_passwords].last_changed) == 3) {
        num_passwords++;
    }

    fclose(file);
}

void save_passwords() {
    FILE *file = fopen("passwords.txt", "w");

    for (int i = 0; i < num_passwords; i++) {
        fprintf(file, "%s %s %ld\n", passwords[i].name, passwords[i].password, passwords[i].last_changed);
    }

    fclose(file);
}

int main() {
    load_passwords();

    while (1) {
        printf("Enter your name: ");
        scanf("%s", passwords[num_passwords].name);

        printf("Enter your password: ");
        scanf("%s", passwords[num_passwords].password);

        passwords[num_passwords].last_changed = time(NULL);
        num_passwords++;

        save_passwords();

        printf("Password saved successfully.\n");
    }

    return 0;
}