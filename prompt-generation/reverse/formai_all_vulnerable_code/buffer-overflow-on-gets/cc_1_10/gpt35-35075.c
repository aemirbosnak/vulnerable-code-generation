//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SONGS 1000 //Maximum number of songs that can be stored in the system

struct song {
    int id;
    char title[50];
    char artist[50];
    int year;
    char genre[20];
    float rating;
};

int count = 0; //Initialize count to 0, as there are no songs at the beginning
struct song song_list[MAX_SONGS]; //Creating an array of songs

//Function to add a new song to the system
void add_song() {
    struct song new_song;
    new_song.id = count + 1; //Assigning an id to the new song
    printf("Enter the details for the new song:\n");
    printf("Title: ");
    fflush(stdin);
    gets(new_song.title);
    printf("Artist: ");
    fflush(stdin);
    gets(new_song.artist);
    printf("Year: ");
    scanf("%d", &new_song.year);
    printf("Genre: ");
    fflush(stdin);
    gets(new_song.genre);
    printf("Rating (out of 5): ");
    scanf("%f", &new_song.rating);

    song_list[count] = new_song; //Add the new song to the song list
    count++; //Increase the song count by 1
    printf("\nSong added successfully!\n");
}

//Function to display all the songs in the system
void display_songs() {
    printf("ID  |  Title  |  Artist  |  Year  |  Genre  |  Rating\n");
    printf("----------------------------------------------------\n");

    for(int i=0;i<count;i++) {
        printf("%-4d|  %-7s|  %-8s|  %-5d|  %-7s|  %-2.1f\n", song_list[i].id, song_list[i].title, song_list[i].artist, song_list[i].year, song_list[i].genre, song_list[i].rating);
    }
}

//Function to search for a song by title
void search_song() {
    char search_title[50];
    printf("Enter the title of the song to be searched: ");
    fflush(stdin);
    gets(search_title);
    int flag=0;

    for(int i=0;i<count;i++) {
        if(strcmp(search_title, song_list[i].title)==0) {
            printf("ID  |  Title  |  Artist  |  Year  |  Genre  |  Rating\n");
            printf("----------------------------------------------------\n");
            printf("%-4d|  %-7s|  %-8s|  %-5d|  %-7s|  %-2.1f\n", song_list[i].id, song_list[i].title, song_list[i].artist, song_list[i].year, song_list[i].genre, song_list[i].rating);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nSong not found!\n");
}

//Function to delete a song by ID
void delete_song() {
    int delete_song_id;
    printf("Enter the ID of the song to be deleted: ");
    scanf("%d", &delete_song_id);
    int flag=0;

    for(int i=0;i<count;i++) {
        if(delete_song_id==song_list[i].id) {
            for(int j=i;j<count-1;j++) {
                song_list[j]=song_list[j+1]; //Shift all the songs to the left after deleting a song
            }
            count--; //Decrease the song count by 1 after deleting a song
            printf("\nSong with ID %d deleted successfully!\n", delete_song_id);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nSong with ID %d not found!\n", delete_song_id);
}

int main() {
    int choice;
    
    do {
        printf("\nMUSIC LIBRARY MANAGEMENT SYSTEM\n\n");
        printf("1. Add a new song\n");
        printf("2. Display all songs\n");
        printf("3. Search for a song\n");
        printf("4. Delete a song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: //Add a new song
                add_song();
                break;
            case 2: //Display all songs
                display_songs();
                break;
            case 3: //Search for a song
                search_song();
                break;
            case 4: //Delete a song
                delete_song();
                break;
            case 5: //Exit
                printf("\nThank you for using the Music Library Management System!\n");
                break;
            default: //Invalid choice
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice!=5);

    return 0;
}