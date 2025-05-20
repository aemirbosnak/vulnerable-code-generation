//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the structure of the music library
struct music_library{
    char song[50];
    char artist[50];
    char album[50];
    int year;
    float duration;
};

//Declaring global variables for the music library and the count of songs in it
struct music_library library[100];
int library_count = 0;

//Function to add a song to the library
void add_song(){
    printf("\nEnter song name : ");
    scanf("%s", library[library_count].song);
    printf("Enter artist name : ");
    scanf("%s", library[library_count].artist);
    printf("Enter album name : ");
    scanf("%s", library[library_count].album);
    printf("Enter year of release : ");
    scanf("%d", &(library[library_count].year));
    printf("Enter duration of song in minutes : ");
    scanf("%f", &(library[library_count].duration));
    library_count++; //Increasing the song count in the library
    printf("\nSong added successfully!\n");
}

//Function to display the entire music library
void display_library(){
    if(library_count == 0){
        printf("\nError : Library is empty!\n");
        return ;
    }
    printf("\n");
    printf("Song\t\tArtist\t\tAlbum\t\tYear\t\tDuration(min)\n");
    printf("-----------------------------------------------------------------\n");
    for(int i=0; i<library_count; i++){
        printf("%s\t\t%s\t\t%s\t\t%d\t\t%.2f\n", library[i].song, library[i].artist, library[i].album, library[i].year, library[i].duration);
    }
}

//Function to search and display a song in the library
void search_song(){
    if(library_count == 0){
        printf("\nError : Library is empty!\n");
        return ;
    }
    char song_name[50];
    printf("\nEnter song name : ");
    scanf("%s", song_name);

    for(int i=0; i<library_count; i++){
        if(strcmp(library[i].song, song_name) == 0){
            printf("\nSong Found!\n");
            printf("Song\t\tArtist\t\tAlbum\t\tYear\t\tDuration(min)\n");
            printf("-----------------------------------------------------------------\n");
            printf("%s\t\t%s\t\t%s\t\t%d\t\t%.2f\n", library[i].song, library[i].artist, library[i].album, library[i].year, library[i].duration);
            return ;
        }
    }
    printf("\nError : Song not found!\n");
}

//Function to delete a song from the library
void delete_song(){
    if(library_count == 0){
        printf("\nError : Library is empty!\n");
        return ;
    }
    char song_name[50];
    printf("\nEnter song name : ");
    scanf("%s", song_name);

    for(int i=0; i<library_count; i++){
        if(strcmp(library[i].song, song_name) == 0){
            //Shifting the rest of the library by one place
            for(int j=i; j<library_count-1; j++){
                library[j] = library[j+1];
            }
            library_count--; //Decreasing the count of songs in the library
            printf("\nSong deleted successfully!\n");
            return ;
        }
    }
    printf("\nError : Song not found!\n");
}

int main(){
    int choice;
    while(1){
        printf("\n\n***********C Music Library Management System***********\n");
        printf("1. Add song\n2. Display library\n3. Search song\n4. Delete song\n");
        printf("5. Exit\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_song();
                break;
            case 2:
                display_library();
                break;
            case 3:
                search_song();
                break;
            case 4:
                delete_song();
                break;
            case 5:
                exit(0);
            default:
                printf("\nError : Invalid choice!\n");
        }
    }
    return 0;
}