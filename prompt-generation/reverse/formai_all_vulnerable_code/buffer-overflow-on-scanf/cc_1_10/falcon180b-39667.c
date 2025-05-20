//Falcon-180B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 64

typedef struct {
    char service[64];
    char username[64];
    char password[PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int num_passwords = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_passwords == MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter service name: ");
                    scanf("%s", passwords[num_passwords].service);
                    printf("Enter username: ");
                    scanf("%s", passwords[num_passwords].username);
                    printf("Enter password: ");
                    scanf("%s", passwords[num_passwords].password);
                    num_passwords++;
                }
                break;
            case '2':
                printf("List of passwords:\n");
                for(int i=0; i<num_passwords; i++) {
                    printf("%s %s %s\n", passwords[i].service, passwords[i].username, passwords[i].password);
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= '3');

    return 0;
}