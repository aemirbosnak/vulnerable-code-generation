//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15

struct contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
};

int main()
{
    struct contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("Enter command (add, view, search, exit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (num_contacts == MAX_CONTACTS) {
                printf("Phonebook is full!\n");
            } else {
                struct contact c;
                printf("Enter name: ");
                scanf("%s", c.name);
                printf("Enter phone: ");
                scanf("%s", c.phone);
                phonebook[num_contacts] = c;
                num_contacts++;
                printf("Added contact %s: %s\n", c.name, c.phone);
            }
        } else if (strcmp(command, "view") == 0) {
            if (num_contacts == 0) {
                printf("Phonebook is empty!\n");
            } else {
                printf("Phonebook:\n");
                for (int i = 0; i < num_contacts; i++) {
                    printf("%d. %s: %s\n", i+1, phonebook[i].name, phonebook[i].phone);
                }
            }
        } else if (strcmp(command, "search") == 0) {
            if (num_contacts == 0) {
                printf("Phonebook is empty!\n");
            } else {
                printf("Enter search term: ");
                char term[MAX_NAME_LEN];
                scanf("%s", term);
                printf("Search results:\n");
                int num_results = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (strstr(phonebook[i].name, term) != NULL || strstr(phonebook[i].phone, term) != NULL) {
                        printf("%d. %s: %s\n", num_results+1, phonebook[i].name, phonebook[i].phone);
                        num_results++;
                    }
                }
                if (num_results == 0) {
                    printf("No results found!\n");
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}