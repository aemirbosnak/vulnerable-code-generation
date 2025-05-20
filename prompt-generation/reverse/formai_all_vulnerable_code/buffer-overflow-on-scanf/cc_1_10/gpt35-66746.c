//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 50

struct password {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

int main() {
    int n = 0;
    printf("Enter the number of passwords you want to manage: ");
    scanf("%d", &n);
    struct password passwords[n];
    
    // Enter and store passwords
    for(int i=0; i<n; i++) {
        printf("\nEnter website name: ");
        scanf("%s", passwords[i].website);
        printf("Enter username: ");
        scanf("%s", passwords[i].username);
        printf("Enter password: ");
        scanf("%s", passwords[i].password);
    }

    // View all passwords
    printf("\nAll passwords:\n");
    for(int i=0; i<n; i++) {
        printf("%s\t%s\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }

    // Search for a specific website's password
    char search[MAX_LENGTH];
    printf("\nEnter website name to search password for: ");
    scanf("%s", search);
    int found = 0;
    for(int i=0; i<n; i++) {
        if(strcmp(passwords[i].website, search) == 0) {
            printf("%s's username: %s and password: %s\n", search, passwords[i].username, passwords[i].password);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Website not found in database.\n");
    }

    // Generate new password
    char generate[MAX_LENGTH];
    printf("\nEnter the website name for which you want to generate a new password: ");
    scanf("%s", generate);
    for(int i=0; i<n; i++) {
        if(strcmp(passwords[i].website, generate) == 0) {
            char newpass[MAX_LENGTH];
            printf("Enter new password: ");
            scanf("%s", newpass);
            strcpy(passwords[i].password, newpass);
            printf("Password for %s has been updated.\n", generate);
            break;
        }
    }

    return 0;
}