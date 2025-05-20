//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100

typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
} Music;

void addMusic(Music *musicCollection, int *count);
void displayMusic(Music *musicCollection, int count);
void searchMusic(Music *musicCollection, int count);
void deleteMusic(Music *musicCollection, int *count);
void saveToFile(Music *musicCollection, int count);
void loadFromFile(Music *musicCollection, int *count);

int main() {
    Music musicCollection[MAX_MUSIC];
    int musicCount = 0;
    int choice;

    loadFromFile(musicCollection, &musicCount);

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch(choice) {
            case 1:
                addMusic(musicCollection, &musicCount);
                break;
            case 2:
                displayMusic(musicCollection, musicCount);
                break;
            case 3:
                searchMusic(musicCollection, musicCount);
                break;
            case 4:
                deleteMusic(musicCollection, &musicCount);
                break;
            case 5:
                saveToFile(musicCollection, musicCount);
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addMusic(Music *musicCollection, int *count) {
    if (*count >= MAX_MUSIC) {
        printf("Music collection is full!\n");
        return;
    }
    printf("Enter Music Title: ");
    fgets(musicCollection[*count].title, sizeof(musicCollection[*count].title), stdin);
    musicCollection[*count].title[strcspn(musicCollection[*count].title, "\n")] = 0; // Remove newline
    printf("Enter Music Artist: ");
    fgets(musicCollection[*count].artist, sizeof(musicCollection[*count].artist), stdin);
    musicCollection[*count].artist[strcspn(musicCollection[*count].artist, "\n")] = 0; // Remove newline
    printf("Enter Music Genre: ");
    fgets(musicCollection[*count].genre, sizeof(musicCollection[*count].genre), stdin);
    musicCollection[*count].genre[strcspn(musicCollection[*count].genre, "\n")] = 0; // Remove newline
    printf("Enter Year of Release: ");
    scanf("%d", &musicCollection[*count].year);
    getchar(); // Clear newline character from input buffer

    (*count)++;
    printf("Music added successfully!\n");
}

void displayMusic(Music *musicCollection, int count) {
    if (count == 0) {
        printf("No music found in the collection.\n");
        return;
    }
    printf("\nMusic Collection:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Artist: %s, Genre: %s, Year: %d\n",
               i + 1, musicCollection[i].title, musicCollection[i].artist,
               musicCollection[i].genre, musicCollection[i].year);
    }
}

void searchMusic(Music *musicCollection, int count) {
    char searchTitle[100];
    printf("Enter Music Title to search: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(musicCollection[i].title, searchTitle) == 0) {
            printf("Found: Title: %s, Artist: %s, Genre: %s, Year: %d\n",
                   musicCollection[i].title,
                   musicCollection[i].artist,
                   musicCollection[i].genre,
                   musicCollection[i].year);
            return;
        }
    }
    printf("Music not found!\n");
}

void deleteMusic(Music *musicCollection, int *count) {
    int deleteIndex;
    displayMusic(musicCollection, *count);

    printf("Enter the number of the music to delete: ");
    scanf("%d", &deleteIndex);
    getchar(); // Clear newline character from input buffer

    if (deleteIndex < 1 || deleteIndex > *count) {
        printf("Invalid selection!\n");
        return;
    }

    for (int i = deleteIndex - 1; i < *count - 1; i++) {
        musicCollection[i] = musicCollection[i + 1];
    }
    
    (*count)--;
    printf("Music deleted successfully!\n");
}

void saveToFile(Music *musicCollection, int count) {
    FILE *file = fopen("music_collection.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%s\n%d\n",
                musicCollection[i].title,
                musicCollection[i].artist,
                musicCollection[i].genre,
                musicCollection[i].year);
    }
    fclose(file);
    printf("Music collection saved successfully!\n");
}

void loadFromFile(Music *musicCollection, int *count) {
    FILE *file = fopen("music_collection.txt", "r");
    if (file == NULL) {
        printf("No existing music collection found, starting fresh.\n");
        return;
    }
    while (fgets(musicCollection[*count].title, sizeof(musicCollection[*count].title), file)) {
        musicCollection[*count].title[strcspn(musicCollection[*count].title, "\n")] = 0; // Remove newline
        fgets(musicCollection[*count].artist, sizeof(musicCollection[*count].artist), file);
        musicCollection[*count].artist[strcspn(musicCollection[*count].artist, "\n")] = 0; // Remove newline
        fgets(musicCollection[*count].genre, sizeof(musicCollection[*count].genre), file);
        musicCollection[*count].genre[strcspn(musicCollection[*count].genre, "\n")] = 0; // Remove newline
        fscanf(file, "%d\n", &musicCollection[*count].year);
        (*count)++;
    }
    fclose(file);
}