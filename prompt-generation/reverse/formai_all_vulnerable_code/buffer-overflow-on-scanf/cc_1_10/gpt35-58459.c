//FormAI DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char username[20], domain[20], password[20];
    int choice;
    printf("\n\tWelcome to My Unique Email Client");

    do{
        printf("\n\nMenu:\n");
        printf("\n1. Login");
        printf("\n2. Forgot Password");
        printf("\n3. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter Username: ");
                scanf("%s", &username);

                printf("\nEnter Domain: ");
                scanf("%s", &domain);

                printf("\nEnter Password: ");
                scanf("%s", &password);

                printf("\n\nLogged in as %s@%s\n", username, domain);
                printf("\n---------------------------");
                printf("\nWelcome to your Email Client!");
                break;

            case 2:
                printf("\nEnter Username: ");
                scanf("%s", &username);

                printf("\nEnter Domain: ");
                scanf("%s", &domain);

                printf("\nAnswer the Security Question: What was your first pet's name? ");
                char security[20];
                scanf("%s", &security);

                printf("\nPassword Reset Instructions have been sent to your registered email.");
                break;

            case 3:
                printf("\n\nExiting Email Client...");
                exit(0);

            default:
                printf("\n\nInvalid Choice! Please try again.");
                break;
        }

    }while(choice != 3);

    return 0;
}