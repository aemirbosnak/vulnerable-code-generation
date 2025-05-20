//FormAI DATASET v1.0 Category: Password management ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct password{
    char website[50];
    char email[50];
    char password[50];
};

void add_password(struct password p[], int *counter);
void display_all_passwords(struct password p[], int counter);
void search_password(struct password p[], int counter);
void delete_password(struct password p[], int *counter);

int main()
{
    struct password passwords[100];
    int counter = 0;
    int choice = 0;

    while(1){
        printf("\nWelcome to Password Manager!\n");
        printf("1. Add password\n");
        printf("2. Display all passwords\n");
        printf("3. Search password\n");
        printf("4. Delete password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_password(passwords, &counter);
                break;
            case 2:
                display_all_passwords(passwords, counter);
                break;
            case 3:
                search_password(passwords, counter);
                break;
            case 4:
                delete_password(passwords, &counter);
                break;
            case 5:
                printf("Thank you for using Password Manager!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void add_password(struct password p[], int *counter)
{
    printf("\nEnter the website: ");
    scanf("%s", p[*counter].website);
    printf("Enter the email: ");
    scanf("%s", p[*counter].email);
    printf("Enter the password: ");
    scanf("%s", p[*counter].password);
    (*counter)++;
    printf("\nPassword added successfully!\n");
    return;
}

void display_all_passwords(struct password p[], int counter)
{
    int i;
    if(counter == 0){
        printf("\nNo passwords to display!\n");
        return;
    }
    printf("\nAll passwords: \n");
    for(i=0; i<counter; i++){
        printf("Website: %s\n", p[i].website);
        printf("Email: %s\n", p[i].email);
        printf("Password: %s\n", p[i].password);
        printf("\n");
    }
    return;
}

void search_password(struct password p[], int counter)
{
    int i, flag = 0;
    char website[50];

    printf("\nEnter the website to search for: ");
    scanf("%s", website);

    for(i=0; i<counter; i++){
        if(strcmp(p[i].website, website)==0){
            printf("\nWebsite found!\n");
            printf("Email: %s\n", p[i].email);
            printf("Password: %s\n", p[i].password);
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("\nWebsite not found!\n");
    }
    return;
}

void delete_password(struct password p[], int *counter)
{
    int i, flag = 0;
    char website[50];

    printf("\nEnter the website to delete password from: ");
    scanf("%s", website);

    for(i=0; i<*counter; i++){
        if(strcmp(p[i].website, website)==0){
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("\nWebsite not found!\n");
        return;
    }
    for(i=i; i<*counter-1; i++){
        strcpy(p[i].website, p[i+1].website);
        strcpy(p[i].email, p[i+1].email);
        strcpy(p[i].password, p[i+1].password);
    }
    (*counter)--;
    printf("\nPassword deleted successfully!\n");
    return;
}