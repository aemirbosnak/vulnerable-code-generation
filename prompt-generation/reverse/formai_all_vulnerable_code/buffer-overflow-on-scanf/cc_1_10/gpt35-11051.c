//FormAI DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password {
    char website[50];
    char username[30];
    char password[30];
};

int main() {
    printf("\n\n\t\tSurprise !! This Program Helps To Manage Passwords\n\n");

    int option, i, j, num_of_passwords = 0;
    struct password passwords[100];

    do {
        printf("\n\t\tOptions:\n\t\t1. Store Password\n\t\t2. Retrieve Password\n\t\t3. Exit\n\t\tEnter your choice: ");
        scanf("%d", &option);

        if(option == 1) {
            printf("\n\t\tEnter Website Name: ");
            scanf("%s", passwords[num_of_passwords].website);

            printf("\n\t\tEnter Username: ");
            scanf("%s", passwords[num_of_passwords].username);

            printf("\n\t\tEnter Password: ");
            scanf("%s", passwords[num_of_passwords].password);

            num_of_passwords++;

            printf("\n\t\tPassword stored successfully! :)\n");
        } else if(option == 2) {
            printf("\n\t\tEnter Website Name: ");
            char website[50];
            scanf("%s", website);

            int found_password = 0;

            for(i=0; i<num_of_passwords; i++) {
                if(strcmp(passwords[i].website, website) == 0) {
                    found_password = 1;

                    printf("\n\t\tUsername: %s\n\t\tPassword: %s\n", passwords[i].username, passwords[i].password);
                    printf("\n\t\tRetrieve your password :) !\n");
                    break;
                }
            }

            if(!found_password) {
                printf("\n\t\tPassword not found :(\n");
            }
        }else if(option == 3) {
            printf("\n\n\t\tExited successfully!\n");
            return 0;
        }else {
            printf("\n\t\tInvalid option!\n");
        }
    } while(1);

    return 0;
}