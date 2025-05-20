//Falcon-180B DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    FILE *passwords_file;
    char filename[MAX_PASSWORD_LENGTH];
    char line[MAX_PASSWORD_LENGTH];
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    printf("Enter the name of the password file: ");
    scanf("%s", filename);

    passwords_file = fopen(filename, "r");
    if (passwords_file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_PASSWORD_LENGTH, passwords_file)!= NULL) {
        if (num_passwords >= MAX_PASSWORDS) {
            printf("Error: too many passwords.\n");
            fclose(passwords_file);
            return 1;
        }

        char *name = strtok(line, ":");
        char *password = strtok(NULL, ":");

        strcpy(passwords[num_passwords].name, name);
        strcpy(passwords[num_passwords].password, password);

        num_passwords++;
    }

    fclose(passwords_file);

    printf("Enter the name of the password you want to retrieve: ");
    scanf("%s", line);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, line) == 0) {
            printf("Password: %s\n", passwords[i].password);
            break;
        }
    }

    return 0;
}