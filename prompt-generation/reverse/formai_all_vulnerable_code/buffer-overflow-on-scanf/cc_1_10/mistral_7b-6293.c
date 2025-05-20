//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASS 100
#define WORD_LEN 50

typedef struct Password {
    char key[WORD_LEN];
    char pass[MAX_PASS];
} Password;

Password passwords[MAX_PASS];
int num_passwords = 0;

void add_password(char *key, char *pass) {
    if (num_passwords >= MAX_PASS) {
        printf("Password manager is full.\n");
        return;
    }
    strcpy(passwords[num_passwords].key, key);
    strcpy(passwords[num_passwords].pass, pass);
    num_passwords++;
}

void delete_password(char *key) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].key, key) == 0) {
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (num_passwords - i - 1));
            num_passwords--;
            break;
        }
    }
}

void display_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s:\t%s\n", passwords[i].key, passwords[i].pass);
    }
}

void search_password(char *keyword) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strstr(passwords[i].key, keyword) != NULL) {
            printf("%s:\t%s\n", passwords[i].key, passwords[i].pass);
        }
    }
}

int main() {
    char cmd[WORD_LEN], key[WORD_LEN], pass[MAX_PASS];
    int choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. Display Passwords\n");
        printf("4. Search Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", cmd);

        choice = atoi(cmd);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter password: ");
                scanf("%s", pass);
                add_password(key, pass);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%s", key);
                delete_password(key);
                break;
            case 3:
                display_passwords();
                break;
            case 4:
                printf("Enter keyword: ");
                scanf("%s", key);
                search_password(key);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}