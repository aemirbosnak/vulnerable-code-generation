//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct password{
    char name[30];
    char password[50];
};

int hash(char *key){
    int sum = 0;
    int i = 0;
    while(key[i]!= '\0'){
        sum += tolower(key[i]) - 97;
        i++;
    }
    return sum % MAX;
}

void add_password(struct password *passwords, char *name, char *password){
    int index = hash(name);
    while(passwords[index].name[0]!= '\0'){
        index = (index + 1) % MAX;
    }
    strcpy(passwords[index].name, name);
    strcpy(passwords[index].password, password);
}

void display_passwords(struct password *passwords){
    int i = 0;
    printf("Name\t\tPassword\n");
    while(i < MAX){
        if(passwords[i].name[0]!= '\0'){
            printf("%s\t\t%s\n", passwords[i].name, passwords[i].password);
        }
        i++;
    }
}

int main(){
    struct password passwords[MAX];
    int choice, i = 0;
    char name[30], password[50];

    do{
        printf("Enter 1 to add a password\n");
        printf("Enter 2 to display all passwords\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter password: ");
                scanf("%s", password);

                add_password(passwords, name, password);
                printf("Password added successfully!\n");
                break;

            case 2:
                display_passwords(passwords);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(choice!= 3);

    return 0;
}