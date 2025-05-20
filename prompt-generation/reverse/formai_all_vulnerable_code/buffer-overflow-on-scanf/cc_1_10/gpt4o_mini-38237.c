//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_TITLE 50
#define MAX_ARTIST 50

typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
} MusicRecord;

typedef struct {
    MusicRecord records[MAX_RECORDS];
    int size;
} MusicLibrary;

void initializeLibrary(MusicLibrary *library) {
    library->size = 0;
}

void addRecord(MusicLibrary *library) {
    if (library->size >= MAX_RECORDS) {
        printf("Library is full. Cannot add more records.\n");
        return;
    }
    
    MusicRecord record;
    printf("Enter title: ");
    scanf("%s", record.title);
    printf("Enter artist: ");
    scanf("%s", record.artist);
    printf("Enter release year: ");
    scanf("%d", &record.year);
    
    library->records[library->size++] = record;
    printf("Record added successfully.\n");
}

void displayRecords(const MusicLibrary *library) {
    if (library->size == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\nMusic Library Records:\n");
    for (int i = 0; i < library->size; i++) {
        printf("Record %d: Title: %s, Artist: %s, Year: %d\n",
               i + 1, library->records[i].title,
               library->records[i].artist,
               library->records[i].year);
    }
}

void searchRecord(const MusicLibrary *library) {
    char query[MAX_TITLE];
    printf("Enter title to search: ");
    scanf("%s", query);
    int found = 0;

    for (int i = 0; i < library->size; i++) {
        if (strcmp(library->records[i].title, query) == 0) {
            printf("Record found: Title: %s, Artist: %s, Year: %d\n",
                   library->records[i].title,
                   library->records[i].artist,
                   library->records[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No record found with the title: %s\n", query);
    }
}

void deleteRecord(MusicLibrary *library) {
    char query[MAX_TITLE];
    printf("Enter title of the record to delete: ");
    scanf("%s", query);
    int found = 0;

    for (int i = 0; i < library->size; i++) {
        if (strcmp(library->records[i].title, query) == 0) {
            found = 1;
            for (int j = i; j < library->size - 1; j++) {
                library->records[j] = library->records[j + 1];
            }
            library->size--;
            printf("Record deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("No record found with the title: %s\n", query);
    }
}

void saveLibrary(const MusicLibrary *library) {
    FILE *file = fopen("music_library.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < library->size; i++) {
        fprintf(file, "%s,%s,%d\n", library->records[i].title,
                library->records[i].artist,
                library->records[i].year);
    }
    fclose(file);
    printf("Library saved to music_library.txt\n");
}

void loadLibrary(MusicLibrary *library) {
    FILE *file = fopen("music_library.txt", "r");
    if (file == NULL) {
        printf("Error opening file for loading.\n");
        return;
    }

    while (!feof(file) && library->size < MAX_RECORDS) {
        MusicRecord record;
        fscanf(file, "%[^,],%[^,],%d\n", record.title, record.artist, &record.year);
        library->records[library->size++] = record;
    }
    fclose(file);
    printf("Library loaded from music_library.txt\n");
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);

    int choice;
    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Save Library\n");
        printf("6. Load Library\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(&library); break;
            case 2: displayRecords(&library); break;
            case 3: searchRecord(&library); break;
            case 4: deleteRecord(&library); break;
            case 5: saveLibrary(&library); break;
            case 6: loadLibrary(&library); break;
            case 7: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}