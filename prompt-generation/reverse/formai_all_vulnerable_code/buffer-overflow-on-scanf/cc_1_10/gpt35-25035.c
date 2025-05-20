//FormAI DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining Structure for Songs
typedef struct song{
    char title[50];
    char artist[50];
    char album[50];
    int year;
}song;

//Function to Add Song to Library
void add_song(song *lib, int *num_song){
    printf("Enter the details of the song:\nTitle: ");
    scanf(" %[^\n]%*c", lib[*num_song].title);
    printf("Artist: ");
    scanf(" %[^\n]%*c", lib[*num_song].artist);
    printf("Album: ");
    scanf(" %[^\n]%*c", lib[*num_song].album);
    printf("Year of Release: ");
    scanf("%d", &lib[*num_song].year);
    (*num_song)++;
    printf("Song Added Successfully to Library!\n");
}

//Function to Show all Songs in Library
void show_all_songs(song *lib, int num_song){
    if(num_song<1){
        printf("Empty Library!\n");
        return;
    }
    printf("\n%-30s %-30s %-30s %-10s\n", "Title", "Artist", "Album", "Year");
    for(int i=0; i<num_song; i++){
        printf("%-30s %-30s %-30s %-10d\n", lib[i].title, lib[i].artist, lib[i].album, lib[i].year);
    }
}

int main(){
    //Initializing the Music Library with maximum capacity of 20 songs
    song *lib = (song *)malloc(20*sizeof(song));
    int num_song = 0;
    int choice = 0;

    while(choice != 3){
        //Printing the Main Menu
        printf("\n=================MEDIEVAL MUSIC LIBRARY====================\n");
        printf("1. Add Song\n2. Show All Songs\n3. Quit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_song(lib, &num_song);
                break;
            case 2:
                show_all_songs(lib, num_song);
                break;
            case 3:
                printf("Good Bye! Have a Nice Day!\n");
                break;
            default:
                printf("Invalid Choice! Try Again!\n");
                break;
        }
    }
    free(lib);//Freeing the Allocated Memory
    return 0;
}