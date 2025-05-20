//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Song {
    char title[50];
    char artist[50];
    char genre[20];
} Song;

Song library[MAX_SIZE];
int count = 0;

void addSong() {
    if (count == MAX_SIZE) {
        printf("Music Library is Full.\n");
        return;
    }

    printf("Enter Song Title: ");
    scanf("%s", library[count].title);

    printf("Enter Artist Name: ");
    scanf("%s", library[count].artist);

    printf("Enter Genre: ");
    scanf("%s", library[count].genre);

    count++;
}

void displayLibrary() {
    if (count == 0) {
        printf("Music Library is Empty.\n");
        return;
    }

    printf("\nMusic Library:\n");
    printf("------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("| %d | %-20s | %-20s | %-10s |\n", i+1, library[i].title, library[i].artist, library[i].genre);
    }

    printf("------------------------\n");
}

void searchSong() {
    char title[50];
    int index = -1;

    printf("Enter Title to Search: ");
    scanf("%s", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song Not Found.\n");
    } else {
        printf("Song Found:\n");
        printf("Title: %s\n", library[index].title);
        printf("Artist: %s\n", library[index].artist);
        printf("Genre: %s\n", library[index].genre);
    }
}

void deleteSong() {
    char title[50];
    int index = -1;

    printf("Enter Title to Delete: ");
    scanf("%s", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song Not Found.\n");
    } else {
        for (int i = index; i < count-1; i++) {
            library[i] = library[i+1];
        }

        count--;
        printf("Song Deleted.\n");
    }
}

int main() {
    int choice;

    while (true) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Display Library\n");
        printf("3. Search Song\n");
        printf("4. Delete Song\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                displayLibrary();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                deleteSong();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}