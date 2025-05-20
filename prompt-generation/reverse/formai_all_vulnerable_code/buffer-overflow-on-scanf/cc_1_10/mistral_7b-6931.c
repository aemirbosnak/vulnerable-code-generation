//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone);
    num_contacts++;
}

void search_contact() {
    char name[NAME_LENGTH];
    printf("Enter name to search for: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found:\nName: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void delete_contact() {
    char name[NAME_LENGTH];
    int index = -1;
    printf("Enter name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }
    for (int i = index; i < num_contacts - 1; i++) {
        contacts[i] = contacts[i+1];
    }
    num_contacts--;
}

void display_phonebook() {
    printf("Phonebook:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
}

void main() {
    int choice;
    while (1) {
        printf("\nPhonebook menu:\n1. Add contact\n2. Search contact\n3. Delete contact\n4. Display phonebook\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_contact(); break;
            case 2: search_contact(); break;
            case 3: delete_contact(); break;
            case 4: display_phonebook(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}