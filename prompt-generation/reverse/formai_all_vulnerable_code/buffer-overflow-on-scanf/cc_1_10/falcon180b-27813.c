//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while(1) {
        int choice;
        printf("1. Add password\n2. Remove password\n3. Search password\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_passwords == MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter username: ");
                    scanf("%s", passwords[num_passwords].username);
                    printf("Enter password: ");
                    scanf("%s", passwords[num_passwords].password);
                    num_passwords++;
                    printf("Password added successfully.\n");
                }
                break;
            case 2:
                printf("Enter username to remove: ");
                scanf("%s", passwords[num_passwords-1].username);
                num_passwords--;
                printf("Password removed successfully.\n");
                break;
            case 3:
                printf("Enter username to search: ");
                scanf("%s", passwords[num_passwords-1].username);
                printf("Password found: %s\n", passwords[num_passwords-1].password);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}