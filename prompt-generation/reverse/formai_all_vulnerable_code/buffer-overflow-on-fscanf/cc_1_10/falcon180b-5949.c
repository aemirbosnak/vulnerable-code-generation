//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct Entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE* diaryFile;
    struct Entry entries[MAX_ENTRIES];
    int numEntries = 0;
    char filename[50] = "diary.txt";
    time_t currentTime;

    diaryFile = fopen(filename, "r");
    if (diaryFile == NULL) {
        printf("No diary file found.\n");
        exit(1);
    }

    while (numEntries < MAX_ENTRIES && fscanf(diaryFile, "%ld %[^\n]", &entries[numEntries].timestamp, entries[numEntries].text) == 2) {
        numEntries++;
    }

    fclose(diaryFile);

    currentTime = time(NULL);

    if (numEntries == MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        exit(1);
    }

    printf("Welcome to your digital diary.\n");
    printf("Current date and time: %s", ctime(&currentTime));

    while (1) {
        printf("\n");
        printf("1. Add new entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &currentTime);

        switch (currentTime) {
        case 1:
            printf("Enter your new entry (max %d characters): ", MAX_ENTRY_LENGTH-1);
            fgets(entries[numEntries].text, MAX_ENTRY_LENGTH, stdin);
            entries[numEntries].timestamp = time(NULL);
            numEntries++;
            printf("Entry added.\n");
            break;

        case 2:
            printf("Your entries:\n");
            for (int i = 0; i < numEntries; i++) {
                printf("%ld - %s\n", entries[i].timestamp, entries[i].text);
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}