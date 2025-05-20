//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE 100
#define MAX_ARTIST 50

typedef struct {
    int id;
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char genre[MAX_ARTIST];
    int year;
} Music;

void displayMenu();
void addMusic(Music library[], int *count);
void displayLibrary(const Music library[], int count);
void searchMusic(const Music library[], int count);
void deleteMusic(Music library[], int *count);
void saveLibrary(const Music library[], int count);
void loadLibrary(Music library[], int *count);

int main() {
    Music library[MAX_MUSIC];
    int count = 0;
    loadLibrary(library, &count);
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMusic(library, &count);
                break;
            case 2:
                displayLibrary(library, count);
                break;
            case 3:
                searchMusic(library, count);
                break;
            case 4:
                deleteMusic(library, &count);
                break;
            case 5:
                saveLibrary(library, count);
                printf("Library saved successfully!\n");
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display Music Library\n");
    printf("3. Search Music by Title\n");
    printf("4. Delete Music\n");
    printf("5. Save Library\n");
    printf("6. Exit\n");
}

void addMusic(Music library[], int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    
    Music newMusic;
    newMusic.id = *count + 1;

    printf("Enter title: ");
    getchar();
    fgets(newMusic.title, MAX_TITLE, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // Remove newline character

    printf("Enter artist: ");
    fgets(newMusic.artist, MAX_ARTIST, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;

    printf("Enter genre: ");
    fgets(newMusic.genre, MAX_ARTIST, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0;

    printf("Enter year: ");
    scanf("%d", &newMusic.year);

    library[*count] = newMusic;
    (*count)++;
    printf("Music added successfully!\n");
}

void displayLibrary(const Music library[], int count) {
    if (count == 0) {
        printf("Library is empty!\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Artist: %s, Genre: %s, Year: %d\n",
               library[i].id, library[i].title, library[i].artist,
               library[i].genre, library[i].year);
    }
}

void searchMusic(const Music library[], int count) {
    char searchTitle[MAX_TITLE];
    printf("Enter title to search: ");
    getchar();
    fgets(searchTitle, MAX_TITLE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Found: ID: %d, Title: %s, Artist: %s, Genre: %s, Year: %d\n",
                   library[i].id, library[i].title, library[i].artist,
                   library[i].genre, library[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void deleteMusic(Music library[], int *count) {
    int id;
    printf("Enter ID of the music to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Invalid ID! Music not found.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        library[i] = library[i + 1];  // Shift the elements to fill the gap
    }
    (*count)--;
    printf("Music deleted successfully!\n");
}

void saveLibrary(const Music library[], int count) {
    FILE *file = fopen("music_library.txt", "w");
    if (!file) {
        printf("Cannot open file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d;%s;%s;%s;%d\n", library[i].id, library[i].title,
                library[i].artist, library[i].genre, library[i].year);
    }
    
    fclose(file);
}

void loadLibrary(Music library[], int *count) {
    FILE *file = fopen("music_library.txt", "r");
    if (!file) {
        printf("No existing library found, starting fresh!\n");
        *count = 0;
        return;
    }

    while (fscanf(file, "%d;%99[^;];%49[^;];%49[^;];%d\n",
                  &library[*count].id, library[*count].title,
                  library[*count].artist, library[*count].genre,
                  &library[*count].year) == 5) {
        (*count)++;
    }
    
    fclose(file);
    printf("Library loaded successfully! Current count: %d\n", *count);
}