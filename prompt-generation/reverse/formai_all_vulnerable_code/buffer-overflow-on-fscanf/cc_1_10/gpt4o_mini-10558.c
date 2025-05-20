//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void saveEntries();
void loadEntries();
void displayMenu();

int main() {
    loadEntries();
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice;
    do {
        printf("\n🎉 Welcome to your Digital Diary! 🎉\n");
        printf("1. Add a new entry\n");
        printf("2. View all entries\n");
        printf("3. Save entries to file\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character left in the buffer.

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                saveEntries();
                break;
            case 4:
                printf("✨ Thank you for using the Digital Diary! Have a fantastic day! ✨\n");
                break;
            default:
                printf("🚨 Invalid choice! Please select a valid option. 🚨\n");
        }
    } while (choice != 4);
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("🛑 Diary is full! Can't add more entries.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[entryCount].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("📅 Today's date: %s\n", diary[entryCount].date);
    printf("📝 Write your diary entry (max %d characters): ", MAX_LENGTH - 1);
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    
    // Remove newline from entry if it exists
    size_t len = strlen(diary[entryCount].entry);
    if (len > 0 && diary[entryCount].entry[len - 1] == '\n') {
        diary[entryCount].entry[len - 1] = '\0';
    }

    entryCount++;
    printf("🎉 Your entry has been saved! 🎉\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("🌟 Your diary is empty! Consider writing your thoughts down. 🌟\n");
        return;
    }

    printf("\n📖 Here are your diary entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
        printf("--------------------------\n");
    }
}

void saveEntries() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("🛑 Error opening file to save entries! 🛑\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Date: %s\nEntry: %s\n", diary[i].date, diary[i].entry);
        fprintf(file, "--------------------------\n");
    }

    fclose(file);
    printf("📂 Your entries have been saved to diary.txt successfully! 📂\n");
}

void loadEntries() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("🌼 No previous entries found. Start writing your feelings! 🌼\n");
        return;
    }

    while (fscanf(file, "Date: %10s\nEntry: %[^\n]\n", diary[entryCount].date, diary[entryCount].entry) != EOF) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            printf("🤫 Reached maximum number of entries while loading! Some entries may not be saved.\n");
            break;
        }
        fscanf(file, "--------------------------\n");  // Skip separator
    }

    fclose(file);
    printf("📚 Previous entries loaded successfully! 📚\n");
}