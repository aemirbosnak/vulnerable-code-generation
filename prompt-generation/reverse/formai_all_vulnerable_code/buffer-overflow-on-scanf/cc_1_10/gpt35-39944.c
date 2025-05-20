//FormAI DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
/* 
Digital Diary in C using Data Structures and Time Functions 
by Claude Shannon

Instructions for use:
1. Run the program and enter the password to access the diary.
2. View, add or delete entries with the respective options.
3. The diary is automatically saved before the program exits.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 100
#define PASSWORD "myDigitalDiary"

typedef struct {
    char date[12];
    char time[9];
    char content[MAX_LENGTH];
} Entry;

void saveEntry(Entry *entries, int count);
void loadEntries(Entry *entries, int *count);
void viewEntries(Entry *entries, int count);
void addEntry(Entry *entries, int *count);
void deleteEntry(Entry *entries, int *count);

int main() {
    char password[MAX_LENGTH];
    printf("Enter password to access digital diary: ");
    scanf("%s", &password);
    if (strcmp(password, PASSWORD) != 0) {
        printf("Password incorrect. Exiting program.\n");
        return 0;
    }

    Entry entries[MAX_ENTRIES];
    int count = 0;
    loadEntries(entries, &count);

    while (1) {
        int choice;
        printf("\n1. View diary entries\n");
        printf("2. Add a new diary entry\n");
        printf("3. Delete a diary entry\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                viewEntries(entries, count);
                break;
            case 2:
                addEntry(entries, &count);
                break;
            case 3:
                deleteEntry(entries, &count);
                break;
            case 4:
                saveEntry(entries, count);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void saveEntry(Entry *entries, int count) {
    FILE *fp;
    fp = fopen("diary.txt", "w");

    if (fp == NULL) {
        printf("Error opening file. Diary was not saved.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%s,%s\n", entries[i].date, entries[i].time, entries[i].content);
    }

    printf("Diary saved successfully.\n");

    fclose(fp);
}

void loadEntries(Entry *entries, int *count) {
    FILE *fp;
    fp = fopen("diary.txt", "r");

    if (fp == NULL) {
        printf("File does not exist. Creating new diary.\n");
        return;
    }

    int i = 0;
    char buffer[MAX_LENGTH];

    while (fgets(buffer, MAX_LENGTH, fp)) {
        sscanf(buffer, "%[^,],%[^,],%[^\n]", entries[i].date, entries[i].time, entries[i].content);
        i++;
    }

    *count = i;

    printf("Diary loaded successfully.\n");

    fclose(fp);
}

void viewEntries(Entry *entries, int count) {
    if (count == 0) {
        printf("There are no diary entries to view.\n");
        return;
    }

    printf("Showing %d diary entries:\n", count);

    for (int i = 0; i < count; i++) {
        printf("--------------------\n");
        printf("Date: %s\n", entries[i].date);
        printf("Time: %s\n", entries[i].time);
        printf("Content: %s\n", entries[i].content);
    }
}

void addEntry(Entry *entries, int *count) {
    if (*count == MAX_ENTRIES) {
        printf("The diary is full. Delete entries to make room for new ones.\n");
        return;
    }

    time_t currTime = time(NULL);
    struct tm *tm = localtime(&currTime);

    printf("Enter your diary entry (max %d characters): ", MAX_LENGTH);
    char entryText[MAX_LENGTH];
    scanf("%s", entryText);

    strcpy(entries[*count].date, asctime(tm));
    entries[*count].date[strlen(entries[*count].date) - 1] = '\0';
    strcpy(entries[*count].time, asctime(tm) + 11);
    entries[*count].time[strlen(entries[*count].time) - 1] = '\0';
    strcpy(entries[*count].content, entryText);

    *count = *count + 1;

    printf("Diary entry added successfully at %s %s.\n", entries[*count - 1].date, entries[*count - 1].time);
}

void deleteEntry(Entry *entries, int *count) {
    if (*count == 0) {
        printf("There are no diary entries to delete.\n");
        return;
    }

    printf("Which entry number would you like to delete? ");
    int entryNum;
    scanf("%d", &entryNum);

    if (entryNum < 1 || entryNum > *count) {
        printf("Invalid entry number. Please try again.\n");
        return;
    }

    printf("Deleting the following diary entry:\n");
    printf("--------------------\n");
    printf("Date: %s\n", entries[entryNum - 1].date);
    printf("Time: %s\n", entries[entryNum - 1].time);
    printf("Content: %s\n", entries[entryNum - 1].content);

    for (int i = entryNum - 1; i < *count - 1; i++) {
        strcpy(entries[i].date, entries[i+1].date);
        strcpy(entries[i].time, entries[i+1].time);
        strcpy(entries[i].content, entries[i+1].content);
    }

    *count = *count - 1;

    printf("Diary entry deleted successfully.\n");
}