//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ENTRIES 100
#define PASSWORD "1234"

typedef struct {
    char date[11];
    char entry[500];
} Entry;

int main() {
    FILE *diary;
    char filename[20];
    int entryCount = 0;
    Entry entries[MAX_ENTRIES];
    time_t now;
    char *password = PASSWORD;
    int i;

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter the name of your diary file (without extension): ");
    scanf("%s", filename);

    diary = fopen(filename, "r");
    if (diary == NULL) {
        printf("Diary file not found.\n");
        exit(1);
    }

    while (fgets(entries[entryCount].date, 11, diary)!= NULL && entryCount < MAX_ENTRIES) {
        entryCount++;
    }

    fclose(diary);

    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Could not open diary file.\n");
        exit(1);
    }

    time(&now);
    strftime(entries[entryCount].date, 11, "%Y-%m-%d", localtime(&now));

    printf("Enter your entry:\n");
    fgets(entries[entryCount].entry, 500, stdin);

    for (i = 0; i < strlen(entries[entryCount].entry); i++) {
        if (entries[entryCount].entry[i] == '\n') {
            entries[entryCount].entry[i] = '\0';
            break;
        }
    }

    fprintf(diary, "Date: %s\nEntry:\n%s\n", entries[entryCount].date, entries[entryCount].entry);
    fclose(diary);

    printf("Entry saved.\n");

    return 0;
}