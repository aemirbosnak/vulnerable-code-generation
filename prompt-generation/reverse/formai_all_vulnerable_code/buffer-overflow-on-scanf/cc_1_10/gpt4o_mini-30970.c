//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
} Music;

int music_count = 0;
Music music_library[MAX_MUSIC];

void add_music() {
    if (music_count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }
    Music new_music;
    printf("Enter music title: ");
    fgets(new_music.title, TITLE_LENGTH, stdin);
    new_music.title[strcspn(new_music.title, "\n")] = '\0'; // Remove trailing newline
    printf("Enter artist name: ");
    fgets(new_music.artist, ARTIST_LENGTH, stdin);
    new_music.artist[strcspn(new_music.artist, "\n")] = '\0'; // Remove trailing newline
    printf("Enter year of release: ");
    scanf("%d", &new_music.year);
    getchar(); // Clear newline character left by scanf
    music_library[music_count] = new_music;
    music_count++;
    printf("Music added successfully!\n");
}

void display_music() {
    if (music_count == 0) {
        printf("No music in the library.\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < music_count; i++) {
        printf("Title: %s, Artist: %s, Year: %d\n", music_library[i].title, music_library[i].artist, music_library[i].year);
    }
}

void find_music() {
    char query[TITLE_LENGTH];
    printf("Enter the title or artist name to search: ");
    fgets(query, TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // Remove trailing newline
    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < music_count; i++) {
        if (strstr(music_library[i].title, query) != NULL || strstr(music_library[i].artist, query) != NULL) {
            printf("Title: %s, Artist: %s, Year: %d\n", music_library[i].title, music_library[i].artist, music_library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found matching the query.\n");
    }
}

void delete_music() {
    char title[TITLE_LENGTH];
    printf("Enter the title of music to delete: ");
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove trailing newline
    int found = -1;
    for (int i = 0; i < music_count; i++) {
        if (strcmp(music_library[i].title, title) == 0) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        for (int i = found; i < music_count - 1; i++) {
            music_library[i] = music_library[i + 1];
        }
        music_count--;
        printf("Music '%s' deleted successfully!\n", title);
    } else {
        printf("Music with title '%s' not found.\n", title);
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Find Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character left by scanf

        switch (choice) {
            case 1:
                add_music();
                break;
            case 2:
                display_music();
                break;
            case 3:
                find_music();
                break;
            case 4:
                delete_music();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}