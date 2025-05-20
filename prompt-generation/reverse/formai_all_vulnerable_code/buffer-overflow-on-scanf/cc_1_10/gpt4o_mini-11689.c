//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int year;
    char genre[MAX_TITLE_LEN];
} Music;

void addMusic(Music *library, int *count);
void displayMusic(Music *library, int count);
void searchMusic(Music *library, int count);
void deleteMusic(Music *library, int *count);
void saveMusicToFile(Music *library, int count);
void loadMusicFromFile(Music *library, int *count);
void menu();

int main() {
    Music library[MAX_MUSICS];
    int musicCount = 0;
    loadMusicFromFile(library, &musicCount);

    int choice;
    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        switch (choice) {
            case 1: addMusic(library, &musicCount); break;
            case 2: displayMusic(library, musicCount); break;
            case 3: searchMusic(library, musicCount); break;
            case 4: deleteMusic(library, &musicCount); break;
            case 5: saveMusicToFile(library, musicCount); break;
            case 6: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice! Please select again.\n"); break;
        }
    } while (choice != 6);

    return 0;
}

void menu() {
    printf("\n=== Music Library Management System ===\n");
    printf("1. Add Music\n");
    printf("2. Display All Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Save Music to File\n");
    printf("6. Exit\n");
}

void addMusic(Music *library, int *count) {
    if (*count >= MAX_MUSICS) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    Music newMusic;
    printf("Enter Music Title: ");
    fgets(newMusic.title, MAX_TITLE_LEN, stdin);
    strtok(newMusic.title, "\n"); // remove newline character
    printf("Enter Artist: ");
    fgets(newMusic.artist, MAX_ARTIST_LEN, stdin);
    strtok(newMusic.artist, "\n");
    printf("Enter Release Year: ");
    scanf("%d", &newMusic.year);
    getchar(); // consume newline
    printf("Enter Genre: ");
    fgets(newMusic.genre, MAX_TITLE_LEN, stdin);
    strtok(newMusic.genre, "\n");

    library[*count] = newMusic;
    (*count)++;
    printf("Music added successfully!\n");
}

void displayMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music in the library.\n");
        return;
    }
    printf("\n=== Music Library ===\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Artist: %s, Year: %d, Genre: %s\n", 
            library[i].title, library[i].artist, library[i].year, library[i].genre);
    }
}

void searchMusic(Music *library, int count) {
    if (count == 0) {
        printf("No music in the library to search.\n");
        return;
    }
    char searchTitle[MAX_TITLE_LEN];
    printf("Enter music title to search: ");
    fgets(searchTitle, MAX_TITLE_LEN, stdin);
    strtok(searchTitle, "\n");

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found - Title: %s, Artist: %s, Year: %d, Genre: %s\n", 
                library[i].title, library[i].artist, library[i].year, library[i].genre);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void deleteMusic(Music *library, int *count) {
    if (*count == 0) {
        printf("No music in the library to delete.\n");
        return;
    }
    char deleteTitle[MAX_TITLE_LEN];
    printf("Enter music title to delete: ");
    fgets(deleteTitle, MAX_TITLE_LEN, stdin);
    strtok(deleteTitle, "\n");

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(library[i].title, deleteTitle) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Music deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void saveMusicToFile(Music *library, int count) {
    FILE *file = fopen("music_library.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%d;%s\n", library[i].title, library[i].artist, 
                library[i].year, library[i].genre);
    }
    fclose(file);
    printf("Library saved to file successfully!\n");
}

void loadMusicFromFile(Music *library, int *count) {
    FILE *file = fopen("music_library.txt", "r");
    if (file == NULL) {
        printf("No previous music library found, starting fresh!\n");
        return;
    }
    
    while (fscanf(file, " %[^;]; %[^;]; %d; %[^;\n]\n", 
                  library[*count].title, library[*count].artist, 
                  &library[*count].year, library[*count].genre) != EOF) {
        (*count)++;
    }
    fclose(file);
}