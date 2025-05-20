//FormAI DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a music item
struct MusicItem {
    char title[50];
    char artist[30];
    char genre[20];
    int year;
};

// Function to add a new item to the library
void addMusicItem(struct MusicItem *library, int *numItems) {
    struct MusicItem newItem;
    printf("Enter the item's title: ");
    scanf("%s", newItem.title);
    printf("Enter the item's artist: ");
    scanf("%s", newItem.artist);
    printf("Enter the item's genre: ");
    scanf("%s", newItem.genre);
    printf("Enter the item's year: ");
    scanf("%d", &newItem.year);
    library[*numItems] = newItem;
    *numItems += 1;
    printf("Item successfully added to library!\n");
}

// Function to search for an item in the library by title
void searchMusicItem(struct MusicItem *library, int numItems) {
    char title[50];
    printf("Enter the title of the item you are looking for: ");
    scanf("%s", title);
    for (int i = 0; i < numItems; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Item found!\nTitle: %s\nArtist: %s\nGenre: %s\nYear: %d\n", library[i].title, library[i].artist, library[i].genre, library[i].year);
            return;
        }
    }
    printf("Item not found in library.\n");
}

// Function to delete an item from the library by title
void deleteMusicItem(struct MusicItem *library, int *numItems) {
    char title[50];
    printf("Enter the title of the item you want to delete: ");
    scanf("%s", title);
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < *numItems - 1; j++) {
                library[j] = library[j+1];
            }
            *numItems -= 1;
            printf("Item successfully deleted from library!\n");
            return;
        }
    }
    printf("Item not found in library, deletion failed.\n");
}

// Main function
int main() {
    struct MusicItem library[100];
    int numItems = 0;
    int userChoice;
    while (1) {
        printf("Welcome to the Music Library Management System!\n");
        printf("1. Add new item\n2. Search for item\n3. Delete item\n4. Exit program\n");
        printf("Please enter your choice: ");
        scanf("%d", &userChoice);
        switch (userChoice) {
            case 1:
                addMusicItem(library, &numItems);
                break;
            case 2:
                searchMusicItem(library, numItems);
                break;
            case 3:
                deleteMusicItem(library, &numItems);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}