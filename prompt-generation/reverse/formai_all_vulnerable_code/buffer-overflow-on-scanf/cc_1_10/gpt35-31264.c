//FormAI DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[20];
    int choice;
    FILE *fptr;
    fptr = fopen("password.txt","w");
    printf("Welcome to the password manager.\n\n");
    printf("Enter your password: ");
    fgets(password, 20, stdin);
    fputs(password, fptr);
    fclose(fptr);
    printf("\nYour password has been saved!\n");
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Change password\n");
        printf("2. Retrieve password\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                fptr = fopen("password.txt", "w");
                if(fptr == NULL) {
                    printf("Error opening file.");
                    exit(1);
                }
                printf("\nEnter new password: ");
                fgets(password, 20, stdin);
                fputs(password, fptr);
                fclose(fptr);
                printf("\nPassword changed successfully!\n");
                break;
            }
            case 2: {
                fptr = fopen("password.txt", "r");
                if(fptr == NULL) {
                    printf("\nError opening file.");
                    exit(1);
                }
                fgets(password, 20, fptr);
                printf("\nYour password is: %s", password);
                fclose(fptr);
                break;
            }
            case 3: {
                printf("\nGoodbye!\n");
                exit(0);
            }
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}