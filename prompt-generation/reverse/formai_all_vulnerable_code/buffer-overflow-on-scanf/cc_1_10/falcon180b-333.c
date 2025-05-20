//Falcon-180B DATASET v1.0 Category: Password management ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX_USER 10
#define MAX_PASSWORD_LENGTH 20

typedef struct{
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
}user;

void create_user(user* u){
    printf("Enter username: ");
    scanf("%s",u->username);
    printf("Enter password: ");
    scanf("%s",u->password);
}

int login(char* username,char* password,user* users,int num_users){
    int i;
    for(i=0;i<num_users;i++){
        if(strcmp(username,users[i].username)==0 && strcmp(password,users[i].password)==0){
            return TRUE;
        }
    }
    return FALSE;
}

void main(){
    user users[MAX_USER];
    int num_users=0;
    char choice;
    do{
        printf("\nPassword Manager\n");
        printf("1.Create User\n2.Login\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%c",&choice);
        switch(choice){
            case '1':
                if(num_users>=MAX_USER){
                    printf("Maximum number of users reached\n");
                    break;
                }
                create_user(&users[num_users]);
                num_users++;
                printf("User created successfully\n");
                break;
            case '2':
                printf("Enter username: ");
                char username[20];
                scanf("%s",username);
                printf("Enter password: ");
                char password[MAX_PASSWORD_LENGTH];
                scanf("%s",password);
                if(login(username,password,users,num_users)){
                    printf("Login successful\n");
                }
                else{
                    printf("Incorrect username or password\n");
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!='3');
}