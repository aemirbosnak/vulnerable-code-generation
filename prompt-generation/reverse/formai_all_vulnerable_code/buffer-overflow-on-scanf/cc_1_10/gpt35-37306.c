//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 1000

// Song Structure
typedef struct song {
    char title[50];
    char artist[30];
    char album[30];
    int year;
} song;

// Display Menu
void displayMenu() {
    printf("Music Library Management System\n");
    printf("-----------------------------------\n");
    printf("1. Add Song\n");
    printf("2. Display All Songs\n");
    printf("3. Search Song\n");
    printf("4. Delete Song\n");
    printf("5. Exit\n");
}

// Add Song
void addSong(song s[], int *count) {
    if (*count == MAX_SONGS) {
        printf("The library is full. Unable to add any more songs.\n");
        return;
    }

    printf("Enter Song Title: ");
    fgets(s[*count].title, 50, stdin);
    s[*count].title[strcspn(s[*count].title, "\n")] = 0;

    printf("Enter Artist Name: ");
    fgets(s[*count].artist, 30, stdin);
    s[*count].artist[strcspn(s[*count].artist, "\n")] = 0;

    printf("Enter Album Name: ");
    fgets(s[*count].album, 30, stdin);
    s[*count].album[strcspn(s[*count].album, "\n")] = 0;

    printf("Enter Year: ");
    scanf("%d", &s[*count].year);

    (*count)++;
    printf("Song added successfully.\n");
}

// Display All Songs
void displaySongs(song s[], int count) {
    if (count == 0) {
        printf("The library is empty.\n");
        return;
    }

    printf("\nList of Songs:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s (%s) [%d]\n", i+1, s[i].title, s[i].artist, s[i].album, s[i].year);
    }
}

// Search Song
void searchSong(song s[], int count) {
    if (count == 0) {
        printf("The library is empty.\n");
        return;
    }

    char title[50];
    printf("Enter Song Title: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(s[i].title, title) == 0) {
            printf("%s - %s (%s) [%d]\n", s[i].title, s[i].artist, s[i].album, s[i].year);
            return;
        }
    }

    printf("Song not found.\n");
}

// Delete Song
void deleteSong(song s[], int *count) {
    if (*count == 0) {
        printf("The library is empty.\n");
        return;
    }

    char title[50];
    printf("Enter Song Title: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(s[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        s[i] = s[i+1];
    }

    (*count)--;
    printf("Song deleted successfully.\n");
}

// Main Function
int main() {
    song library[MAX_SONGS];
    int count = 0, choice;

    while (1) {
        displayMenu();
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                addSong(library, &count);
                break;
            case 2:
                displaySongs(library, count);
                break;
            case 3:
                searchSong(library, count);
                break;
            case 4:
                deleteSong(library, &count);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice.\n");
        }

        getchar();
    }

    return 0;
}