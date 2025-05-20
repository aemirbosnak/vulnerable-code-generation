//FormAI DATASET v1.0 Category: Password management ; Style: recursive
#include<stdio.h>
#include<string.h>
#define MAX_PASSWORD_LENGTH 20
#define MAX_PASSWORDS_STORED 10

char passwords[MAX_PASSWORDS_STORED][MAX_PASSWORD_LENGTH];
int password_index = 0;

void add_password(char password[]){
    if(strlen(password) > MAX_PASSWORD_LENGTH){
        printf("Error: Password length exceeded limit (Max limit: %d)\n", MAX_PASSWORD_LENGTH);
    }
    else if(password_index >= MAX_PASSWORDS_STORED){
        printf("Error: Maximum allowed passwords exceeded (Max passwords: %d)\n", MAX_PASSWORDS_STORED);
    }
    else{
        strcpy(passwords[password_index], password);
        printf("Password added successfully!\n");
        password_index++;
    }
}

int find_password(char password[], int index){
    if(index >= password_index){
        return -1;
    }

    if(strcmp(passwords[index], password) == 0){
        return index;
    }

    return find_password(password, index + 1);
}

void update_password(char old_password[], char new_password[]){
    int password_index = find_password(old_password, 0);
    if(password_index == -1){
        printf("Error: Password not found\n");
    }
    else{
        if(strlen(new_password) > MAX_PASSWORD_LENGTH){
            printf("Error: Password length exceeded limit (Max limit: %d)\n", MAX_PASSWORD_LENGTH);
        }
        else{
            strcpy(passwords[password_index], new_password);
            printf("Password updated successfully!\n");
        }
    }
}

void display_all_passwords(int index){
    if(index < password_index){
        printf("%d: %s\n", index+1, passwords[index]);
        display_all_passwords(index + 1);
    }
}

int main(){
    int option;
    char password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];

    do{
        printf("---------------------------------------\n");
        printf("Password Manager\n");
        printf("---------------------------------------\n");
        printf("1. Add new password\n");
        printf("2. Update password\n");
        printf("3. Display all passwords\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter password: ");
                scanf("%s", password);
                add_password(password);
                break;

            case 2:
                printf("Enter old password: ");
                scanf("%s", password);
                printf("Enter new password: ");
                scanf("%s", new_password);
                update_password(password, new_password);
                break;

            case 3:
                display_all_passwords(0);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option\n");
        }
    }while(option != 4);

    return 0;
}