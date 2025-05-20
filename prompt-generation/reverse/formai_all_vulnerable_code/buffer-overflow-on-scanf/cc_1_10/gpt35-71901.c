//FormAI DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* C MUSIC LIBRARY MANAGEMENT SYSTEM */

/* Structure to hold song details */
struct song{
    char title[50];
    char artist[25];
    int duration;
};

/* Function prototypes */
void add_song();
void display_songs();
void search_song();
void delete_song();

/* Initialize song array */
struct song music_lib[100];

/* Keeping track of number of songs in library */
int num_songs = 0;

int main(){

    /* Displaying program title */
    printf("\n\tC MUSIC LIBRARY MANAGEMENT SYSTEM\n\n");

    int choice;

    /* Displaying menu options */
    do{
        printf("MAIN MENU\n");
        printf("1. Add a Song\n");
        printf("2. Display All Songs\n");
        printf("3. Search for a Song\n");
        printf("4. Delete a Song\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Evaluating user's choice */
        switch(choice){
            case 1: add_song();
                    break;
            case 2: display_songs();
                    break;
            case 3: search_song();
                    break;
            case 4: delete_song();
                    break;
            case 5: printf("\nThank you for using C Music Library Management System.\n\n");
                    exit(0);
                    break;
            default: printf("\nInvalid choice. Please try again.\n\n");
                     break;
        }
    } while(1);
    return 0;
}

/* Function to add a song to library */
void add_song(){

    /* If library is full */
    if(num_songs == 100){
        printf("\nError: Music Library is Full.\n\n");
        return;
    }

    printf("\nEnter Song Title: ");
    scanf(" %[^\n]", music_lib[num_songs].title);
    printf("Enter Artist Name: ");
    scanf(" %[^\n]", music_lib[num_songs].artist);
    printf("Enter Song Duration(in seconds): ");
    scanf("%d", &music_lib[num_songs].duration);

    printf("\nSong Added Successfully.\n\n");

    /* Incrementing number of songs counter */
    num_songs++;
}

/* Function to display all songs in library */
void display_songs(){

    /* If there are no songs */
    if(num_songs == 0){
        printf("\nError: No Songs Found in Music Library.\n\n");
        return;
    }

    printf("\nMUSIC LIBRARY\n");
    printf("\nSong Title\t\tArtist\t\tDuration\n");

    int i;
    for(i = 0; i < num_songs; i++){
        printf("%-20s\t\t%-15s\t%3d sec\n", music_lib[i].title, music_lib[i].artist, music_lib[i].duration);
    }
    printf("\n");
}

/* Function to search for a song in library */
void search_song(){

    /* If there are no songs */
    if(num_songs == 0){
        printf("\nError: No Songs Found in Music Library.\n\n");
        return;
    }

    char search_title[50];
    printf("\nEnter Song Title to Search: ");
    scanf(" %[^\n]", search_title);

    int found = 0;
    int i;
    for(i = 0; i < num_songs; i++){
        if(strcmp(search_title, music_lib[i].title) == 0){
            printf("\nSong Found!\n");
            printf("\nSong Title\t\tArtist\t\tDuration\n");
            printf("%-20s\t\t%-15s\t%3d sec\n\n", music_lib[i].title, music_lib[i].artist, music_lib[i].duration);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("\nError: Song Not Found in Music Library.\n\n");
    }
}

/* Function to delete a song from library */
void delete_song(){

    /* If there are no songs */
    if(num_songs == 0){
        printf("\nError: No Songs Found in Music Library.\n\n");
        return;
    }

    char delete_title[50];
    printf("\nEnter Song Title to Delete: ");
    scanf(" %[^\n]", delete_title);

    int found = 0;
    int i;
    for(i = 0; i < num_songs; i++){
        if(strcmp(delete_title, music_lib[i].title) == 0){
            found = 1;
            break;
        }
    }

    if(!found){
        printf("\nError: Song Not Found in Music Library.\n\n");
        return;
    }

    /* Shifting songs up to delete the 'i'th song */
    for(i; i < num_songs - 1; i++){
        strcpy(music_lib[i].title, music_lib[i+1].title);
        strcpy(music_lib[i].artist, music_lib[i+1].artist);
        music_lib[i].duration = music_lib[i+1].duration;
    }

    /* Decrementing number of songs counter */
    num_songs--;

    printf("\nSong Deleted Successfully.\n\n");
}