//Falcon-180B DATASET v1.0 Category: Password management ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct{
    char username[50];
    char password[100];
}User;

void addUser(User* user){
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

void login(User* user){
    printf("Enter username: ");
    char input[50];
    scanf("%s", input);
    if(strcmp(input, user->username) == 0){
        printf("Enter password: ");
        char password[100];
        scanf("%s", password);
        if(strcmp(password, user->password) == 0){
            printf("Login Successful!\n");
        }
        else{
            printf("Incorrect password.\n");
        }
    }
    else{
        printf("User not found.\n");
    }
}

void main(){
    User user[MAX_SIZE];
    int count = 0;
    char choice;

    do{
        printf("1. Add User\n2. Login\n3. Exit\n");
        scanf("%c", &choice);

        switch(choice){
            case '1':
                if(count >= MAX_SIZE){
                    printf("Maximum number of users reached.\n");
                }
                else{
                    addUser(&user[count]);
                    count++;
                }
                break;
            case '2':
                printf("Enter username: ");
                char username[50];
                scanf("%s", username);
                for(int i=0; i<count; i++){
                    if(strcmp(username, user[i].username) == 0){
                        login(&user[i]);
                        break;
                    }
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice!= '3');
}