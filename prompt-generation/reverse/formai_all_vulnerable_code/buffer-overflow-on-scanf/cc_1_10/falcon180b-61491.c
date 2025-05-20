//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

int main() {
    int choice;
    int num_contacts = 0;
    contact *contacts = NULL;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                break;
            case 2:
                printf("Enter name to remove: ");
                scanf("%s", contacts[num_contacts].name);
                num_contacts--;
                break;
            case 3:
                printf("Number of contacts: %d\n", num_contacts);
                for(int i=0; i<num_contacts; i++) {
                    printf("Name: %s\nEmail: %s\n", contacts[i].name, contacts[i].email);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}