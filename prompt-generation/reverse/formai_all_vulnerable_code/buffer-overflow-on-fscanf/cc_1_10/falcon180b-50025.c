//Falcon-180B DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LEN];
} password_t;

void generate_password(char* password, int length) {
    // Generate a random password
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_size = strlen(charset);
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_size];
    }
    password[length] = '\0';
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char username[50];
    printf("Enter your username: ");
    scanf("%s", username);

    FILE* fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("No passwords found.\n");
    } else {
        while (num_passwords < MAX_PASSWORDS && fscanf(fp, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password) == 2) {
            if (strcmp(passwords[num_passwords].username, username) == 0) {
                printf("Password found: %s\n", passwords[num_passwords].password);
                break;
            }
            num_passwords++;
        }
        fclose(fp);
    }

    if (num_passwords == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return 1;
    }

    if (strcmp(passwords[num_passwords].username, username) == 0) {
        printf("Password already saved.\n");
        return 1;
    }

    char new_password[MAX_PASSWORD_LEN];
    generate_password(new_password, strlen(new_password));

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, new_password);
    num_passwords++;

    fp = fopen("passwords.txt", "w");
    for (int i = 0; i < num_passwords; i++) {
        fprintf(fp, "%s %s\n", passwords[i].username, passwords[i].password);
    }
    fclose(fp);

    printf("Password saved successfully.\n");

    return 0;
}