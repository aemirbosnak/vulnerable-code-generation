//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

contact* new_contact() {
    contact* c = malloc(sizeof(contact));
    c->name[0] = '\0';
    c->email[0] = '\0';
    return c;
}

void delete_contact(contact* c) {
    free(c);
}

int compare_contacts(const void* a, const void* b) {
    const contact* c1 = a;
    const contact* c2 = b;
    return strcmp(c1->name, c2->name);
}

void print_contact(contact* c) {
    printf("Name: %s, Email: %s\n", c->name, c->email);
}

int main() {
    int choice, n;
    contact* contacts = NULL;

    do {
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Sort contacts\n");
        printf("4. Print contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts->name);
                printf("Enter email: ");
                scanf("%s", contacts->email);
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", contacts->name);
                contacts = realloc(contacts, sizeof(contact));
                break;
            case 3:
                qsort(contacts, n, sizeof(contact), compare_contacts);
                break;
            case 4:
                for(n=0; n<sizeof(contacts)/sizeof(contact); n++) {
                    print_contact(&contacts[n]);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}