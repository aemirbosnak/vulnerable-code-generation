//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

typedef struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

int main() {
    int num_contacts = 0;
    Contact *phonebook = (Contact *) malloc(sizeof(Contact) * MAX_CONTACTS);

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", phonebook[num_contacts].name);
            printf("Enter number: ");
            scanf("%s", phonebook[num_contacts].number);
            num_contacts++;
            break;
        case 2:
            printf("Enter name to search: ");
            char search_name[MAX_NAME_LEN];
            scanf("%s", search_name);
            int i;
            for (i = 0; i < num_contacts; i++) {
                if (strcmp(phonebook[i].name, search_name) == 0) {
                    printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
                }
            }
            break;
        case 3:
            printf("Enter name to delete: ");
            char delete_name[MAX_NAME_LEN];
            scanf("%s", delete_name);
            int j;
            for (j = 0; j < num_contacts; j++) {
                if (strcmp(phonebook[j].name, delete_name) == 0) {
                    memmove(&phonebook[j], &phonebook[j+1], sizeof(Contact) * (num_contacts - j - 1));
                    num_contacts--;
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    free(phonebook);
    return 0;
}