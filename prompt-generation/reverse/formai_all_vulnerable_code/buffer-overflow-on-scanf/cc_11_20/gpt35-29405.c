//FormAI DATASET v1.0 Category: Password management ; Style: realistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// This program is a password manager created in C programming language. It allows the user to store and retrieve their passwords.

struct Password {
    char name[50];
    char password[50];
};

int main() {
    struct Password passwords[100];
    int count = 0;
    int option;
    int i;

    do {
        printf("\nPassword Manager: \n\n");
        printf("1. Add Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if(count == 100) {
                    printf("\nMaximum limit reached. No more passwords can be added.\n");
                    break;
                }
                printf("\nEnter the name of the website/service: ");
                scanf("%s", passwords[count].name);
                printf("Enter the password (must contain at least 8 characters, including uppercase, lowercase, and special characters): ");
                scanf("%s", passwords[count].password);

                if(strlen(passwords[count].password) < 8) {
                    printf("\nPassword must contain at least 8 characters including uppercase, lowercase and special characters.\n");
                    break;
                }

                int uppercase = 0, lowercase = 0, special = 0;

                for(i = 0; i < strlen(passwords[count].password); i++) {
                    if(isupper(passwords[count].password[i]))
                        uppercase++;
                    else if(islower(passwords[count].password[i]))
                        lowercase++;
                    else if(!isalnum(passwords[count].password[i]))
                        special++;
                }

                if(uppercase < 1 || lowercase < 1 || special < 1) {
                    printf("\nPassword must contain at least 1 uppercase, 1 lowercase and 1 special character.\n");
                    break;
                }

                printf("\nPassword added successfully!\n");
                count++;
                break;

            case 2:
                if(count == 0) {
                    printf("\nNo passwords added yet.\n");
                    break;
                }
                char website[50];
                printf("\nEnter the name of the website/service: ");
                scanf("%s", website);

                for(i = 0; i < count; i++) {
                    if(strcmp(website, passwords[i].name) == 0) {
                        printf("Password: %s\n", passwords[i].password);
                        break;
                    }
                }

                if(i == count)
                    printf("\nPassword does not exist for this website/service.\n");
                break;

            case 3:
                printf("\nExiting the program!\n");
                break;

            default:
                printf("\nInvalid option. Try again.\n");
        }
    } while(option != 3);
    return 0;
}