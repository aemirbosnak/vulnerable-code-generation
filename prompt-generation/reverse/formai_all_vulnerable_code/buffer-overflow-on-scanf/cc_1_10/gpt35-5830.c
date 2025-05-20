//FormAI DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct album {
    char name[50];
    char artist[50];
    char year[5];
};

void addAlbum(struct album library[], int *num_albums);
void displayAlbums(struct album library[], int num_albums);
void searchAlbums(struct album library[], int num_albums);
void deleteAlbum(struct album library[], int *num_albums);

int main() {
    struct album library[100];
    int num_albums = 0;
    char choice;
    do {
        printf("\nWelcome to the C Music Library Management System!\n");
        printf("Please choose an option:\n");
        printf("1. Add Album\n2. Display Albums\n3. Search Albums\n4. Delete Album\n5. Exit\n");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                addAlbum(library, &num_albums);
                break;
            case '2':
                displayAlbums(library, num_albums);
                break;
            case '3':
                searchAlbums(library, num_albums);
                break;
            case '4':
                deleteAlbum(library, &num_albums);
                break;
            case '5':
                printf("Thank you for using the C Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    } while(choice != '5');
    return 0;
}

void addAlbum(struct album library[], int *num_albums) {
    if(*num_albums == 100) {
        printf("Maximum number of albums (100) reached!\n");
        return;
    }
    printf("Enter the album name: ");
    scanf(" %s", library[*num_albums].name);
    printf("Enter the artist name: ");
    scanf(" %s", library[*num_albums].artist);
    printf("Enter the release year: ");
    scanf(" %s", library[*num_albums].year);
    printf("Album added successfully!\n");
    (*num_albums)++;
}

void displayAlbums(struct album library[], int num_albums) {
    if(num_albums == 0) {
        printf("No albums found in the library!\n");
        return;
    }
    printf("Albums in the library:\n");
    for(int i=0; i<num_albums; i++) {
        printf("%d. Album: %s\n   Artist: %s\n   Year: %s\n", i+1, library[i].name, library[i].artist, library[i].year);
    }
}

void searchAlbums(struct album library[], int num_albums) {
    if(num_albums == 0) {
        printf("No albums found in the library!\n");
        return;
    }
    char keyword[50];
    printf("Enter a keyword to search for: ");
    scanf(" %s", keyword);
    int found = 0;
    for(int i=0; i<num_albums; i++) {
        if(strstr(library[i].name, keyword) || strstr(library[i].artist, keyword) || strstr(library[i].year, keyword)) {
            printf("%d. Album: %s\n   Artist: %s\n   Year: %s\n", i+1, library[i].name, library[i].artist, library[i].year);
            found = 1;
        }
    }
    if(!found) {
        printf("No albums found with the given keyword!\n");
    }
}

void deleteAlbum(struct album library[], int *num_albums) {
    if(*num_albums == 0) {
        printf("No albums found in the library!\n");
        return;
    }
    printf("Enter the number of the album to be deleted: ");
    int index;
    scanf("%d", &index);
    if(index < 1 || index > *num_albums) {
        printf("Invalid album number!\n");
        return;
    }
    for(int i=index-1; i<*num_albums-1; i++) {
        strcpy(library[i].name, library[i+1].name);
        strcpy(library[i].artist, library[i+1].artist);
        strcpy(library[i].year, library[i+1].year);
    }
    printf("Album deleted successfully!\n");
    (*num_albums)--;
}