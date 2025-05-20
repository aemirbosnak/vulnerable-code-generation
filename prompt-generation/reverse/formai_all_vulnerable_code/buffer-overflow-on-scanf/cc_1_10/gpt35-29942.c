//FormAI DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct DiaryEntry {
    char date[11];
    char subject[100];
    char content[1000];
};

void addEntry(struct DiaryEntry* diary, int* numEntries);
void viewEntries(struct DiaryEntry* diary, int numEntries);
void searchEntries(struct DiaryEntry* diary, int numEntries);
void saveEntries(struct DiaryEntry* diary, int numEntries);

int main() {

    int numEntries = 0;
    struct DiaryEntry diary[1000];

    printf("\n==================================================");
    printf("\n\tC Digital Diary");
    printf("\n==================================================");

    while (1) {
        printf("\n\nEnter 'a' to add an entry");
        printf("\nEnter 'v' to view all entries");
        printf("\nEnter 's' to search for an entry");
        printf("\nEnter 'q' to quit\n");

        char input;
        scanf(" %c", &input);

        switch (input) {
        case 'a':
            addEntry(diary, &numEntries);
            break;
        case 'v':
            viewEntries(diary, numEntries);
            break;
        case 's':
            searchEntries(diary, numEntries);
            break;
        case 'q':
            saveEntries(diary, numEntries);
            return 0;
        default:
            printf("\nInvalid input. Please try again.\n");
            break;
        }
    }

    return 0;
}

void addEntry(struct DiaryEntry* diary, int* numEntries) {
    printf("\n\nAdding a new entry...\n");

    printf("\nEnter the current date in dd/mm/yyyy format: ");
    scanf(" %[^\n]s", diary[*numEntries].date);

    printf("\nEnter a subject for this entry: ");
    scanf(" %[^\n]s", diary[*numEntries].subject);

    printf("\nEnter the content for this entry: ");
    scanf(" %[^\n]s", diary[*numEntries].content);

    (*numEntries)++;
}

void viewEntries(struct DiaryEntry* diary, int numEntries) {
    printf("\n\nViewing all entries...\n");

    if (numEntries == 0) {
        printf("\nNo entries found.\n");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        printf("\nEntry %d:", i+1);
        printf("\nDate: %s", diary[i].date);
        printf("\nSubject: %s", diary[i].subject);
        printf("\nContent: %s", diary[i].content);
        printf("\n");
    }
}

void searchEntries(struct DiaryEntry* diary, int numEntries) {
    printf("\n\nSearching for an entry...\n");

    if (numEntries == 0) {
        printf("\nNo entries found.\n");
        return;
    }

    char searchDate[11];
    printf("\nEnter the date you are searching for in dd/mm/yyyy format: ");
    scanf(" %[^\n]s", searchDate);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(searchDate, diary[i].date) == 0) {
            printf("\nEntry found:");
            printf("\nDate: %s", diary[i].date);
            printf("\nSubject: %s", diary[i].subject);
            printf("\nContent: %s", diary[i].content);
            printf("\n");
            return;
        }
    }

    printf("\nNo entry matching that date found.\n");
}

void saveEntries(struct DiaryEntry* diary, int numEntries) {
    printf("\n\nSaving all entries...\n");

    FILE* file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("\nUnable to create file. Entries not saved.\n");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%s\n", diary[i].date);
        fprintf(file, "%s\n", diary[i].subject);
        fprintf(file, "%s\n", diary[i].content);
        fprintf(file, "\n");
    }

    fclose(file);

    printf("\nEntries saved successfully.\n");
}