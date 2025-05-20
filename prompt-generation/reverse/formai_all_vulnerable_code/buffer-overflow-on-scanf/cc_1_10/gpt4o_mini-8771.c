//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100

typedef struct {
    char title[100];
    char artist[100];
    char genre[100];
    int year;
} Music;

Music music_library[MAX_MUSIC];
int count = 0;

// Function to add music to the library
void add_music() {
    if (count >= MAX_MUSIC) {
        printf("Music library is full!\n\n");
        return;
    }
    
    Music new_music;
    printf("Enter title: ");
    getchar(); // Clear the buffer
    fgets(new_music.title, sizeof(new_music.title), stdin);
    new_music.title[strcspn(new_music.title, "\n")] = 0; // Remove newline
    
    printf("Enter artist: ");
    fgets(new_music.artist, sizeof(new_music.artist), stdin);
    new_music.artist[strcspn(new_music.artist, "\n")] = 0; // Remove newline
    
    printf("Enter genre: ");
    fgets(new_music.genre, sizeof(new_music.genre), stdin);
    new_music.genre[strcspn(new_music.genre, "\n")] = 0; // Remove newline
    
    printf("Enter year: ");
    scanf("%d", &new_music.year);
    
    music_library[count++] = new_music;
    printf("🎉 Music '%s' by '%s' added successfully!\n\n", new_music.title, new_music.artist);
}

// Function to display all music in the library
void display_music() {
    if (count == 0) {
        printf("💔 No music found! Please add some music first.\n\n");
        return;
    }
    
    printf("📚 Music Library:\n");
    for (int i = 0; i < count; i++) {
        printf("Track %d: '%s' by %s, Genre: %s, Year: %d\n",
               i + 1, music_library[i].title, music_library[i].artist, 
               music_library[i].genre, music_library[i].year);
    }
    printf("\n");
}

// Function to search for a music by title
void search_music() {
    char search_title[100];
    printf("Enter title to search: ");
    getchar(); // Clear the buffer
    fgets(search_title, sizeof(search_title), stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Remove newline
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(music_library[i].title, search_title) == 0) {
            printf("Found! '%s' by %s, Genre: %s, Year: %d\n\n",
                   music_library[i].title, music_library[i].artist, 
                   music_library[i].genre, music_library[i].year);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("😢 Sorry, music with title '%s' not found in the library.\n\n", search_title);
    }
}

// Main menu interface
void menu() {
    int choice;
    do {
        printf("🎶 Welcome to the Music Library Management System! 🎶\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Exit\n");
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
                search_music();
                break;
            case 4:
                printf("🎵 Thank you for using the Music Library Management System! Goodbye! 🎵\n");
                break;
            default:
                printf("🚫 Invalid choice! Please select again.\n\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}