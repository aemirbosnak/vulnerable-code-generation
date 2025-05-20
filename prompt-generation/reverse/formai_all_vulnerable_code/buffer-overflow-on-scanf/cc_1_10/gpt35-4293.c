//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_SONGS 500

typedef struct {
    char title[50];
    char artist[30];
    char genre[20];
    int year_released;
    int num_songs;
    char songs[MAX_SONGS][50];
} Album;

Album albums[MAX_ALBUMS];
int num_albums = 0;

void menu();
void display_albums();
void add_album();
void remove_album();
void search_album();

int main() {
    menu();
    return 0;
}

void menu() {
    char choice;
    printf("Welcome to the Music Library Management System!\n");
    do {
        printf("\n---MENU---\n");
        printf("1. Display Albums\n");
        printf("2. Add Album\n");
        printf("3. Remove Album\n");
        printf("4. Search Album\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                display_albums();
                break;
            case '2':
                add_album();
                break;
            case '3':
                remove_album();
                break;
            case '4':
                search_album();
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != '5');
}

void display_albums() {
    if (num_albums == 0) {
        printf("No albums to display.\n");
        return;
    }
    printf("\n---ALBUMS---\n");
    for (int i = 0; i < num_albums; i++) {
        printf("%d. Title: %s\n", i+1, albums[i].title);
        printf("Artist: %s, Genre: %s\n", albums[i].artist, albums[i].genre);
        printf("Year Released: %d, Number of Songs: %d\n", albums[i].year_released, albums[i].num_songs);
        printf("Songs:\n");
        for (int j = 0; j < albums[i].num_songs; j++) {
            printf("    %d. %s\n", j+1, albums[i].songs[j]);
        }
    }
}

void add_album() {
    if (num_albums == MAX_ALBUMS) {
        printf("Maximum number of albums reached.\n");
        return;
    }
    Album new_album;
    printf("\n---ADD ALBUM---\n");
    printf("Enter Title: ");
    scanf(" %[^\n]", new_album.title);
    printf("Enter Artist: ");
    scanf(" %[^\n]", new_album.artist);
    printf("Enter Genre: ");
    scanf(" %[^\n]", new_album.genre);
    printf("Enter Year Released: ");
    scanf(" %d", &new_album.year_released);
    printf("Enter Number of Songs: ");
    scanf(" %d", &new_album.num_songs);
    printf("Enter Songs:\n");
    for (int i = 0; i < new_album.num_songs; i++) {
        scanf(" %[^\n]", new_album.songs[i]);
    }
    albums[num_albums] = new_album;
    num_albums++;
    printf("Album added successfully.\n");
}

void remove_album() {
    if (num_albums == 0) {
        printf("No albums to remove.\n");
        return;
    }
    char title[50];
    printf("\n---REMOVE ALBUM---\n");
    printf("Enter album title: ");
    scanf(" %[^\n]", title);
    int index_to_remove = -1;
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(title, albums[i].title) == 0) {
            index_to_remove = i;
            break;
        }
    }
    if (index_to_remove == -1) {
        printf("Album not found.\n");
    } else {
        for (int i = index_to_remove; i < num_albums - 1; i++) {
            albums[i] = albums[i+1];
        }
        num_albums--;
        printf("Album removed successfully.\n");
    }
}

void search_album() {
    if (num_albums == 0) {
        printf("No albums to search for.\n");
        return;
    }
    char title[50];
    printf("\n---SEARCH ALBUM---\n");
    printf("Enter album title: ");
    scanf(" %[^\n]", title);
    int index_to_display = -1;
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(title, albums[i].title) == 0) {
            index_to_display = i;
            break;
        }
    }
    if (index_to_display == -1) {
        printf("Album not found.\n");
    } else {
        printf("\n---ALBUM---\n");
        printf("Title: %s\n", albums[index_to_display].title);
        printf("Artist: %s, Genre: %s\n", albums[index_to_display].artist, albums[index_to_display].genre);
        printf("Year Released: %d, Number of Songs: %d\n", albums[index_to_display].year_released, albums[index_to_display].num_songs);
        printf("Songs:\n");
        for (int j = 0; j < albums[index_to_display].num_songs; j++) {
            printf("    %d. %s\n", j+1, albums[index_to_display].songs[j]);
        }
    }
}