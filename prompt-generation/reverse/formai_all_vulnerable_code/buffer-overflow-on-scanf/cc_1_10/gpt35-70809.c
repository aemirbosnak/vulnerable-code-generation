//FormAI DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure to store details about a song
struct Song{
    char name[50]; 
    char artist[50];
    char album[50];
    int year;
    int length; //(in seconds)
    int bitrate; //(in Kbps)
    char path[100]; //(path on disk)
};

//function to add a new song to the library
void add_song(struct Song* library, int* song_count){
    printf("Enter details for the new song:\n");
    printf("Name: ");
    scanf("%s", library[*song_count].name);
    printf("Artist: ");
    scanf("%s", library[*song_count].artist);
    printf("Album: ");
    scanf("%s", library[*song_count].album);
    printf("Year: ");
    scanf("%d", &library[*song_count].year);
    printf("Length (in seconds): ");
    scanf("%d", &library[*song_count].length);
    printf("Bitrate (in Kbps): ");
    scanf("%d", &library[*song_count].bitrate);
    printf("Path on disk: ");
    scanf("%s", library[*song_count].path);
    (*song_count)++; //increment song count after adding a new song
    printf("Song added successfully!\n");
}

//function to search for a song in the library by name
void search_song_by_name(struct Song* library, int song_count){
    char name[50];
    int found = 0;
    printf("Enter name of song to search for: ");
    scanf("%s", name);
    for(int i = 0; i < song_count; i++){
        if(strcmp(name, library[i].name) == 0){
            found = 1;
            printf("Song found at position %d in the library:\n", i+1);
            printf("Name: %s\n", library[i].name);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("Length: %d seconds\n", library[i].length);
            printf("Bitrate: %d Kbps\n", library[i].bitrate);
            printf("Path on disk: %s\n", library[i].path);
            break; //exit loop after finding first instance of the song
        }
    }
    if(!found) printf("Song not found in the library.\n");
}

//function to search for a song in the library by artist
void search_song_by_artist(struct Song* library, int song_count){
    char artist[50];
    int found = 0;
    printf("Enter name of artist to search for: ");
    scanf("%s", artist);
    for(int i = 0; i < song_count; i++){
        if(strcmp(artist, library[i].artist) == 0){
            found = 1;
            printf("Song found at position %d in the library:\n", i+1);
            printf("Name: %s\n", library[i].name);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("Length: %d seconds\n", library[i].length);
            printf("Bitrate: %d Kbps\n", library[i].bitrate);
            printf("Path on disk: %s\n", library[i].path);
        }
    }
    if(!found) printf("No songs found in the library by that artist.\n");
}

//function to edit details of a song in the library
void edit_song(struct Song* library, int song_count){
    char name[50];
    int found = 0;
    printf("Enter name of song to edit details of: ");
    scanf("%s", name);
    for(int i = 0; i < song_count; i++){
        if(strcmp(name, library[i].name) == 0){
            found = 1;
            printf("\nCurrent details of the song:\n");
            printf("Name: %s\n", library[i].name);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("Length: %d seconds\n", library[i].length);
            printf("Bitrate: %d Kbps\n", library[i].bitrate);
            printf("Path on disk: %s\n", library[i].path);
            printf("\nEnter new details for the song:\n");
            printf("Name: ");
            scanf("%s", library[i].name);
            printf("Artist: ");
            scanf("%s", library[i].artist);
            printf("Album: ");
            scanf("%s", library[i].album);
            printf("Year: ");
            scanf("%d", &library[i].year);
            printf("Length (in seconds): ");
            scanf("%d", &library[i].length);
            printf("Bitrate (in Kbps): ");
            scanf("%d", &library[i].bitrate);
            printf("Path on disk: ");
            scanf("%s", library[i].path);
            printf("Details of song updated successfully!\n");
            break; //exit loop after finding first instance of the song
        }
    }
    if(!found) printf("Song not found in the library.\n");
}

int main(){
    struct Song* library = malloc(100 * sizeof(struct Song)); //initialize array to store details of songs in the library
    int song_count = 0; //initialize song count to 0
    int choice;
    while(1){ //infinite loop to display menu and accept user input until user exits
        printf("\nC Music Library Management System\n");
        printf("1. Add new song to library\n");
        printf("2. Search for song by name\n");
        printf("3. Search for song by artist\n");
        printf("4. Edit details of existing song\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_song(library, &song_count); break;
            case 2: search_song_by_name(library, song_count); break;
            case 3: search_song_by_artist(library, song_count); break;
            case 4: edit_song(library, song_count); break;
            case 5: printf("Thank you for using C Music Library Management System.\n"); free(library); return 0;
            default: printf("Invalid choice. Please try again.\n");
        }
    }   
}