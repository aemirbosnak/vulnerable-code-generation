//FormAI DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void print_menu(){
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
}

void register_user(User* users, int* num_users){
    if(*num_users >= MAX_USERS){
        printf("Maximum number of users reached. Cannot register more users.\n");
        return;
    }

    printf("Enter username (max %d characters): ", MAX_PASSWORD_LENGTH);
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);

    for(int i = 0; i < *num_users; i++){
        if(strcmp(users[i].username, username) == 0){
            printf("Username already taken. Please choose a different username.\n");
            return;
        }
    }

    printf("Enter password (max %d characters): ", MAX_PASSWORD_LENGTH);
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    User new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    users[*num_users] = new_user;
    (*num_users)++;

    printf("Registration successful!\n");
}

void login(User* users, int num_users){
    printf("Enter username: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);

    printf("Enter password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    for(int i = 0; i < num_users; i++){
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0){
            printf("Login successful!\n");
            return;
        }
    }

    printf("Invalid username or password. Please try again.\n");
}

int main(){

    User users[MAX_USERS];
    int num_users = 0;

    while(1){
        print_menu();
        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            register_user(users, &num_users);
        }
        else if(choice == 2){
            login(users, num_users);
        }
        else if(choice == 3){
            printf("Goodbye!\n");
            break;
        }
        else{
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}