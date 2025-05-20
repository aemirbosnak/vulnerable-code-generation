//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining struct for the song
struct Song{
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

// Defining function to add a song
void addSong(struct Song* songs, int* count){
    printf("Enter Song Title: ");
    scanf("%s", songs[*count].title);
    printf("Enter Artist Name: ");
    scanf("%s", songs[*count].artist);
    printf("Enter Album Name: ");
    scanf("%s", songs[*count].album);
    printf("Enter Release Year: ");
    scanf("%d", &songs[*count].year);
    (*count)++; // increase count of songs
    printf("Song Added Successfully\n\n");
}

// Defining function to search a song by title
void searchSong(struct Song* songs, int count){
    char title[100];
    printf("Enter Song Title: ");
    scanf("%s", title);
    int flag = 0; // flag is introduced to track if any match was found or not
    for(int i=0; i<count; i++){
        if(strcmp(songs[i].title, title) == 0){
            printf("Title: %s | Artist: %s | Album: %s | Year: %d\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
            flag = 1; // update flag if match found
        }
    }
    if(flag == 0){
        printf("No Match Found\n\n");
    }else{
        printf("\n");
    }
}

// Defining function to delete a song by title
void deleteSong(struct Song* songs, int* count){
    char title[100];
    printf("Enter Song Title: ");
    scanf("%s", title);
    int flag = 0;
    for(int i=0; i<*count; i++){
        if(strcmp(songs[i].title, title) == 0){
            for(int j=i; j<*count-1; j++){ // shift all the elements to left after the deleted song
                songs[j] = songs[j+1];
            }
            (*count)--; // decrease count of songs
            flag = 1; // update flag if match found
            printf("Song Deleted Successfully\n\n");
            break; // break loop once song is deleted
        }
    }
    if(flag == 0){
        printf("No Match Found\n\n");
    }
}

// Defining function to display all the songs
void displaySongs(struct Song* songs, int count){
    if(count == 0){
        printf("No Songs Found\n\n");
    }else{
        printf("All Songs:\n");
        for(int i=0; i<count; i++){
            printf("Title: %s | Artist: %s | Album: %s | Year: %d\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
        }
        printf("\n");
    }
}

// Main function
int main(){
    struct Song songs[100];
    int count = 0;
    int choice;
    do{
        printf("Music Library Management System \n");
        printf("1. Add Song\n");
        printf("2. Search Song\n");
        printf("3. Delete Song\n");
        printf("4. Display All Songs\n");
        printf("5. Quit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addSong(songs, &count);
                break;
            case 2:
                searchSong(songs, count);
                break;
            case 3:
                deleteSong(songs, &count);
                break;
            case 4:
                displaySongs(songs, count);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice\n\n");
        }
    }while(choice != 5);
    return 0;
}