//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    int year;
} song;

int main() {
    int choice, count = 0;
    song *library = NULL;
    printf("Welcome to the Music Library Management System\n\n");

    while (1) {
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. View all songs\n");
        printf("4. Search for a song\n");
        printf("5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a song
                printf("\nAdding a song\n\n");
                library = realloc(library, (count + 1) * sizeof(song));
                printf("Enter the title of the song: ");
                scanf("%s", library[count].title);
                printf("Enter the artist of the song: ");
                scanf("%s", library[count].artist);
                printf("Enter the year of the song: ");
                scanf("%d", &library[count].year);
                count++;
                printf("Song added successfully!\n\n");
                break;
            case 2: // Remove a song
                if (count == 0) {
                    printf("\nThe library is currently empty.\n\n");
                } else {
                    char title[50];
                    int found = 0;
                    printf("\nEnter the title of the song to remove: ");
                    scanf("%s", title);
                    for (int i = 0; i < count; i++) {
                        if (strcmp(title, library[i].title) == 0) {
                            memmove(&library[i], &library[i + 1], (count - i - 1) * sizeof(song));
                            library = realloc(library, (count - 1) * sizeof(song));
                            count--;
                            printf("Song removed successfully!\n\n");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("No song with that title was found.\n\n");
                    }
                }
                break;
            case 3: // View all songs
                if (count == 0) {
                    printf("\nThe library is currently empty.\n\n");
                } else {
                    printf("\nAll songs currently in the library:\n");
                    for (int i = 0; i < count; i++) {
                        printf("Title: %s\n", library[i].title);
                        printf("Artist: %s\n", library[i].artist);
                        printf("Year: %d\n\n", library[i].year);
                    }
                }
                break;
            case 4: // Search for a song
                if (count == 0) {
                    printf("\nThe library is currently empty.\n\n");
                } else {
                    char title[50];
                    int found = 0;
                    printf("\nEnter the title of the song to search for: ");
                    scanf("%s", title);
                    for (int i = 0; i < count; i++) {
                        if (strcmp(title, library[i].title) == 0) {
                            printf("Song found:\n");
                            printf("Title: %s\n", library[i].title);
                            printf("Artist: %s\n", library[i].artist);
                            printf("Year: %d\n\n", library[i].year);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("No song with that title was found.\n\n");
                    }
                }
                break;
            case 5: // Exit
                printf("\nExiting the Music Library Management System. Goodbye!\n");
                free(library);
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 5.\n\n");
        }
    }

    return 0;
}