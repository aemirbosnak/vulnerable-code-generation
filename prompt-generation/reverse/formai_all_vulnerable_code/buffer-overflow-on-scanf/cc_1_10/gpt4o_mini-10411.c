//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_NAME 50

typedef struct {
    char title[MAX_NAME];
    char artist[MAX_NAME];
    int year;
    char genre[MAX_NAME];
} Music;

Music library[MAX_MUSIC];
int count = 0;

void addMusic();
void viewMusic();
void searchMusic();
void deleteMusic();
void displayMenu();

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline character

        switch (choice) {
            case 1: addMusic(); break;
            case 2: viewMusic(); break;
            case 3: searchMusic(); break;
            case 4: deleteMusic(); break;
            case 5: printf("Exiting the Music Library Management System...\n"); break;
            default: printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. View Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Exit\n");
}

void addMusic() {
    if (count >= MAX_MUSIC) {
        printf("Music library is full. Can't add more music!\n");
        return;
    }
    
    Music new_music;
    printf("Enter title: ");
    fgets(new_music.title, MAX_NAME, stdin);
    new_music.title[strcspn(new_music.title, "\n")] = 0; // remove newline
    printf("Enter artist: ");
    fgets(new_music.artist, MAX_NAME, stdin);
    new_music.artist[strcspn(new_music.artist, "\n")] = 0; // remove newline
    printf("Enter year: ");
    scanf("%d", &new_music.year);
    getchar();  // consume newline character
    printf("Enter genre: ");
    fgets(new_music.genre, MAX_NAME, stdin);
    new_music.genre[strcspn(new_music.genre, "\n")] = 0; // remove newline

    library[count] = new_music;
    count++;
    printf("Music added successfully!\n");
}

void viewMusic() {
    if (count == 0) {
        printf("No music in the library yet.\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < count; i++) {
        printf("Music %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Year: %d\n", library[i].year);
        printf("Genre: %s\n\n", library[i].genre);
    }
}

void searchMusic() {
    if (count == 0) {
        printf("No music in the library to search!\n");
        return;
    }
    
    char search_title[MAX_NAME];
    printf("Enter title to search: ");
    fgets(search_title, MAX_NAME, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            printf("Music found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Genre: %s\n", library[i].genre);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No music found with the title \"%s\".\n", search_title);
    }
}

void deleteMusic() {
    if (count == 0) {
        printf("No music to delete!\n");
        return;
    }
    
    char delete_title[MAX_NAME];
    printf("Enter title to delete: ");
    fgets(delete_title, MAX_NAME, stdin);
    delete_title[strcspn(delete_title, "\n")] = 0; // remove newline

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(library[i].title, delete_title) == 0) {
            break;
        }
    }

    if (i < count) {
        for (int j = i; j < count - 1; j++) {
            library[j] = library[j + 1];
        }
        count--;
        printf("Music \"%s\" deleted successfully!\n", delete_title);
    } else {
        printf("No music found with the title \"%s\" to delete.\n", delete_title);
    }
}