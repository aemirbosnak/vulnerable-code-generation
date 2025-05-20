//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct{
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char genre[MAX_SIZE];
}Song;

void print_menu();
void add_song(Song *library, int *num_songs);
void delete_song(Song *library, int *num_songs);
void search_song(Song *library, int num_songs);
void display_library(Song *library, int num_songs);

int main(){
    Song library[MAX_SIZE];
    int num_songs = 0;
    int choice;

    do{
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_song(library, &num_songs);
                break;
            case 2:
                delete_song(library, &num_songs);
                break;
            case 3:
                search_song(library, num_songs);
                break;
            case 4:
                display_library(library, num_songs);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }while(choice != 5);

    return 0;
}

void print_menu(){
    printf("---- Music Library Management System ----\n");
    printf("1. Add song\n");
    printf("2. Delete song\n");
    printf("3. Search song\n");
    printf("4. Display library\n");
    printf("5. Exit\n");
}

void add_song(Song *library, int *num_songs){
    if(*num_songs == MAX_SIZE){
        printf("Library full. Cannot add more songs.\n");
        return;
    }
    printf("Enter song title: ");
    scanf(" %[^\n]", library[*num_songs].title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", library[*num_songs].artist);
    printf("Enter genre: ");
    scanf(" %[^\n]", library[*num_songs].genre);
    (*num_songs)++;
}

void delete_song(Song *library, int *num_songs){
    char title[MAX_SIZE];
    printf("Enter song title to delete: ");
    scanf(" %[^\n]", title);
    int i;
    for(i=0; i<*num_songs; i++){
        if(strcmp(library[i].title, title) == 0){
            int j;
            for(j=i; j<*num_songs-1; j++){
                strcpy(library[j].title, library[j+1].title);
                strcpy(library[j].artist, library[j+1].artist);
                strcpy(library[j].genre, library[j+1].genre);
            }
            (*num_songs)--;
            printf("Song deleted.\n");
            return;
        }
    }
    printf("Song not found in library.\n");
}

void search_song(Song *library, int num_songs){
    char title[MAX_SIZE];
    printf("Enter song title to search: ");
    scanf(" %[^\n]", title);
    int i;
    for(i=0; i<num_songs; i++){
        if(strcmp(library[i].title, title) == 0){
            printf("Song found in library:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            return;
        }
    }
    printf("Song not found in library.\n");
}

void display_library(Song *library, int num_songs){
    if(num_songs == 0){
        printf("Library is empty.\n");
        return;
    }
    printf("----- Music Library -----\n");
    int i;
    for(i=0; i<num_songs; i++){
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Genre: %s\n", library[i].genre);
        printf("\n");
    }
}