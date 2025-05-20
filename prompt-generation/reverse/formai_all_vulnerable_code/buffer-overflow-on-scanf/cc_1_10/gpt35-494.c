//FormAI DATASET v1.0 Category: Password management ; Style: surprised
#include<stdio.h>

int main(){
    printf("Welcome to our Password Management System!\n");
    printf("Please enter your username: ");
    char username[20];
    scanf("%s", &username);
    printf("Ah, welcome %s!\n", username);
    printf("Please enter your current password: ");
    char password[20];
    scanf("%s", &password);
    int attempts = 0;
    while(attempts < 3){
        if(strcmp(password, "correctPassword123") == 0){
            printf("Password accepted!\n");
            printf("What would you like to do?\n");
            printf("1. Change password\n");
            printf("2. View saved passwords\n");
            printf("3. Exit\n");
            int choice;
            scanf("%d", &choice);
            switch(choice){
                case 1:{
                    printf("Enter new password: ");
                    char newPassword[20];
                    scanf("%s", &newPassword);
                    printf("New password saved!\n");
                    strcpy(password, newPassword);
                    break;
                }
                case 2:{
                    printf("Saved passwords:\n");
                    printf("1. Email: qwerty123\n");
                    printf("2. Social Media: 987654\n");
                    printf("3. Bank Account: myPass123\n");
                    break;
                }
                case 3:{
                    printf("Goodbye!\n");
                    return 0;
                }
                default:{
                    printf("Invalid choice, try again.\n");
                    break;
                }
            }
        }
        else{
            printf("Incorrect password. Please try again.\n");
            attempts++;
            if(attempts == 3){
                printf("Too many failed attempts. Account locked.\n");
                return 0;
            }
            printf("Attempts remaining: %d\n", (3-attempts));
            printf("Please enter your current password: ");
            scanf("%s", &password);
        }
    }
    return 0;
}