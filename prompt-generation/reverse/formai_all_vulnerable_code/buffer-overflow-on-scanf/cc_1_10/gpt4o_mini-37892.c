//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_LEN 50
#define ARTIST_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    int year;
} Music;

Music library[MAX_MUSIC];
int music_count = 0;

void add_music() {
    if (music_count >= MAX_MUSIC) {
        printf("Library is full!\n");
        return;
    }
    
    Music new_music;
    printf("Enter title: ");
    scanf(" %[^\n]", new_music.title);
    printf("Enter artist: ");
    scanf(" %[^\n]", new_music.artist);
    printf("Enter year: ");
    scanf("%d", &new_music.year);
    
    library[music_count++] = new_music;
    printf("Music added: %s - %s (%d)\n", new_music.title, new_music.artist, new_music.year);
}

void view_music() {
    if (music_count == 0) {
        printf("No music in library.\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < music_count; i++) {
        printf("%d. %s - %s (%d)\n", i + 1, library[i].title, library[i].artist, library[i].year);
    }
    printf("----------------------\n");
}

void delete_music() {
    view_music();
    if (music_count == 0) return;

    int index;
    printf("Enter music index to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > music_count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < music_count - 1; i++) {
        library[i] = library[i + 1];
    }
    music_count--;
    printf("Music deleted successfully!\n");
}

void search_music() {
    char search_term[TITLE_LEN];
    printf("Enter search term: ");
    scanf(" %[^\n]", search_term);
    
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < music_count; i++) {
        if (strstr(library[i].title, search_term) || strstr(library[i].artist, search_term)) {
            printf("%d. %s - %s (%d)\n", i + 1, library[i].title, library[i].artist, library[i].year);
        }
    }
    printf("----------------------\n");
}

void save_library() {
    FILE *file = fopen("music_library.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < music_count; i++) {
        fprintf(file, "%s|%s|%d\n", library[i].title, library[i].artist, library[i].year);
    }
    fclose(file);
    printf("Library saved successfully!\n");
}

void load_library() {
    FILE *file = fopen("music_library.txt", "r");
    if (!file) {
        printf("No saved library found.\n");
        return;
    }
    
    music_count = 0;
    while (!feof(file) && music_count < MAX_MUSIC) {
        Music new_music;
        fscanf(file, " %[^\n]|%[^\n]|%d\n", new_music.title, new_music.artist, &new_music.year);
        library[music_count++] = new_music;
    }
    fclose(file);
    printf("Library loaded successfully!\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. View Music\n");
        printf("3. Delete Music\n");
        printf("4. Search Music\n");
        printf("5. Save Library\n");
        printf("6. Load Library\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_music(); break;
            case 2: view_music(); break;
            case 3: delete_music(); break;
            case 4: search_music(); break;
            case 5: save_library(); break;
            case 6: load_library(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}