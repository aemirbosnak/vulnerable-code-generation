//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} PhoneBook;

void initialize_phone_book(PhoneBook *pb) {
    pb->count = 0;
}

void add_entry(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->count < MAX_ENTRIES) {
        strncpy(pb->entries[pb->count].name, name, NAME_LENGTH);
        strncpy(pb->entries[pb->count].phone, phone, PHONE_LENGTH);
        pb->count++;
        printf("🧙‍♂️ New entry added: %s - %s\n", name, phone);
    } else {
        printf("📚 The spell book is full! Cannot add more entries.\n");
    }
}

void view_entries(const PhoneBook *pb) {
    printf("\n📖 Phone Book Entries:\n");
    if (pb->count == 0) {
        printf("🤷‍♂️ No entries found, the book is empty.\n");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        printf("🦄 %d. %s - %s\n", i + 1, pb->entries[i].name, pb->entries[i].phone);
    }
}

int find_entry(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strncmp(pb->entries[i].name, name, NAME_LENGTH) == 0) {
            return i;
        }
    }
    return -1;
}

void search_entry(const PhoneBook *pb, const char *name) {
    int index = find_entry(pb, name);
    if (index != -1) {
        printf("🔍 Found: %s - %s\n", pb->entries[index].name, pb->entries[index].phone);
    } else {
        printf("👻 No entry found for %s.\n", name);
    }
}

void delete_entry(PhoneBook *pb, int index) {
    if (index >= 0 && index < pb->count) {
        for (int i = index; i < pb->count - 1; i++) {
            pb->entries[i] = pb->entries[i + 1];
        }
        pb->count--;
        printf("🧚‍♀️ Entry deleted successfully.\n");
    } else {
        printf("⚠️ Invalid index! Cannot delete entry.\n");
    }
}

void magical_menu() {
    printf("\n🌌 Welcome to the Wizard's Phone Book! 🌌\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit Magic Realm\n");
}

int main() {
    PhoneBook pb;
    initialize_phone_book(&pb);
    int choice;
    char name[NAME_LENGTH], phone[PHONE_LENGTH];
    
    while (1) {
        magical_menu();
        printf("✨ Choose your spell: ");
        scanf("%d", &choice);
        getchar(); // to consume '\n' left in the input buffer

        switch (choice) {
            case 1:
                printf("🔮 Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("🕯️ Enter phone number: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0; // Remove newline
                add_entry(&pb, name, phone);
                break;

            case 2:
                view_entries(&pb);
                break;

            case 3:
                printf("🔍 Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                search_entry(&pb, name);
                break;

            case 4:
                view_entries(&pb);
                printf("🧙‍♂️ Enter entry number to delete: ");
                int index;
                scanf("%d", &index);
                delete_entry(&pb, index - 1);
                break;

            case 5:
                printf("🚪 Exiting the magic realm... Farewell!\n");
                exit(0);

            default:
                printf("❓ Unknown choice, try again!\n");
        }
    }
    return 0;
}