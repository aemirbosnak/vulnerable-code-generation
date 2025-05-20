//FormAI DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include<stdio.h>
#include<string.h>
#define SIZE 100

// Struct to represent a music item
struct MusicItem {
    char title[SIZE];
    char artist[SIZE];
    int year;
};

// Function to add a new music item
void add_item(struct MusicItem library[], int *count) {
    // Check if there is space in the library
    if (*count < SIZE) {

        printf("\nPlease enter the music title: ");
        fgets(library[*count].title, SIZE, stdin);

        printf("Please enter the artist name: ");
        fgets(library[*count].artist, SIZE, stdin);

        printf("Please enter the year of release: ");
        scanf("%d", &library[*count].year);
        
        // Clearing input buffer
        getchar();

        printf("Music item added successfully!\n");
        *count += 1;
    }
    else {
        printf("Library is full. Cannot add more music items.\n");
    }
}

// Function to search and display music items by artist name
void search_artist(struct MusicItem library[], int count) {
    char search[SIZE];
    int found = 0;

    printf("\nPlease enter the artist to search for: ");
    fgets(search, SIZE, stdin);
    search[strcspn(search, "\n")] = 0; // Removing the newline character from the input

    for (int i = 0; i < count; i++) {
        if (strcmp(search, library[i].artist) == 0) {
            printf("Title: %s\nArtist: %s\nYear: %d\n\n", library[i].title, library[i].artist, library[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No music item found with artist name '%s'\n", search);
    }
}

int main() {
    struct MusicItem library[SIZE]; // Array to store the music items
    int count = 0; // Number of music items in the library
    
    // Main menu loop
    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add a new music item\n");
        printf("2. Search music item by artist name\n");
        printf("3. Exit\n");
        printf("Please enter your choice (1-3): ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clearing input buffer
        
        switch(choice) {
            case 1:
                add_item(library, &count);
                break;

            case 2:
                search_artist(library, count);
                break;

            case 3:
                printf("\nThank you for using Music Library Management System!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}