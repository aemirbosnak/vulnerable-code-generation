//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    char email[MAX_SIZE];
} contact;

void add_contact(contact* list, int size, char* name, char* email) {
    if(size >= MAX_SIZE) {
        printf("Error: List is full.\n");
        return;
    }

    strcpy(list[size].name, name);
    strcpy(list[size].email, email);

    printf("Contact added successfully.\n");
}

void delete_contact(contact* list, int size, char* name) {
    int i;

    for(i = 0; i < size; i++) {
        if(strcmp(list[i].name, name) == 0) {
            memset(&list[i], 0, sizeof(contact));
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Error: Contact not found.\n");
}

void display_contacts(contact* list, int size) {
    int i;

    for(i = 0; i < size; i++) {
        if(strcmp(list[i].name, "")!= 0 && strcmp(list[i].email, "")!= 0) {
            printf("Name: %s\nEmail: %s\n", list[i].name, list[i].email);
        }
    }
}

void send_email(contact* list, int size, char* subject, char* message) {
    int i;

    for(i = 0; i < size; i++) {
        if(strcmp(list[i].name, "")!= 0 && strcmp(list[i].email, "")!= 0) {
            printf("Sending email to %s...\n", list[i].email);
        }
    }
}

int main() {
    contact list[MAX_SIZE];
    int size = 0;

    while(1) {
        printf("1. Add contact\n2. Delete contact\n3. Display contacts\n4. Send email\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[MAX_SIZE];
                char email[MAX_SIZE];

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter email: ");
                scanf("%s", email);

                add_contact(list, size, name, email);
                break;
            }

            case 2: {
                char name[MAX_SIZE];

                printf("Enter name: ");
                scanf("%s", name);

                delete_contact(list, size, name);
                break;
            }

            case 3: {
                display_contacts(list, size);
                break;
            }

            case 4: {
                char subject[MAX_SIZE];
                char message[MAX_SIZE];

                printf("Enter subject: ");
                scanf("%s", subject);

                printf("Enter message: ");
                scanf("%s", message);

                send_email(list, size, subject, message);
                break;
            }

            case 5: {
                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}