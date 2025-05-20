//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int year;
    float price;
} Song;

void addSong(Song *song) {
    song->price = (rand() % 100) + 1;
    printf("Added song: %s (%d) - $%.2f\n", song->name, song->year, song->price);
}

void removeSong(Song *song) {
    printf("Removed song: %s (%d) - $%.2f\n", song->name, song->year, song->price);
}

void updatePrice(Song *song) {
    song->price *= 1.05;
    printf("Updated price for song: %s (%d) - $%.2f\n", song->name, song->year, song->price);
}

int main() {
    Song songs[10];
    int choice, song_id;

    printf("Welcome to the C Music Library Management System!\n");
    printf("Choose an option:\n");
    printf("1. Add a song\n");
    printf("2. Remove a song\n");
    printf("3. Update the price of a song\n");
    printf("4. Display all songs\n");
    printf("5. Quit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the song: ");
                scanf("%s", songs[song_id].name);
                printf("Enter the year the song was released: ");
                scanf("%d", &songs[song_id].year);
                printf("Enter the price of the song: ");
                scanf("%f", &songs[song_id].price);
                addSong(&songs[song_id]);
                break;
            case 2:
                printf("Enter the ID of the song to remove: ");
                scanf("%d", &song_id);
                removeSong(&songs[song_id]);
                break;
            case 3:
                printf("Enter the ID of the song to update: ");
                scanf("%d", &song_id);
                updatePrice(&songs[song_id]);
                break;
            case 4:
                printf("Displaying all songs:\n");
                for (int i = 0; i < 10; i++) {
                    printf("ID: %d - Name: %s (%d) - Price: $%.2f\n", i, songs[i].name, songs[i].year, songs[i].price);
                }
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}