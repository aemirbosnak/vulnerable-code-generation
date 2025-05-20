//FormAI DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

struct Song {
    char name[50];
    char artist[50];
    char album[50];
    int year;
};

typedef struct Song song;

void searchSong(song library[], int size) {
    int i;
    char query[50];
    printf("\nEnter the name of the song to search: ");
    scanf("%s", query);
    for (i = 0; i < size; i++) {
        if (strcmp(library[i].name, query) == 0) {
            printf("\n%s - %s (%s) [%d]\n", library[i].artist, library[i].name, library[i].album, library[i].year);
            return;
        }
    }
    printf("\nSong not found!\n");
}

void addSong(song library[], int size) {
    printf("\nEnter the details of the song:\n");
    printf("Name: ");
    scanf("%s", library[size].name);
    printf("Artist: ");
    scanf("%s", library[size].artist);
    printf("Album: ");
    scanf("%s", library[size].album);
    printf("Year: ");
    scanf("%d", &library[size].year);
    printf("\nSong added successfully!\n");
}

void editSong(song library[], int size) {
    int i;
    char query[50];
    printf("\nEnter the name of the song to edit: ");
    scanf("%s", query);
    for (i = 0; i < size; i++) {
        if (strcmp(library[i].name, query) == 0) {
            printf("\nEnter the new details of the song:\n");
            printf("Name: ");
            scanf("%s", library[i].name);
            printf("Artist: ");
            scanf("%s", library[i].artist);
            printf("Album: ");
            scanf("%s", library[i].album);
            printf("Year: ");
            scanf("%d", &library[i].year);
            printf("\nSong edited successfully!\n");
            return;
        }
    }
    printf("\nSong not found!\n");
}

void deleteSong(song library[], int size) {
    int i, index = -1;
    char query[50];
    printf("\nEnter the name of the song to delete: ");
    scanf("%s", query);
    for (i = 0; i < size; i++) {
        if (strcmp(library[i].name, query) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nSong not found!\n");
        return;
    }
    for (i = index; i < size - 1; i++) {
        library[i] = library[i + 1];
    }
    printf("\nSong deleted successfully!\n");
}

void displayLibrary(song library[], int size) {
    int i;
    if (size == 0) {
        printf("\nThe library is empty!\n");
        return;
    }
    printf("\nMusic Library:\n");
    for (i = 0; i < size; i++) {
        printf("%d. %s - %s (%s)[%d]\n", i + 1, library[i].artist, library[i].name, library[i].album, library[i].year);
    }
}

int main() {
    int option, size = 0;
    song library[100];
    printf("\nWelcome to the Music Library Management System!\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Search for a song\n");
        printf("2. Add a song\n");
        printf("3. Edit a song\n");
        printf("4. Delete a song\n");
        printf("5. Display the music library\n");
        printf("6. Exit\n\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                searchSong(library, size);
                break;
            case 2:
                addSong(library, size);
                size++;
                break;
            case 3:
                editSong(library, size);
                break;
            case 4:
                deleteSong(library, size);
                size--;
                break;
            case 5:
                displayLibrary(library, size);
                break;
            case 6:
                printf("\nThank you for using the Music Library Management System!\n");
                break;
            default:
                printf("\nPlease enter a valid option!\n");
        }
    } while (option != 6);
    return 0;
}