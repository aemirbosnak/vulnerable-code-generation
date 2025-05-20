//FormAI DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

typedef struct password{
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} password;

void add_password(password *pw, int *count);
void view_passwords(password *pw, int count);
void update_password(password *pw, int count);
void search_password(password *pw, int count);
void delete_password(password *pw, int *count);

int main()
{
    int count = 0;
    password passwords[MAX_PASSWORDS];
    int choice;
    printf("Welcome to your Password Manager! \n");

    do{
        printf("\n1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Update Password\n");
        printf("4. Search Password\n");
        printf("5. Delete Password\n");
        printf("6. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_password(passwords, &count);
                break;
            case 2:
                view_passwords(passwords, count);
                break;
            case 3:
                update_password(passwords, count);
                break;
            case 4:
                search_password(passwords, count);
                break;
            case 5:
                delete_password(passwords, &count);
                break;
            case 6:
                printf("Thank you for using the Password Manager!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}

void add_password(password *pw, int *count){
    if(*count >= MAX_PASSWORDS){
        printf("Maximum Number of Passwords Reached.\n");
        return;
    }

    printf("Enter Password Name : ");
    scanf("%s", pw[*count].name);

    printf("Enter Password : ");
    scanf("%s", pw[*count].password);

    printf("Password Added Successfully!\n");

    (*count)++;
}

void view_passwords(password *pw, int count){
    if(count == 0){
        printf("There are no Passwords Saved.\n");
        return;
    }

    printf("Password Name\tPassword\n");
    printf("-------------\t--------\n");

    for(int i=0; i<count; i++){
        printf("%s\t%s\n", pw[i].name, pw[i].password);
    }
}

void update_password(password *pw, int count){
    if(count == 0){
        printf("There are no Passwords Saved.\n");
        return;
    }

    char name[MAX_LENGTH];
    printf("Enter Password Name : ");
    scanf("%s", name);

    for(int i=0; i<count; i++){
        if(strcmp(pw[i].name, name) == 0){
            printf("Enter New Password : ");
            scanf("%s", pw[i].password);
            printf("Password Updated Successfully!\n");
            return;
        }
    }

    printf("Password Name '%s' not Found.\n", name);
}

void search_password(password *pw, int count){
    if(count == 0){
        printf("There are no Passwords Saved.\n");
        return;
    }

    char name[MAX_LENGTH];
    printf("Enter Password Name : ");
    scanf("%s", name);

    for(int i=0; i<count; i++){
        if(strcmp(pw[i].name, name) == 0){
            printf("Password Name\tPassword\n");
            printf("-------------\t--------\n");
            printf("%s\t%s\n", pw[i].name, pw[i].password);
            return;
        }
    }

    printf("Password Name '%s' not Found.\n", name);
}

void delete_password(password *pw, int *count){
    if(*count == 0){
        printf("There are no Passwords Saved.\n");
        return;
    }

    char name[MAX_LENGTH];
    printf("Enter Password Name : ");
    scanf("%s", name);

    for(int i=0; i<*count; i++){
        if(strcmp(pw[i].name, name) == 0){
            for(int j=i; j<*count-1; j++){
                strcpy(pw[j].name, pw[j+1].name);
                strcpy(pw[j].password, pw[j+1].password);
            }
            (*count)--;
            printf("Password Deleted Successfully!\n");
            return;
        }
    }

    printf("Password Name '%s' not Found.\n", name);
}