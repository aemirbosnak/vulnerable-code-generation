//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

void generatePassword(char *password, int length) {
    // Generating random password
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789#$&*@";
    int i;
    int charsetLen = strlen(charset);
    srand(time(NULL)); // Seed for random number generator

    for(i=0; i<length; i++) {
        int randomIndex = rand()%charsetLen; // Generating random index within the length of charset
        password[i] = charset[randomIndex]; // Getting character from the charset using random index
    }

    password[length] = '\0'; // Adding null terminator at end of password
}

int main() {
    char masterPassword[20], newPassword[20], confirmNewPassword[20], savedPassword[20];
    FILE *fp;

    printf("Welcome to the Password Management System\n");
    printf("Please enter your Master Password: ");
    scanf("%s", masterPassword);

    // Open file containing saved password
    fp = fopen("saved_password.txt", "r");

    if(fp == NULL) {
        printf("No saved password found. Creating a new password now.\n");
        printf("Please choose a new password (8-20 characters long, containing uppercase/lowercase letters, numbers and symbols): ");
        scanf("%s", newPassword);

        // Checking password length
        if(strlen(newPassword) < 8 || strlen(newPassword) > 20) {
            printf("Password should be 8-20 characters long. Please try again.\n");
            exit(0);
        }

        // Checking password contains atleast one uppercase, one lowercase, one number and one symbol
        int i, hasUpper=0, hasLower=0, hasNumber=0, hasSymbol=0;
        for(i=0; i<strlen(newPassword); i++) {
            char c = newPassword[i];
            if(isupper(c)) hasUpper=1;
            if(islower(c)) hasLower=1;
            if(isdigit(c)) hasNumber=1;
            if(!isalnum(c)) hasSymbol=1;
        }
        if(!hasUpper || !hasLower || !hasNumber || !hasSymbol) {
            printf("Password should contain atleast one uppercase, one lowercase, one number and one symbol. Please try again.\n");
            exit(0);
        }

        // Confirming new password
        printf("Please confirm your new password: ");
        scanf("%s", confirmNewPassword);

        if(strcmp(newPassword, confirmNewPassword) != 0) {
            printf("New passwords do not match. Try again.\n");
            exit(0);
        }

        // Generating random password for saved password
        char savedPassword[11];
        generatePassword(savedPassword, 10);

        // Saving new password in file
        fp = fopen("saved_password.txt", "w");
        fprintf(fp, "%s\n%s", newPassword, savedPassword);
        fclose(fp);

        printf("New password created successfully.\n");
    }
    else {
        fscanf(fp, "%s %s", savedPassword, masterPassword);

        // Checking if entered password matches saved password
        if(strcmp(masterPassword, savedPassword) != 0) {
            printf("Incorrect password. You do not have permission to access this system.\n");
            exit(0);
        }

        printf("Access granted.\n");

        // Enable user to change saved password
        char newSavedPassword[20];
        printf("Would you like to change your saved password? (Y/N) ");
        getchar(); // To clear input buffer
        char option = getchar();

        if(option == 'Y' || option == 'y') {
            printf("Please enter a new saved password: ");
            scanf("%s", newSavedPassword);

            printf("Please enter your current (master) password to confirm: ");
            scanf("%s", masterPassword);

            if(strcmp(masterPassword, savedPassword) != 0) {
                printf("Incorrect password. Please try again later.\n");
                exit(0);
            }

            fp = fopen("saved_password.txt", "w");
            fprintf(fp, "%s\n%s", newSavedPassword, newSavedPassword);
            fclose(fp);

            printf("Saved password changed successfully.\n");
        }
    }

    return 0;
}