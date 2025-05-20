//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100
#define ALBUM_LENGTH 100

struct Music {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
    int year;
};

// Function prototypes
void displayMenu();
void addMusic(struct Music* library, int* count);
void viewMusic(const struct Music* library, int count);
void searchMusic(const struct Music* library, int count);
void deleteMusic(struct Music* library, int* count);
void saveToFile(const struct Music* library, int count);
void loadFromFile(struct Music* library, int* count);
void clearBuffer();

int main() {
    struct Music musicLibrary[MAX_MUSICS];
    int musicCount = 0;
    loadFromFile(musicLibrary, &musicCount);
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the newline left in the buffer

        switch (choice) {
            case 1: addMusic(musicLibrary, &musicCount); break;
            case 2: viewMusic(musicLibrary, musicCount); break;
            case 3: searchMusic(musicLibrary, musicCount); break;
            case 4: deleteMusic(musicLibrary, &musicCount); break;
            case 5: saveToFile(musicLibrary, musicCount); break;
            case 6: printf("Exiting... Thank you for using the music library!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. View All Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Save Music to File\n");
    printf("6. Exit\n");
}

void addMusic(struct Music* library, int* count) {
    if (*count >= MAX_MUSICS) {
        printf("Music library is full! Can't add more music.\n");
        return;
    }

    printf("Enter music title: ");
    fgets(library[*count].title, TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = '\0'; // Remove newline

    printf("Enter artist: ");
    fgets(library[*count].artist, ARTIST_LENGTH, stdin);
    library[*count].artist[strcspn(library[*count].artist, "\n")] = '\0';

    printf("Enter album: ");
    fgets(library[*count].album, ALBUM_LENGTH, stdin);
    library[*count].album[strcspn(library[*count].album, "\n")] = '\0';

    printf("Enter year of release: ");
    scanf("%d", &library[*count].year);
    clearBuffer();

    (*count)++;
    printf("Music added successfully!\n");
}

void viewMusic(const struct Music* library, int count) {
    if (count == 0) {
        printf("No music in the library!\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s, Album: %s, Year: %d\n", 
               i + 1, library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

void searchMusic(const struct Music* library, int count) {
    char searchTitle[TITLE_LENGTH];
    
    printf("Enter music title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found: %s by %s, Album: %s, Year: %d\n", 
                   library[i].title, library[i].artist, library[i].album, library[i].year);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No music found with the title \"%s\".\n", searchTitle);
    }
}

void deleteMusic(struct Music* library, int* count) {
    if (*count == 0) {
        printf("No music to delete!\n");
        return;
    }

    int index;
    printf("Enter the number of the music to delete (1-%d): ", *count);
    scanf("%d", &index);
    clearBuffer();

    if (index < 1 || index > *count) {
        printf("Invalid selection.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        library[i] = library[i + 1]; // Shift left
    }

    (*count)--;
    printf("Music deleted successfully!\n");
}

void saveToFile(const struct Music* library, int count) {
    FILE* file = fopen("music_library.txt", "w");
    if (!file) {
        printf("Unable to save to file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%s|%s|%d\n", 
                library[i].title, library[i].artist, library[i].album, library[i].year);
    }

    fclose(file);
    printf("Library saved successfully!\n");
}

void loadFromFile(struct Music* library, int* count) {
    FILE* file = fopen("music_library.txt", "r");
    if (!file) {
        printf("No saved library found, starting fresh!\n");
        return;
    }

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%d\n", 
                  library[*count].title, library[*count].artist, 
                  library[*count].album, &library[*count].year) != EOF) {
        (*count)++;
    }

    fclose(file);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}