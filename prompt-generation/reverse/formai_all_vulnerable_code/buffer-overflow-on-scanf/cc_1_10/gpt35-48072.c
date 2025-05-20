//FormAI DATASET v1.0 Category: Music Library Management System ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000

typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float rating;
} song;

song library[MAX_SIZE];
int num_songs = 0;

void add_song() {
    if(num_songs == MAX_SIZE) {
        printf("Library is full!\n");
        return;
    }
    song new_song;
    printf("Enter title: ");
    scanf("%s", new_song.title);
    printf("Enter artist: ");
    scanf("%s", new_song.artist);
    printf("Enter album: ");
    scanf("%s", new_song.album);
    printf("Enter year: ");
    scanf("%d", &new_song.year);
    printf("Enter rating (out of 10): ");
    scanf("%f", &new_song.rating);
    library[num_songs++] = new_song;
    printf("Song added successfully!\n");
}

void display_library() {
    if(num_songs == 0) {
        printf("Library is empty!\n");
        return;
    }
    printf("Title\tArtist\tAlbum\tYear\tRating\n");
    for(int i=0; i<num_songs; i++) {
        printf("%s\t%s\t%s\t%d\t%.1f\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].rating);
    }
}

void search_by_title() {
    char search_title[50];
    printf("Enter title to search for: ");
    scanf("%s", search_title);
    int found = 0;
    for(int i=0; i<num_songs; i++) {
        if(strcmp(search_title, library[i].title) == 0) {
            found = 1;
            printf("%s\t%s\t%s\t%d\t%.1f\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].rating);
        }
    }
    if(!found) {
        printf("Song not found!\n");
    }
}

void search_by_artist() {
    char search_artist[50];
    printf("Enter artist to search for: ");
    scanf("%s", search_artist);
    int found = 0;
    for(int i=0; i<num_songs; i++) {
        if(strcmp(search_artist, library[i].artist) == 0) {
            found = 1;
            printf("%s\t%s\t%s\t%d\t%.1f\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].rating);
        }
    }
    if(!found) {
        printf("No songs by that artist found!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add song\n");
        printf("2. Display library\n");
        printf("3. Search by title\n");
        printf("4. Search by artist\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_song();
                    break;
            case 2: display_library();
                    break;
            case 3: search_by_title();
                    break;
            case 4: search_by_artist();
                    break;
            case 5: printf("Goodbye!\n");
                    break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}