//FormAI DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 20

void add_password(char passwords[MAX_PASSWORDS][MAX_LENGTH], char name[MAX_LENGTH], char password[MAX_LENGTH], int *num_passwords);
void remove_password(char passwords[MAX_PASSWORDS][MAX_LENGTH], char name[MAX_LENGTH], int *num_passwords);
void view_passwords(char passwords[MAX_PASSWORDS][MAX_LENGTH], int num_passwords);

int main() {
    char passwords[MAX_PASSWORDS][MAX_LENGTH];
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
    int num_passwords = 0;
    int choice;

    do {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. Remove Password\n");
        printf("3. View Passwords\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                add_password(passwords, name, password, &num_passwords);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                remove_password(passwords, name, &num_passwords);
                break;
            case 3:
                view_passwords(passwords, num_passwords);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void add_password(char passwords[MAX_PASSWORDS][MAX_LENGTH], char name[MAX_LENGTH], char password[MAX_LENGTH], int *num_passwords) {
    if (*num_passwords < MAX_PASSWORDS) {
        strcpy(passwords[*num_passwords], name);
        strcat(passwords[*num_passwords], " ");
        strcat(passwords[*num_passwords], password);
        (*num_passwords)++;
        printf("Password added successfully\n");
    } else {
        printf("Max number of passwords reached\n");
    }
}

void remove_password(char passwords[MAX_PASSWORDS][MAX_LENGTH], char name[MAX_LENGTH], int *num_passwords) {
    int i, j;
    for (i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i], name) == 0) {
            for (j = i; j < *num_passwords - 1; j++) {
                strcpy(passwords[j], passwords[j+1]);
            }
            (*num_passwords)--;
            printf("Password removed successfully\n");
            return;
        }
    }
    printf("Password not found\n");
}

void view_passwords(char passwords[MAX_PASSWORDS][MAX_LENGTH], int num_passwords) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i]);
    }
}