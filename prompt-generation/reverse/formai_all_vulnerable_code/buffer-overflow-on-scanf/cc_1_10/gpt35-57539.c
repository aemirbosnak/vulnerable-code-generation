//FormAI DATASET v1.0 Category: Password management ; Style: curious
#include<stdio.h>
#include<string.h>

// structure to hold user details
struct user_details {
    char name[50];
    char username[20];
    char password[20];
};

// function to create a new user
void create_user(struct user_details users[], int *user_count){
    char name[50], username[20], password[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    strcpy(users[*user_count].name, name);
    strcpy(users[*user_count].username, username);
    strcpy(users[*user_count].password, password);
    (*user_count)++;
    printf("User created successfully!\n\n");
}

// function to authenticate user
int authenticate_user(struct user_details users[], int user_count){
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for(int i=0;i<user_count;i++){
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0){
            printf("Welcome %s!\n\n", users[i].name);
            return i;
        }
    }
    printf("Invalid credentials. Please try again.\n\n");
    return -1;
}

// function to update user's password
void update_password(struct user_details users[], int user_count, int user_index){
    char old_password[20], new_password[20], confirm_password[20];
    printf("Enter current password: ");
    scanf("%s", old_password);
    if(strcmp(users[user_index].password, old_password) != 0){
        printf("Incorrect password.\n\n");
        return;
    }
    printf("Enter new password: ");
    scanf("%s", new_password);
    printf("Confirm new password: ");
    scanf("%s", confirm_password);
    if(strcmp(new_password, confirm_password) == 0){
        strcpy(users[user_index].password, new_password);
        printf("Password updated successfully.\n\n");
    }
    else{
        printf("Passwords do not match. Password not updated.\n\n");
    }
}

// main function
int main(){
    int user_count = 0, choice, user_index;
    struct user_details users[10];
    while(1){
        printf("1. Create new user\n");
        printf("2. Login\n");
        printf("3. Update password\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                create_user(users, &user_count);
                break;
            case 2:
                user_index = authenticate_user(users, user_count);
                if(user_index != -1){
                    // user authenticated
                    // do whatever you want to do after login
                }
                break;
            case 3:
                update_password(users, user_count, user_index);
                break;
            case 4:
                printf("Exiting program...\n\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}