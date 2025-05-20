//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
} MailingList;

void add_contact(MailingList *list, char *name, char *email) {
    list->num_contacts++;
    list->contacts = realloc(list->contacts, sizeof(Contact) * list->num_contacts);
    strcpy(list->contacts[list->num_contacts-1].name, name);
    strcpy(list->contacts[list->num_contacts-1].email, email);
}

int main() {
    MailingList list;
    list.num_contacts = 0;
    list.contacts = NULL;

    char choice;
    do {
        printf("Mailing List Manager\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Print Contacts\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                printf("Enter email: ");
                char email[MAX_EMAIL_LENGTH];
                scanf("%s", email);
                add_contact(&list, name, email);
                break;

            case '2':
                printf("Enter email to remove: ");
                char remove_email[MAX_EMAIL_LENGTH];
                scanf("%s", remove_email);
                int i;
                for(i=0; i<list.num_contacts; i++) {
                    if(strcmp(list.contacts[i].email, remove_email) == 0) {
                        int j;
                        for(j=i; j<list.num_contacts-1; j++) {
                            strcpy(list.contacts[j].name, list.contacts[j+1].name);
                            strcpy(list.contacts[j].email, list.contacts[j+1].email);
                        }
                        list.num_contacts--;
                        break;
                    }
                }
                break;

            case '3':
                printf("Name\tEmail\n");
                for(int i=0; i<list.num_contacts; i++) {
                    printf("%s\t%s\n", list.contacts[i].name, list.contacts[i].email);
                }
                break;

            case '4':
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while(choice!= '4');

    return 0;
}