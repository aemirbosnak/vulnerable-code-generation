//FormAI DATASET v1.0 Category: Music Library Management System ; Style: expert-level
/* A Music Library Management System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 20
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_GENRE_LEN 20

/* Create a song struct */
struct Song {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char genre[MAX_GENRE_LEN];
    int year;
};

int main() {
    int choice;
    int numSongs = 0;
    struct Song songs[MAX_SONGS];

    while(1) {
        printf("\nMusic Library Management System");
        printf("\n------------------------------");
        printf("\n1. Add a Song");
        printf("\n2. List all Songs");
        printf("\n3. Search for a Song");
        printf("\n4. Delete a Song");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: /* Add a song */
                if(numSongs == MAX_SONGS)
                    printf("\nMusic library is full!");
                else {
                    printf("\nEnter song name: ");
                    scanf("%s", songs[numSongs].name);
                    printf("Enter artist name: ");
                    scanf("%s", songs[numSongs].artist);
                    printf("Enter genre: ");
                    scanf("%s", songs[numSongs].genre);
                    printf("Enter year released: ");
                    scanf("%d", &songs[numSongs].year);
                    numSongs++;
                    printf("%s added to music library!", songs[numSongs-1].name);
                }
                break;
            case 2: /* List all songs */
                if(numSongs == 0)
                    printf("\nMusic library is empty!");
                else {
                    printf("\n%-30s %-20s %-20s %s", "Song Name", "Artist", "Genre", "Year");
                    printf("\n--------------------------------------------------------------------");
                    for(int i = 0; i < numSongs; i++) {
                        printf("\n%-30s %-20s %-20s %d", songs[i].name, songs[i].artist, songs[i].genre, songs[i].year);
                    }
                }
                break;
            case 3: /* Search for a song */
                if(numSongs == 0)
                    printf("\nMusic library is empty!");
                else {
                    char searchName[MAX_NAME_LEN];
                    int found = 0;
                    printf("\nEnter song name to search: ");
                    scanf("%s", searchName);
                    for(int i = 0; i < numSongs; i++) {
                        if(strcmp(searchName, songs[i].name) == 0) {
                            printf("\n%-30s %-20s %-20s %s", "Song Name", "Artist", "Genre", "Year");
                            printf("\n--------------------------------------------------------------------");
                            printf("\n%-30s %-20s %-20s %d", songs[i].name, songs[i].artist, songs[i].genre, songs[i].year);
                            found = 1;
                            break;
                        }
                    }
                    if(!found)
                        printf("%s not found in music library!", searchName);
                }
                break;
            case 4: /* Delete a song */
                if(numSongs == 0)
                    printf("\nMusic library is empty!");
                else {
                    char delName[MAX_NAME_LEN];
                    int found = 0;
                    printf("\nEnter song name to delete: ");
                    scanf("%s", delName);
                    for(int i = 0; i < numSongs; i++) {
                        if(strcmp(delName, songs[i].name) == 0) {
                            found = 1;
                            for(int j = i; j < numSongs - 1; j++) {
                                strcpy(songs[j].name, songs[j+1].name);
                                strcpy(songs[j].artist, songs[j+1].artist);
                                strcpy(songs[j].genre, songs[j+1].genre);
                                songs[j].year = songs[j+1].year;
                            }
                            numSongs--;
                            printf("%s deleted from music library!", delName);
                            break;
                        }
                    }
                    if(!found)
                        printf("%s not found in music library!", delName);
                }
                break;
            case 5: /* Exit */
                exit(0);
            default:
                printf("\nInvalid choice. Try Again!");
                break;    
        }
    }
    return 0;
}