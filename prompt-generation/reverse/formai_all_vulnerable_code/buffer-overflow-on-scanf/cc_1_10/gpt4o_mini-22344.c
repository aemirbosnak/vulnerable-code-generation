//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LENGTH 100
#define ARTIST_LENGTH 100
#define ALBUM_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
    int year;
} Music;

int music_count = 0;
Music library[MAX_MUSIC];

void add_music() {
    if (music_count == MAX_MUSIC) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    
    Music new_music;
    
    printf("Enter title: ");
    getchar(); // To clear the newline character from input buffer
    fgets(new_music.title, TITLE_LENGTH, stdin);
    strtok(new_music.title, "\n"); // To remove newline character
    
    printf("Enter artist: ");
    fgets(new_music.artist, ARTIST_LENGTH, stdin);
    strtok(new_music.artist, "\n");
    
    printf("Enter album: ");
    fgets(new_music.album, ALBUM_LENGTH, stdin);
    strtok(new_music.album, "\n");
    
    printf("Enter year: ");
    scanf("%d", &new_music.year);
    
    library[music_count] = new_music;
    music_count++;
    printf("Music added successfully!\n");
}

void display_music() {
    printf("\nMusic Library:\n");
    for (int i = 0; i < music_count; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n\n", library[i].year);
    }
}

void search_music() {
    char search_title[TITLE_LENGTH];
    printf("Enter title to search: ");
    getchar();
    fgets(search_title, TITLE_LENGTH, stdin);
    strtok(search_title, "\n");
    
    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            printf("Found Music:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No music found with title: %s\n", search_title);
    }
}

void delete_music() {
    char delete_title[TITLE_LENGTH];
    printf("Enter title to delete: ");
    getchar();
    fgets(delete_title, TITLE_LENGTH, stdin);
    strtok(delete_title, "\n");
    
    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strcmp(library[i].title, delete_title) == 0) {
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
        printf("No music found with title: %s\n", delete_title);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Music Library Management System ===\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                delete_music();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}