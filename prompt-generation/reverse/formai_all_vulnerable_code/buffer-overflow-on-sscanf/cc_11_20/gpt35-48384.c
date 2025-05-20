//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
/* Romeo and Juliet Mailing List Manager */
/* Written in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char subscribers[100][50];
    int num_subscribers = 0;
    char input[50];
    char action[10];
    char email[50];
    int i, j;
    int found;

    printf("Welcome to the Romeo and Juliet mailing list manager!\n");

    while(1) {
        printf("\nEnter command (add/remove/view/quit): ");
        fgets(input, 50, stdin);
        sscanf(input, "%s", action);

        if(strcmp(action, "add") == 0) {
            printf("\nEnter email address to add: ");
            fgets(input, 50, stdin);
            sscanf(input, "%s", email);

            // Check if email already exists
            found = 0;
            for(i = 0; i < num_subscribers; i++) {
                if(strcmp(subscribers[i], email) == 0) {
                    printf("Email already exists in mailing list.\n");
                    found = 1;
                    break;
                }
            }

            if(!found) {
                strcpy(subscribers[num_subscribers], email);
                printf("Email added to mailing list.\n");
                num_subscribers++;
            }
        }

        else if(strcmp(action, "remove") == 0) {
            printf("\nEnter email address to remove: ");
            fgets(input, 50, stdin);
            sscanf(input, "%s", email);

            // Check if email exists
            found = 0;
            for(i = 0; i < num_subscribers; i++) {
                if(strcmp(subscribers[i], email) == 0) {
                    found = 1;
                    for(j = i; j < num_subscribers-1; j++) {
                        strcpy(subscribers[j], subscribers[j+1]);
                    }
                    num_subscribers--;
                    printf("Email removed from mailing list.\n");
                    break;
                }
            }
            if(!found) {
                printf("Email not found in mailing list.\n");
            }
        }

        else if(strcmp(action, "view") == 0) {
            if(num_subscribers == 0) {
                printf("Mailing list is empty.\n");
            }
            else {
                printf("\nMailing list:\n");
                for(i = 0; i < num_subscribers; i++) {
                    printf("%d. %s\n", i+1, subscribers[i]);
                }
            }
        }

        else if(strcmp(action, "quit") == 0) {
            printf("\nGoodbye!\n");
            break;
        }

        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}