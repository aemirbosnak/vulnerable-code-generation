//FormAI DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <string.h>
#define MAX 100

struct song{
    int id;
    char title[MAX];
    char artist[MAX];
    char album[MAX];
};

//Function to add a song to the library
void addSong(struct song arr[], int *size){
    struct song s;
    printf("Enter song ID: ");
    scanf("%d", &s.id);
    printf("Enter song title: ");
    scanf("%s", s.title);
    printf("Enter song artist: ");
    scanf("%s", s.artist);
    printf("Enter song album: ");
    scanf("%s", s.album);
    arr[*size] = s;
    (*size)++;
    printf("Song added successfully!\n");
}

//Function to search for a specific song in the library
void searchSong(struct song arr[], int size){
    int id;
    printf("Enter song ID to search for: ");
    scanf("%d", &id);
    for(int i=0; i<size; i++){
        if(arr[i].id == id){
            printf("Song found!\nTitle: %s\nArtist: %s\nAlbum: %s\n", arr[i].title, arr[i].artist, arr[i].album);
            return;
        }
    }
    printf("Song not found!\n");
}

//Function to display all songs in the library
void displayAllSongs(struct song arr[], int size){
    printf("ID\tTitle\t\t\t\tArtist\t\t\t\tAlbum\n");
    printf("----------------------------------------------------------------------------\n");
    for(int i=0; i<size; i++){
        printf("%d\t%-30s\t%-30s\t%-30s\n", arr[i].id, arr[i].title, arr[i].artist, arr[i].album);
    }
    printf("----------------------------------------------------------------------------\n");
}

int main(){
    struct song library[MAX];
    int size=0, choice;
    do{
        printf("\n");
        printf("Music Library Management System\n");
        printf("1. Add a song to the library\n");
        printf("2. Search for a song in the library\n");
        printf("3. Display all songs in the library\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addSong(library, &size);
                break;
            case 2:
                searchSong(library, size);
                break;
            case 3:
                displayAllSongs(library, size);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 4);
    return 0;
}