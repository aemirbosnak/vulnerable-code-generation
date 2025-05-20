//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PASSWORDS 100

typedef struct
{
    char username[50];
    char password[50];
}Password;

Password passwords[MAX_PASSWORDS];
int num_passwords=0;

void add_password()
{
    char username[50],password[50];
    printf("Enter username: ");
    scanf("%s",username);
    printf("Enter password: ");
    scanf("%s",password);

    for(int i=0;i<num_passwords;i++)
    {
        if(strcmp(passwords[i].username,username)==0)
        {
            printf("User already exists!\n");
            return;
        }
    }

    strcpy(passwords[num_passwords].username,username);
    strcpy(passwords[num_passwords].password,password);
    num_passwords++;
    printf("Password added successfully!\n");
}

void delete_password()
{
    char username[50];
    printf("Enter username: ");
    scanf("%s",username);

    for(int i=0;i<num_passwords;i++)
    {
        if(strcmp(passwords[i].username,username)==0)
        {
            memmove(&passwords[i],&passwords[i+1],(MAX_PASSWORDS-i-1)*sizeof(Password));
            num_passwords--;
            printf("Password deleted successfully!\n");
            return;
        }
    }

    printf("User not found!\n");
}

void search_password()
{
    char username[50];
    printf("Enter username: ");
    scanf("%s",username);

    for(int i=0;i<num_passwords;i++)
    {
        if(strcmp(passwords[i].username,username)==0)
        {
            printf("Password: %s\n",passwords[i].password);
            return;
        }
    }

    printf("User not found!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Add password\n2. Delete password\n3. Search password\n4. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add_password();
                break;
            case 2:
                delete_password();
                break;
            case 3:
                search_password();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=4);

    return 0;
}