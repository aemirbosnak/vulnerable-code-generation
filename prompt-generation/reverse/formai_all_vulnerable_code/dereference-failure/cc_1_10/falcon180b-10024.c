//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generate_password(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }

    password[length] = '\0';
}

int main() {
    char filename[MAX_PASSWORD_LENGTH];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }

    struct Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char line[MAX_PASSWORD_LENGTH];
    while (fgets(line, MAX_PASSWORD_LENGTH, file)!= NULL) {
        char *name = strtok(line, ":");
        char *password = strtok(NULL, ":");

        if (name == NULL || password == NULL) {
            printf("Invalid format!\n");
            return 1;
        }

        strcpy(passwords[num_passwords].name, name);
        strcpy(passwords[num_passwords].password, password);

        num_passwords++;

        if (num_passwords >= MAX_PASSWORDS) {
            break;
        }
    }

    fclose(file);

    char search_name[MAX_PASSWORD_LENGTH];
    printf("Enter the name of the password you want to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, search_name) == 0) {
            printf("Password found!\n");
            printf("Name: %s\n", passwords[i].name);
            printf("Password: %s\n", passwords[i].password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Password not found!\n");
    }

    return 0;
}