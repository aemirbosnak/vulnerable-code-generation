//FormAI DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Song {
    char title[MAX];
    char artist[MAX];
    char album[MAX];
    char genre[MAX];
};

int main() {
    struct Song library[MAX];
    int menuChoice, numSongs=0;

    do {
        printf("\n------------ MUSIC LIBRARY MANAGEMENT SYSTEM ------------\n");
        printf("1 - Add a song\n");
        printf("2 - Remove a song\n");
        printf("3 - View all songs\n");
        printf("4 - Search songs\n");
        printf("5 - Quit\n");
        printf("---------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        switch(menuChoice) {
            case 1:
                if(numSongs == MAX) {
                    printf("The music library is full. You cannot add more songs.\n");
                } else {
                    printf("Enter the title of the song: ");
                    scanf(" %[^\n]s", library[numSongs].title);

                    printf("Enter the name of the artist: ");
                    scanf(" %[^\n]s", library[numSongs].artist);

                    printf("Enter the name of the album: ");
                    scanf(" %[^\n]s", library[numSongs].album);

                    printf("Enter the genre of the song: ");
                    scanf(" %[^\n]s", library[numSongs].genre);

                    numSongs++;
                    printf("The song has been added.\n");
                }
                break;

            case 2:
                if(numSongs == 0) {
                    printf("The music library is empty. There is no song to remove.\n");
                } else {
                    int songIndex, i;

                    printf("Which song do you want to remove? (Enter the song index number): ");
                    scanf("%d", &songIndex);

                    if(songIndex > numSongs || songIndex < 1) {
                        printf("Invalid song index. Please enter a valid index number.\n");
                        break;
                    }

                    songIndex--;
                    for(i = songIndex; i < numSongs-1; i++) {
                        library[i] = library[i+1];
                    }

                    numSongs--;
                    printf("The song has been removed.\n");
                }
                break;

            case 3:
                if(numSongs == 0) {
                    printf("The music library is empty. There is no song to show.\n");
                } else {
                    int i;

                    printf("\n----------------------------------------------\n");
                    printf("| %-3s | %-30s | %-20s | %-20s |\n", "No", "Title", "Artist", "Album");
                    printf("----------------------------------------------\n");

                    for(i = 0; i < numSongs; i++) {
                        printf("| %-3d | %-30s | %-20s | %-20s |\n", i+1, library[i].title, library[i].artist, library[i].album);
                    }

                    printf("----------------------------------------------\n");
                }
                break;

            case 4:
                if(numSongs == 0) {
                    printf("The music library is empty. There is no song to search.\n");
                } else {
                    char keyword[MAX];

                    printf("Enter the keyword you want to search: ");
                    scanf(" %[^\n]s", keyword);

                    int i;

                    printf("\n----------------------------------------------\n");
                    printf("| %-3s | %-30s | %-20s | %-20s |\n", "No", "Title", "Artist", "Album");
                    printf("----------------------------------------------\n");

                    for(i=0; i<numSongs; i++) {
                        if((strstr(library[i].title, keyword) != NULL) || (strstr(library[i].artist, keyword) != NULL) || (strstr(library[i].album, keyword) != NULL) || (strstr(library[i].genre, keyword) != NULL)) {
                            printf("| %-3d | %-30s | %-20s | %-20s |\n", i+1, library[i].title, library[i].artist, library[i].album);
                        }
                    }

                    printf("----------------------------------------------\n");
                }
                break;

            case 5:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid choice number.\n");
                break;
        }

    } while(menuChoice != 5);

    return 0;
}