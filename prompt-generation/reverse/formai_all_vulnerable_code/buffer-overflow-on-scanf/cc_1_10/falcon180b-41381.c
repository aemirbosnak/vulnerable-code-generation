//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold diary entry
typedef struct {
    char date[10];
    char mood[20];
    char entry[1000];
} DiaryEntry;

// Function to add a new entry
void addEntry(DiaryEntry* diary) {
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary->date);

    printf("Enter your mood: ");
    scanf("%s", diary->mood);

    printf("Enter your thoughts:\n");
    fgets(diary->entry, 1000, stdin);
    diary->entry[strcspn(diary->entry, "\n")] = '\0'; // Remove newline character
}

// Function to display all entries
void displayEntries(DiaryEntry* diary, int numEntries) {
    printf("\nDiary entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Mood: %s\n", diary[i].mood);
        printf("Entry:\n%s\n\n", diary[i].entry);
    }
}

// Function to search for a specific entry
void searchEntry(DiaryEntry* diary, int numEntries, char* keyword) {
    printf("\nSearch results:\n");
    for (int i = 0; i < numEntries; i++) {
        if (strstr(diary[i].entry, keyword)) {
            printf("Date: %s\n", diary[i].date);
            printf("Mood: %s\n", diary[i].mood);
            printf("Entry:\n%s\n\n", diary[i].entry);
        }
    }
}

int main() {
    // Initialize diary with 10 entries
    DiaryEntry diary[10];
    int numEntries = 0;

    // Add new entries
    while (numEntries < 10) {
        addEntry(&diary[numEntries]);
        numEntries++;
    }

    // Display all entries
    displayEntries(diary, numEntries);

    // Search for a specific entry
    char keyword[20];
    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);
    searchEntry(diary, numEntries, keyword);

    return 0;
}