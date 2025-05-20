//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_SIZE 50
#define ARTIST_SIZE 30

typedef struct {
    char title[TITLE_SIZE];
    char artist[ARTIST_SIZE];
    int year;
    char genre[20];
} Music;

Music library[MAX_MUSIC];
int count = 0;

void addMusic();
void displayMusic();
void searchMusic();
void deleteMusic();
void saveLibrary();
void loadLibrary();

int main() {
    int choice;

    loadLibrary();
    
    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Save Library\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                displayMusic();
                break;
            case 3:
                searchMusic();
                break;
            case 4:
                deleteMusic();
                break;
            case 5:
                saveLibrary();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addMusic() {
    if (count >= MAX_MUSIC) {
        printf("Library is full, cannot add more music.\n");
        return;
    }

    printf("Enter music title: ");
    fgets(library[count].title, TITLE_SIZE, stdin);
    library[count].title[strcspn(library[count].title, "\n")] = '\0'; // remove newline

    printf("Enter artist name: ");
    fgets(library[count].artist, ARTIST_SIZE, stdin);
    library[count].artist[strcspn(library[count].artist, "\n")] = '\0'; // remove newline

    printf("Enter year of release: ");
    scanf("%d", &library[count].year);
    getchar(); // consume newline

    printf("Enter genre: ");
    fgets(library[count].genre, 20, stdin);
    library[count].genre[strcspn(library[count].genre, "\n")] = '\0'; // remove newline

    printf("Music added to library.\n");
    count++;
}

void displayMusic() {
    if (count == 0) {
        printf("No music in the library.\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Artist: %s, Year: %d, Genre: %s\n",
               library[i].title, library[i].artist, library[i].year, library[i].genre);
    }
}

void searchMusic() {
    char searchTitle[TITLE_SIZE];
    printf("Enter music title to search: ");
    fgets(searchTitle, TITLE_SIZE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found: Title: %s, Artist: %s, Year: %d, Genre: %s\n",
                   library[i].title, library[i].artist, library[i].year, library[i].genre);
            return;
        }
    }
    printf("Music title not found in the library.\n");
}

void deleteMusic() {
    char deleteTitle[TITLE_SIZE];
    printf("Enter music title to delete: ");
    fgets(deleteTitle, TITLE_SIZE, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = '\0'; // remove newline

    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, deleteTitle) == 0) {
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1]; // shift elements left
            }
            count--;
            printf("Music deleted from library.\n");
            return;
        }
    }
    printf("Music title not found in the library.\n");
}

void saveLibrary() {
    FILE *file = fopen("music_library.dat", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    fwrite(library, sizeof(Music), count, file);
    fclose(file);
    printf("Library saved successfully.\n");
}

void loadLibrary() {
    FILE *file = fopen("music_library.dat", "r");
    if (file != NULL) {
        count = fread(library, sizeof(Music), MAX_MUSIC, file);
        fclose(file);
        printf("Library loaded successfully.\n");
    } else {
        printf("No previous library found, starting fresh.\n");
    }
}