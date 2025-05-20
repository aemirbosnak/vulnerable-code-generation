//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    time_t timestamp;
    char entry[100];
} DiaryEntry;

void addEntry(DiaryEntry* diary, int size, char* entry) {
    if (size >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    strcpy(diary[size].entry, entry);
    diary[size].timestamp = time(NULL);
    size++;
}

void viewEntries(DiaryEntry* diary, int size) {
    printf("Diary Entries:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %s\n", ctime(&diary[i].timestamp), diary[i].entry);
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int size = 0;

    char choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter your entry: ");
                char entry[100];
                scanf("%[^\n]", entry);
                addEntry(diary, size, entry);
                break;
            case '2':
                viewEntries(diary, size);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '3');

    return 0;
}