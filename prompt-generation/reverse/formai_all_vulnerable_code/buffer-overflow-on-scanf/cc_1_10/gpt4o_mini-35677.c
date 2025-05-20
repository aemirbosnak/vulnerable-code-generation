//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define TITLE_SIZE 50
#define ARTIST_SIZE 50

typedef struct {
    char title[TITLE_SIZE];
    char artist[ARTIST_SIZE];
    int year;
    char genre[TITLE_SIZE];
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
    getchar(); // consume newline
    fgets(new_music.title, TITLE_SIZE, stdin);
    new_music.title[strcspn(new_music.title, "\n")] = 0; // remove newline

    printf("Enter artist name: ");
    fgets(new_music.artist, ARTIST_SIZE, stdin);
    new_music.artist[strcspn(new_music.artist, "\n")] = 0; // remove newline

    printf("Enter release year: ");
    scanf("%d", &new_music.year);
    printf("Enter genre: ");
    getchar(); // consume newline
    fgets(new_music.genre, TITLE_SIZE, stdin);
    new_music.genre[strcspn(new_music.genre, "\n")] = 0; // remove newline

    library[music_count++] = new_music;

    printf("Music added successfully to the library!\n");
}

void display_music() {
    if (music_count == 0) {
        printf("Music library is empty!\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < music_count; i++) {
        printf("Title: %s, Artist: %s, Year: %d, Genre: %s\n",
               library[i].title, library[i].artist, library[i].year, library[i].genre);
    }
    printf("---------------------\n");
}

void search_music() {
    if (music_count == 0) {
        printf("Music library is empty!\n");
        return;
    }
    char query[TITLE_SIZE];
    printf("Enter music title to search: ");
    getchar(); // consume newline
    fgets(query, TITLE_SIZE, stdin);
    query[strcspn(query, "\n")] = 0; // remove newline

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < music_count; i++) {
        if (strstr(library[i].title, query) != NULL) {
            printf("Found: Title: %s, Artist: %s, Year: %d, Genre: %s\n",
                   library[i].title, library[i].artist, library[i].year, library[i].genre);
            found = 1;
        }
    }
    if (!found) {
        printf("No music found with the title \"%s\".\n", query);
    }
    printf("------------------------\n");
}

void delete_music() {
    if (music_count == 0) {
        printf("Music library is empty!\n");
        return;
    }
    char query[TITLE_SIZE];
    printf("Enter music title to delete: ");
    getchar(); // consume newline
    fgets(query, TITLE_SIZE, stdin);
    query[strcspn(query, "\n")] = 0; // remove newline

    for (int i = 0; i < music_count; i++) {
        if (strcmp(library[i].title, query) == 0) {
            for (int j = i; j < music_count - 1; j++) {
                library[j] = library[j + 1];
            }
            music_count--;
            printf("Music titled \"%s\" deleted successfully!\n", query);
            return;
        }
    }
    printf("No music found with the title \"%s\" to delete.\n", query);
}

void save_library() {
    FILE *file = fopen("music_library.dat", "wb");
    if (!file) {
        printf("Error saving music library!\n");
        return;
    }
    fwrite(library, sizeof(Music), music_count, file);
    fclose(file);
    printf("Music library saved successfully to 'music_library.dat'.\n");
}

void load_library() {
    FILE *file = fopen("music_library.dat", "rb");
    if (!file) {
        printf("No saved library found. Starting fresh.\n");
        return;
    }
    music_count = fread(library, sizeof(Music), MAX_MUSIC, file);
    fclose(file);
    printf("Music library loaded successfully. %d records found.\n", music_count);
}

void display_menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. Display All Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Save Library\n");
    printf("6. Load Library\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    load_library();
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_music(); break;
            case 2: display_music(); break;
            case 3: search_music(); break;
            case 4: delete_music(); break;
            case 5: save_library(); break;
            case 6: load_library(); break;
            case 7: exit(0);
            default: printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}