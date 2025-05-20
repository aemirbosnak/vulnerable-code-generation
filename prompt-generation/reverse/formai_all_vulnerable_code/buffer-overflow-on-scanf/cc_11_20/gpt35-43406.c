//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Password {
    char website[50];
    char username[50];
    char password[50];
} Password;

int main() {
    int option, i;
    Password passwords[10];

    do {
        printf("\nPassword Manager\n");
        printf("1. Add a Password\n");
        printf("2. View All Passwords\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                for(i=0; i<10; i++) {
                    if(passwords[i].website[0] == '\0') {
                        printf("\nEnter website name: ");
                        scanf("%s", passwords[i].website);
                        printf("Enter username: ");
                        scanf("%s", passwords[i].username);
                        printf("Enter password: ");
                        scanf("%s", passwords[i].password);
                        printf("\nPassword added successfully!\n");
                        break;
                    }
                }
                if(i == 10) {
                    printf("\nError: Maximum password limit reached!\n");
                }
                break;

            case 2:
                if(passwords[0].website[0] == '\0') {
                    printf("\nNo passwords found!\n");
                }
                else {
                    printf("\nList of Passwords:\n");
                    for(i=0; i<10; i++) {
                        if(passwords[i].website[0] != '\0') {
                            printf("%d. %s - %s:%s\n", i+1, passwords[i].website, passwords[i].username, passwords[i].password);
                        }
                    }
                }
                break;

            case 3:
                printf("\nExiting Password Manager... Goodbye!\n");
                break;

            default:
                printf("\nError: Invalid option selected!\n");
        }

    } while(option != 3);

    return 0;
}