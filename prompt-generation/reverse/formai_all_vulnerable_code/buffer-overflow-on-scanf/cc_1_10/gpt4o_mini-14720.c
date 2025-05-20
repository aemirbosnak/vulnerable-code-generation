//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 256
#define DIARY_FILE "happy_diary.txt"

void add_entry();
void view_entries();

int main() {
    int choice;

    printf("🎉 Welcome to Your Happy Diary! 🎉\n");
    printf("What would you like to do?\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Exit\n");
    
    while (1) {
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf
        
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("✨ Thank you for using Happy Diary! Have a great day! ✨\n");
                exit(0);
            default:
                printf("🚫 Invalid choice! Please try again. 🚫\n");
        }
    }

    return 0;
}

void add_entry() {
    FILE *file;
    char entry[MAX_ENTRY];
    
    printf("📖 Write your entry (max %d characters):\n", MAX_ENTRY - 1);
    fgets(entry, MAX_ENTRY, stdin);
    
    file = fopen(DIARY_FILE, "a");
    if (file == NULL) {
        printf("❌ Error opening file for writing! Please try again. ❌\n");
        return;
    }

    fprintf(file, "%s", entry);
    fclose(file);
    
    printf("🎊 Your entry has been saved! 🎊\n");
}

void view_entries() {
    FILE *file;
    char entry[MAX_ENTRY];

    file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("📄 No entries found! Start by adding a new entry! 📄\n");
        return;
    }

    printf("📜 Here are your diary entries:\n");
    while (fgets(entry, MAX_ENTRY, file) != NULL) {
        printf("- %s", entry);
    }

    fclose(file);
    printf("🌟 End of entries! 🌟\n");
}