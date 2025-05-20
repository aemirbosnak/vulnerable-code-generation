//FormAI DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    char content[101];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter today's date (DD/MM/YYYY): ");
    scanf("%s", diary[num_entries].date);

    printf("Enter your diary entry (100 characters or less): ");
    scanf(" %[^\n]s", diary[num_entries].content);

    num_entries++;
}

void view_entries() {
    printf("Date    Entry\n");
    printf("======================\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n", diary[i].date, diary[i].content);
    }
}

void save_entries() {
    FILE *fp = fopen("diary.txt", "w");

    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%s\n%s\n", diary[i].date, diary[i].content);
    }

    fclose(fp);

    printf("Diary entries saved to diary.txt.\n");
}

void load_entries() {
    FILE *fp = fopen("diary.txt", "r");

    if (fp == NULL) {
        printf("No existing diary entries found.\n");
        return;
    }

    int i = 0;
    while (fscanf(fp, "%s %[^\n]s", diary[i].date, diary[i].content) != EOF) {
        i++;
    }

    num_entries = i;
    fclose(fp);

    printf("Loaded %d diary entries from diary.txt.\n", num_entries);
}

int main() {
    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a diary entry\n");
        printf("2. View diary entries\n");
        printf("3. Save diary entries to file\n");
        printf("4. Load existing diary entries from file\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                save_entries();
                break;
            case 4:
                load_entries();
                break;
            case 5:
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}