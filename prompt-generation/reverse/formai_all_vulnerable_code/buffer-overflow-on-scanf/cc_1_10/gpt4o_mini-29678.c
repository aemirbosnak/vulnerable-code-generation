//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int duration; // in seconds
    int is_available;
} Music;

Music music_library[MAX_MUSIC];
int music_count = 0;

void add_music() {
    if (music_count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }

    Music new_music;
    printf("Enter title of the music: ");
    scanf(" %[^\n]s", new_music.title);
    printf("Enter artist of the music: ");
    scanf(" %[^\n]s", new_music.artist);
    printf("Enter duration (in seconds): ");
    scanf("%d", &new_music.duration);
    new_music.is_available = 1; // Mark as available by default

    music_library[music_count++] = new_music;
    printf("Music added successfully!\n");
}

void display_music() {
    if (music_count == 0) {
        printf("No music in the library.\n");
        return;
    }

    printf("\nMusic Library:\n");
    for (int i = 0; i < music_count; i++) {
        printf("ID: %d | Title: %s | Artist: %s | Duration: %d sec | Available: %s\n",
               i + 1, music_library[i].title, music_library[i].artist,
               music_library[i].duration,
               music_library[i].is_available ? "Yes" : "No");
    }
}

void borrow_music() {
    int id;
    printf("Enter the ID of the music to borrow: ");
    scanf("%d", &id);
    if (id < 1 || id > music_count) {
        printf("Invalid music ID!\n");
        return;
    }

    if (!music_library[id - 1].is_available) {
        printf("This music is currently unavailable.\n");
        return;
    }

    music_library[id - 1].is_available = 0;
    printf("You have borrowed \"%s\" by %s.\n", 
           music_library[id - 1].title, 
           music_library[id - 1].artist);
}

void return_music() {
    int id;
    printf("Enter the ID of the music to return: ");
    scanf("%d", &id);
    if (id < 1 || id > music_count) {
        printf("Invalid music ID!\n");
        return;
    }

    if (music_library[id - 1].is_available) {
        printf("This music was not borrowed.\n");
        return;
    }

    music_library[id - 1].is_available = 1;
    printf("You have returned \"%s\" by %s.\n", 
           music_library[id - 1].title, 
           music_library[id - 1].artist);
}

void menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display Music\n");
    printf("3. Borrow Music\n");
    printf("4. Return Music\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_music();
                break;
            case 2:
                display_music();
                break;
            case 3:
                borrow_music();
                break;
            case 4:
                return_music();
                break;
            case 5:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}