//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    printf(" Welcome to the System Administration program \n");
    printf("---------------------------------------------\n");

    int choice, i;
    char username[20], password[20];
    char admin_username[] = "admin";
    char admin_password[] = "admin123";

    do{
        printf("\n1. Add a new user\n");
        printf("2. Delete a user\n");
        printf("3. Change user's password\n");
        printf("4. View all users\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            
            case 1:
                printf("Enter the username of the new user: ");
                scanf("%s", username);
                printf("Enter the password for the new user: ");
                scanf("%s", password);
                system("useradd -m -p $(openssl passwd -1 $password) $username");
                printf("User %s has been added successfully.\n", username);
                break;

            case 2:
                printf("Enter the username of the user to be deleted: ");
                scanf("%s", username);
                system("userdel -r $username");
                printf("User %s has been deleted successfully.\n", username);
                break;

            case 3:
                printf("Enter the username of the user whose password you want to change: ");
                scanf("%s", username);
                printf("Enter the new password for the user: ");
                scanf("%s", password);
                system("passwd $username");
                printf("Password has been changed successfully.\n");
                break;

            case 4:
                printf("List of all users:\n");
                system("cat /etc/passwd | cut -d : -f 1");
                break;

            case 5:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }

    }while(choice!=5);

    return 0;
}