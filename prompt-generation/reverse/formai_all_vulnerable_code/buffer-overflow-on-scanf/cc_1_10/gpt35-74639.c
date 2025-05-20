//FormAI DATASET v1.0 Category: Music Library Management System ; Style: brave
#include<stdio.h>
#include<string.h>

struct musicLibrary {
    int id;
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int rating;
};

struct musicLibrary musicList[100];
int current_size = 0;

void displayMenu() {
    printf("========== WELCOME TO C MUSIC LIBRARY MANAGEMENT SYSTEM ==========\n");
    printf("1. Add a song\n");
    printf("2. Edit a song\n");
    printf("3. Delete a song\n");
    printf("4. Search by artist name\n");
    printf("5. Search by album name\n");
    printf("6. Display all songs\n");
    printf("7. Exit\n");
    printf("================================================================\n\n");
}

void addSong() {
    int id;
    printf("Enter song id: ");
    scanf("%d", &id);
    for (int i = 0; i < current_size; i++) {
        if (musicList[i].id == id) {
            printf("Song with id %d already exists!\n", id);
            return;
        }
    }
    struct musicLibrary newSong;
    newSong.id = id;
    printf("Enter song title: ");
    scanf("%s", newSong.title);
    printf("Enter artist name: ");
    scanf("%s", newSong.artist);
    printf("Enter album name: ");
    scanf("%s", newSong.album);
    printf("Enter year of release: ");
    scanf("%d", &newSong.year);
    printf("Enter song rating: ");
    scanf("%d", &newSong.rating);
    musicList[current_size++] = newSong;
    printf("Song added successfully!\n");
}

void editSong() {
    int id, found = 0;
    printf("Enter song id to edit: ");
    scanf("%d", &id);
    for (int i = 0; i < current_size; i++) {
        if (musicList[i].id == id) {
            printf("Enter new song title (or '-' to leave unchanged): ");
            char input[50];
            scanf("%s", input);
            if (strcmp(input, "-") != 0) strcpy(musicList[i].title, input);
            printf("Enter new artist name (or '-' to leave unchanged): ");
            scanf("%s", input);
            if (strcmp(input, "-") != 0) strcpy(musicList[i].artist, input);
            printf("Enter new album name (or '-' to leave unchanged): ");
            scanf("%s", input);
            if (strcmp(input, "-") != 0) strcpy(musicList[i].album, input);
            printf("Enter new year of release (or -1 to leave unchanged): ");
            int year;
            scanf("%d", &year);
            if (year != -1) musicList[i].year = year;
            printf("Enter new song rating (or -1 to leave unchanged): ");
            int rating;
            scanf("%d", &rating);
            if (rating != -1) musicList[i].rating = rating;
            printf("Song with id %d was successfully updated!\n", id);
            found = 1;
            break;
        }
    }
    if (!found) printf("Song with id %d not found!\n", id);
}

void deleteSong() {
    int id, found = 0;
    printf("Enter song id to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < current_size; i++) {
        if (musicList[i].id == id) {
            found = 1;
            for (int j = i; j < current_size - 1; j++) {
                musicList[j] = musicList[j + 1];
            }
            current_size--;
            printf("Song with id %d was successfully deleted!\n", id);
            break;
        }
    }
    if (!found) printf("Song with id %d not found!\n", id);
}

void searchByArtist() {
    char artist[50];
    printf("Enter artist name: ");
    scanf("%s", artist);
    printf("Search results:\n");
    int found = 0;
    for (int i = 0; i < current_size; i++) {
        if (strcmp(musicList[i].artist, artist) == 0) {
            printf("%d. %s - %s (%d) - Rating: %d\n", musicList[i].id, musicList[i].title, musicList[i].album, musicList[i].year, musicList[i].rating);
            found = 1;
        }
    }
    if (!found) printf("No songs found for artist '%s'!\n", artist);
}

void searchByAlbum() {
    char album[50];
    printf("Enter album name: ");
    scanf("%s", album);
    printf("Search results:\n");
    int found = 0;
    for (int i = 0; i < current_size; i++) {
        if (strcmp(musicList[i].album, album) == 0) {
            printf("%d. %s - %s (%d) - Rating: %d\n", musicList[i].id, musicList[i].title, musicList[i].artist, musicList[i].year, musicList[i].rating);
            found = 1;
        }
    }
    if (!found) printf("No songs found for album '%s'!\n", album);
}

void displayAll() {
    printf("============== ALL SONGS ==============\n");
    for (int i = 0; i < current_size; i++) {
        printf("%d. %s - %s (%d) - Rating: %d\n", musicList[i].id, musicList[i].title, musicList[i].artist, musicList[i].year, musicList[i].rating);
    }
    printf("======================================\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                editSong();
                break;
            case 3:
                deleteSong();
                break;
            case 4:
                searchByArtist();
                break;
            case 5:
                searchByAlbum();
                break;
            case 6:
                displayAll();
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while (choice != 7);
    return 0;
}