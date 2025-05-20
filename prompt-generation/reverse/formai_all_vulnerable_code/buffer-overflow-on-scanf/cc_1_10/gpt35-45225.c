//FormAI DATASET v1.0 Category: Password management ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USER 10
#define MAX_PASS 14

int main() {
    char users[MAX_USER][MAX_PASS];
    char passwords[MAX_USER][MAX_PASS];
    int i;
    int authenticated = 0;
    printf("Welcome to the password management system.\n\n");

    //add users and passwords
    for(i=0; i<MAX_USER; i++) {
        printf("Enter a username (max 9 characters): ");
        scanf("%s", &users[i]);
        printf("Enter a password (max 13 characters): ");
        scanf("%s", &passwords[i]);
    }

    //authenticate user
    char username[MAX_PASS];
    char password[MAX_PASS];

    while(authenticated == 0) {
        printf("\nEnter your username: ");
        scanf("%s", username);
        printf("Enter your password: ");
        scanf("%s", password);

        for(i=0; i<MAX_USER; i++) {
            if(strcmp(users[i], username) == 0 && strcmp(passwords[i], password) == 0) {
                authenticated = 1;
                printf("\nAuthentication successful!\n\n");
                break;
            }
        }

        if(authenticated == 0) {
            printf("\nAuthentication failed. Please try again.\n\n");
        }
    }

    //add new password
    char newPass[MAX_PASS];
    printf("Enter a new password (max 13 characters): ");
    scanf("%s", newPass);

    //update password
    for(i=0; i<MAX_USER; i++) {
        if(strcmp(users[i], username) == 0) {
            strcpy(passwords[i], newPass);
            printf("Password updated successfully!\n\n");
            break;
        }
    }

    return 0;
}