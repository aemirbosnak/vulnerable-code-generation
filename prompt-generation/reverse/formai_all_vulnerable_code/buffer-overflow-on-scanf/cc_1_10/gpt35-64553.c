//FormAI DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct password{
    char name[MAX];
    char username[MAX];
    char password[MAX];
};

void add_password(struct password passwords[], int *count);
void show_password(struct password passwords[], int count);

int main() {
    int count = 0;
    char choice;
    struct password passwords[MAX];

    printf("Welcome to the Password Manager!\n");

    while(1){
        printf("\nMenu:\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf(" %c",&choice);

        switch(choice){
            case '1':
                add_password(passwords,&count);
                break;
            case '2':
                show_password(passwords,count);
                break;
            case '3':
                printf("\nExiting...\n\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Try again.\n");
        }
    }
    return 0;
}

void add_password(struct password passwords[], int *count){
    getchar();
    printf("\nEnter the name of the website: ");
    fgets(passwords[*count].name,MAX,stdin);
    passwords[*count].name[strcspn(passwords[*count].name, "\n")] = 0;

    printf("Enter username/email: ");
    fgets(passwords[*count].username,MAX,stdin);
    passwords[*count].username[strcspn(passwords[*count].username, "\n")] = 0;

    printf("Enter password: ");
    fgets(passwords[*count].password,MAX,stdin);
    passwords[*count].password[strcspn(passwords[*count].password, "\n")] = 0;

    printf("\nPassword added successfully!\n");

    (*count)++;
}

void show_password(struct password passwords[], int count){
    if(count == 0){
        printf("\nNo passwords found!\n");
        return;
    }
    printf("\nPasswords:\n");
    printf("%-30s %-20s %s\n","Website","Username","Password");
    for(int i=0;i<count;i++){
        printf("%-30s %-20s %s\n",passwords[i].name,passwords[i].username,passwords[i].password);
    }
}