//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 25

struct user {
    char name[20];
    char password[MAX_PASSWORD_LENGTH + 1];
};

void print_menu();
void add_user(struct user users[], int *count);
void remove_user(struct user users[], int *count, int index);
void login(struct user users[], int count);

int main() {
    struct user users[MAX_USERS];
    int count = 0;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user(users, &count);
                break;
            case 2:
                login(users, count);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\nPassword Manager\n");
    printf("1. Add User\n");
    printf("2. Login\n");
    printf("3. Exit\n");
}

void add_user(struct user users[], int *count) {
    if (*count >= MAX_USERS) {
        printf("Maximum number of users reached!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", users[*count].name);

    printf("Enter password: ");
    fgets(users[*count].password, MAX_PASSWORD_LENGTH + 1, stdin);
    users[*count].password[strcspn(users[*count].password, "\n")] = '\0';

    (*count)++;
}

void remove_user(struct user users[], int *count, int index) {
    if (index < 0 || index >= *count) {
        printf("Invalid user index!\n");
        return;
    }

    memmove(&users[index], &users[index + 1], sizeof(struct user) * (*count - index - 1));

    (*count)--;
}

void login(struct user users[], int count) {
    char name[20];
    char password[MAX_PASSWORD_LENGTH + 1];
    int index = -1;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
    password[strcspn(password, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].name, name) == 0 && strcmp(users[i].password, password) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Invalid credentials!\n");
    } else {
        printf("Login successful!\n");
    }
}