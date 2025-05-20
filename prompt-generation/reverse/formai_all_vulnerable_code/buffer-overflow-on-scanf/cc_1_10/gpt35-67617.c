//FormAI DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct music{
    char song_title[50];
    char artist[50];
    char album[50];
    float duration;
};

void add_song(struct music *ptr, int n);
void delete_song(struct music *ptr, int n);
void search_song(struct music *ptr, int n);
void display_all_songs(struct music *ptr, int n);

int main(){
    int num_songs, choice;
    printf("Enter number of songs: ");
    scanf("%d", &num_songs);

    struct music *song_ptr = malloc(num_songs *sizeof(struct music));

    do{
        printf("\n\n----Music Library Management System----\n");
        printf("\n1. Add Song\n2. Delete Song\n3. Search Song\n4. Display All Songs\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_song(song_ptr, num_songs);
                break;
            case 2:
                delete_song(song_ptr, num_songs);
                break;
            case 3:
                search_song(song_ptr, num_songs);
                break;
            case 4:
                display_all_songs(song_ptr, num_songs);
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    } while(choice != 5);

    free(song_ptr);
    return 0;
}

void add_song(struct music *ptr, int n){
    printf("\n---Add Song---\n");
    for(int i=0; i<n; i++){
        if(strcmp(ptr[i].song_title, "") == 0){
            printf("\nEnter Song Title: ");
            scanf(" %[^\n]", ptr[i].song_title);
            printf("Enter Artist Name: ");
            scanf(" %[^\n]", ptr[i].artist);
            printf("Enter Album Name: ");
            scanf(" %[^\n]", ptr[i].album);
            printf("Enter Song Duration (in seconds): ");
            scanf("%f", &ptr[i].duration);
            printf("\nSong added successfully!\n");
            return;
        }
    }
    printf("\nError: The library is full!\n");
}

void delete_song(struct music *ptr, int n){
    printf("\n---Delete Song---\n");
    char title[50];
    printf("\nEnter Song Title: ");
    scanf(" %[^\n]", title);
    for(int i=0; i<n; i++){
        if(strcmp(ptr[i].song_title, title) == 0){
            strcpy(ptr[i].song_title, "");
            strcpy(ptr[i].artist,"");
            strcpy(ptr[i].album,"");
            ptr[i].duration = 0;
            printf("\nSong deleted successfully!\n");
            return;
        }
    }
    printf("\nError: Song not found!\n");
}

void search_song(struct music *ptr, int n){
    printf("\n---Search Song---\n");
    char title[50];
    printf("\nEnter Song Title: ");
    scanf(" %[^\n]", title);
    for(int i=0; i<n; i++){
        if(strcmp(ptr[i].song_title, title) == 0){
            printf("\nSong Title: %s", ptr[i].song_title);
            printf("\nArtist Name: %s", ptr[i].artist);
            printf("\nAlbum Name: %s", ptr[i].album);
            printf("\nSong Duration (in seconds): %.2f", ptr[i].duration);
            return;
        }
    }
    printf("\nError: Song not found!\n");
}

void display_all_songs(struct music *ptr, int n){
    printf("\n---All Songs---\n");
    for(int i=0; i<n; i++){
        if(strcmp(ptr[i].song_title, "") != 0){
            printf("\nSong Title: %s", ptr[i].song_title);
            printf("\nArtist Name: %s", ptr[i].artist);
            printf("\nAlbum Name: %s", ptr[i].album);
            printf("\nSong Duration (in seconds): %.2f\n", ptr[i].duration);
        }
    }
}