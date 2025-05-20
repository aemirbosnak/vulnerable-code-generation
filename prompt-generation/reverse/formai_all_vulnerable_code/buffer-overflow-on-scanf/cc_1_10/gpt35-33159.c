//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 1000
#define MAX_PASSWORD_LENGTH 50

struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS] = {0};

int num_users = 0;

// Function prototypes
void display_menu();
void add_user();
void delete_user();
void change_password();

int main()
{
    display_menu();
    return 0;
}

void display_menu()
{
    int choice;
    do {
        printf("\nPassword Management\n");
        printf("---------------------------\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Change Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_user();
                break;
            case 2:
                delete_user();
                break;
            case 3:
                change_password();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while(choice != 4);
}

void add_user()
{
    if(num_users >= MAX_USERS) {
        printf("\nMax number of users reached!\n");
        return;
    }

    printf("\nEnter username: ");
    scanf("%s", users[num_users].username);

    // Check if username already exists
    for(int i=0; i<num_users; ++i) {
        if(strcmp(users[i].username, users[num_users].username) == 0) {
            printf("\nUsername already exists, please try a different one.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", users[num_users].password);

    printf("\nUser added successfully!\n");
    ++num_users;
}

void delete_user()
{
    char username[MAX_PASSWORD_LENGTH];
    printf("\nEnter username to delete: ");
    scanf("%s", username);

    // Find index of user with given username
    int index = -1;
    for(int i=0; i<num_users; ++i) {
        if(strcmp(users[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("\nUser not found\n");
        return;
    }

    memmove(users+index, users+index+1, (num_users - index - 1) * sizeof(struct User));
    --num_users;

    printf("\nUser deleted successfully!\n");
}

void change_password()
{
    char username[MAX_PASSWORD_LENGTH];
    char old_password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];

    printf("\nEnter username: ");
    scanf("%s", username);

    int index = -1;
    for(int i=0; i<num_users; ++i) {
        if(strcmp(users[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("\nUser not found\n");
        return;
    }

    printf("Enter old password: ");
    scanf("%s", old_password);

    if(strcmp(users[index].password, old_password) != 0) {
        printf("\nIncorrect password, please try again.\n");
        return;
    }

    printf("Enter new password: ");
    scanf("%s", new_password);

    // Check if new password meets requirements
    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;
    for(int i=0; i<strlen(new_password); ++i) {
        if(islower(new_password[i])) {
            has_lower = 1;
        }
        else if(isupper(new_password[i])) {
            has_upper = 1;
        }
        else if(isdigit(new_password[i])) {
            has_digit = 1;
        }
    }
    if(strlen(new_password) < 8 || !has_lower || !has_upper || !has_digit) {
        printf("\nPassword must be at least 8 characters long and contain at least one lowercase letter, one uppercase letter, and one digit.\n");
        return;
    }

    strcpy(users[index].password, new_password);
    printf("\nPassword changed successfully!\n");
}