//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct PhoneBook {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initPhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Alas! The phone book is full, like a heart too heavy to bear!\n");
        return;
    }
    
    printf("Oh dear, enter the name of your beloved (Contact): ");
    scanf(" %[^\n]", pb->contacts[pb->count].name);
    printf("And their sweet number (Phone): ");
    scanf(" %[^\n]", pb->contacts[pb->count].phone);
    
    pb->count++;
    printf("A new contact has been inscribed in the stars!\n");
}

void displayContacts(PhoneBook *pb) {
    if (pb->count == 0) {
        printf("The pages of this phone book are empty, like the hearts of star-crossed lovers!\n");
        return;
    }

    printf("Herein lies the list of contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Whose name dost thou seek? ");
    scanf(" %[^\n]", name);
    
    int found = 0;
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            printf("Ah, thine beloved is found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Oh woe! Such a name is but a whisper in the breeze.\n");
    }
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Which fair contact shall we banish from this earthly realm? ");
    scanf(" %[^\n]", name);
    
    int found = 0;
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            found = 1;
            printf("%s hath been laid to rest, their number forgotten.\n", pb->contacts[i].name);
            pb->contacts[i] = pb->contacts[pb->count - 1]; // Replace with last contact
            pb->count--;
            break;
        }
    }
    
    if (!found) {
        printf("Alas, the spirit of %s remains untouched! No such contact exists.\n", name);
    }
}

void showMenu() {
    printf("~~~~~~~ The Phone Book of Verona ~~~~~~~\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search for Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Choose thy fate (1-5): ");
}

int main() {
    PhoneBook pb;
    initPhoneBook(&pb);
    
    int choice;
    do {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                searchContact(&pb);
                break;
            case 4:
                deleteContact(&pb);
                break;
            case 5:
                printf("Farewell! Until we meet again in life's ballad.\n");
                break;
            default:
                printf("Thou hast chosen poorly, select again!\n");
        }
    } while (choice != 5);
    
    return 0;
}