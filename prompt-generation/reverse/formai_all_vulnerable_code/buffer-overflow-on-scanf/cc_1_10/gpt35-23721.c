//FormAI DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    int id;
    char title[30];
    char artist[30];
    char genre[30];
    int rating;
};

void displaySongs(struct Song** songs, int songCount);
int addSong(struct Song** songs, int songCount, int id, char* title, char* artist, char* genre, int rating);
void searchByArtist(struct Song** songs, int songCount, char* artist);
void searchByGenre(struct Song** songs, int songCount, char* genre);
void editSong(struct Song** songs, int songCount, int id, char* title, char* artist, char* genre, int rating);
void deleteSong(struct Song** songs, int* songCount, int id);

int main() {
    struct Song** songs = malloc(sizeof(struct Song*));
    int songCount = 0;
    int option;
    int id, rating;
    char title[30], artist[30], genre[30];

    do {
        printf("\n\n--- C MUSIC LIBRARY MANAGEMENT SYSTEM ---\n\n");
        printf("1. Display all songs\n");
        printf("2. Add new song\n");
        printf("3. Search by artist\n");
        printf("4. Search by genre\n");
        printf("5. Edit a song\n");
        printf("6. Delete a song\n");
        printf("7. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: // Display all songs
                displaySongs(songs, songCount);
                break;
            case 2: // Add new song
                printf("--- Add New Song ---\n");
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter artist: ");
                scanf("%s", artist);
                printf("Enter genre: ");
                scanf("%s", genre);
                printf("Enter rating (1 - 5): ");
                scanf("%d", &rating);

                songCount = addSong(songs, songCount, id, title, artist, genre, rating);

                printf("\nSong added successfully!\n");
                break;
            case 3: // Search by artist
                printf("--- Search by Artist ---\n");
                printf("Enter artist name: ");
                scanf("%s", artist);

                searchByArtist(songs, songCount, artist);
                break;
            case 4: // Search by genre
                printf("--- Search by Genre ---\n");
                printf("Enter genre: ");
                scanf("%s", genre);

                searchByGenre(songs, songCount, genre);
                break;
            case 5: // Edit a song
                printf("--- Edit a Song ---\n");
                printf("Enter ID of song to edit: ");
                scanf("%d", &id);
                printf("Enter new title: ");
                scanf("%s", title);
                printf("Enter new artist: ");
                scanf("%s", artist);
                printf("Enter new genre: ");
                scanf("%s", genre);
                printf("Enter new rating (1 - 5): ");
                scanf("%d", &rating);

                editSong(songs, songCount, id, title, artist, genre, rating);

                printf("\nSong edited successfully!\n");
                break;
            case 6: // Delete a song
                printf("--- Delete a Song ---\n");
                printf("Enter ID of song to delete: ");
                scanf("%d", &id);

                deleteSong(songs, &songCount, id);

                printf("\nSong deleted successfully!\n");
                break;
            case 7: // Exit
                printf("\nThank you for using C Music Library Management System!\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }

    } while(option != 7);

    free(songs);

    return 0;
}

void displaySongs(struct Song** songs, int songCount) {
    if(songCount == 0) {
        printf("\nNo songs to display!\n");
        return;
    }

    printf("\nID\tTitle\t\t\tArtist\t\t\tGenre\t\t\tRating\n");
    printf("--------------------------------------------------------------------------------------\n");

    for(int i = 0; i < songCount; i++) {
        printf("%d.\t%s\t\t\t%s\t\t\t%s\t\t\t%d\n", songs[i]->id, songs[i]->title, songs[i]->artist, songs[i]->genre, songs[i]->rating);
    }
}

int addSong(struct Song** songs, int songCount, int id, char* title, char* artist, char* genre, int rating) {
    songs = realloc(songs, (songCount + 1) * sizeof(struct Song*));

    songs[songCount] = malloc(sizeof(struct Song));

    songs[songCount]->id = id;
    strcpy(songs[songCount]->title, title);
    strcpy(songs[songCount]->artist, artist);
    strcpy(songs[songCount]->genre, genre);
    songs[songCount]->rating = rating;

    return ++songCount;
}

void searchByArtist(struct Song** songs, int songCount, char* artist) {
    int count = 0;

    for(int i = 0; i < songCount; i++) {
        if(strcmp(songs[i]->artist, artist) == 0) {
            printf("%d.\t%s\t\t\t%s\t\t\t%s\t\t\t%d\n", songs[i]->id, songs[i]->title, songs[i]->artist, songs[i]->genre, songs[i]->rating);
            count++;
        }
    }

    if(count == 0) {
        printf("No songs found with artist %s!\n", artist);
    }
}

void searchByGenre(struct Song** songs, int songCount, char* genre) {
    int count = 0;

    for(int i = 0; i < songCount; i++) {
        if(strcmp(songs[i]->genre, genre) == 0) {
            printf("%d.\t%s\t\t\t%s\t\t\t%s\t\t\t%d\n", songs[i]->id, songs[i]->title, songs[i]->artist, songs[i]->genre, songs[i]->rating);
            count++;
        }
    }

    if(count == 0) {
        printf("No songs found with genre %s!\n", genre);
    }
}

void editSong(struct Song** songs, int songCount, int id, char* title, char* artist, char* genre, int rating) {
    for(int i = 0; i < songCount; i++) {
        if(songs[i]->id == id) {
            strcpy(songs[i]->title, title);
            strcpy(songs[i]->artist, artist);
            strcpy(songs[i]->genre, genre);
            songs[i]->rating = rating;
            break;
        }
    }
}

void deleteSong(struct Song** songs, int* songCount, int id) {
    for(int i = 0; i < *songCount; i++) {
        if(songs[i]->id == id) {
            free(songs[i]);
            for(int j = i; j < *songCount - 1; j++) {
                songs[j] = songs[j+1];
            }
            (*songCount)--;
            break;
        }
    }
}