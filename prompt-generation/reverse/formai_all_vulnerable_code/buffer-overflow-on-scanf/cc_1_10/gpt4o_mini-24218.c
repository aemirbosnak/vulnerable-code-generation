//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC 100
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char genre[MAX_TITLE_LENGTH];
    int year;
    int isAvailable;
} Music;

Music library[MAX_MUSIC];
int musicCount = 0;

void displayMenu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Music\n");
    printf("2. View All Music\n");
    printf("3. Search Music\n");
    printf("4. Delete Music\n");
    printf("5. Borrow Music\n");
    printf("6. Return Music\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

void addMusic() {
    if (musicCount == MAX_MUSIC) {
        printf("Library is full! Cannot add more music.\n");
        return;
    }
    
    Music newMusic;

    printf("Enter title: ");
    getchar(); // To consume the newline character
    fgets(newMusic.title, MAX_TITLE_LENGTH, stdin);
    newMusic.title[strcspn(newMusic.title, "\n")] = 0; // remove newline

    printf("Enter artist: ");
    fgets(newMusic.artist, MAX_ARTIST_LENGTH, stdin);
    newMusic.artist[strcspn(newMusic.artist, "\n")] = 0; // remove newline

    printf("Enter genre: ");
    fgets(newMusic.genre, MAX_TITLE_LENGTH, stdin);
    newMusic.genre[strcspn(newMusic.genre, "\n")] = 0; // remove newline

    printf("Enter year of release: ");
    scanf("%d", &newMusic.year);
    newMusic.isAvailable = 1; // Mark as available

    library[musicCount++] = newMusic;
    printf("Music added successfully!\n");
}

void viewAllMusic() {
    if (musicCount == 0) {
        printf("No music available in the library.\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < musicCount; i++) {
        printf("Title: %s, Artist: %s, Genre: %s, Year: %d, Status: %s\n", 
                library[i].title, 
                library[i].artist, 
                library[i].genre, 
                library[i].year, 
                library[i].isAvailable ? "Available" : "Borrowed");
    }
}

void searchMusic() {
    if (musicCount == 0) {
        printf("No music available to search.\n");
        return;
    }

    char searchTerm[MAX_TITLE_LENGTH];
    printf("Enter title or artist to search: ");
    getchar(); // To consume the newline character
    fgets(searchTerm, MAX_TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < musicCount; i++) {
        if (strstr(library[i].title, searchTerm) || strstr(library[i].artist, searchTerm)) {
            printf("Found: %s by %s, Genre: %s, Year: %d\n", 
                    library[i].title, 
                    library[i].artist, 
                    library[i].genre, 
                    library[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No music found matching the search term.\n");
    }
}

void deleteMusic() {
    if (musicCount == 0) {
        printf("No music to delete.\n");
        return;
    }

    char titleToRemove[MAX_TITLE_LENGTH];
    printf("Enter title of music to delete: ");
    getchar(); // To consume the newline character
    fgets(titleToRemove, MAX_TITLE_LENGTH, stdin);
    titleToRemove[strcspn(titleToRemove, "\n")] = 0; // remove newline

    for (int i = 0; i < musicCount; i++) {
        if (strcmp(library[i].title, titleToRemove) == 0) {
            for (int j = i; j < musicCount - 1; j++) {
                library[j] = library[j + 1]; // shift left
            }
            musicCount--;
            printf("Music deleted successfully.\n");
            return;
        }
    }

    printf("Music not found in the library!\n");
}

void borrowMusic() {
    if (musicCount == 0) {
        printf("No music available to borrow.\n");
        return;
    }

    char titleToBorrow[MAX_TITLE_LENGTH];
    printf("Enter title of music to borrow: ");
    getchar(); // To consume the newline character
    fgets(titleToBorrow, MAX_TITLE_LENGTH, stdin);
    titleToBorrow[strcspn(titleToBorrow, "\n")] = 0; // remove newline

    for (int i = 0; i < musicCount; i++) {
        if (strcmp(library[i].title, titleToBorrow) == 0) {
            if (library[i].isAvailable) {
                library[i].isAvailable = 0; // Mark as borrowed
                printf("You have borrowed: %s\n", library[i].title);
                return;
            } else {
                printf("Sorry, this music is currently borrowed.\n");
                return;
            }
        }
    }

    printf("Music not found in the library!\n");
}

void returnMusic() {
    if (musicCount == 0) {
        printf("No music available to return.\n");
        return;
    }

    char titleToReturn[MAX_TITLE_LENGTH];
    printf("Enter title of music to return: ");
    getchar(); // To consume the newline character
    fgets(titleToReturn, MAX_TITLE_LENGTH, stdin);
    titleToReturn[strcspn(titleToReturn, "\n")] = 0; // remove newline

    for (int i = 0; i < musicCount; i++) {
        if (strcmp(library[i].title, titleToReturn) == 0) {
            if (!library[i].isAvailable) {
                library[i].isAvailable = 1; // Mark as available
                printf("You have returned: %s\n", library[i].title);
                return;
            } else {
                printf("This music was not borrowed.\n");
                return;
            }
        }
    }

    printf("Music not found in the library!\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMusic(); break;
            case 2: viewAllMusic(); break;
            case 3: searchMusic(); break;
            case 4: deleteMusic(); break;
            case 5: borrowMusic(); break;
            case 6: returnMusic(); break;
            case 7: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}