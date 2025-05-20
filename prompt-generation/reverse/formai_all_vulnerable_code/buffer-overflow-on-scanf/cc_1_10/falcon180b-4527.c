//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct Password{
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
};

int main(){
    char choice;
    int num_passwords = 0;
    struct Password passwords[MAX_PASSWORDS];
    char input_password[MAX_PASSWORD_LENGTH];
    char input_username[MAX_PASSWORD_LENGTH];
    int i;

    printf("Welcome to the Password Manager!\n");
    printf("Please enter your master password to continue: ");
    scanf("%s", input_password);

    //check if master password is correct
    if(strcmp(input_password, "password")!= 0){
        printf("Incorrect master password!\n");
        return 1;
    }

    while(1){
        printf("\nPlease select an option:\n");
        printf("1. Add a new password\n");
        printf("2. View saved passwords\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);

        switch(choice){
            case '1':
                printf("Enter the username: ");
                scanf("%s", input_username);
                printf("Enter the password: ");
                scanf("%s", input_password);

                if(num_passwords >= MAX_PASSWORDS){
                    printf("Maximum number of passwords reached!\n");
                    break;
                }

                strcpy(passwords[num_passwords].username, input_username);
                strcpy(passwords[num_passwords].password, input_password);
                num_passwords++;
                break;

            case '2':
                if(num_passwords == 0){
                    printf("No passwords saved yet!\n");
                    break;
                }

                for(i=0; i<num_passwords; i++){
                    printf("\n%s\n%s\n", passwords[i].username, passwords[i].password);
                }
                break;

            case '3':
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}