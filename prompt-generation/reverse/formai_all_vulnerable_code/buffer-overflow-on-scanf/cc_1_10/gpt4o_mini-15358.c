//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phoneNumber[15];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb, const char *name, const char *phoneNumber) {
    if (pb->count < MAX_CONTACTS) {
        strcpy(pb->contacts[pb->count].name, name);
        strcpy(pb->contacts[pb->count].phoneNumber, phoneNumber);
        pb->count++;
        printf("Alas! A new contact has been added: %s, %s\n", name, phoneNumber);
    } else {
        printf("O woe! The phone book is full, cannot add more contacts!\n");
    }
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("O! What light through yonder window breaks? The phone book is empty!\n");
    } else {
        printf("List of Contacts doth appear before thee:\n");
        for (int i = 0; i < pb->count; i++) {
            printf("%d. %s: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phoneNumber);
        }
    }
}

void searchContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Ah! I've found thee, sweet %s: %s\n", name, pb->contacts[i].phoneNumber);
            return;
        }
    }
    printf("O cruel fate! No such contact named %s exists!\n", name);
}

void removeContact(PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Alas! Taking leave of thee: %s was removed from the phone book.\n", name);
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            return;
        }
    }
    printf("O lament! There lies no contact as %s to be expelled!\n", name);
}

void freePhoneBook(PhoneBook *pb) {
    // In this simple implementation, there's no dynamically allocated memory to free,
    // but we include this function for good practice and future use.
    pb->count = 0;
    printf("The tangled web of contacts hath been unspun.\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);

    char command[20];
    char name[50];
    char phoneNumber[15];

    printf("Welcome to the Romeo and Juliet Phone Book!\n");

    while (1) {
        printf("\nWhat dost thou wish to do? (add, display, search, remove, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter the name of thy dear friend: ");
            scanf("%s", name);
            printf("Enter their noble number: ");
            scanf("%s", phoneNumber);
            addContact(&pb, name, phoneNumber);
        } else if (strcmp(command, "display") == 0) {
            displayContacts(&pb);
        } else if (strcmp(command, "search") == 0) {
            printf("Whom dost thou seek? Enter name: ");
            scanf("%s", name);
            searchContact(&pb, name);
        } else if (strcmp(command, "remove") == 0) {
            printf("What name shall be erased from our hearts? ");
            scanf("%s", name);
            removeContact(&pb, name);
        } else if (strcmp(command, "exit") == 0) {
            printf("Parting is such sweet sorrow, but we shall meet again!\n");
            break;
        } else {
            printf("I prithee, enter a valid command!\n");
        }
    }

    freePhoneBook(&pb);
    return 0;
}