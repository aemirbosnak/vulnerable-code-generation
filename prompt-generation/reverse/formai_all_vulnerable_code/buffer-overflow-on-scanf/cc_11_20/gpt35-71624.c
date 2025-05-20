//FormAI DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char name[100];
    char email_address[50];
    struct email *next;
};

int main()
{
    printf("Welcome to your Mailing List Manager!\n\n");

    struct email *head = NULL;
    struct email *current = NULL;

    char input[10];

    while (1) {
        printf("What would you like to do? Add, Remove, Print, or Exit?\n");
        scanf("%s", input);

        if (strcmp(input, "Add") == 0) {
            struct email *new_email = malloc(sizeof(struct email));

            printf("Please enter the name of the recipient:\n");
            scanf("%s", new_email->name);

            printf("Please enter the email address of the recipient:\n");
            scanf("%s", new_email->email_address);

            new_email->next = NULL;

            if (head == NULL) {
                head = new_email;
                current = head;
            } else {
                current->next = new_email;
                current = new_email;
            }

            printf("Email successfully added to the mailing list!\n\n");
        } else if (strcmp(input, "Remove") == 0) {
            char email_address[50];
            struct email *previous = NULL;
            struct email *current = head;

            printf("Please enter the email address you would like to remove:\n");
            scanf("%s", email_address);

            while (current != NULL) {
                if (strcmp(current->email_address, email_address) == 0) {
                    if (current == head) {
                        head = current->next;
                        free(current);
                        printf("Email successfully removed from the mailing list!\n\n");
                        break;
                    } else {
                        previous->next = current->next;
                        free(current);
                        printf("Email successfully removed from the mailing list!\n\n");
                        break;
                    }
                }

                previous = current;
                current = current->next;
            }

            if (current == NULL) {
                printf("Email not found in the mailing list.\n\n");
            }
        } else if (strcmp(input, "Print") == 0) {
            struct email *current = head;

            while (current != NULL) {
                printf("%s: %s\n", current->name, current->email_address);
                current = current->next;
            }

            printf("\n");
        } else if (strcmp(input, "Exit") == 0) {
            printf("Thank you for using your Mailing List Manager!\n");
            return 0;
        } else {
            printf("Invalid input. Please try again.\n\n");
        }
    }

    return 0;
}