//FormAI DATASET v1.0 Category: System administration ; Style: creative
//This C program is an example of a system administration program.
//It allows a user to add new user accounts, delete existing accounts and change user passwords.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User{
    char username[20];
    char password[20];
};

void addUser(struct User users[], int* index){
    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    strcpy(users[*index].username, username);
    strcpy(users[*index].password, password);
    (*index)++;
    printf("User added successfully!\n\n");
}

void deleteUser(struct User users[], int* index){
    char username[20];
    printf("Enter username to delete: ");
    scanf("%s", username);
    int i;
    for(i=0; i<*index; i++){
        if(strcmp(users[i].username, username) == 0){
            int j;
            for(j=i; j<*index-1; j++){
                strcpy(users[j].username, users[j+1].username);
                strcpy(users[j].password, users[j+1].password);
            }
            (*index)--;
            printf("User deleted successfully!\n\n");
            return;
        }
    }
    printf("User not found!\n\n");
}

void changePassword(struct User users[], int index){
    char username[20];
    char password[20];
    printf("Enter username to change password: ");
    scanf("%s", username);
    int i;
    for(i=0; i<index; i++){
        if(strcmp(users[i].username, username) == 0){
            printf("Enter new password: ");
            scanf("%s", password);
            strcpy(users[i].password, password);
            printf("Password changed successfully!\n\n");
            return;
        }
    }
    printf("User not found!\n\n");
}

int main(){
    struct User users[50];
    int index = 0;
    int choice;
    do{
        printf("1. Add user\n");
        printf("2. Delete user\n");
        printf("3. Change password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addUser(users, &index);
                break;
            case 2:
                deleteUser(users, &index);
                break;
            case 3:
                changePassword(users, index);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n\n");
        }
    }while(choice != 4);
    return 0;
}