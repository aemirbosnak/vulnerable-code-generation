//FormAI DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE 100
#define MAX_ARTIST 50

struct Song {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int rating;
};

void print_menu() {
    printf("\n");
    printf("1. Add a new song\n");
    printf("2. Remove a song\n");
    printf("3. Display all songs\n");
    printf("4. Search for a song\n");
    printf("5. Update a song\n");
    printf("6. Exit\n");
    printf("\n");
}

int add_song(struct Song collection[], int num_songs) {
    if (num_songs == MAX_SONGS) {
        printf("Error: song collection is full.\n");
        return num_songs;
    }
    
    printf("Enter title: ");
    fgets(collection[num_songs].title, MAX_TITLE, stdin);
    collection[num_songs].title[strcspn(collection[num_songs].title, "\n")] = '\0';
    
    printf("Enter artist: ");
    fgets(collection[num_songs].artist, MAX_ARTIST, stdin);
    collection[num_songs].artist[strcspn(collection[num_songs].artist, "\n")] = '\0';
    
    printf("Enter rating (0-5): ");
    scanf("%d", &collection[num_songs].rating);
    getchar();
    
    printf("Song added successfully.\n");
    
    return num_songs + 1;
}

int remove_song(struct Song collection[], int num_songs) {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    
    printf("Enter title: ");
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = '\0';
    
    printf("Enter artist: ");
    fgets(artist, MAX_ARTIST, stdin);
    artist[strcspn(artist, "\n")] = '\0';
    
    int i, j;
    for (i = 0; i < num_songs; i++) {
        if (strcmp(collection[i].title, title) == 0 && strcmp(collection[i].artist, artist) == 0) {
            for (j = i; j < num_songs - 1; j++) {
                collection[j] = collection[j+1];
            }
            
            printf("Song removed successfully.\n");
            
            return num_songs - 1;
        }
    }
    
    printf("Error: song not found.\n");
    
    return num_songs;
}

void display_songs(struct Song collection[], int num_songs) {
    if (num_songs == 0) {
        printf("No songs in collection.\n");
        return;
    }
    
    int i;
    for (i = 0; i < num_songs; i++) {
        printf("%d. %s - %s (rating: %d)\n", i+1, collection[i].artist, collection[i].title, collection[i].rating);
    }
}

void search_songs(struct Song collection[], int num_songs) {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    
    printf("Enter title: ");
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = '\0';
    
    printf("Enter artist: ");
    fgets(artist, MAX_ARTIST, stdin);
    artist[strcspn(artist, "\n")] = '\0';
    
    int i;
    for (i = 0; i < num_songs; i++) {
        if (strcmp(collection[i].title, title) == 0 && strcmp(collection[i].artist, artist) == 0) {
            printf("%d. %s - %s (rating: %d)\n", i+1, collection[i].artist, collection[i].title, collection[i].rating);
            return;
        }
    }
    
    printf("Error: song not found.\n");
}

int update_song(struct Song collection[], int num_songs) {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    
    printf("Enter title: ");
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = '\0';
    
    printf("Enter artist: ");
    fgets(artist, MAX_ARTIST, stdin);
    artist[strcspn(artist, "\n")] = '\0';
    
    int i;
    for (i = 0; i < num_songs; i++) {
        if (strcmp(collection[i].title, title) == 0 && strcmp(collection[i].artist, artist) == 0) {
            printf("Enter new rating (0-5): ");
            scanf("%d", &collection[i].rating);
            getchar();
            
            printf("Song updated successfully.\n");
            
            return num_songs;
        }
    }
    
    printf("Error: song not found.\n");
    
    return num_songs;
}

int main() {
    struct Song collection[MAX_SONGS];
    int num_songs = 0;
    int choice;
    
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                num_songs = add_song(collection, num_songs);
                break;
            case 2:
                num_songs = remove_song(collection, num_songs);
                break;
            case 3:
                display_songs(collection, num_songs);
                break;
            case 4:
                search_songs(collection, num_songs);
                break;
            case 5:
                num_songs = update_song(collection, num_songs);
                break;
            case 6:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}