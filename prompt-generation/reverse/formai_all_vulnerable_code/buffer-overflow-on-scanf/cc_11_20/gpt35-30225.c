//FormAI DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char title[50];
    char artist[50];
    char album[50];
    int year;
    char genre[20];
} Song;

int main() {
    Song library[50]; // initialize an array to hold up to 50 songs
    int num_songs = 0; // keep track of number of songs in the library currently

    // display welcome message and menu options
    printf("Welcome to the C Music Library Management System!\n");
    printf("Please choose an option below:\n");
    printf("1. Add a song\n");
    printf("2. Remove a song\n");
    printf("3. Search for a song\n");
    printf("4. Display all songs\n");
    printf("5. Exit program\n");

    int choice;
    scanf("%d", &choice);

    while (choice != 5) {
        switch (choice) {
            case 1:
                printf("Please enter the following information for the song:\n");
                printf("ID (integer): ");
                scanf("%d", &library[num_songs].id);
                getchar(); // consume newline character

                printf("Title: ");
                fgets(library[num_songs].title, sizeof(library[num_songs].title), stdin);
                library[num_songs].title[strcspn(library[num_songs].title, "\n")] = 0; // remove newline character

                printf("Artist: ");
                fgets(library[num_songs].artist, sizeof(library[num_songs].artist), stdin);
                library[num_songs].artist[strcspn(library[num_songs].artist, "\n")] = 0;

                printf("Album: ");
                fgets(library[num_songs].album, sizeof(library[num_songs].album), stdin);
                library[num_songs].album[strcspn(library[num_songs].album, "\n")] = 0;

                printf("Year (integer): ");
                scanf("%d", &library[num_songs].year);
                getchar(); // consume newline character

                printf("Genre: ");
                fgets(library[num_songs].genre, sizeof(library[num_songs].genre), stdin);
                library[num_songs].genre[strcspn(library[num_songs].genre, "\n")] = 0;

                num_songs++;
                printf("Song added to library.\n");
                break;
            case 2:
                printf("Please enter the ID of the song to remove: ");
                int remove_id;
                scanf("%d", &remove_id);
                getchar(); // consume newline character

                int remove_index = -1;
                for (int i = 0; i < num_songs; i++) {
                    if (library[i].id == remove_id) {
                        remove_index = i;
                        break;
                    }
                }

                if (remove_index == -1) {
                    printf("Sorry, that ID does not exist in the library.\n");
                } else {
                    for (int i = remove_index; i < num_songs-1; i++) {
                        library[i] = library[i+1];
                    }
                    num_songs--;
                    printf("Song removed from library.\n");
                }
                break;
            case 3:
                printf("Please enter the ID of the song to search for: ");
                int search_id;
                scanf("%d", &search_id);
                getchar(); // consume newline character

                int search_index = -1;
                for (int i = 0; i < num_songs; i++) {
                    if (library[i].id == search_id) {
                        search_index = i;
                        break;
                    }
                }

                if (search_index == -1) {
                    printf("Sorry, that ID does not exist in the library.\n");
                } else {
                    printf("Search result:\n");
                    printf("Title: %s\n", library[search_index].title);
                    printf("Artist: %s\n", library[search_index].artist);
                    printf("Album: %s\n", library[search_index].album);
                    printf("Year: %d\n", library[search_index].year);
                    printf("Genre: %s\n", library[search_index].genre);
                }
                break;
            case 4:
                printf("All songs in the library:\n");
                for (int i = 0; i < num_songs; i++) {
                    printf("%d - %s by %s, from the album %s released in %d, genre: %s\n", 
                            library[i].id, library[i].title, library[i].artist, library[i].album, library[i].year, library[i].genre);
                }
                break;
            default:
                printf("Invalid input.\n");
        }

        // re-display menu options
        printf("\nPlease choose an option below:\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Search for a song\n");
        printf("4. Display all songs\n");
        printf("5. Exit program\n");
        scanf("%d", &choice);
    }

    printf("Exiting program. Thank you for using the C Music Library Management System!\n");

    return 0;
}