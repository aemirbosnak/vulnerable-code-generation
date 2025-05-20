//FormAI DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold diary entries
typedef struct {
    char date[11];
    char time[6];
    char content[500];
} DiaryEntry;

// Function prototypes
void addEntry(DiaryEntry* diary);
void printEntry(DiaryEntry* diary, int i);
void printAllEntries(DiaryEntry* diary, int numEntries);
void saveEntries(DiaryEntry* diary, int numEntries);
void loadEntries(DiaryEntry* diary, int* numEntries);

int main() {
    DiaryEntry diary[1000];
    int numEntries = 0;
    char input;

    loadEntries(diary, &numEntries);

    // Main menu loop
    do {
        printf("Welcome to MyDigitalDiary!\n");
        printf("Please select an option:\n");
        printf("1. Add an entry\n");
        printf("2. View an entry\n");
        printf("3. View all entries\n");
        printf("4. Exit\n");
        scanf(" %c", &input);
        system("clear");

        switch (input) {
            case '1':
                addEntry(&diary[numEntries]);
                numEntries++;
                saveEntries(diary, numEntries);
                printf("Entry added successfully.\n\n");
                break;

            case '2':
                if (numEntries == 0) {
                    printf("No entries available.\n\n");
                    break;
                }
                printf("Enter entry number to view: ");
                int i;
                scanf("%d", &i);
                system("clear");
                printEntry(diary, i-1);
                printf("\n");
                break;

            case '3':
                if (numEntries == 0) {
                    printf("No entries available.\n\n");
                    break;
                }
                printAllEntries(diary, numEntries);
                printf("\n");
                break;

            case '4':
                printf("Exiting MyDigitalDiary..\n");
                break;

            default:
                printf("Invalid input. Please try again.\n\n");
        }

    } while (input != '4');

    return 0;
}

// Function to add a new diary entry
void addEntry(DiaryEntry* diary) {
    time_t t = time(NULL);
    struct tm* timeinfo = localtime(&t);

    // Format date and time
    strftime(diary->date, 11, "%d/%m/%Y", timeinfo);
    strftime(diary->time, 6, "%H:%M", timeinfo);

    // Read content from user input
    printf("Enter diary content: ");
    scanf(" %[^\n]s", diary->content);
}

// Function to print a single diary entry
void printEntry(DiaryEntry* diary, int i) {
    printf("Entry #%d\n", i+1);
    printf("Date: %s\n", diary[i].date);
    printf("Time: %s\n", diary[i].time);
    printf("Content: %s\n", diary[i].content);
}

// Function to print all diary entries
void printAllEntries(DiaryEntry* diary, int numEntries) {
    for (int i=0; i<numEntries; i++) {
        printEntry(diary, i);
        printf("\n");
    }
}

// Function to save diary entries to text file
void saveEntries(DiaryEntry* diary, int numEntries) {
    FILE* fp = fopen("diary.txt", "w");

    if (fp == NULL) {
        printf("Error saving diary entries.\n");
        exit(1);
    }

    for (int i=0; i<numEntries; i++) {
        fprintf(fp, "%s|%s|%s\n", diary[i].date,
                                    diary[i].time,
                                    diary[i].content);
    }

    fclose(fp);
}

// Function to load diary entries from text file
void loadEntries(DiaryEntry* diary, int* numEntries) {
    FILE* fp = fopen("diary.txt", "r");

    if (fp == NULL) {
        printf("No diary entries found.\n");
        return;
    }

    // Read each line from text file and store in DiaryEntry struct
    while (!feof(fp)) {
        fscanf(fp, "%[^|]|%[^|]|%[^\n]\n", diary[*numEntries].date,
                                           diary[*numEntries].time,
                                           diary[*numEntries].content);
        (*numEntries)++;
    }

    fclose(fp);
}