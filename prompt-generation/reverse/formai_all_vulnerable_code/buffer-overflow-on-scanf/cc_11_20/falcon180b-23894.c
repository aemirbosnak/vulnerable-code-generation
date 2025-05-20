//Falcon-180B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct Password {
    char website[50];
    char username[50];
    char password[50];
};

int main() {
    int numPasswords = 0;
    char choice;
    struct Password passwords[MAX_PASSWORDS];

    do {
        printf("\nPassword Manager\n");
        printf("-----------------\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter website: ");
                scanf("%s", passwords[numPasswords].website);
                printf("Enter username: ");
                scanf("%s", passwords[numPasswords].username);
                printf("Enter password: ");
                scanf("%s", passwords[numPasswords].password);
                numPasswords++;
                break;
            case '2':
                printf("\nPasswords:\n");
                for(int i=0; i<numPasswords; i++) {
                    printf("%s %s %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
                }
                break;
            case '3':
                printf("Enter website: ");
                char searchWebsite[50];
                scanf("%s", searchWebsite);
                int found = 0;
                for(int i=0; i<numPasswords; i++) {
                    if(strcmp(passwords[i].website, searchWebsite) == 0) {
                        printf("\n%s %s %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
                        found = 1;
                    }
                }
                if(found == 0) {
                    printf("No password found for %s\n", searchWebsite);
                }
                break;
            case '4':
                printf("Enter website: ");
                char deleteWebsite[50];
                scanf("%s", deleteWebsite);
                int index = -1;
                for(int i=0; i<numPasswords; i++) {
                    if(strcmp(passwords[i].website, deleteWebsite) == 0) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("No password found for %s\n", deleteWebsite);
                } else {
                    numPasswords--;
                    for(int i=index; i<numPasswords; i++) {
                        strcpy(passwords[i].website, passwords[i+1].website);
                        strcpy(passwords[i].username, passwords[i+1].username);
                        strcpy(passwords[i].password, passwords[i+1].password);
                    }
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= '5');

    return 0;
}