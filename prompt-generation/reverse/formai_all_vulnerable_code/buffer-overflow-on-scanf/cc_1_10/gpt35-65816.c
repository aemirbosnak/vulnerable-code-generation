//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct password {
    char name[50];
    char username[50];
    char password[50];
};

void menu();
void add_password(struct password passwords[], int *num_passwords);
void view_passwords(struct password passwords[], int num_passwords);
void search_password(struct password passwords[], int num_passwords, char *search_term);
void generate_password(char *password);

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char choice;

    while (1) {
        menu();
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'a': add_password(passwords, &num_passwords);
                break;
            case 'v': view_passwords(passwords, num_passwords);
                break;
            case 's': {
                char search_term[MAX_PASSWORD_LENGTH];
                printf("Enter search term: ");
                scanf("%s", search_term);
                search_password(passwords, num_passwords, search_term);
                break;
            }
            case 'q': printf("Quitting...\n");
                exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void menu() {
    printf("Password Manager\n");
    printf("a) Add password\n");
    printf("v) View passwords\n");
    printf("s) Search passwords\n");
    printf("q) Quit program\n");
}

void add_password(struct password passwords[], int *num_passwords) {
    if (*num_passwords >= MAX_PASSWORDS) {
        printf("Cannot add any more passwords. Maximum limit reached.\n");
    } else {
        struct password new_password;
        printf("Enter name of website/service: ");
        scanf("%s", new_password.name);
        printf("Enter username: ");
        scanf("%s", new_password.username);
        generate_password(new_password.password);
        passwords[*num_passwords] = new_password;
        (*num_passwords)++;
        printf("Password saved successfully!\n");
    }
}

void view_passwords(struct password passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords saved yet.\n");
    } else {
        printf("Website/Service\t\tUsername\t\tPassword\n");
        for (int i = 0; i < num_passwords; i++) {
            printf("%s\t\t%s\t\t%s\n", passwords[i].name, passwords[i].username, passwords[i].password);
        }
    }
}

void search_password(struct password passwords[], int num_passwords, char *search_term) {
    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strstr(passwords[i].name, search_term) != NULL || strstr(passwords[i].username, search_term) != NULL) {
            printf("Website/Service\t\tUsername\t\tPassword\n");
            printf("%s\t\t%s\t\t%s\n", passwords[i].name, passwords[i].username, passwords[i].password);
            found = 1;
        }
    }
    if (!found) {
        printf("No matching passwords found.\n");
    }
}

void generate_password(char *password) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-{}[]|\\;:'\"<>,.?/";
    const int min_length = 8;
    const int max_length = 20;
    int length = rand() % (max_length - min_length + 1) + min_length;
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length] = '\0';
}