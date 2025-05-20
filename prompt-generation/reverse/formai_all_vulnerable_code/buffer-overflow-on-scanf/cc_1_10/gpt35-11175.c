//FormAI DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_SONGS 1000

/* Song Structure */
typedef struct{
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
} Song;

/* Function prototypes */
void display_menu();
void add_song(Song song[], int *count);
void display_all_songs(Song song[], int count);
void search_song(Song song[], int count);
void update_song(Song song[], int count);
void delete_song(Song song[], int *count);

/* Main function */
int main(){
    Song song[MAX_SONGS];
    int count = 0, choice;

    printf("Welcome to the C Music Library Management System!\n");
    do{
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_song(song, &count);
                break;
            case 2:
                display_all_songs(song, count);
                break;
            case 3:
                search_song(song, count);
                break;
            case 4:
                update_song(song, count);
                break;
            case 5:
                delete_song(song, &count);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 6);

    return 0;
}

/* Function to display the menu */
void display_menu(){
    printf("\n------ MENU ------\n");
    printf("1. Add a song\n");
    printf("2. Display all songs\n");
    printf("3. Search for a song\n");
    printf("4. Update a song\n");
    printf("5. Delete a song\n");
    printf("6. Exit\n");
}

/* Function to add a song to the library */
void add_song(Song song[], int *count){
    if(*count == MAX_SONGS){
        printf("Sorry, the library is full.\n");
        return;
    }

    printf("Enter the title of the song: ");
    scanf("\n%[^\n]", song[*count].title);
    printf("Enter the name of the artist: ");
    scanf("\n%[^\n]", song[*count].artist);
    printf("Enter the name of the album: ");
    scanf("\n%[^\n]", song[*count].album);
    printf("Enter the year of release: ");
    scanf("%d", &song[*count].year);

    printf("Song '%s' has been added to the library.\n", song[*count].title);
    (*count)++;
}

/* Function to display all songs in the library */
void display_all_songs(Song song[], int count){
    if(count == 0){
        printf("The library is empty.\n");
        return;
    }

    printf("\n--- All Songs ---\n");
    for(int i=0; i<count; i++){
        printf("%d. %s - %s (%s - %d)\n", i+1, song[i].title, song[i].artist, song[i].album, song[i].year);
    }
}

/* Function to search for a song in the library */
void search_song(Song song[], int count){
    if(count == 0){
        printf("The library is empty.\n");
        return;
    }

    char keyword[MAX_LENGTH];
    int found = 0;

    printf("Enter a keyword to search: ");
    scanf("\n%[^\n]", keyword);

    printf("\n--- Search Results ---\n");
    for(int i=0; i<count; i++){
        if(strstr(song[i].title, keyword) != NULL || strstr(song[i].artist, keyword) != NULL || strstr(song[i].album, keyword) != NULL){
            printf("%d. %s - %s (%s - %d)\n", i+1, song[i].title, song[i].artist, song[i].album, song[i].year);
            found = 1;
        }
    }

    if(!found){
        printf("No songs found.\n");
    }
}

/* Function to update a song in the library */
void update_song(Song song[], int count){
    if(count == 0){
        printf("The library is empty.\n");
        return;
    }

    int index, field, updated = 0;
    char new_value[MAX_LENGTH];

    printf("Enter the index of the song to update: ");
    scanf("%d", &index);
    if(index < 1 || index > count){
        printf("Invalid index.\n");
        return;
    }

    printf("Select the field to update:\n");
    printf("1. Title\n");
    printf("2. Artist\n");
    printf("3. Album\n");
    printf("4. Year\n");
    scanf("%d", &field);

    printf("Enter the new value: ");
    scanf("\n%[^\n]", new_value);

    switch(field){
        case 1:
            strcpy(song[index-1].title, new_value);
            updated = 1;
            break;
        case 2:
            strcpy(song[index-1].artist, new_value);
            updated = 1;
            break;
        case 3:
            strcpy(song[index-1].album, new_value);
            updated = 1;
            break;
        case 4:
            song[index-1].year = atoi(new_value);
            updated = 1;
            break;
        default:
            printf("Invalid field.\n");
    }

    if(updated){
        printf("Song '%s' has been updated successfully.\n", song[index-1].title);
    }
}

/* Function to delete a song from the library */
void delete_song(Song song[], int *count){
    if(*count == 0){
        printf("The library is empty.\n");
        return;
    }

    int index;
    printf("Enter the index of the song to delete: ");
    scanf("%d", &index);
    if(index < 1 || index > *count){
        printf("Invalid index.\n");
        return;
    }

    printf("Song '%s' has been deleted from the library.\n", song[index-1].title);
    for(int i=index-1; i<*count-1; i++){
        song[i] = song[i+1];
    }
    (*count)--;
}