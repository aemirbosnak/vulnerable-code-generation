//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

// Function to display the menu
void display_menu() {
    printf("\n🎉 Welcome to Your Digital Diary! 🎉\n");
    printf("1. Add a Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete a Diary Entry\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

// Function to add a diary entry
void add_entry() {
    if (entry_count < MAX_ENTRIES) {
        printf("🖊️  Enter your diary entry (max %d characters): ", MAX_LENGTH - 1);
        getchar(); // Clear newline
        fgets(diary[entry_count].content, MAX_LENGTH, stdin);
        // Remove newline character from the end
        diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0;
        entry_count++;
        printf("🎉 Your entry has been saved! 🎉\n");
    } else {
        printf("😢 Oops! You have reached the maximum number of entries.\n");
    }
}

// Function to view diary entries
void view_entries() {
    if (entry_count == 0) {
        printf("📖 Your diary is empty! Start adding entries!\n");
    } else {
        printf("\n📜 Here are your diary entries:\n");
        for (int i = 0; i < entry_count; i++) {
            printf("%d. %s\n", i + 1, diary[i].content);
        }
    }
}

// Function to delete a diary entry
void delete_entry() {
    if (entry_count == 0) {
        printf("😢 Your diary is empty! Nothing to delete.\n");
        return;
    }
    int entry_number;
    printf("🔍 Enter the entry number to delete (1-%d): ", entry_count);
    scanf("%d", &entry_number);
    entry_number--; // Adjust for zero-indexing
    if (entry_number >= 0 && entry_number < entry_count) {
        for (int i = entry_number; i < entry_count - 1; i++) {
            diary[i] = diary[i + 1]; // Shift entries left
        }
        entry_count--;
        printf("🗑️ Entry %d has been deleted! 🗑️\n", entry_number + 1);
    } else {
        printf("❌ Invalid entry number! Please try again.\n");
    }
}

// Main function for the program
int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("💖 Thank you for using your Digital Diary! Goodbye! 💖\n");
                break;
            default:
                printf("❓ Invalid choice. Please select between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}