//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 100

typedef struct {
    char title[50];
    char entry[200];
    time_t timestamp;
} DiaryEntry;

void saveEntry(DiaryEntry *entry) {
    FILE *file = fopen("diary.txt", "a");
    if (file == NULL) {
        printf("Oh dear, I can't open the diary!\n");
        return;
    }

    time_t now = time(NULL);
    entry->timestamp = now;

    int size = sizeof(DiaryEntry) - sizeof(entry->timestamp);
    fwrite(entry, size, 1, file);
    fwrite(&entry->timestamp, sizeof(time_t), 1, file);

    fclose(file);
    printf("Wow, I managed to save that!\n");
}

void loadEntry(int index) {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("What? The diary isn't here?\n");
        return;
    }

    DiaryEntry entry;
    fread(&entry, sizeof(DiaryEntry), 1, file);

    if (index != entry.timestamp) {
        printf("How strange, this isn't the entry I was looking for!\n");
        fclose(file);
        return;
    }

    printf("\nTitle: %s\n", entry.title);
    printf("Entry:\n%s\n", entry.entry);
    printf("Timestamp: %s", ctime(&entry.timestamp));

    fclose(file);
}

int main() {
    srand(time(NULL));

    DiaryEntry diary[DIARY_SIZE];

    int option;
    while (1) {
        printf("\nSurprised Digital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read an entry\n");
        printf("3. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Okay, let me write something down...\n");
                printf("Enter a title: ");
                scanf("%s", diary[rand() % DIARY_SIZE].title);
                printf("Enter your surprise: ");
                scanf("%s", diary[rand() % DIARY_SIZE].entry);
                saveEntry(&diary[rand() % DIARY_SIZE]);
                break;
            case 2:
                printf("Alright, let me see what I was surprised about before...\n");
                int index;
                printf("Enter the timestamp: ");
                scanf("%ld", &index);
                loadEntry(index);
                break;
            case 3:
                printf("Really? You're leaving already?\n");
                exit(0);
            default:
                printf("Hmm, that's not an option I recognize.\n");
        }
    }

    return 0;
}