//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100

typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    int duration; // in seconds
} Music;

Music library[MAX_MUSICS];
int music_count = 0;

void addMusic() {
    if (music_count >= MAX_MUSICS) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    Music newMusic;
    printf("Enter title: ");
    getchar(); // To consume the newline character from previous input
    fgets(newMusic.title, sizeof(newMusic.title), stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = '\0'; // Remove newline

    printf("Enter artist: ");
    fgets(newMusic.artist, sizeof(newMusic.artist), stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = '\0'; // Remove newline

    printf("Enter genre: ");
    fgets(newMusic.genre, sizeof(newMusic.genre), stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = '\0'; // Remove newline

    printf("Enter duration (in seconds): ");
    scanf("%d", &newMusic.duration);

    library[music_count++] = newMusic;
    printf("Music added to library!\n");
}

void displayMusic() {
    if (music_count == 0) {
        printf("No music in library!\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < music_count; i++) {
        printf("Title: %s, Artist: %s, Genre: %s, Duration: %d seconds\n", 
               library[i].title, library[i].artist, library[i].genre, library[i].duration);
    }
}

void searchMusic() {
    char search_title[100];
    printf("Enter music title to search: ");
    getchar();
    fgets(search_title, sizeof(search_title), stdin);
    search_title[strcspn(search_title, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strcasecmp(library[i].title, search_title) == 0) {
            printf("Found: Title: %s, Artist: %s, Genre: %s, Duration: %d seconds\n", 
                   library[i].title, library[i].artist, library[i].genre, library[i].duration);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Music titled '%s' not found in the library.\n", search_title);
    }
}

void deleteMusic() {
    char delete_title[100];
    printf("Enter music title to delete: ");
    getchar();
    fgets(delete_title, sizeof(delete_title), stdin);
    delete_title[strcspn(delete_title, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strcasecmp(library[i].title, delete_title) == 0) {
            for (int j = i; j < music_count - 1; j++) {
                library[j] = library[j + 1];
            }
            music_count--;
            found = 1;
            printf("Music titled '%s' has been deleted.\n", delete_title);
            break;
        }
    }
    if (!found) {
        printf("Music titled '%s' not found. Cannot delete.\n", delete_title);
    }
}

void mainMenu() {
    int choice;
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display All Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMusic(); break;
            case 2: displayMusic(); break;
            case 3: searchMusic(); break;
            case 4: deleteMusic(); break;
            case 5: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    mainMenu();
    return 0;
}