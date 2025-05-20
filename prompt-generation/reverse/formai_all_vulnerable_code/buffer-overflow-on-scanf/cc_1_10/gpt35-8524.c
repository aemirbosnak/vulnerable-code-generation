//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

void add_song(struct song[], int*);
void display_song(struct song[], int);
void search_song(struct song[], int);
void delete_song(struct song[], int*);

int main()
{
    struct song library[100];
    int count = 0;
    int choice;

    printf("\nWELCOME TO THE MUSIC LIBRARY MANAGEMENT SYSTEM");

    while(1) {
        printf("\n\nMENU:\n1. Add a song to the library\n2. Display all songs\n3. Search for a song\n4. Delete a song\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(library, &count);
                break;
            case 2:
                display_song(library, count);
                break;
            case 3:
                search_song(library, count);
                break;
            case 4:
                delete_song(library, &count);
                break;
            case 5:
                printf("\nThank You for using the Music Library Management System! Have a nice day!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}

void add_song(struct song library[], int *count) {
    printf("\nEnter the title of the song: ");
    scanf(" %[^\n]", library[*count].title);
    printf("Enter the artist's name: ");
    scanf(" %[^\n]", library[*count].artist);
    printf("Enter the album of the song: ");
    scanf(" %[^\n]", library[*count].album);
    printf("Enter the year it was released: ");
    scanf("%d", &library[*count].year);

    *count += 1;

    printf("\nSong added successfully!\n");
}

void display_song(struct song library[], int count) {
    if(count == 0) {
        printf("\nThe library is empty!\n");
        return;
    }

    printf("\n%-30s | %-30s | %-30s | %s\n", "Title", "Artist", "Album", "Year");

    for(int i=0; i<count; i++) {
        printf("%-30s | %-30s | %-30s | %d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

void search_song(struct song library[], int count) {
    if(count == 0) {
        printf("\nThe library is empty!\n"); 
        return;
    }

    char search_title[50];
    int found = 0;

    printf("\nEnter the title of the song you want to search: ");
    scanf(" %[^\n]", search_title);

    for(int i=0; i<count; i++) {
        if(strcmp(search_title, library[i].title) == 0) {
            printf("\n%-30s | %-30s | %-30s | %s\n", "Title", "Artist", "Album", "Year");
            printf("%-30s | %-30s | %-30s | %d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("\nSorry, the song was not found! Please try again.\n");
    }
}

void delete_song(struct song library[], int *count) {
    if(*count == 0) {
        printf("\nThe library is empty!\n"); 
        return;
    }

    char delete_title[50];
    int found = 0;

    printf("\nEnter the title of the song you want to delete: ");
    scanf(" %[^\n]", delete_title);

    for(int i=0; i<*count; i++) {
        if(strcmp(delete_title, library[i].title) == 0) {
            for(int j=i; j<(*count)-1; j++) {
                strcpy(library[j].title, library[j+1].title);
                strcpy(library[j].artist, library[j+1].artist);
                strcpy(library[j].album, library[j+1].album);
                library[j].year = library[j+1].year;
            }
            (*count)--;
            found = 1;
            printf("\nSong deleted successfully!\n");
            break;
        }
    }

    if(found == 0) {
        printf("\nSorry, the song was not found! Please try again.\n");
    }
}