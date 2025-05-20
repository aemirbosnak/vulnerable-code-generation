//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[11];
    char title[100];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;

int main() {
    // Load the diary from a file
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    while (fscanf(file, "%s %s %[^\n]", entries[num_entries].date, entries[num_entries].title, entries[num_entries].entry) != EOF) {
        num_entries++;
    }
    fclose(file);

    // Display the diary entries
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n\n", entries[i].date, entries[i].title, entries[i].entry);
    }

    // Add a new diary entry
    char date[11], title[100], entry[MAX_ENTRY_LENGTH];
    printf("Enter the date (yyyy-mm-dd): ");
    scanf("%s", date);
    printf("Enter the title: ");
    scanf(" %[^\n]%*c", title);
    printf("Enter the entry: ");
    scanf(" %[^\n]%*c", entry);
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].title, title);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;

    // Save the diary to a file
    file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s %s %s\n", entries[i].date, entries[i].title, entries[i].entry);
    }
    fclose(file);

    return 0;
}