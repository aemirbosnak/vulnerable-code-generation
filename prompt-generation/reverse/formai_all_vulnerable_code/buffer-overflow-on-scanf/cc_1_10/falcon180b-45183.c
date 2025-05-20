//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int count = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("\n\nPassword Manager\n");
        printf("--------------------\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Delete password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(count >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter username: ");
                    scanf("%s", passwords[count].username);
                    printf("Enter password: ");
                    scanf("%s", passwords[count].password);
                    count++;
                }
                break;

            case '2':
                for(int i=0; i<count; i++) {
                    printf("\nUsername: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
                }
                break;

            case '3':
                if(count == 0) {
                    printf("No passwords to delete.\n");
                } else {
                    printf("Enter username of password to delete: ");
                    scanf("%s", passwords[count-1].username);
                    count--;
                }
                break;

            case '4':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= '4');

    return 0;
}