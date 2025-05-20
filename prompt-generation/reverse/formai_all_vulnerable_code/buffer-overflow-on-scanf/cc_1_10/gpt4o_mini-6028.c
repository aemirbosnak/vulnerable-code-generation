//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
} Song;

void addSong(Song songs[], int *count) {
    if (*count >= MAX_SONGS) {
        printf("Cannot add more songs, library is full.\n");
        return;
    }
    printf("Enter song title: ");
    getchar(); // consume newline character
    fgets(songs[*count].title, MAX_LENGTH, stdin);
    songs[*count].title[strcspn(songs[*count].title, "\n")] = 0; // remove trailing newline

    printf("Enter artist: ");
    fgets(songs[*count].artist, MAX_LENGTH, stdin);
    songs[*count].artist[strcspn(songs[*count].artist, "\n")] = 0;

    printf("Enter album: ");
    fgets(songs[*count].album, MAX_LENGTH, stdin);
    songs[*count].album[strcspn(songs[*count].album, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &songs[*count].year);

    (*count)++;
    printf("Song added successfully!\n");
}

void displaySongs(Song songs[], int count) {
    if (count == 0) {
        printf("No songs in the library.\n");
        return;
    }
    printf("\n--- Song Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Artist: %s, Album: %s, Year: %d\n", 
               i + 1, songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
    }
}

void searchSong(Song songs[], int count) {
    char search[MAX_LENGTH];
    printf("Enter title or artist to search: ");
    getchar(); // consume newline character
    fgets(search, MAX_LENGTH, stdin);
    search[strcspn(search, "\n")] = 0; // remove trailing newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(songs[i].title, search) != NULL || strstr(songs[i].artist, search) != NULL) {
            printf("Found: %s by %s in album %s (%d)\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No song found with that title or artist.\n");
    }
}

void deleteSong(Song songs[], int *count) {
    int index;
    printf("Enter the song number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid song number.\n");
        return;
    }
    for (int i = index - 1; i < *count - 1; i++) {
        songs[i] = songs[i + 1];
    }
    (*count)--;
    printf("Song deleted successfully!\n");
}

void saveToFile(Song songs[], int count) {
    FILE *file = fopen("music_library.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%s\n%d\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
    }
    fclose(file);
    printf("Library saved successfully!\n");
}

int loadFromFile(Song songs[]) {
    FILE *file = fopen("music_library.txt", "r");
    if (file == NULL) {
        return 0; // no songs loaded if file doesn't exist
    }
    int count = 0;
    while (fgets(songs[count].title, MAX_LENGTH, file) != NULL) {
        strtok(songs[count].title, "\n");
        fgets(songs[count].artist, MAX_LENGTH, file);
        strtok(songs[count].artist, "\n");
        fgets(songs[count].album, MAX_LENGTH, file);
        strtok(songs[count].album, "\n");
        fscanf(file, "%d\n", &songs[count].year);
        count++;
    }
    fclose(file);
    return count;
}

int main() {
    Song songs[MAX_SONGS];
    int count = loadFromFile(songs);
    int choice;

    while (1) {
        printf("\n--- Music Library Management ---\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search for a song\n");
        printf("4. Delete a song\n");
        printf("5. Save library to file\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(songs, &count);
                break;
            case 2:
                displaySongs(songs, count);
                break;
            case 3:
                searchSong(songs, count);
                break;
            case 4:
                deleteSong(songs, &count);
                break;
            case 5:
                saveToFile(songs, count);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please select again.\n");
        }
    }

    return 0;
}