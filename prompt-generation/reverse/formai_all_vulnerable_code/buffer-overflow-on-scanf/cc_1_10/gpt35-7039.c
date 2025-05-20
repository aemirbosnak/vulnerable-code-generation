//FormAI DATASET v1.0 Category: Digital Diary ; Style: portable
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    Date date;
    char* entry;
} DiaryEntry;

int main() {
    int numEntries;
    printf("Enter number of diary entries: ");
    scanf("%d", &numEntries);

    DiaryEntry* entries = (DiaryEntry*)malloc(numEntries * sizeof(DiaryEntry));

    printf("Enter the diary entries in the format DD MM YYYY Entry\n");

    for(int i=0; i<numEntries; i++) {
        scanf("%d %d %d", &entries[i].date.day, 
                          &entries[i].date.month,
                          &entries[i].date.year);
        getchar(); // to consume the newline character
        entries[i].entry = (char*)malloc(1024 * sizeof(char));
        fgets(entries[i].entry, 1024, stdin);
    }

    printf("\n\n");

    // Display the diary entries
    for(int i=0; i<numEntries; i++) {
        printf("%02d-%02d-%4d\t%s", entries[i].date.day, 
                                     entries[i].date.month,
                                     entries[i].date.year,
                                     entries[i].entry);
    }

    // Free memory allocated for diary entries
    for(int i=0; i<numEntries; i++) {
        free(entries[i].entry);
    }
    free(entries);

    return 0;
}