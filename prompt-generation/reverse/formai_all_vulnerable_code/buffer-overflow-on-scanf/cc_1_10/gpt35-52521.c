//FormAI DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 12
#define MAX_USERNAME_LENGTH 20

struct password{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main(){

    printf("Welcome to Password Management - The ultimate way to manage your passwords!\n");
    printf("\n");

    struct password passwords[50];
    int numPasswords = 0;

    while(1){
        int option;

        printf("What do you want to do?\n");
        printf("1 - Save a new password\n");
        printf("2 - View saved passwords\n");
        printf("3 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        if(option == 1){

            char username[MAX_USERNAME_LENGTH];
            char password[MAX_PASSWORD_LENGTH];

            printf("Enter Username (max 20 characters): ");
            scanf("%s", username);
            printf("Enter Password (max 12 characters): ");
            scanf("%s", password);

            if(strlen(username) > MAX_USERNAME_LENGTH){
                printf("Username exceeds %d characters. Try again.\n", MAX_USERNAME_LENGTH);
            }
            else if(strlen(password) > MAX_PASSWORD_LENGTH){
                printf("Password exceeds %d characters. Try again.\n", MAX_PASSWORD_LENGTH);
            }
            else{
                strcpy(passwords[numPasswords].username, username);
                strcpy(passwords[numPasswords].password, password);
                numPasswords++;
                printf("Password saved successfully!\n");
            }
        }
        else if(option == 2){

            if(numPasswords == 0){
                printf("No passwords saved yet.\n");
            }
            else{
                printf("Saved Passwords:\n");
                for(int i = 0; i < numPasswords; i++){
                    printf("%s - %s\n", passwords[i].username, passwords[i].password);
                }
            }
        }
        else if(option == 3){
            printf("Thank you for using Password Management! Have a great day :)\n");
            break;
        }
        else{
            printf("Invalid option. Try again.\n");
        }

        printf("\n");
    }

    return 0;
}