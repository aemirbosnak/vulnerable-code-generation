//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50
#define ALBUM_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
    int year;
} Music;

void addMusic(Music *library, int *count);
void displayMusic(Music *library, int count);
void searchMusic(Music *library, int count);
void deleteMusic(Music *library, int *count);
void saveMusic(Music *library, int count);
void loadMusic(Music *library, int *count);

int main() {
    Music library[MAX_MUSIC];
    int count = 0;
    int choice;

    loadMusic(library, &count);

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Save Music\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                addMusic(library, &count);
                break;
            case 2:
                displayMusic(library, count);
                break;
            case 3:
                searchMusic(library, count);
                break;
            case 4:
                deleteMusic(library, &count);
                break;
            case 5:
                saveMusic(library, count);
                break;
            case 6:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addMusic(Music *library, int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }
    printf("Enter title: ");
    fgets(library[*count].title, TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline

    printf("Enter artist: ");
    fgets(library[*count].artist, ARTIST_LENGTH, stdin);
    library[*count].artist[strcspn(library[*count].artist, "\n")] = 0;

    printf("Enter album: ");
    fgets(library[*count].album, ALBUM_LENGTH, stdin);
    library[*count].album[strcspn(library[*count].album, "\n")] = 0;

    printf("Enter year: ");
    scanf("%d", &library[*count].year);
    getchar(); // Consume newline

    (*count)++;
    printf("Music added successfully!\n");
}

void displayMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music in the library.\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Artist: %s, Album: %s, Year: %d\n",
               i + 1, library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

void searchMusic(Music *library, int count) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found: Title: %s, Artist: %s, Album: %s, Year: %d\n",
                   library[i].title, library[i].artist, library[i].album, library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("Music not found.\n");
    }
}

void deleteMusic(Music *library, int *count) {
    int index;
    printf("Enter index of music to delete (1 to %d): ", *count);
    scanf("%d", &index);
    getchar(); // Consume newline

    if (index < 1 || index > *count) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        library[i] = library[i + 1];
    }
    (*count)--;
    printf("Music deleted successfully!\n");
}

void saveMusic(Music *library, int count) {
    FILE *file = fopen("music_library.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%s\n%d\n", 
                library[i].title, 
                library[i].artist, 
                library[i].album, 
                library[i].year);
    }

    fclose(file);
    printf("Music saved successfully!\n");
}

void loadMusic(Music *library, int *count) {
    FILE *file = fopen("music_library.txt", "r");
    if (file == NULL) {
        printf("No existing library found, starting fresh.\n");
        return;
    }

    while (fgets(library[*count].title, TITLE_LENGTH, file)) {
        library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline
        fgets(library[*count].artist, ARTIST_LENGTH, file);
        library[*count].artist[strcspn(library[*count].artist, "\n")] = 0;
        fgets(library[*count].album, ALBUM_LENGTH, file);
        library[*count].album[strcspn(library[*count].album, "\n")] = 0;
        fscanf(file, "%d\n", &library[*count].year);
        (*count)++;
    }

    fclose(file);
    printf("Music loaded successfully!\n");
}