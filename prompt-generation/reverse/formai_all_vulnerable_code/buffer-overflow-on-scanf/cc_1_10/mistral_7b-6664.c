//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 50

// Relaxed style structure definition for Digital Diary entry
typedef struct {
    char name[30];
    char mood[20];
    char thoughts[200];
    time_t timestamp;
} DiaryEntry;

// Function to generate unique ID for each entry
int generate_id() {
    static int id = 0;
    id++;
    return id;
}

int main() {
    DiaryEntry diary[DIARY_SIZE];
    int entry_count = 0;

    while (entry_count < DIARY_SIZE) {
        // Generate unique ID for the entry
        int id = generate_id();

        printf("\nEnter name for entry %d: ", id);
        scanf("%s", diary[entry_count].name);

        printf("\nEnter mood for %s: ", diary[entry_count].name);
        scanf("%s", diary[entry_count].mood);

        printf("\nEnter thoughts for %s: ", diary[entry_count].name);
        scanf("%[^\n]s", diary[entry_count].thoughts);

        diary[entry_count].timestamp = time(NULL);

        entry_count++;

        printf("\nDo you want to add another entry? (Y/N): ");
        char choice;
        scanf("%c", &choice);

        if (choice != 'Y') {
            break;
        }
    }

    printf("\nTotal number of entries added: %d", entry_count);

    // Printing all the entries in the diary
    printf("\nYour Digital Diary:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("\nEntry %d:\n", i+1);
        printf("Name: %s\n", diary[i].name);
        printf("Mood: %s\n", diary[i].mood);
        printf("Thoughts: %s\n", diary[i].thoughts);
        printf("Timestamp: %s", ctime(&(diary[i].timestamp)));
    }

    return 0;
}