//FormAI DATASET v1.0 Category: Music Library Management System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct MusicLibrary{
    char title[50];
    char artist[50];
    int year;
} MusicLibrary;

MusicLibrary library[5];
int numberOfTracks = 0;

void addTrack(){
    if(numberOfTracks>=5){
        printf("Cannot add more than 5 tracks\n");
        return;
    }
    printf("Enter the track title: ");
    fflush(stdin);
    fgets(library[numberOfTracks].title, sizeof(library[numberOfTracks].title), stdin);
    printf("Enter the track artist: ");
    fflush(stdin);
    fgets(library[numberOfTracks].artist, sizeof(library[numberOfTracks].artist), stdin);
    printf("Enter the track year: ");
    scanf("%d", &library[numberOfTracks].year);
    numberOfTracks++;
}

void displayTracks(){
    if(numberOfTracks==0){
        printf("No tracks in the library\n");
        return;
    }
    printf("\nTitle\t\tArtist\t\tYear\n");
    for(int i=0;i<numberOfTracks;i++){
        printf("%s\t\t%s\t\t%d\n", library[i].title, library[i].artist, library[i].year);
    }
}

void searchTrack(){
    if(numberOfTracks==0){
        printf("No tracks in the library\n");
        return;
    }
    int year, flag=0;
    char artist[50];
    printf("Enter the track artist to search: ");
    fflush(stdin);
    fgets(artist, sizeof(artist), stdin);
    printf("Enter the track year to search: ");
    scanf("%d", &year);
    for(int i=0;i<numberOfTracks;i++){
        if(strcmp(library[i].artist, artist)==0 && library[i].year==year){
            printf("Track found\nTitle: %sArtist: %sYear: %d\n", library[i].title, library[i].artist, library[i].year);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("No match found\n");
    }
}

int main(){
    int choice;
    char temp[10];
    
    while(1){
        printf("\n\nMusic Library Management System\n\n");
        printf("1. Add Track\n2. Display Tracks\n3. Search Track\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addTrack();
                break;
            case 2:
                displayTracks();
                break;
            case 3:
                searchTrack();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("Press any key to continue...");
        fflush(stdin);
        fgets(temp, sizeof(temp), stdin);
    }
    return 0;
}