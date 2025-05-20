//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

// Structure to hold phone book entry
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} PhoneBookEntry;

// PhoneBook structure to contain multiple entries
typedef struct {
    PhoneBookEntry entries[MAX_ENTRIES];
    int count;
} PhoneBook;

// Function declarations (the magic incantations)
void addEntry(PhoneBook *pb);
void displayEntries(const PhoneBook *pb);
void findEntry(const PhoneBook *pb);
void deleteEntry(PhoneBook *pb);
void saveToFile(const PhoneBook *pb);
void loadFromFile(PhoneBook *pb);
void clearScreen();

// The main function (the point of origin)
int main() {
    PhoneBook pb = { .count = 0 };
    loadFromFile(&pb); // Raise the spirits from the file
    int choice;
    
    while (1) {
        clearScreen();
        printf("=== Welcome to the Enchanted Phone Book ===\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Save & Exit\n");
        printf("Choose your next spell (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Only digits, brave user!\n");
            while (getchar() != '\n'); // Clear the buffer
            continue;
        }

        switch (choice) {
            case 1: 
                addEntry(&pb); 
                break;
            case 2: 
                displayEntries(&pb); 
                break;
            case 3: 
                findEntry(&pb); 
                break;
            case 4: 
                deleteEntry(&pb); 
                break;
            case 5: 
                saveToFile(&pb); 
                printf("Saving... until we meet again!\n");
                exit(0);
            default: 
                printf("Invalid choice, try again!\n");
        }
        printf("Press Enter to continue... ");
        while (getchar() != '\n'); // Clear the buffer
        getchar(); // Wait for user input
    }
    return 0;
}

// Add new entries (the summon)
void addEntry(PhoneBook *pb) {
    if (pb->count >= MAX_ENTRIES) {
        printf("The enchanted phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", pb->entries[pb->count].name);
    printf("Enter phone number: ");
    scanf("%s", pb->entries[pb->count].phone);
    pb->count++;
    printf("Entry added!\n");
}

// Display all entries (the reveal)
void displayEntries(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No entries found in the mystic tome!\n");
        return;
    }
    printf("=== Phone Book Entries ===\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d: %s - %s\n", i + 1, pb->entries[i].name, pb->entries[i].phone);
    }
}

// Find an entry by name (the search)
void findEntry(const PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            printf("Found: %s - %s\n", pb->entries[i].name, pb->entries[i].phone);
            return; // Exit puzzle if found
        }
    }
    printf("No entry found for %s.\n", name);
}

// Delete an entry (the vanishing act)
void deleteEntry(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            pb->entries[i] = pb->entries[pb->count - 1]; // Shift the last entry
            pb->count--;
            printf("Entry deleted!\n");
            return; // Exit puzzle if deleted
        }
    }
    printf("No entry found for %s.\n", name);
}

// Save phone book to file (the binding incantation)
void saveToFile(const PhoneBook *pb) {
    FILE *file = fopen("phonebook.dat", "wb");
    fwrite(pb, sizeof(PhoneBook), 1, file);
    fclose(file);
}

// Load phone book from file (drawing from the abyss)
void loadFromFile(PhoneBook *pb) {
    FILE *file = fopen("phonebook.dat", "rb");
    if (file) {
        fread(pb, sizeof(PhoneBook), 1, file);
        fclose(file);
    }
}

// Clear the screen (the cleansing ritual)
void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}