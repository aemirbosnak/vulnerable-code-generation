//Falcon-180B DATASET v1.0 Category: Password management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[50];
} Password;

int main() {
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    while(numPasswords < MAX_PASSWORDS) {
        printf("Enter a username and password (or leave blank to finish):\n");
        scanf("%s %s", passwords[numPasswords].username, passwords[numPasswords].password);

        if(strlen(passwords[numPasswords].username) == 0 && strlen(passwords[numPasswords].password) == 0)
            break;

        numPasswords++;
    }

    printf("\nNumber of passwords stored: %d\n", numPasswords);

    while(1) {
        printf("\nEnter a username to search for:\n");
        char searchUsername[50];
        scanf("%s", searchUsername);

        int searchResult = -1;
        for(int i = 0; i < numPasswords; i++) {
            if(strcmp(passwords[i].username, searchUsername) == 0) {
                printf("\nPassword for %s: %s\n", searchUsername, passwords[i].password);
                searchResult = 0;
                break;
            }
        }

        if(searchResult == -1)
            printf("\nNo password found for %s.\n", searchUsername);

        char searchAgain;
        printf("\nSearch again? (y/n): ");
        scanf(" %c", &searchAgain);

        if(searchAgain!= 'y')
            break;
    }

    return 0;
}