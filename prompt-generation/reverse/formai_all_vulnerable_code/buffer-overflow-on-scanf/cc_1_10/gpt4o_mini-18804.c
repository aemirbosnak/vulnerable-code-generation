//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void save_entry(const char *date, const char *entry) {
    if (entry_count < MAX_ENTRIES) {
        strcpy(diary[entry_count].date, date);
        strcpy(diary[entry_count].entry, entry);
        entry_count++;
    } else {
        printf("Diary full! Cannot save more entries.\n");
    }
}

void display_entries() {
    if (entry_count == 0) {
        printf("Your diary is empty, brave survivor.\n");
    } else {
        for (int i = 0; i < entry_count; i++) {
            printf("Entry %d [%s]: %s\n", i + 1, diary[i].date, diary[i].entry);
        }
    }
}

void create_entry() {
    char entry[MAX_LENGTH];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // Format the date as YYYY-MM-DD
    strftime(diary[entry_count].date, sizeof(diary[entry_count].date), "%Y-%m-%d", t);
    
    printf("Write your entry (max %d characters): ", MAX_LENGTH);
    getchar(); // Clear the newline character from previous input
    fgets(entry, sizeof(entry), stdin);
    
    // Remove newline character from entry
    entry[strcspn(entry, "\n")] = 0;

    save_entry(diary[entry_count].date, entry);
    printf("Your thoughts are now preserved in this barren world.\n");
}

void delete_entry() {
    int index;
    printf("Enter the entry number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > entry_count) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries left
    }
    
    entry_count--;
    printf("The entry has been erased from existence.\n");
}

void show_menu() {
    printf("\n======= Survivor's Digital Diary =======\n");
    printf("1. Create Entry\n");
    printf("2. Display All Entries\n");
    printf("3. Delete an Entry\n");
    printf("4. Exit\n");
    printf("=========================================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        show_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Preserving memories of this desolate world...\n");
                exit(0);
                break;
            default:
                printf("That choice does not exist in this new reality.\n");
        }
    }
    
    return 0;
}