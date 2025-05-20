//FormAI DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100 // Maximum number of passwords to store
#define MAX_PW_LEN 20     // Maximum length of a password

struct Password{
    char name[MAX_PW_LEN];
    char password[MAX_PW_LEN];
};

typedef struct Password Password;

int get_action(){
    int action;

    printf("\n\n1. Add a new password\n");
    printf("2. Display all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    
    scanf("%d", &action);

    return action;
}

void add_password(Password *pw, int *pw_count){
    int index = *pw_count;

    if(index >= MAX_PASSWORDS){
        printf("Error: Maximum number of passwords reached (%d).\n", MAX_PASSWORDS);
        return;
    }

    printf("\nEnter name: ");
    scanf("%s", pw[index].name);

    printf("Enter password: ");
    scanf("%s", pw[index].password);

    (*pw_count)++;
    printf("Password added successfully.\n");
}

void display_passwords(Password *pw, int pw_count){
    if(!pw_count){
        printf("\nNo passwords stored.\n");
        return;
    }

    printf("\n%-20s%s\n", "Name", "Password");
    printf("--------------------------------------\n");
    for(int i=0; i<pw_count; i++){
        printf("%-20s%s\n", pw[i].name, pw[i].password);
    }
}

void search_password(Password *pw, int pw_count){
    if(!pw_count){
        printf("\nNo passwords stored to search for.\n");
        return;
    }

    char search_term[MAX_PW_LEN];

    printf("\nEnter name to search for: ");
    scanf("%s", search_term);

    for(int i=0; i<pw_count; i++){
        if(strcmp(search_term, pw[i].name) == 0){
            printf("\nPassword for %s: %s\n", pw[i].name, pw[i].password);
            return;
        }
    }

    printf("\nMatching password not found.\n");
}

void delete_password(Password *pw, int *pw_count){
    if(!(*pw_count)){
        printf("\nNo passwords stored to delete.\n");
        return;
    }

    char delete_term[MAX_PW_LEN];

    printf("\nEnter name to delete: ");
    scanf("%s", delete_term);

    for(int i=0; i<*pw_count; i++){
        if(strcmp(delete_term, pw[i].name) == 0){
            printf("\nPassword for %s: %s\n", pw[i].name, pw[i].password);
            
            for(int j=i; j<(*pw_count)-1; j++){
                strcpy(pw[j].name, pw[j+1].name);
                strcpy(pw[j].password, pw[j+1].password);
            }

            (*pw_count)--;
            printf("Password deleted.\n");
            return;
        }
    }

    printf("\nMatching password not found.\n");
}

int main(){
    Password pw[MAX_PASSWORDS];
    int pw_count = 0;
    int action;

    while(1){
        action = get_action();

        switch (action){
            case 1:
                add_password(pw, &pw_count);
                break;
            case 2:
                display_passwords(pw, pw_count);
                break;
            case 3:
                search_password(pw, pw_count);
                break;
            case 4:
                delete_password(pw, &pw_count);
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}