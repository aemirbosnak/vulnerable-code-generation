//FormAI DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100

struct Album {
    char title[50];
    char artist[50];
    int year;
};

struct Album albums[MAX_ALBUMS];
int num_albums = 0;

void add_album() {
    struct Album new_album;
    memset(&new_album, 0, sizeof(new_album));
    printf("Enter album title: ");
    scanf("%49s", new_album.title);
    printf("Enter artist name: ");
    scanf("%49s", new_album.artist);
    printf("Enter year of release: ");
    scanf("%d", &new_album.year);
    
    albums[num_albums++] = new_album;
    printf("Album added successfully!\n");
}

void print_albums() {
    printf("Title\tArtist\tYear\n");
    for (int i = 0; i < num_albums; i++) {
        printf("%s\t%s\t%d\n", albums[i].title, albums[i].artist, albums[i].year);
    }
}

int main() {
    printf("Welcome to the Medieval Music Library Manager!\n");
    int choice;
    do {
        printf("1. Add album\n");
        printf("2. Print albums\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_album();
                break;
            case 2:
                print_albums();
                break;
            case 3:
                printf("Goodbye, noble music lover!\n");
                break;
            default:
                printf("Invalid choice, try again!\n");
        }
    } while (choice != 3);
    
    return 0;
}