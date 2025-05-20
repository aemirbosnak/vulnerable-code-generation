//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store a digital diary entry
struct DigitalDiaryEntry {
    int day;
    int month;
    int year;
    char title[50];
    char content[500];
};

// Function to add an entry to the digital diary
void addEntry(struct DigitalDiaryEntry* diary, int* nEntries) {
    printf("Enter the day: ");
    scanf("%d", &(diary[*nEntries].day));
    printf("Enter the month: ");
    scanf("%d", &(diary[*nEntries].month));
    printf("Enter the year: ");
    scanf("%d", &(diary[*nEntries].year));
    printf("Enter the title: ");
    scanf("%s", diary[*nEntries].title);
    printf("Enter the content: ");
    /*
     * We use a combination of fgets and sscanf to allow multi-line input.
     * Without this, scanf would only read the first word of the content.
     */
    getchar();  // Remove the newline character left behind by scanf
    fgets(diary[*nEntries].content, 500, stdin);
    sscanf(diary[*nEntries].content, "%[^\n]s", diary[*nEntries].content);
    (*nEntries)++;
    printf("Entry added successfully!\n");
}

// Function to display all entries in the digital diary
void displayEntries(struct DigitalDiaryEntry* diary, int nEntries) {
    if (nEntries == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("All entries:\n");
    for (int i = 0; i < nEntries; i++) {
        printf("%d/%d/%d - %s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].title);
        printf("%s\n", diary[i].content);
        printf("--------------------------------\n");
    }
}

// Function to search for entries by title
void searchByTitle(struct DigitalDiaryEntry* diary, int nEntries) {
    if (nEntries == 0) {
        printf("No entries found.\n");
        return;
    }
    char searchTerm[50];
    printf("Enter the title to search for: ");
    scanf("%s", searchTerm);
    int numMatches = 0;
    printf("Search results:\n");
    for (int i = 0; i < nEntries; i++) {
        if (strcmp(searchTerm, diary[i].title) == 0) {
            printf("%d/%d/%d - %s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].title);
            printf("%s\n", diary[i].content);
            printf("--------------------------------\n");
            numMatches++;
        }
    }
    if (numMatches == 0) {
        printf("No entries found with that title.\n");
    }
}

int main() {
    struct DigitalDiaryEntry diary[100]; // Assume max of 100 entries
    int nEntries = 0;
    while (1) {
        int choice;
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. Display all entries\n");
        printf("3. Search by title\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry(diary, &nEntries);
                break;
            case 2:
                displayEntries(diary, nEntries);
                break;
            case 3:
                searchByTitle(diary, nEntries);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}