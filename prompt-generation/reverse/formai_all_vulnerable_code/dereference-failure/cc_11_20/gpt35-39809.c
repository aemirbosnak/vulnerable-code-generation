//FormAI DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// A struct to hold mailing list data
typedef struct {
    char *name;
    char *email;
} MailingList;

int main() {
    int choice = 0, count = 0;
    MailingList *list = NULL;

    while (choice != 4) {
        printf("~~~ Mailing List Manager ~~~\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. List contacts\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[100], email[100];

                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);

                list = realloc(list, (count + 1) * sizeof(MailingList));
                list[count].name = malloc((strlen(name) + 1) * sizeof(char));
                list[count].email = malloc((strlen(email) + 1) * sizeof(char));

                strcpy(list[count].name, name);
                strcpy(list[count].email, email);

                count++;

                printf("\nContact added!\n");
                break;
            }
            case 2: {
                if (count == 0) {
                    printf("\nThere are no contacts to remove.\n");
                } else {
                    char remove_email[100];
                    int index = -1;

                    printf("\nEnter email of contact to remove: ");
                    scanf("%s", remove_email);

                    for (int i = 0; i < count; i++) {
                        if (strcmp(list[i].email, remove_email) == 0) {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1) {
                        printf("\nNo contact found with email '%s'\n", remove_email);
                    } else {
                        free(list[index].name);
                        free(list[index].email);

                        for (int i = index; i < count - 1; i++) {
                            list[i].name = list[i + 1].name;
                            list[i].email = list[i + 1].email;
                        }

                        count--;

                        list = realloc(list, count * sizeof(MailingList));

                        printf("\nContact with email '%s' removed\n", remove_email);
                    }
                }
                break;
            }
            case 3: {
                if (count == 0) {
                    printf("\nThere are no contacts to display.\n");
                } else {
                    printf("\n+----------------------+---------------------------+\n");
                    printf("| Name                 | Email                     |\n");
                    printf("+----------------------+---------------------------+\n");

                    for (int i = 0; i < count; i++) {
                        printf("| %-20s | %-25s |\n", list[i].name, list[i].email);
                    }

                    printf("+----------------------+---------------------------+\n");
                }
                break;
            }
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again\n");
                break;
        }

        printf("\n");
    }

    // Free memory used by the mailing list
    for (int i = 0; i < count; i++) {
        free(list[i].name);
        free(list[i].email);
    }
    free(list);

    return 0;
}