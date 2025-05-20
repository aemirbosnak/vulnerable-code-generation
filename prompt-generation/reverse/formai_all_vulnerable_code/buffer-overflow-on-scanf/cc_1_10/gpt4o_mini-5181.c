//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LEN 100
#define ARTIST_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    int year;
    float duration; // in minutes
} Music;

Music library[MAX_MUSIC];
int music_count = 0;

void add_music() {
    if (music_count >= MAX_MUSIC) {
        printf("Music library is full!\n");
        return;
    }
    
    Music new_music;

    printf("Enter music title: ");
    getchar(); // to consume newline character
    fgets(new_music.title, TITLE_LEN, stdin);
    new_music.title[strcspn(new_music.title, "\n")] = 0; // remove the newline character

    printf("Enter artist name: ");
    fgets(new_music.artist, ARTIST_LEN, stdin);
    new_music.artist[strcspn(new_music.artist, "\n")] = 0; // remove the newline character

    printf("Enter release year: ");
    scanf("%d", &new_music.year);
    
    printf("Enter duration (in minutes): ");
    scanf("%f", &new_music.duration);
    
    library[music_count] = new_music;
    music_count++;
    
    printf("Music added successfully!\n");
}

void display_music() {
    if (music_count == 0) {
        printf("No music found in the library.\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < music_count; i++) {
        printf("ID: %d | Title: %s | Artist: %s | Year: %d | Duration: %.2f minutes\n",
               i + 1, library[i].title, library[i].artist, library[i].year, library[i].duration);
    }
}

void search_music() {
    char search_title[TITLE_LEN];
    printf("Enter the title of the music to search: ");
    getchar(); // to consume newline character
    fgets(search_title, TITLE_LEN, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // remove the newline character

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strstr(library[i].title, search_title) != NULL) {
            printf("ID: %d | Title: %s | Artist: %s | Year: %d | Duration: %.2f minutes\n",
                   i + 1, library[i].title, library[i].artist, library[i].year, library[i].duration);
            found = 1;
        }
    }

    if (!found) {
        printf("No music found matching the title '%s'.\n", search_title);
    }
}

void delete_music() {
    int id;
    printf("Enter the ID of the music to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > music_count) {
        printf("Invalid music ID!\n");
        return;
    }

    for (int i = id - 1; i < music_count - 1; i++) {
        library[i] = library[i + 1];
    }
    music_count--;
   
    printf("Music with ID %d deleted successfully!\n", id);
}

void menu() {
    int choice;

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display All Music\n");
        printf("3. Search Music by Title\n");
        printf("4. Delete Music by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_music(); break;
            case 2: display_music(); break;
            case 3: search_music(); break;
            case 4: delete_music(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}