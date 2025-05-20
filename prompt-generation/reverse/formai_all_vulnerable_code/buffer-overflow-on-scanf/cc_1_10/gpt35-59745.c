//FormAI DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LEN 20

struct User {
    char username[20];
    char password[MAX_PASSWORD_LEN];
};

struct UserList {
    int num_users;
    struct User users[MAX_USERS];
};

void save_users(struct UserList *ulist, FILE *file) {
    fseek(file, 0, SEEK_SET);
    fwrite(&ulist->num_users, sizeof(ulist->num_users), 1, file);
    fwrite(ulist->users, sizeof(struct User), ulist->num_users, file);
}

void load_users(struct UserList *ulist, FILE *file) {
    fseek(file, 0, SEEK_SET);
    fread(&ulist->num_users, sizeof(ulist->num_users), 1, file);
    fread(ulist->users, sizeof(struct User), MAX_USERS, file);
}

void set_password(struct User *user) {
    char password[MAX_PASSWORD_LEN];
    printf("Enter new password for %s: ", user->username);
    scanf("%s", password);
    strncpy(user->password, password, MAX_PASSWORD_LEN);
}

void change_password(struct UserList *ulist) {
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    struct User *user = NULL;
    for (int i = 0; i < ulist->num_users; i++) {
        if (strcmp(ulist->users[i].username, username) == 0) {
            user = &ulist->users[i];
            break;
        }
    }

    if (user == NULL) {
        printf("User not found\n");
        return;
    }

    set_password(user);
    printf("New password set for user %s\n", user->username);
}

void add_user(struct UserList *ulist) {
    if (ulist->num_users >= MAX_USERS) {
        printf("Maximum number of users reached\n");
        return;
    }

    char username[20];
    char password[MAX_PASSWORD_LEN];
    printf("Enter new username: ");
    scanf("%s", username);

    struct User *user = NULL;
    for (int i = 0; i < ulist->num_users; i++) {
        if (strcmp(ulist->users[i].username, username) == 0) {
            user = &ulist->users[i];
            break;
        }
    }

    if (user != NULL) {
        printf("User already exists\n");
        return;
    }

    set_password(&(ulist->users[ulist->num_users]));
    strncpy(ulist->users[ulist->num_users].username, username, 20);
    ulist->num_users++;
    printf("New user added: %s\n", username);
}

void remove_user(struct UserList *ulist) {
    char username[20];
    printf("Enter username to remove: ");
    scanf("%s", username);

    int index = -1;
    for (int i = 0; i < ulist->num_users; i++) {
        if (strcmp(ulist->users[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("User not found\n");
        return;
    }

    ulist->num_users--;
    if (index < ulist->num_users)
        ulist->users[index] = ulist->users[ulist->num_users];
    printf("User %s removed\n", username);
}

int main() {
    struct UserList ulist = {0};
    FILE *file = fopen("users.dat", "rb+");
    if (file == NULL) {
        file = fopen("users.dat", "wb");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }
    } else {
        load_users(&ulist, file);
    }

    int running = 1;
    while (running) {
        printf("1. Change password\n");
        printf("2. Add user\n");
        printf("3. Remove user\n");
        printf("4. Quit\n");
        printf("Enter a number: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            change_password(&ulist);
            break;
        case 2:
            add_user(&ulist);
            break;
        case 3:
            remove_user(&ulist);
            break;
        case 4:
            running = 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

        save_users(&ulist, file);
    }

    fclose(file);
    return 0;
}