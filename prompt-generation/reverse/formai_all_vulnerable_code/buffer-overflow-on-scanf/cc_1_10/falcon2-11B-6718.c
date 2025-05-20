//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_TRACKS 100
#define MAX_ARTISTS 100
#define MAX_TITLES 100
#define MAX_GENRES 10
#define MAX_COPIES 10
int main() {
    int num_tracks, num_artists, num_titles, num_genres, num_copies;
    char artist_name[MAX_ARTISTS][MAX_TITLES+1];
    char title_name[MAX_TITLES][MAX_TITLES+1];
    char genre_name[MAX_GENRES][MAX_GENRES+1];
    char copy_name[MAX_COPIES][MAX_COPIES+1];
    char track_number[MAX_TRACKS+1];
    char command;
    do {
        printf("Welcome to the Music Library Manager!\n");
        printf("What would you like to do? (add/delete/update/play/exit)\n");
        scanf(" %c", &command);
        switch(tolower(command)) {
            case 'a':
                printf("Enter the artist name: ");
                scanf("%s", artist_name[num_artists]);
                printf("Enter the title name: ");
                scanf("%s", title_name[num_titles]);
                printf("Enter the genre name: ");
                scanf("%s", genre_name[num_genres]);
                printf("Enter the copy name: ");
                scanf("%s", copy_name[num_copies]);
                printf("Enter the track number: ");
                scanf("%s", track_number);
                num_tracks++;
                num_artists++;
                num_titles++;
                num_genres++;
                num_copies++;
                break;
            case 'd':
                printf("Enter the artist name: ");
                scanf("%s", artist_name[num_artists]);
                printf("Enter the title name: ");
                scanf("%s", title_name[num_titles]);
                printf("Enter the genre name: ");
                scanf("%s", genre_name[num_genres]);
                printf("Enter the copy name: ");
                scanf("%s", copy_name[num_copies]);
                printf("Enter the track number: ");
                scanf("%s", track_number);
                num_tracks--;
                num_artists--;
                num_titles--;
                num_genres--;
                num_copies--;
                break;
            case 'u':
                printf("Enter the artist name: ");
                scanf("%s", artist_name[num_artists]);
                printf("Enter the title name: ");
                scanf("%s", title_name[num_titles]);
                printf("Enter the genre name: ");
                scanf("%s", genre_name[num_genres]);
                printf("Enter the copy name: ");
                scanf("%s", copy_name[num_copies]);
                printf("Enter the track number: ");
                scanf("%s", track_number);
                printf("Enter the new artist name: ");
                scanf("%s", artist_name[num_artists]);
                printf("Enter the new title name: ");
                scanf("%s", title_name[num_titles]);
                printf("Enter the new genre name: ");
                scanf("%s", genre_name[num_genres]);
                printf("Enter the new copy name: ");
                scanf("%s", copy_name[num_copies]);
                printf("Enter the new track number: ");
                scanf("%s", track_number);
                num_tracks++;
                num_artists++;
                num_titles++;
                num_genres++;
                num_copies++;
                break;
            case 'p':
                printf("Enter the artist name: ");
                scanf("%s", artist_name[num_artists]);
                printf("Enter the title name: ");
                scanf("%s", title_name[num_titles]);
                printf("Enter the genre name: ");
                scanf("%s", genre_name[num_genres]);
                printf("Enter the copy name: ");
                scanf("%s", copy_name[num_copies]);
                printf("Enter the track number: ");
                scanf("%s", track_number);
                printf("Playing track %s by %s in genre %s on copy %s\n", track_number, artist_name[num_artists], genre_name[num_genres], copy_name[num_copies]);
                break;
            case 'e':
                printf("Thank you for using the Music Library Manager!\n");
                break;
            default:
                printf("Invalid command\n");
        }
    } while(tolower(command)!= 'e');
    return 0;
}