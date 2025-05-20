//Falcon-180B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    FILE *file;
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error: could not open passwords file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s", passwords[num_passwords].name, passwords[num_passwords].password) == 2) {
        num_passwords++;
        if (num_passwords >= MAX_PASSWORDS) {
            printf("Error: too many passwords in file.\n");
            return 1;
        }
    }

    fclose(file);

    printf("Enter a password name: ");
    scanf("%s", passwords[num_passwords].name);
    strcpy(passwords[num_passwords].password, "");

    file = fopen("passwords.txt", "a");
    if (file == NULL) {
        printf("Error: could not open passwords file for writing.\n");
        return 1;
    }

    fprintf(file, "%s %s\n", passwords[num_passwords].name, passwords[num_passwords].password);
    fclose(file);

    printf("Password added successfully.\n");

    return 0;
}