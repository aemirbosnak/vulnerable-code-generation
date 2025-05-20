//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Define constants - maximum length of username and password
#define MAX_USERNAME_LENGTH 25
#define MAX_PASSWORD_LENGTH 20

//User struct which stores user credentials
typedef struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_t;

//Function to validate password strength
int is_valid_password(char* password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;
    for(int i=0;i<length;i++) {
        if(isupper(*(password+i))) {
            has_uppercase = 1;
        }
        else if(islower(*(password+i))) {
            has_lowercase = 1;
        }
        else if(isdigit(*(password+i))) {
            has_digit = 1;
        }
        else {
            has_special = 1;
        }
    }
    if(length<8 || !has_uppercase || !has_lowercase || !has_digit || !has_special) {
        return 0;
    }
    return 1;
}

//Function to add new user
void add_user(user_t** users, int* num_users, char* username, char* password) {
    user_t* new_user = (user_t*)malloc(sizeof(user_t));
    strcpy(new_user->username, username);
    strcpy(new_user->password, password);
    (*num_users)++;
    *users = (user_t*)realloc(*users, (*num_users)*sizeof(user_t));
    (*users)[*num_users-1] = *new_user;
    printf("User added successfully.\n");
}

//Function to change password
void change_password(user_t* users, int num_users, char* username, char* new_password) {
    int found = 0;
    for(int i=0;i<num_users;i++) {
        if(strcmp(users[i].username, username)==0) {
            strcpy(users[i].password, new_password);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("User not found.\n");
    }
    else {
        printf("Password changed successfully.\n");
    }
}

int main() {
    user_t *users = NULL;
    int num_users = 0;
    int choice = 0;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    while(1) {
        printf("Enter:\n1. to add new user\n2. to change password\n3. to exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                if(is_valid_password(password)) {
                    add_user(&users, &num_users, username, password);
                }
                else {
                    printf("Invalid password. Password should have atleast 8 characters, one uppercase letter, one lowercase letter, one digit and one special character.\n");
                }
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter new password: ");
                scanf("%s", new_password);
                if(is_valid_password(new_password)) {
                    change_password(users, num_users, username, new_password);
                }
                else {
                    printf("Invalid password. Password should have atleast 8 characters, one uppercase letter, one lowercase letter, one digit and one special character.\n");
                }
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}