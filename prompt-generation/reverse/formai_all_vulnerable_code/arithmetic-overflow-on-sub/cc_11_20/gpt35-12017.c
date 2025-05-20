//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include<stdio.h>
#include<string.h>

struct song {
    char title[100];
    char artist[100];
    char genre[100];
    int year;
};

int main() {
    int choice;
    int i, j, k;
    int count;
    char temp[100];
    struct song temp_song;

    printf("\n************************************************************\n");
    printf("\tWELCOME TO THE C MUSIC LIBRARY MANAGEMENT SYSTEM\n");
    printf("************************************************************\n");

    printf("\nEnter number of songs in your library:");
    scanf("%d", &count);

    struct song music_library[count];

    for(i=0; i<count; i++) {
        printf("\nEnter Song %d details", i+1);
        printf("\nTitle:");
        scanf(" %s", music_library[i].title);
        printf("\nArtist:");
        scanf(" %s", music_library[i].artist);
        printf("\nGenre:");
        scanf(" %s", music_library[i].genre);
        printf("\nYear:");
        scanf("%d", &music_library[i].year);
    }

    do {
        printf("\n*************************************************\n");
        printf("\t\tMENU\n");
        printf("*************************************************\n");
        printf("\n1.Sort by Title\n2.Sort by Artist\n3.Search for Song\n4.Display Library\n0.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice) {
            case 1: //Sort by Title
                for(i=0; i<count-1; i++) {
                    for(j=i+1; j<count; j++) {
                        if(strcmp(music_library[i].title, music_library[j].title) > 0) {
                            temp_song = music_library[i];
                            music_library[i] = music_library[j];
                            music_library[j] = temp_song;
                        }
                    }
                }
                printf("\nLibrary sorted by title!");
                break;

            case 2: //Sort by Artist
                for(i=0; i<count-1; i++) {
                    for(j=i+1; j<count; j++) {
                        if(strcmp(music_library[i].artist, music_library[j].artist) > 0) {
                            temp_song = music_library[i];
                            music_library[i] = music_library[j];
                            music_library[j] = temp_song;
                        }
                    }
                }
                printf("\nLibrary sorted by artist!");
                break;

            case 3: //Search for Song
                printf("\nEnter the title of the song to search:");
                scanf(" %s", temp);

                for(i=0; i<count; i++) {
                    if(strcmp(music_library[i].title, temp) == 0) {
                        printf("\nSong found!");
                        printf("\nTitle: %s", music_library[i].title);
                        printf("\nArtist: %s", music_library[i].artist);
                        printf("\nGenre: %s", music_library[i].genre);
                        printf("\nYear: %d", music_library[i].year);
                        break;
                    }
                }
                if(i == count) {
                    printf("\nSong not found!");
                }
                break;

            case 4: //Display Library
                printf("\n****************************************************\n");
                printf("\t\tLIBRARY\n");
                printf("****************************************************\n");
                for(i=0; i<count; i++) {
                    printf("\nTitle: %s", music_library[i].title);
                    printf("\nArtist: %s", music_library[i].artist);
                    printf("\nGenre: %s", music_library[i].genre);
                    printf("\nYear: %d", music_library[i].year);
                    printf("\n");
                }
                break;

            case 0: //Exit
                printf("\nExiting program. Thank you!");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid choice.");
                break;
        }

    } while(choice != 0);

    return 0;
}