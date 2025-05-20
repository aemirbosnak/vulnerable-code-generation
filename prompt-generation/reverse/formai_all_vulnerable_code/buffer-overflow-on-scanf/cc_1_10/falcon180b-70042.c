//Falcon-180B DATASET v1.0 Category: Password management ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user {
    char username[50];
    char password[50];
    int count;
};

void create_account(struct user *user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
    user->count = 0;
    printf("\nAccount created successfully!\n");
}

void login(struct user *user) {
    printf("Enter username: ");
    char temp_username[50];
    scanf("%s", temp_username);
    if(strcmp(temp_username, user->username) == 0) {
        printf("Enter password: ");
        char temp_password[50];
        scanf("%s", temp_password);
        if(strcmp(temp_password, user->password) == 0) {
            printf("\nLogin successful!\n");
            user->count++;
        } else {
            printf("\nIncorrect password!\n");
        }
    } else {
        printf("\nUser not found!\n");
    }
}

void reset_password(struct user *user) {
    printf("Enter new password: ");
    scanf("%s", user->password);
    printf("\nPassword reset successfully!\n");
}

void view_account(struct user *user) {
    printf("\nUsername: %s\n", user->username);
    printf("Password: %s\n", user->password);
    printf("Login count: %d\n", user->count);
}

int main() {
    struct user user;
    int choice;
    while(1) {
        printf("\n\nWelcome to Password Manager\n");
        printf("1. Create account\n2. Login\n3. Reset password\n4. View account\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_account(&user);
                break;
            case 2:
                login(&user);
                break;
            case 3:
                reset_password(&user);
                break;
            case 4:
                view_account(&user);
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}