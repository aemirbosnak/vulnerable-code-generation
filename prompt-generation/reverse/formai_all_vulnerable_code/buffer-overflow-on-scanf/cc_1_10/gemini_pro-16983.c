//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_MESSAGES 1000

typedef struct {
    char name[50];
    char email[50];
} contact;

typedef struct {
    char subject[50];
    char body[1000];
    int sender;
    int recipients[MAX_CONTACTS];
    int num_recipients;
} message;

contact contacts[MAX_CONTACTS];
message messages[MAX_MESSAGES];
int num_contacts = 0;
int num_messages = 0;

void add_contact() {
    printf("Enter contact name: ");
    scanf(" %[^\n]%*c", contacts[num_contacts].name);
    printf("Enter contact email: ");
    scanf(" %[^\n]%*c", contacts[num_contacts].email);
    num_contacts++;
}

void list_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s (%s)\n", i + 1, contacts[i].name, contacts[i].email);
    }
}

void search_contacts() {
    char query[50];
    printf("Enter search query: ");
    scanf(" %[^\n]%*c", query);
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(contacts[i].name, query) || strstr(contacts[i].email, query)) {
            printf("%d. %s (%s)\n", i + 1, contacts[i].name, contacts[i].email);
        }
    }
}

void add_message() {
    printf("Enter message subject: ");
    scanf(" %[^\n]%*c", messages[num_messages].subject);
    printf("Enter message body: ");
    scanf(" %[^\n]%*c", messages[num_messages].body);
    printf("Enter sender contact number: ");
    int sender;
    scanf("%d", &sender);
    messages[num_messages].sender = sender - 1;
    printf("Enter recipient contact numbers (separated by spaces): ");
    int recipient;
    while (scanf("%d", &recipient)) {
        messages[num_messages].recipients[messages[num_messages].num_recipients] = recipient - 1;
        messages[num_messages].num_recipients++;
    }
    num_messages++;
}

void list_messages() {
    for (int i = 0; i < num_messages; i++) {
        printf("Message %d:\n", i + 1);
        printf("Subject: %s\n", messages[i].subject);
        printf("Body: %s\n", messages[i].body);
        printf("Sender: %s (%s)\n", contacts[messages[i].sender].name,
            contacts[messages[i].sender].email);
        printf("Recipients:\n");
        for (int j = 0; j < messages[i].num_recipients; j++) {
            printf(" - %s (%s)\n", contacts[messages[i].recipients[j]].name,
                contacts[messages[i].recipients[j]].email);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("Mailing List Manager\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Add Message\n");
        printf("5. List Messages\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            list_contacts();
            break;
        case 3:
            search_contacts();
            break;
        case 4:
            add_message();
            break;
        case 5:
            list_messages();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}