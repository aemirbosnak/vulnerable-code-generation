//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_SIZE 50
#define PHONE_SIZE 20

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} PhoneEntry;

typedef struct {
    PhoneEntry entries[MAX_ENTRIES];
    int count;
} PhoneBook;

void addEntry(PhoneBook *book) {
    if (book->count >= MAX_ENTRIES) {
        printf("The enchanted phone book is full! No more entries can be added.\n");
        return;
    }
    
    printf("Enter the name of the magical creature: ");
    scanf("%s", book->entries[book->count].name);
    printf("Enter the enchanted phone number: ");
    scanf("%s", book->entries[book->count].phone);
    
    book->count++;
    printf("A new entry for %s has been added to the phone book!\n", book->entries[book->count - 1].name);
}

void searchEntry(PhoneBook *book) {
    char searchName[NAME_SIZE];
    printf("Whose phone number would you like to summon? ");
    scanf("%s", searchName);
    
    for (int i = 0; i < book->count; i++) {
        if (strcmp(book->entries[i].name, searchName) == 0) {
            printf("The magical phone number for %s is: %s\n", book->entries[i].name, book->entries[i].phone);
            return;
        }
    }
    
    printf("Alas! There is no entry for %s in the enchanted book.\n", searchName);
}

void deleteEntry(PhoneBook *book) {
    char deleteName[NAME_SIZE];
    printf("Whom shall we erase from the book of magic? ");
    scanf("%s", deleteName);
    
    for (int i = 0; i < book->count; i++) {
        if (strcmp(book->entries[i].name, deleteName) == 0) {
            for (int j = i; j < book->count - 1; j++) {
                book->entries[j] = book->entries[j + 1];
            }
            book->count--;
            printf("The entry for %s has been vanquished from the enchanted book.\n", deleteName);
            return;
        }
    }
    
    printf("The magical creature %s was not found in the book to vanish!\n", deleteName);
}

void displayEntries(PhoneBook *book) {
    if (book->count == 0) {
        printf("The enchanted phone book is empty. No magical creatures are recorded.\n");
        return;
    }
    
    printf("Behold the list of magical creatures and their phone numbers:\n");
    for (int i = 0; i < book->count; i++) {
        printf("%d. %s - %s\n", i + 1, book->entries[i].name, book->entries[i].phone);
    }
}

int main() {
    PhoneBook book;
    book.count = 0;
    int choice;
    
    do {
        printf("\nWelcome to the Enchanted Phone Book!\n");
        printf("1. Add Magical Creature\n");
        printf("2. Search for Magical Creature\n");
        printf("3. Delete Magical Creature\n");
        printf("4. Display All Magical Creatures\n");
        printf("5. Exit the Enchanted Realm\n");
        printf("Choose your desire (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(&book);
                break;
            case 2:
                searchEntry(&book);
                break;
            case 3:
                deleteEntry(&book);
                break;
            case 4:
                displayEntries(&book);
                break;
            case 5:
                printf("Farewell! May your adventures be magical!\n");
                break;
            default:
                printf("That is not a valid choice! The magic will guide you.\n");
        }
    } while (choice != 5);

    return 0;
}