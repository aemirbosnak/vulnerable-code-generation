//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

int main() {
    int choice, i, count=0, year;
    char title[50], artist[50], album[50];
    struct Music musicList[100];
    
    printf("*********************************************************\n");
    printf("*              Welcome to C Music Library!              *\n");
    printf("*********************************************************\n");

    do {
        printf("\n1. Add a new song");
        printf("\n2. Display all songs");
        printf("\n3. Search by year");
        printf("\n4. Search by artist");
        printf("\n5. Quit");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter song title: ");
                scanf("%s", title);
                printf("Enter artist name: ");
                scanf("%s", artist);
                printf("Enter album name: ");
                scanf("%s", album);
                printf("Enter release year: ");
                scanf("%d", &year);
                
                struct Music newSong;
                strcpy(newSong.title, title);
                strcpy(newSong.artist, artist);
                strcpy(newSong.album, album);
                newSong.year = year;

                musicList[count] = newSong;
                count++;
                printf("\nNew song added successfully!\n");
                break;
            case 2:
                if(count == 0) {
                    printf("\nNo songs found.\n");
                    break;
                }
                printf("\nTitle\t\tArtist\t\tAlbum\t\tYear\n");
                for(i=0; i<count; i++) {
                    printf("%s\t\t%s\t\t%s\t\t%d\n", musicList[i].title, musicList[i].artist, musicList[i].album, musicList[i].year);
                }
                break;
            case 3:
                printf("\nEnter year: ");
                scanf("%d", &year);
                printf("\nTitle\t\tArtist\t\tAlbum\t\tYear\n");
                for(i=0; i<count; i++) {
                    if(musicList[i].year == year) {
                        printf("%s\t\t%s\t\t%s\t\t%d\n", musicList[i].title, musicList[i].artist, musicList[i].album, musicList[i].year);
                    }
                }
                break;
            case 4:
                printf("\nEnter artist name: ");
                scanf("%s", artist);
                printf("\nTitle\t\tArtist\t\tAlbum\t\tYear\n");
                for(i=0; i<count; i++) {
                    if(strcmp(musicList[i].artist, artist) == 0) {
                        printf("%s\t\t%s\t\t%s\t\t%d\n", musicList[i].title, musicList[i].artist, musicList[i].album, musicList[i].year);
                    }
                }
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 5);
    
    return 0;
}