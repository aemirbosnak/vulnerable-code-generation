//FormAI DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 30

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} account_t;

int menu(void);
void add_password(account_t* list, int* count);
void view_passwords(account_t* list, int count);
void save_passwords(account_t* list, int count);
void load_passwords(account_t* list, int* count);

int main(void) {
    account_t passwords[MAX_PASSWORDS];
    int count = 0;
    int choice;

    load_passwords(passwords, &count);

    while ((choice = menu()) != 0) {
        switch (choice) {
            case 1:
                add_password(passwords, &count);
                break;
            case 2:
                view_passwords(passwords, count);
                break;
            case 3:
                save_passwords(passwords, count);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

int menu(void) {
    int choice;

    printf("\n");
    printf("1. Add a password\n");
    printf("2. View passwords\n");
    printf("3. Save passwords to file\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

void add_password(account_t* list, int* count) {
    if (*count >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", list[*count].username);
    printf("Enter password: ");
    scanf("%s", list[*count].password);

    (*count)++;
}

void view_passwords(account_t* list, int count) {
    int i;

    if (count == 0) {
        printf("No passwords to view\n");
        return;
    }

    printf("Username\tPassword\n");
    printf("--------\t--------\n");
    for (i = 0; i < count; i++) {
        printf("%s\t\t%s\n", list[i].username, list[i].password);
    }
}

void save_passwords(account_t* list, int count) {
    FILE* file;
    int i;

    if (count == 0) {
        printf("No passwords to save\n");
        return;
    }

    file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(file, "%s,%s\n", list[i].username, list[i].password);
    }

    fclose(file);

    printf("Passwords saved to file\n");
}

void load_passwords(account_t* list, int* count) {
    FILE* file;
    char line[MAX_LENGTH * 2];
    char* username;
    char* password;

    file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("File not found\n");
        return;
    }

    while (fgets(line, sizeof line, file) != NULL && *count < MAX_PASSWORDS) {
        username = strtok(line, ",");
        password = strtok(NULL, "\n");

        if (username == NULL || password == NULL) {
            continue;
        }

        strcpy(list[*count].username, username);
        strcpy(list[*count].password, password);
        (*count)++;
    }

    fclose(file);
}