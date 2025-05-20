//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
} Music;

void addMusic(Music *musics, int *count);
void listMusics(Music *musics, int count);
void searchMusic(Music *musics, int count);
void deleteMusic(Music *musics, int *count);
void saveToFile(Music *musics, int count);
void loadFromFile(Music *musics, int *count);
void printMenu();

int main() {
    Music musics[MAX_MUSICS];
    int count = 0;
    int choice;

    loadFromFile(musics, &count);

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addMusic(musics, &count);
                break;
            case 2:
                listMusics(musics, count);
                break;
            case 3:
                searchMusic(musics, count);
                break;
            case 4:
                deleteMusic(musics, &count);
                break;
            case 5:
                saveToFile(musics, count);
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void printMenu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Music\n");
    printf("2. List Musics\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Save to File\n");
    printf("6. Exit\n");
}

void addMusic(Music *musics, int *count) {
    if (*count >= MAX_MUSICS) {
        printf("Music library is full. Cannot add more music.\n");
        return;
    }

    Music newMusic;
    printf("Enter the title: ");
    getchar(); // to consume newline character
    fgets(newMusic.title, MAX_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove trailing newline

    printf("Enter the artist: ");
    fgets(newMusic.artist, MAX_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;

    printf("Enter the genre: ");
    fgets(newMusic.genre, MAX_LENGTH, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0;

    printf("Enter the release year: ");
    scanf("%d", &newMusic.year);

    musics[*count] = newMusic;
    (*count)++;
    printf("Music added successfully!\n");
}

void listMusics(Music *musics, int count) {
    if (count == 0) {
        printf("No music found in the library.\n");
        return;
    }

    printf("\n--- Music List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Artist: %s, Genre: %s, Year: %d\n",
               i + 1, musics[i].title, musics[i].artist,
               musics[i].genre, musics[i].year);
    }
}

void searchMusic(Music *musics, int count) {
    char searchTerm[MAX_LENGTH];
    printf("Enter the title of the music to search: ");
    getchar();
    fgets(searchTerm, MAX_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(musics[i].title, searchTerm) != NULL) {
            printf("Found: Title: %s, Artist: %s, Genre: %s, Year: %d\n",
                   musics[i].title, musics[i].artist,
                   musics[i].genre, musics[i].year);
            return;
        }
    }
    printf("No music found with the title '%s'.\n", searchTerm);
}

void deleteMusic(Music *musics, int *count) {
    int index;
    if (*count == 0) {
        printf("No music found to delete.\n");
        return;
    }

    listMusics(musics, *count);
    printf("Enter the number of the music to delete: ");
    scanf("%d", &index);
    index--; // Correcting index to be zero-based

    if (index < 0 || index >= *count) {
        printf("Invalid number! Please try again.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        musics[i] = musics[i + 1];
    }
    (*count)--;
    printf("Music deleted successfully!\n");
}

void saveToFile(Music *musics, int count) {
    FILE *file = fopen("music_library.txt", "w");
    if (!file) {
        printf("Error saving to file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%s;%d\n", musics[i].title, musics[i].artist,
                musics[i].genre, musics[i].year);
    }
    fclose(file);
    printf("Music library saved to 'music_library.txt'.\n");
}

void loadFromFile(Music *musics, int *count) {
    FILE *file = fopen("music_library.txt", "r");
    if (!file) {
        printf("No previous library found, starting fresh...\n");
        return;
    }

    while (fscanf(file, "%[^;];%[^;];%[^;];%d\n", musics[*count].title, 
           musics[*count].artist, musics[*count].genre, &musics[*count].year) == 4) {
        (*count)++;
        if (*count >= MAX_MUSICS) break;
    }
    
    fclose(file);
    printf("Music library loaded from 'music_library.txt'.\n");
}