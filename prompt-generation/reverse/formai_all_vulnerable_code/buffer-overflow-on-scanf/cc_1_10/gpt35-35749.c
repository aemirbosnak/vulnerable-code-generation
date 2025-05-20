//FormAI DATASET v1.0 Category: Password management ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Password {
    char account[50];
    char password[50];
};

typedef struct Password password;

// function for adding a new password
void add_password(password *enc_password, int *password_count) {
    printf("\nEnter the name of the account: ");
    scanf("%s", enc_password[*password_count].account);
    printf("Enter the password for %s: ", enc_password[*password_count].account);
    scanf("%s", enc_password[*password_count].password);
    (*password_count)++;
    printf("\nPassword added successfully!\n");
}

// function for displaying all saved passwords
void display_passwords(password *enc_password, int *password_count) {
    if(*password_count == 0) {
        printf("\nThere are no saved passwords to display.\n");
        return;
    }
    printf("\nAccounts\tPasswords\n");
    for(int i=0; i<*password_count; i++) {
        printf("%s\t\t%s\n", enc_password[i].account, enc_password[i].password);
    }
}

// function for deleting a password
void delete_password(password *enc_password, int *password_count) {
    if(*password_count == 0) {
        printf("\nThere are no saved passwords to delete.\n");
        return;
    }
    char account_name[50];
    printf("\nEnter the name of the account whose password you want to delete: ");
    scanf("%s", account_name);
    int found = 0;
    for(int i=0; i<*password_count; i++) {
        if(strcmp(enc_password[i].account, account_name) == 0) {
            found = 1;
            for(int j=i; j<*password_count-1; j++) {
                strcpy(enc_password[j].account, enc_password[j+1].account);
                strcpy(enc_password[j].password, enc_password[j+1].password);
            }
            (*password_count)--;
            printf("\nPassword deleted successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("\nAccount not found. Failed to delete password.\n");
    }
}

// function for searching for a password
void search_password(password *enc_password, int *password_count) {
    if(*password_count == 0) {
        printf("\nThere are no saved passwords to search.\n");
        return;
    }
    char account_name[50];
    printf("\nEnter the name of the account whose password you want to search: ");
    scanf("%s", account_name);
    int found = 0;
    for(int i=0; i<*password_count; i++) {
        if(strcmp(enc_password[i].account, account_name) == 0) {
            found = 1;
            printf("\nThe password for %s is: %s\n", enc_password[i].account, enc_password[i].password);
            break;
        }
    }
    if(!found) {
        printf("\nAccount not found. Failed to search password.\n");
    }
}

int main() {
    printf("##########################################################\n");
    printf("#                  Password Management System             #\n");
    printf("##########################################################\n\n");

    password *enc_password = (password*)malloc(10*sizeof(password)); // allocation of memory
    int password_count = 0;
    int choice;

    while(1) {
        printf("\n----------------------------------------------------------\n");
        printf("Press 1 to add a new password.\n");
        printf("Press 2 to display all saved passwords.\n");
        printf("Press 3 to delete a password.\n");
        printf("Press 4 to search for a password.\n");
        printf("Press 5 to exit.\n");
        printf("----------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_password(enc_password, &password_count);
                break;
            case 2:
                display_passwords(enc_password, &password_count);
                break;
            case 3:
                delete_password(enc_password, &password_count);
                break;
            case 4:
                search_password(enc_password, &password_count);
                break;
            case 5:
                printf("\nExiting Password Management System. Goodbye!\n");
                free(enc_password); // release memory
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}