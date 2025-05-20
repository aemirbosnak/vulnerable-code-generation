//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    char email[MAX_SIZE];
} Contact;

Contact contacts[MAX_SIZE];
int num_contacts = 0;

void add_contact() {
    num_contacts++;
    printf("Enter the name of the contact: ");
    scanf("%s", contacts[num_contacts - 1].name);
    printf("Enter the email address of the contact: ");
    scanf("%s", contacts[num_contacts - 1].email);
}

void remove_contact() {
    num_contacts--;
    printf("Enter the name of the contact to remove: ");
    char name[MAX_SIZE];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            memmove(&contacts[i], &contacts[i + 1], sizeof(Contact) * (num_contacts - i - 1));
            break;
        }
    }
}

void view_contacts() {
    printf("Name\tEmail\n");
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].email);
    }
}

void send_message() {
    printf("Enter the message to send: ");
    char message[MAX_SIZE];
    scanf("%s", message);
    printf("Enter the recipient's email address: ");
    char recipient[MAX_SIZE];
    scanf("%s", recipient);
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(recipient, contacts[i].email) == 0) {
            printf("Message sent to %s\n", contacts[i].name);
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add contact\n2. Remove contact\n3. View contacts\n4. Send message\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                view_contacts();
                break;
            case 4:
                send_message();
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}