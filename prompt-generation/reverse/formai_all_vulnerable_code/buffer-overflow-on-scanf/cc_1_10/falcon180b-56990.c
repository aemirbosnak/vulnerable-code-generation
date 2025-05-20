//Falcon-180B DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000

typedef struct {
    char website[50];
    char username[50];
    char password[100];
} Password;

int main() {
    char choice;
    int count = 0;
    Password passwords[MAX_PASSWORDS];

    printf("Welcome to the Cheerful Password Manager!\n");
    printf("Please choose an option:\n");
    printf("1. Add a new password\n");
    printf("2. Search for a password\n");
    printf("3. Exit\n");
    scanf("%c", &choice);

    while (choice!= '3') {
        switch (choice) {
        case '1':
            printf("Enter the website:\n");
            scanf("%s", passwords[count].website);
            printf("Enter the username:\n");
            scanf("%s", passwords[count].username);
            printf("Enter the password:\n");
            scanf("%s", passwords[count].password);
            count++;
            printf("Password added successfully!\n");
            break;
        case '2':
            printf("Enter the website to search for:\n");
            scanf("%s", passwords[0].website);
            for (int i = 0; i < count; i++) {
                if (strcmp(passwords[i].website, passwords[0].website) == 0) {
                    printf("Website found!\n");
                    printf("Username: %s\n", passwords[i].username);
                    printf("Password: %s\n", passwords[i].password);
                }
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
        printf("Please choose an option:\n");
        scanf("%c", &choice);
    }

    return 0;
}