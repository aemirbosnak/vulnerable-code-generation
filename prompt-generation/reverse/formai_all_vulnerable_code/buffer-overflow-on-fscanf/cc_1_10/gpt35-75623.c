//FormAI DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char title[100];
    char body[1000];
    char date[20];
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void print_menu();
void new_entry();
void view_entries();
void save_entries();
void load_entries();

int main() {
    printf("Welcome to the Digital Diary!\n");
    load_entries();
    print_menu();
    return 0;
}

void print_menu() {
    printf("\nMenu:\n");
    printf("1. New Entry\n");
    printf("2. View Entries\n");
    printf("3. Save Entries\n");
    printf("4. Exit\n");
    printf("Select an option: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            new_entry();
            break;
        case 2:
            view_entries();
            break;
        case 3:
            save_entries();
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            print_menu();
    }
}

void new_entry() {
    printf("\nNew Entry:\n");
    Entry new_entry;
    printf("Title: ");
    getchar();
    fgets(new_entry.title, sizeof(new_entry.title), stdin);
    printf("Body: ");
    fgets(new_entry.body, sizeof(new_entry.body), stdin);
    time_t current_time;
    time(&current_time);
    char* date = ctime(&current_time);
    strcpy(new_entry.date, date);
    entries[num_entries++] = new_entry;
    printf("Entry added!\n");
    print_menu();
}

void view_entries() {
    printf("\nEntries:\n");
    if (num_entries == 0) {
        printf("No entries to display.\n");
    } else {
        for (int i = 0; i < num_entries; i++) {
            printf("Title: %s\n", entries[i].title);
            printf("Body: %s", entries[i].body);
            printf("Date: %s", entries[i].date);
            printf("--------------------------------------------------\n");
        }
    }
    print_menu();
}

void save_entries() {
    FILE* file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error: could not open file.\n");
        print_menu();
    } else {
        for (int i = 0; i < num_entries; i++) {
            fprintf(file, "%s\n%s\n%s\n", entries[i].title, entries[i].body, entries[i].date);
        }
        fclose(file);
        printf("Entries saved to file \"diary.txt\".\n");
    }
    print_menu();
}

void load_entries() {
    FILE* file = fopen("diary.txt", "r");
    if (!file) {
        printf("No saved entries found.\n");
    } else {
        int i = 0;
        char title[100];
        char body[1000];
        char date[20];
        while (fscanf(file, "%[^\n]\n%[^\n]\n%[^\n]\n", title, body, date) == 3) {
            Entry entry;
            strcpy(entry.title, title);
            strcpy(entry.body, body);
            strcpy(entry.date, date);
            entries[i++] = entry;
        }
        num_entries = i;
        fclose(file);
        printf("Entries loaded from file \"diary.txt\".\n");
    }
}