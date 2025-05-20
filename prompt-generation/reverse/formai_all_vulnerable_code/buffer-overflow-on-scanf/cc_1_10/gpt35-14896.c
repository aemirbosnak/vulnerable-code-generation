//FormAI DATASET v1.0 Category: Mailing list manager ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} MailingList;

void display_menu();
void add_contact(MailingList* list);
void remove_contact(MailingList* list);
void display_contacts(MailingList* list);
void save_contacts(MailingList* list, const char* filename);
void load_contacts(MailingList* list, const char* filename);

int main() {
    MailingList list;
    list.count = 0;

    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(&list);
                break;
            case 2:
                remove_contact(&list);
                break;
            case 3:
                display_contacts(&list);
                break;
            case 4:
                save_contacts(&list, "contacts.txt");
                break;
            case 5:
                load_contacts(&list, "contacts.txt");
                break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (1);

    return 0;
}

void display_menu() {
    printf("\n1. Add contact\n");
    printf("2. Remove contact\n");
    printf("3. Display contacts\n");
    printf("4. Save contacts\n");
    printf("5. Load contacts\n");
    printf("6. Exit\n");
}

void add_contact(MailingList* list) {
    if (list->count == MAX_CONTACTS) {
        printf("Mailing list is full!\n");
        return;
    }

    Contact new_contact;

    printf("Enter name: ");
    scanf("%s", new_contact.name);

    printf("Enter email: ");
    scanf("%s", new_contact.email);

    list->contacts[list->count] = new_contact;

    printf("Contact added!\n");

    list->count++;
}

void remove_contact(MailingList* list) {
    if (list->count == 0) {
        printf("Mailing list is empty!\n");
        return;
    }

    char name[MAX_NAME_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    int i;
    int removed = 0;

    for (i = 0; i < list->count;) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            int j;

            for (j = i; j < list->count - 1; j++) {
                list->contacts[j] = list->contacts[j + 1];
            }

            list->count--;
            removed = 1;
        } else {
            i++;
        }
    }

    if (!removed) {
        printf("Contact not found!\n");
    } else {
        printf("Contact removed!\n");
    }
}

void display_contacts(MailingList* list) {
    if (list->count == 0) {
        printf("Mailing list is empty!\n");
        return;
    }

    int i;

    for (i = 0; i < list->count; i++) {
        printf("%-30s %-50s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

void save_contacts(MailingList* list, const char* filename) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    int i;

    for (i = 0; i < list->count; i++) {
        fprintf(file, "%s,%s\n", list->contacts[i].name, list->contacts[i].email);
    }

    fclose(file);

    printf("Contacts saved to %s!\n", filename);
}

void load_contacts(MailingList* list, const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];

    while (fgets(line, sizeof(line), file) != NULL) {
        char* name = strtok(line, ",");
        char* email = strtok(NULL, "\n");

        Contact new_contact;
        strcpy(new_contact.name, name);
        strcpy(new_contact.email, email);

        list->contacts[list->count] = new_contact;
        list->count++;
    }

    fclose(file);

    printf("Contacts loaded from %s!\n", filename);
}