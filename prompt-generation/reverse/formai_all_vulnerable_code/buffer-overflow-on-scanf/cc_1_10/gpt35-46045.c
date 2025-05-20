//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    char title[50];
    char artist[50];
    int year;
} Record;

Record musicLibrary[MAX_RECORDS];
int numRecords = 0;

void addRecord(char* title, char* artist, int year) {
    if (numRecords == MAX_RECORDS) {
        printf("Sorry, the music library is full.\n");
        return;
    }

    Record newRecord;
    strcpy(newRecord.title, title);
    strcpy(newRecord.artist, artist);
    newRecord.year = year;

    musicLibrary[numRecords++] = newRecord;

    printf("Record added successfully!\n");
}

void deleteRecord(char* title) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(musicLibrary[i].title, title) == 0) {
            int j;
            for (j = i + 1; j < numRecords; j++) {
                musicLibrary[j - 1] = musicLibrary[j];
            }
            numRecords--;
            printf("Record deleted successfully!\n");
            return;
        }
    }

    printf("Record not found in music library.\n");
}

void searchRecord(char* artist) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(musicLibrary[i].artist, artist) == 0) {
            printf("%s - %s (%d)\n", musicLibrary[i].artist, musicLibrary[i].title, musicLibrary[i].year);
        }
    }
}

void listRecords() {
    if (numRecords == 0) {
        printf("Music library is empty!\n");
        return;
    }

    int i;
    for (i = 0; i < numRecords; i++) {
        printf("%s - %s (%d)\n", musicLibrary[i].artist, musicLibrary[i].title, musicLibrary[i].year);
    }
}

int main() {
    while (1) {
        int choice;
        printf("Choose an option:\n1. Add record\n2. Delete record\n3. Search records\n4. List all records\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char title[50];
                char artist[50];
                int year;

                printf("Enter title, artist, and year of record:\n");
                scanf("%s %s %d", title, artist, &year);

                addRecord(title, artist, year);
                break;
            }
            case 2: {
                char title[50];

                printf("Enter the title of the record to be deleted:\n");
                scanf("%s", title);

                deleteRecord(title);
                break;
            }
            case 3: {
                char artist[50];

                printf("Enter the artist name to search records by:\n");
                scanf("%s", artist);

                searchRecord(artist);
                break;
            }
            case 4: {
                listRecords();
                break;
            }
            case 5: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice, please try again.\n");
                break;
            }
        }
    }

    return 0;
}