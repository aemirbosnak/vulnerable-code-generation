//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define TITLE_LEN 100
#define ARTIST_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    int year;
} Music;

Music musicCollection[MAX_MUSICS];
int count = 0;

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. View Music Collection\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void addMusic() {
    if (count >= MAX_MUSICS) {
        printf("Music collection is full!\n");
        return;
    }
    
    Music newMusic;
    printf("Enter music title: ");
    getchar();  // clear newline from buffer
    fgets(newMusic.title, TITLE_LEN, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0;  // Remove newline character

    printf("Enter artist name: ");
    fgets(newMusic.artist, ARTIST_LEN, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0;  // Remove newline character

    printf("Enter release year: ");
    scanf("%d", &newMusic.year);

    musicCollection[count++] = newMusic;
    printf("Music added to the collection!\n");
}

void viewMusicCollection() {
    if (count == 0) {
        printf("No music in the collection.\n");
        return;
    }
    printf("\n--- Music Collection ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Artist: %s, Year: %d\n", 
               i + 1, musicCollection[i].title, musicCollection[i].artist, musicCollection[i].year);
    }
}

void searchMusic() {
    char query[TITLE_LEN];
    printf("Enter the title or artist to search: ");
    getchar();  // clear newline from buffer
    fgets(query, TITLE_LEN, stdin);
    query[strcspn(query, "\n")] = 0;  // Remove newline character

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(musicCollection[i].title, query) != NULL || 
            strstr(musicCollection[i].artist, query) != NULL) {
            printf("Title: %s, Artist: %s, Year: %d\n", 
                   musicCollection[i].title, musicCollection[i].artist, musicCollection[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No results found for '%s'.\n", query);
    }
}

void deleteMusic() {
    if (count == 0) {
        printf("No music to delete.\n");
        return;
    }
    viewMusicCollection();
    int index;
    printf("Enter the number of the music to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Invalid number!\n");
        return;
    }

    for (int i = index - 1; i < count - 1; i++) {
        musicCollection[i] = musicCollection[i + 1];
    }
    count--;
    printf("Music deleted from the collection!\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMusic(); break;
            case 2: viewMusicCollection(); break;
            case 3: searchMusic(); break;
            case 4: deleteMusic(); break;
            case 5: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);
    return 0;
}