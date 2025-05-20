//FormAI DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char title[50];
    char content[500];
    char date[20];
    char time[20];
} Entry;

int entryCount = 0;
Entry diary[MAX_ENTRIES];

void addEntry(char* title, char* content) {
    time_t timestamp;
    struct tm* localTime;

    // Get current date and time
    timestamp = time(NULL);
    localTime = localtime(&timestamp);

    // Set entry properties
    snprintf(diary[entryCount].date, sizeof(diary[entryCount].date), "%d/%d/%d", 
        localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
    snprintf(diary[entryCount].time, sizeof(diary[entryCount].time), "%d:%d:%d", 
        localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    snprintf(diary[entryCount].title, sizeof(diary[entryCount].title), "%s", title);
    snprintf(diary[entryCount].content, sizeof(diary[entryCount].content), "%s", content);
    entryCount++;

    printf("\nEntry added successfully!\n\n");
}

void deleteEntry(int index) {
    if (index < 1 || index > entryCount) {
        printf("\nInvalid entry index. Please enter a value between 1 and %d.\n\n", entryCount);
        return;
    }

    // Shift entries to fill gap
    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;

    printf("\nEntry deleted successfully!\n\n");
}

void searchEntries(char* query) {
    int results[MAX_ENTRIES];
    int count = 0;

    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].title, query) != NULL ||
            strstr(diary[i].content, query) != NULL) {
            results[count] = i;
            count++;
        }
    }

    if (count == 0) {
        printf("\nNo results found.\n\n");
        return;
    }

    // Print search results
    printf("\nSearch results:\n");
    for (int i = 0; i < count; i++) {
        printf("\n%d: %s (%s)", results[i] + 1, diary[results[i]].title, diary[results[i]].date);
    }
    printf("\n\n");
}

void listEntries() {
    printf("\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s (%s)\n", i + 1, diary[i].title, diary[i].date);
    }
    if (entryCount == 0) {
        printf("No entries found.\n");
    }
    printf("\n");
}

void saveDiary() {
    FILE* file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("\nFailed to save diary.\n\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n%s\n%s\n", diary[i].date, diary[i].time, diary[i].title, diary[i].content);
    }
    fclose(file);

    printf("\nDiary saved successfully!\n\n");
}

void loadDiary() {
    FILE* file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("\nFailed to load diary.\n\n");
        return;
    }

    char date[20], time[20], title[50], content[500];
    while (fscanf(file, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", date, time, title, content) != EOF) {
        snprintf(diary[entryCount].date, sizeof(diary[entryCount].date), "%s", date);
        snprintf(diary[entryCount].time, sizeof(diary[entryCount].time), "%s", time);
        snprintf(diary[entryCount].title, sizeof(diary[entryCount].title), "%s", title);
        snprintf(diary[entryCount].content, sizeof(diary[entryCount].content), "%s", content);
        entryCount++;
    }
    fclose(file);

    printf("\nDiary loaded successfully!\n\n");
}

int main() {
    int choice = -1;

    // Load diary from file
    loadDiary();

    // Display menu and allow user to perform actions
    while (choice != 0) {
        printf("Digital Diary\n");
        printf("=============\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entries\n");
        printf("4. List all entries\n");
        printf("5. Save diary\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
        case 1:
            printf("\nEnter title: ");
            char title[50];
            fgets(title, sizeof(title), stdin);

            printf("\nEnter content: ");
            char content[500];
            fgets(content, sizeof(content), stdin);

            addEntry(title, content);
            break;
        case 2:
            printf("\nEnter index of entry to delete: ");
            int index;
            scanf("%d", &index);
            deleteEntry(index);
            break;
        case 3:
            printf("\nEnter search query: ");
            char query[50];
            fgets(query, sizeof(query), stdin);
            searchEntries(query);
            break;
        case 4:
            listEntries();
            break;
        case 5:
            saveDiary();
            break;
        case 0:
            printf("\nGoodbye!\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n\n");
        }
    }

    return 0;
}