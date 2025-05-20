//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // YYYY-MM-DD
    char mood[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

void log_entry(DiaryEntry *diary, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Diary is full! Could not add more entries.\n");
        return;
    }

    printf("Enter today's mood (e.g., Happy, Sad, Excited): ");
    scanf(" %[^\n]", diary[*count].mood);

    printf("Write your diary entry:\n");
    printf(" (Max %d characters)\n", MAX_LENGTH);
    printf(" > ");
    scanf(" %[^\n]", diary[*count].entry);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(diary[*count].date, sizeof(diary[*count].date), "%04d-%02d-%02d", 
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    (*count)++;
    printf("Diary entry added successfully!\n");
}

void view_entries(DiaryEntry *diary, int count) {
    if (count == 0) {
        printf("No diary entries found.\n");
        return;
    }
    
    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Mood: %s\n", diary[i].mood);
        printf("Entry: %s\n", diary[i].entry);
        printf("----------------------------\n");
    }
}

void save_to_file(DiaryEntry *diary, int count) {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Date: %s\n", diary[i].date);
        fprintf(file, "Mood: %s\n", diary[i].mood);
        fprintf(file, "Entry: %s\n\n", diary[i].entry);
    }

    fclose(file);
    printf("Diary entries saved to diary.txt!\n");
}

void menu() {
    printf("--- Digital Diary ---\n");
    printf("1. Log new entry\n");
    printf("2. View all entries\n");
    printf("3. Save to file\n");
    printf("4. Exit\n");
    printf("---------------------\n");
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int count = 0;
    int choice;

    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                log_entry(diary, &count);
                break;
            case 2:
                view_entries(diary, count);
                break;
            case 3:
                save_to_file(diary, count);
                break;
            case 4:
                printf("Exiting the diary. Have a great day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 4);

    return 0;
}