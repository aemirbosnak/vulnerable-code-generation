//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for holding password details
struct Password {
    char username[50];
    char website[50];
    char password[50];
};

int main(){
    int choice, count = 0;

    // Allocating memory dynamically for password list
    struct Password *passwordList = (struct Password*) malloc(sizeof(struct Password));

    printf("\nWelcome to Password Manager!\n");

    while(1){
        printf("\nPlease select an option:\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                // Adding a new password
                printf("\nEnter a username: ");
                scanf("%s", passwordList[count].username);

                printf("Enter the website the password is for: ");
                scanf("%s", passwordList[count].website);

                printf("Enter the password: ");
                scanf("%s", passwordList[count].password);

                count++;

                // Reallocating memory for additional passwords
                passwordList = (struct Password*) realloc(passwordList, (count+1)*sizeof(struct Password));

                break;
            case 2:
                // Viewing saved passwords
                if(count == 0){
                    printf("\nYou have not saved any passwords.\n");
                } else {
                    printf("\nYour saved passwords:\n");

                    for(int i=0;i<count;i++){
                        printf("%d. Website: %s, Username: %s, Password: %s\n", i+1, passwordList[i].website, passwordList[i].username, passwordList[i].password);
                    }
                }

                break;
            case 3:
                // Exiting program
                printf("\nThank you for using Password Manager!\n");
                free(passwordList);
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
    return 0;
}