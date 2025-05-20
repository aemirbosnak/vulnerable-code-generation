//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: mathematical
#define MAX_CONTACTS 100
#define CONTACT_SIZE 50

typedef struct {
    char name[CONTACT_SIZE];
    char phone[CONTACT_SIZE];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int numContacts = 0;

void addContact(const char *name, const char *phone) {
    if (numContacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(phoneBook[numContacts].name, name);
    strcpy(phoneBook[numContacts].phone, phone);
    numContacts++;
}

int searchContactByName(const char *name) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void printContacts() {
    for (int i = 0; i < numContacts; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", phoneBook[i].name);
        printf("Phone: %s\n", phoneBook[i].phone);
    }
}

void deleteContactByName(const char *name) {
    int index = searchContactByName(name);

    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int i = index; i < numContacts - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }

    numContacts--;
}

int main() {
    char command[10];
    char name[CONTACT_SIZE];
    char phone[CONTACT_SIZE];

    while (1) {
        printf("Enter command (add/print/search/delete/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        switch (command[0]) {
            case 'a':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                addContact(name, phone);
                break;

            case 'p':
                printContacts();
                break;

            case 's':
                printf("Enter name to search: ");
                scanf("%s", name);
                int index = searchContactByName(name);

                if (index != -1) {
                    printf("Contact found at index %d.\n", index + 1);
                } else {
                    printf("Contact not found.\n");
                }
                break;

            case 'd':
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContactByName(name);
                break;

            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}