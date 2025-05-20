//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 50
#define MAX_ARTIST 50

typedef struct {
    int id;
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
} Music;

Music musicLibrary[MAX_MUSIC];
int musicCount = 0;

void addMusic() {
    if (musicCount >= MAX_MUSIC) {
        printf("Music library is full.\n");
        return;
    }

    Music newMusic;
    newMusic.id = musicCount + 1;

    printf("Enter music title: ");
    getchar(); // to consume leftover newline
    fgets(newMusic.title, MAX_TITLE, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove newline

    printf("Enter artist name: ");
    fgets(newMusic.artist, MAX_ARTIST, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // remove newline

    printf("Enter release year: ");
    scanf("%d", &newMusic.year);

    musicLibrary[musicCount++] = newMusic;
    printf("Music added successfully!\n");
}

void displayMusic() {
    if (musicCount == 0) {
        printf("No music in the library.\n");
        return;
    }

    printf("\nMusic Library:\n");
    printf("ID\tTitle\t\t\tArtist\t\tYear\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < musicCount; i++) {
        printf("%d\t%-20s\t%-20s\t%d\n", musicLibrary[i].id, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
    printf("--------------------------------------------------\n");
}

void searchMusic() {
    char searchTitle[MAX_TITLE];
    printf("Enter music title to search: ");
    getchar(); // consume leftover newline
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strcasecmp(musicLibrary[i].title, searchTitle) == 0) {
            printf("\nFound Music:\n");
            printf("ID: %d\nTitle: %s\nArtist: %s\nYear: %d\n", musicLibrary[i].id, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music not found.\n");
    }
}

void deleteMusic() {
    int id;
    printf("Enter music ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > musicCount) {
        printf("Invalid music ID.\n");
        return;
    }

    for (int i = id - 1; i < musicCount - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1]; // shift music left
    }
    musicCount--;
    printf("Music deleted successfully!\n");
}

void saveLibrary() {
    FILE *file = fopen("music_library.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < musicCount; i++) {
        fprintf(file, "%d;%s;%s;%d\n", musicLibrary[i].id, musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year);
    }
    fclose(file);
    printf("Library saved successfully!\n");
}

void loadLibrary() {
    FILE *file = fopen("music_library.txt", "r");
    if (!file) {
        printf("Could not open file for reading, starting with an empty library.\n");
        return;
    }
    
    while (fscanf(file, "%d;%49[^;];%49[^;];%d\n", &musicLibrary[musicCount].id, musicLibrary[musicCount].title, musicLibrary[musicCount].artist, &musicLibrary[musicCount].year) == 4) {
        musicCount++;
    }
    fclose(file);
    printf("Library loaded successfully!\n");
}

void displayMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Save Library\n");
    printf("6. Load Library\n");
    printf("7. Exit\n");
}

int main() {
    loadLibrary();

    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMusic(); break;
            case 2: displayMusic(); break;
            case 3: searchMusic(); break;
            case 4: deleteMusic(); break;
            case 5: saveLibrary(); break;
            case 6: loadLibrary(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}