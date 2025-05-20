//FormAI DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE 100

// Function declarations
void menu();
void add_entry();
void view_entries();
void search_entries();
void update_entry();
void delete_entry();
void encrypt_decrypt(char[], int);
void save_entries();
void load_entries();

// Struct for date
struct Date {
    int day;
    int month;
    int year;
};

// Struct for diary entry
struct Entry {
    int id;
    char title[MAX_LINE];
    char content[MAX_LINE];
    struct Date date;
    char encrypted_content[MAX_LINE];
};

// Global variables
struct Entry entries[MAX_LINE];
int num_entries = 0;
char password[MAX_LINE];

// Main method
int main() {
    int choice;
    printf("Welcome to your Digital Diary!\n");
    printf("Enter password: ");
    scanf("%s", password);
    encrypt_decrypt(password, 1); // Encrypt password for security
    load_entries(); // Load existing entries
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                update_entry();
                break;
            case 5:
                delete_entry();
                break;
            case 6:
                save_entries();
                exit(0); // Terminate program
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}

// Display menu
void menu() {
    printf("Menu:\n");
    printf("1. Add entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Update an entry\n");
    printf("5. Delete an entry\n");
    printf("6. Save and exit\n");
}

// Add new entry
void add_entry() {
    struct Entry entry;
    printf("Enter the title for your entry: ");
    scanf("%s", entry.title);
    printf("Enter the content for your entry: ");
    scanf("%s", entry.content);
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &entry.date.day, &entry.date.month, &entry.date.year);
    entry.id = num_entries + 1;
    encrypt_decrypt(entry.content, 1); // Encrypt content for security
    strcpy(entry.encrypted_content, entry.content);
    entries[num_entries] = entry;
    num_entries++;
    printf("Entry added successfully.\n");
}

// View all entries
void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("ID\tDATE\t\t\t\tTITLE\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d\t%d/%d/%d\t\t%s\n", entries[i].id, entries[i].date.day, entries[i].date.month, entries[i].date.year, entries[i].title);
    }
    printf("------------------------------------------------\n");
}

// Search for an entry
void search_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    char query[MAX_LINE];
    printf("Enter search query: ");
    scanf("%s", query);
    int found = 0;
    printf("ID\tDATE\t\t\t\tTITLE\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, query) != NULL || strstr(entries[i].content, query) != NULL) {
            printf("%d\t%d/%d/%d\t\t%s\n", entries[i].id, entries[i].date.day, entries[i].date.month, entries[i].date.year, entries[i].title);
            found = 1;
        }
    }
    printf("------------------------------------------------\n");
    if (!found) {
        printf("No entries found.\n");
    }
}

// Update an entry
void update_entry() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    int id;
    printf("Enter the ID of the entry you want to update: ");
    scanf("%d", &id);
    for (int i = 0; i < num_entries; i++) {
        if (entries[i].id == id) {
            printf("Enter the new title for your entry: ");
            scanf("%s", entries[i].title);
            printf("Enter the new content for your entry: ");
            scanf("%s", entries[i].content);
            encrypt_decrypt(entries[i].content, 1); // Encrypt content for security
            strcpy(entries[i].encrypted_content, entries[i].content);
            printf("Entry updated successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

// Delete an entry
void delete_entry() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    int id;
    printf("Enter the ID of the entry you want to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < num_entries; i++) {
        if (entries[i].id == id) {
            for (int j = i; j < num_entries - 1; j++) {
                entries[j] = entries[j + 1];
            }
            num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

// Encrypt or decrypt a string using a simple cipher
void encrypt_decrypt(char str[], int key) {
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = ((str[i] - 'A' + key) % 26) + 'A';
            } else {
                str[i] = ((str[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
}

// Save entries to file
void save_entries() {
    FILE *file = fopen("diary.dat", "wb");
    if (!file) {
        printf("Error: Could not open file.\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        encrypt_decrypt(entries[i].encrypted_content, -1); // Decrypt content for saving to file
        fwrite(&entries[i], sizeof(struct Entry), 1, file);
        encrypt_decrypt(entries[i].encrypted_content, 1); // Encrypt content again for security
    }
    fclose(file);
}

// Load existing entries from file
void load_entries() {
    FILE *file = fopen("diary.dat", "rb");
    if (!file) {
        return;
    }
    struct Entry entry;
    while (fread(&entry, sizeof(struct Entry), 1, file)) {
        encrypt_decrypt(entry.encrypted_content, -1); // Decrypt content for loading from file
        entries[num_entries] = entry;
        num_entries++;
        encrypt_decrypt(entry.encrypted_content, 1); // Encrypt content again for security
    }
    fclose(file);
}