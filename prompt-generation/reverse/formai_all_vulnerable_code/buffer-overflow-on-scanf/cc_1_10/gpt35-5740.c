//FormAI DATASET v1.0 Category: Password management ; Style: high level of detail
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 100
#define MAX_SIZE 100

struct password{
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

int menu();
void add_password(struct password *pw, int *size);
void view_passwords(struct password *pw, int size);
void search_password(struct password *pw, int size);
void change_password(struct password *pw, int size);

int main(){
    int choice, size=0;
    struct password pw[MAX_SIZE];

    do{
        choice = menu();
        switch(choice){
            case 1:
                add_password(pw, &size);
                break;
            case 2:
                view_passwords(pw, size);
                break;
            case 3:
                search_password(pw, size);
                break;
            case 4:
                change_password(pw, size);
                break;
            case 5:
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }while(choice!=5);

    return 0;
}

int menu(){
    int choice;
    printf("\nWelcome to Password Management System\n");
    printf("1. Add a password\n");
    printf("2. View all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Change a password\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_password(struct password *pw, int *size){
    if(*size == MAX_SIZE){
        printf("Database is full, cannot add more passwords.\n");
        return;
    }
    printf("Enter the website (max %d characters): ", MAX_LENGTH);
    scanf(" %s", pw[*size].website);
    printf("Enter the username (max %d characters): ", MAX_LENGTH);
    scanf(" %s", pw[*size].username);
    printf("Enter the password (max %d characters): ", MAX_LENGTH);
    scanf(" %s", pw[*size].password);
    (*size)++;
    printf("Password added successfully.\n");
}

void view_passwords(struct password *pw, int size){
    if(size == 0){
        printf("Database is empty.\n");
        return;
    }
    printf("Website\t\tUsername\tPassword\n");
    for(int i=0; i<size; i++){
        printf("%s\t\t%s\t\t%s\n", pw[i].website, pw[i].username, pw[i].password);
    }
}

void search_password(struct password *pw, int size){
    char search[MAX_LENGTH];
    if(size == 0){
        printf("Database is empty.\n");
        return;
    }
    printf("Enter the website to search: ");
    scanf(" %s", search);
    for(int i=0; i<size; i++){
        if(strcmp(pw[i].website, search) == 0){
            printf("Website\t\tUsername\tPassword\n");
            printf("%s\t\t%s\t\t%s\n", pw[i].website, pw[i].username, pw[i].password);
            return;
        }
    }
    printf("Website not found in database.\n");
}

void change_password(struct password *pw, int size){
    char search[MAX_LENGTH];
    if(size == 0){
        printf("Database is empty.\n");
        return;
    }
    printf("Enter the website to change password: ");
    scanf(" %s", search);
    for(int i=0; i<size; i++){
        if(strcmp(pw[i].website, search) == 0){
            printf("Enter the new password (max %d characters): ", MAX_LENGTH);
            scanf(" %s", pw[i].password);
            printf("Password changed successfully.\n");
            return;
        }
    }
    printf("Website not found in database.\n");
}