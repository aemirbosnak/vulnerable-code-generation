//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIARY_LINES 100
#define MAX_LINE_LENGTH 255

typedef struct DiaryEntry {
    char date[11];
    char description[MAX_LINE_LENGTH];
} DiaryEntry;

void get_current_date(char date[]);
void save_entry(DiaryEntry entries[], const char description[], int *current_entry);
void load_entries(DiaryEntry entries[], int *current_entry);
void print_menu();
void print_entry(const DiaryEntry entry);

int main() {
    DiaryEntry diary[MAX_DIARY_LINES];
    int current_entry = 0;

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                get_current_date(diary[current_entry].date);
                printf("Enter your diary entry: ");
                fgets(diary[current_entry].description, MAX_LINE_LENGTH, stdin);
                save_entry(diary, diary[current_entry].description, &current_entry);
                break;
            case 2:
                if (current_entry == 0) {
                    printf("No diary entries yet.\n");
                    break;
                }
                load_entries(diary, &current_entry);
                print_entry(diary[current_entry - 1]);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void get_current_date(char date[]) {
    time_t now;
    struct tm* local_time;

    now = time(NULL);
    local_time = localtime(&now);

    strftime(date, sizeof(date), "%Y-%m-%d", local_time);
}

void save_entry(DiaryEntry entries[], const char description[], int *current_entry) {
    FILE *file;
    file = fopen("diary.dat", "ab");

    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    fwrite(&entries[*current_entry], sizeof(DiaryEntry), 1, file);
    fwrite(description, strlen(description) + 1, 1, file);

    fclose(file);

    (*current_entry)++;
}

void load_entries(DiaryEntry entries[], int *current_entry) {
    FILE *file;
    DiaryEntry entry;
    char description[MAX_LINE_LENGTH];

    file = fopen("diary.dat", "rb");

    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return;
    }

    while (fread(&entry, sizeof(DiaryEntry), 1, file)) {
        strcpy(description, "");
        fread(description, strlen(entry.description) + 1, 1, file);
        entry.description[strlen(entry.description)] = '\0';

        printf("%s - %s\n", entry.date, description);

        (*current_entry)++;
    }

    fclose(file);
}

void print_menu() {
    printf("\nDigital Diary Menu:\n");
    printf("1. Write a new entry\n");
    printf("2. View the last entry\n");
    printf("3. Exit\n");
}

void print_entry(const DiaryEntry entry) {
    printf("\nDate: %s\n", entry.date);
    printf("Description:\n%s\n", entry.description);
}