//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include<stdio.h>
#include<string.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 20

struct user {
    char username[50];
    char password[MAX_PASSWORDS];
};

struct database {
    int num_users;
    struct user users[MAX_USERS];
};

struct database db;

void add_user(char *username, char *password) {
    if(db.num_users < MAX_USERS) {
        strcpy(db.users[db.num_users].username, username);
        strcpy(db.users[db.num_users].password, password);
        db.num_users++;
        printf("User added successfully!\n");
    }
    else {
        printf("Database full! Unable to add user.\n");
    }
}

void change_password(char *username, char *old_password, char *new_password) {
    int i;
    for(i=0; i<db.num_users; i++) {
        if(strcmp(username, db.users[i].username)==0) {
            if(strcmp(old_password, db.users[i].password)==0) {
                strcpy(db.users[i].password, new_password);
                printf("Password changed successfully!\n");
                return;
            }
            else {
                printf("Incorrect password for user %s.\n", username);
                return;
            }
        }
    }
    printf("User %s not found.\n", username);
}

void remove_user(char *username, char *password) {
    int i;
    for(i=0; i<db.num_users; i++) {
        if(strcmp(username, db.users[i].username)==0) {
            if(strcmp(password, db.users[i].password)==0) {
                int j;
                for(j=i; j<db.num_users-1; j++) {
                    strcpy(db.users[j].username, db.users[j+1].username);
                    strcpy(db.users[j].password, db.users[j+1].password);
                }
                db.num_users--;
                printf("User %s removed successfully!\n", username);
                return;
            }
            else {
                printf("Incorrect password for user %s.\n", username);
                return;
            }
        }
    }
    printf("User %s not found.\n", username);
}

void display_users() {
    int i;
    printf("Users in database:\n");
    for(i=0; i<db.num_users; i++) {
        printf("- %s\n", db.users[i].username);
    }
}

int main() {
    char username[50], password[MAX_PASSWORDS], old_password[MAX_PASSWORDS], new_password[MAX_PASSWORDS];
    int choice;

    // initialize database
    db.num_users = 0;

    do {
        printf("\n===== Password Management System =====\n");
        printf("1. Add User\n");
        printf("2. Change Password\n");
        printf("3. Remove User\n");
        printf("4. Display Users\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password (max %d characters): ", MAX_PASSWORDS-1);
                scanf("%s", password);
                add_user(username, password);
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter old password: ");
                scanf("%s", old_password);
                printf("Enter new password (max %d characters): ", MAX_PASSWORDS-1);
                scanf("%s", new_password);
                change_password(username, old_password, new_password);
                break;

            case 3:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                remove_user(username, password);
                break;

            case 4:
                display_users();
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

    } while(choice != 5);

    return 0;
}