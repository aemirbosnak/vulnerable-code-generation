//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    int year;
    char genre[TITLE_LENGTH];
} Music;

Music library[MAX_MUSICS];
int music_count = 0;

void add_music() {
    if (music_count >= MAX_MUSICS) {
        printf("Music library is full!\n");
        return;
    }
    
    Music new_music;
    
    printf("Enter title: ");
    scanf(" %[^\n]", new_music.title);
    
    printf("Enter artist: ");
    scanf(" %[^\n]", new_music.artist);
    
    printf("Enter year: ");
    scanf("%d", &new_music.year);
    
    printf("Enter genre: ");
    scanf(" %[^\n]", new_music.genre);
    
    library[music_count] = new_music;
    music_count++;
    
    printf("Music added successfully!\n");
}

void view_music() {
    if (music_count == 0) {
        printf("No music in the library.\n");
        return;
    }
    
    printf("\nMusic Library:\n");
    for (int i = 0; i < music_count; i++) {
        printf("Title: %s, Artist: %s, Year: %d, Genre: %s\n", 
               library[i].title, library[i].artist, library[i].year, library[i].genre);
    }
}

void search_music() {
    char search_title[TITLE_LENGTH];
    printf("Enter title to search: ");
    scanf(" %[^\n]", search_title);
    
    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strcasecmp(library[i].title, search_title) == 0) {
            printf("Found Music - Title: %s, Artist: %s, Year: %d, Genre: %s\n", 
                   library[i].title, library[i].artist, library[i].year, library[i].genre);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void delete_music() {
    char delete_title[TITLE_LENGTH];
    printf("Enter title of the music to delete: ");
    scanf(" %[^\n]", delete_title);
    
    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strcasecmp(library[i].title, delete_title) == 0) {
            found = 1;
            for (int j = i; j < music_count - 1; j++) {
                library[j] = library[j + 1];
            }
            music_count--;
            printf("Music deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Music not found in the library.\n");
    }
}

void display_menu() {
    printf("\nMusic Library Management System\n");
    printf("1. Add Music\n");
    printf("2. View Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_music();
                break;
            case 2:
                view_music();
                break;
            case 3:
                search_music();
                break;
            case 4:
                delete_music();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}