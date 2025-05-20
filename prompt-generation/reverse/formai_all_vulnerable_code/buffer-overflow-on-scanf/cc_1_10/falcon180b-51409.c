//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_USER 100
#define MAX_PASS 100

typedef struct user{
    char username[MAX_USER];
    char password[MAX_PASS];
    int is_admin;
}user;

void create_user(user* u){
    printf("Enter username: ");
    scanf("%s",u->username);
    printf("Enter password: ");
    scanf("%s",u->password);
    printf("User created successfully!\n");
}

int login(user* u){
    printf("Enter username: ");
    scanf("%s",u->username);
    printf("Enter password: ");
    scanf("%s",u->password);
    if(strcmp(u->username,"admin")==0 && strcmp(u->password,"admin")==0){
        u->is_admin=1;
        return 1;
    }
    else if(strcmp(u->username,"user")==0 && strcmp(u->password,"user")==0){
        u->is_admin=0;
        return 1;
    }
    else{
        printf("Invalid username or password!\n");
        return 0;
    }
}

int main(){
    user u;
    int choice;
    do{
        printf("\n\n");
        printf("1. Create user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                create_user(&u);
                break;
            case 2:
                if(login(&u)){
                    if(u.is_admin){
                        printf("Welcome admin!\n");
                    }
                    else{
                        printf("Welcome user!\n");
                    }
                    break;
                }
                else{
                    continue;
                }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(1);
    return 0;
}