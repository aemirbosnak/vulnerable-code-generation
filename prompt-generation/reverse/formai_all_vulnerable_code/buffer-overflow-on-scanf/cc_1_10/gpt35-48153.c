//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char title[50];
    char artist[50];
    int year;
    int tracks;
};

void addAlbum(struct Album *albums, int *numAlbums);
void removeAlbum(struct Album *albums, int *numAlbums);
void viewAlbums(struct Album *albums, int numAlbums);
void saveToFile(struct Album *albums, int numAlbums);
void loadFromFile(struct Album *albums, int *numAlbums);

int main() {
    struct Album albums[100];
    int numAlbums = 0;
    char choice;

    do {
        printf("\n=======================");
        printf("\n Music Library Management System");
        printf("\n=======================");
        printf("\n1. Add an album");
        printf("\n2. Remove an album");
        printf("\n3. View all albums");
        printf("\n4. Save to file");
        printf("\n5. Load from file");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");

        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addAlbum(albums, &numAlbums);
                break;
            case '2':
                removeAlbum(albums, &numAlbums);
                break;
            case '3':
                viewAlbums(albums, numAlbums);
                break;
            case '4':
                saveToFile(albums, numAlbums);
                break;
            case '5':
                loadFromFile(albums, &numAlbums);
                break;
            case '6':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }

    } while(choice != '6');

    return 0;
}

void addAlbum(struct Album *albums, int *numAlbums) {
    if(*numAlbums < 100) {
        printf("\nEnter album title: ");
        scanf(" %[^\n]*%s", albums[*numAlbums].title);
        printf("\nEnter artist: ");
        scanf(" %[^\n]*%s", albums[*numAlbums].artist);
        printf("\nEnter year released: ");
        scanf("%d", &albums[*numAlbums].year);
        printf("\nEnter number of tracks: ");
        scanf("%d", &albums[*numAlbums].tracks);
        (*numAlbums)++;
    } else {
        printf("\nMaximum number of albums reached.\n");
    }
}

void removeAlbum(struct Album *albums, int *numAlbums) {
    int i, found = 0;
    char title[50];

    printf("\nEnter album title to remove: ");
    scanf(" %[^\n]*%s", title);

    for(i = 0; i < *numAlbums; i++) {
        if(strcmp(title, albums[i].title) == 0) {
            found = 1;
            break;
        }
    }

    if(found) {
        for(i = i + 1; i < *numAlbums; i++) {
            albums[i - 1] = albums[i];
        }
        (*numAlbums)--;
        printf("\nAlbum successfully removed.\n");
    } else {
        printf("\nAlbum not found.\n");
    }
}

void viewAlbums(struct Album *albums, int numAlbums) {
    int i;

    if(numAlbums == 0) {
        printf("\nNo albums in library.\n");
    } else {
        printf("\nTitle\t\tArtist\t\tYear\tTracks\n");

        for(i = 0; i < numAlbums; i++) {
            printf("%s\t%s\t\t%d\t%d\n", albums[i].title, albums[i].artist, albums[i].year, albums[i].tracks);
        }
    }
}

void saveToFile(struct Album *albums, int numAlbums) {
    FILE *file;
    int i;

    file = fopen("albums.txt", "w");

    if(file != NULL) {
        fprintf(file, "%d\n", numAlbums);

        for(i = 0; i < numAlbums; i++) {
            fprintf(file, "%s\n%s\n%d\n%d\n", albums[i].title, albums[i].artist, albums[i].year, albums[i].tracks);
        }

        fclose(file);
        printf("\nLibrary saved to file.\n");
    } else {
        printf("\nUnable to save to file.\n");
    }
}

void loadFromFile(struct Album *albums, int *numAlbums) {
    FILE *file;
    int i;

    file = fopen("albums.txt", "r");

    if(file != NULL) {
        fscanf(file, "%d", numAlbums);

        for(i = 0; i < *numAlbums; i++) {
            fscanf(file, "%s%s%d%d", albums[i].title, albums[i].artist, &albums[i].year, &albums[i].tracks);
        }

        fclose(file);
        printf("\nLibrary loaded from file.\n");
    } else {
        printf("\nUnable to load from file.\n");
    }
}