//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE 256

struct DiaryEntry {
    time_t timestamp;
    char content[ENTRY_SIZE];
};

void saveEntry(struct DiaryEntry entries[], int *currentEntry) {
    time_t rawtime;
    struct tm *timeinfo;
    char filename[32];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(filename, sizeof(filename), "%Y-%m-%d-%H-%M-%S.txt", timeinfo);

    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%s\n", asctime(timeinfo));
        fprintf(file, "%s\n", entries[*currentEntry].content);
        fclose(file);

        printf("Entry saved to %s\n", filename);
        (*currentEntry)++;
    } else {
        perror("Error opening file");
    }
}

int main() {
    int currentEntry = 0;
    struct DiaryEntry entries[MAX_ENTRIES];

    while (currentEntry < MAX_ENTRIES) {
        printf("Enter your diary entry (type 'quit' to exit): ");
        fgets(entries[currentEntry].content, ENTRY_SIZE, stdin);
        entries[currentEntry].content[strlen(entries[currentEntry].content) - 1] = '\0';

        saveEntry(entries, &currentEntry);

        if (strncmp(entries[currentEntry].content, "quit", 4) == 0) {
            break;
        }
    }

    printf("Maximum number of entries reached.\n");

    return 0;
}