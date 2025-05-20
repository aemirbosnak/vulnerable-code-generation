//FormAI DATASET v1.0 Category: Music Library Management System ; Style: happy
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SONGS 100

//Defining song structure
struct song{
    char title[50];
    char artist[50];
    char genre[20];
    float duration;
};

//Initialising the library with some sample songs
struct song library[MAX_SONGS] ={
    {"Shape of You", "Ed Sheeran", "Pop", 4.23},
    {"Blinding Lights", "The Weeknd", "R&B", 3.20},
    {"Bad Guy", "Billie Eilish", "Pop", 3.15},
    {"Don't Start Now", "Dua Lipa", "Pop", 3.03},
    {"Circles", "Post Malone", "Rap", 3.35},
    {"Lose You To Love Me", "Selena Gomez", "Pop", 3.26}
};

int num_songs = 6; //Number of songs in the library

//Function to add new song to the library
void add_song(){
    if(num_songs == MAX_SONGS){
        printf("\nLibrary is full! Cannot add more songs.\n");
        return;
    }
    printf("\nEnter song title: ");
    scanf("%s", library[num_songs].title);
    printf("Enter artist name: ");
    scanf("%s", library[num_songs].artist);
    printf("Enter song genre: ");
    scanf("%s", library[num_songs].genre);
    printf("Enter song duration: ");
    scanf("%f", &library[num_songs].duration);
    num_songs++;
    printf("\nSong added successfully to the library!\n");
}

//Function to display all the songs in the library
void display_songs(){
    printf("\n*** Library Contents ***\n\n");
    printf("Title\t\tArtist\t\tGenre\t\tDuration\n");
    for(int i=0;i<num_songs;i++){
        printf("%s\t%s\t%s\t%.2f\n", library[i].title, library[i].artist, library[i].genre, library[i].duration);
    }
    printf("\n");
}

//Function to search for a song by title
void search_song(){
    char title[50];
    printf("\nEnter song title to search: ");
    scanf("%s", title);
    int found = 0;
    for(int i=0;i<num_songs;i++){
        if(strcmp(title, library[i].title)==0){
            printf("\n*** Song Found! ***\n\n");
            printf("Title\t\tArtist\t\tGenre\t\tDuration\n");
            printf("%s\t%s\t%s\t%.2f\n", library[i].title, library[i].artist, library[i].genre, library[i].duration);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nSong not found in the library.\n");
    }
}

//Main function
int main(){
    printf("**** Welcome to the Happy Music Library Management System! ****\n\n");
    int choice;
    while(1){
        printf("Select an option:\n");
        printf("1. Add new song\n");
        printf("2. Display all songs\n");
        printf("3. Search for a song by title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_song();
                    break;
            case 2: display_songs();
                    break;
            case 3: search_song();
                    break;
            case 4: printf("\nThank you for using the Happy Music Library Management System!\n");
                    exit(0);
            default: printf("\nInvalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}