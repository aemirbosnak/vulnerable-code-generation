//FormAI DATASET v1.0 Category: Music Library Management System ; Style: scalable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct album {
    char name[50];
    char artist[50];
    int release_year;
    float rating;
    int num_of_tracks;
};

int num_of_albums = 0;

void add_album(struct album albums[]) {
    printf("Enter the album name: ");
    fgets(albums[num_of_albums].name, 50, stdin);

    printf("Enter the artist name: ");
    fgets(albums[num_of_albums].artist, 50, stdin);

    printf("Enter the release year: ");
    scanf("%d", &albums[num_of_albums].release_year);

    printf("Enter the rating out of 10: ");
    scanf("%f", &albums[num_of_albums].rating);

    printf("Enter the number of tracks: ");
    scanf("%d", &albums[num_of_albums].num_of_tracks);

    num_of_albums++;
}

void display_album(struct album album) {
    printf("Album Name: %s", album.name);
    printf("Artist Name: %s", album.artist);
    printf("Release Year: %d\n", album.release_year);
    printf("Rating: %.1f/10\n", album.rating);
    printf("Number of Tracks: %d\n", album.num_of_tracks);
}

void display_all_albums(struct album albums[]) {
    printf("-----------------------------------------\n");
    for(int i=0; i<num_of_albums; i++) {
        display_album(albums[i]);
        printf("-----------------------------------------\n");
    }
}

void search_albums(struct album albums[]) {
    char search_term[50];
    int found = 0;

    printf("Enter the album or artist name to search: ");
    fgets(search_term, 50, stdin);

    for(int i=0; i<num_of_albums; i++) {
        if(strstr(albums[i].name, search_term) != NULL || strstr(albums[i].artist, search_term) != NULL) {
            display_album(albums[i]);
            printf("-----------------------------------------\n");
            found = 1;
        }
    }

    if(found == 0) {
        printf("No albums found.\n");
    }
}

int main() {
    struct album albums[100];
    int choice;

    do {
        printf("*************** Music Library Management System ***************\n");
        printf("1. Add an album\n");
        printf("2. Display all albums\n");
        printf("3. Search for albums\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        getchar(); // To get rid of \n character in the buffer
        switch(choice) {
            case 1:
                add_album(albums);
                break;
            case 2:
                display_all_albums(albums);
                break;
            case 3:
                search_albums(albums);
                break;
            case 0:
                printf("Thank you for using Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);

    return 0;
}