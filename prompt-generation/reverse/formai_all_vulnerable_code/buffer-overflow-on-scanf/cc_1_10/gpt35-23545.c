//FormAI DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct Music {
    char songName[50];
    char artist[50];
    char album[50];
    int year;
    char genre[20];
    int rating;
} Music;
 
void addMusic(Music *library, int *numSongs) {
    int index = *numSongs;
    printf("Enter the title of the song: ");
    scanf("%s", library[index].songName);
    printf("Enter the artist's name: ");
    scanf("%s", library[index].artist);
    printf("Enter the album name: ");
    scanf("%s", library[index].album);
    printf("Enter the year of release (YYYY): ");
    scanf("%d", &library[index].year);
    printf("Enter the genre: ");
    scanf("%s", library[index].genre);
    printf("Enter the rating (1-10): ");
    scanf("%d", &library[index].rating);
    (*numSongs)++;
    printf("Song added to library successfully!\n\n");
}
 
void displayMusic(Music *library, int numSongs) {
    printf("---------------\n");
    printf("|   Library   |\n");
    printf("---------------\n");
    printf("Title\tArtist\tAlbum\tYear\tGenre\tRating\n");
    for(int i=0; i<numSongs; i++) {
        printf("%s\t%s\t%s\t%d\t%s\t%d\n", library[i].songName, library[i].artist, library[i].album, library[i].year, library[i].genre, library[i].rating);
    }
    printf("\n");
}
 
int main() {
    Music *library = malloc(sizeof(Music)*100);
    int numSongs = 0;
    int choice;
    while(1) {
        printf("---------------\n");
        printf("|   Options   |\n");
        printf("---------------\n");
        printf("1. Add Music\n");
        printf("2. Display Music Library\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMusic(library, &numSongs);
                break;
            case 2:
                displayMusic(library, numSongs);
                break;
            case 3:
                printf("Exiting music library management system. Goodbye!\n");
                free(library);
                return 0;
            default:
                printf("Invalid choice entered. Please try again.\n\n");
                break;
        }
    }
    return 0;
}