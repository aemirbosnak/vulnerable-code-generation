//FormAI DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct album {
    char title[50];
    char artist[50];
    char genre[50];
    char year[5];
};

int main() {
    int option, num_of_albums = 0, i;
    struct album albums[50];
    char search_term[50];

    printf("\n\nWelcome to the C Music Library Management System!\n");

    while (1) {
        printf("\n\nWhat would you like to do?\n");
        printf("1. Add an album\n");
        printf("2. View all albums\n");
        printf("3. Search for an album\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Adding an album...\n\n");

                printf("Enter the title: ");
                scanf(" %[^\n]%*c", albums[num_of_albums].title);

                printf("Enter the artist: ");
                scanf(" %[^\n]%*c", albums[num_of_albums].artist);

                printf("Enter the genre: ");
                scanf(" %[^\n]%*c", albums[num_of_albums].genre);

                printf("Enter the year: ");
                scanf(" %[^\n]%*c", albums[num_of_albums].year);

                printf("\n%s by %s added to the library!\n", albums[num_of_albums].title, albums[num_of_albums].artist);

                num_of_albums++;

                break;

            case 2:
                printf("Viewing all albums...\n\n");

                for (i = 0; i < num_of_albums; i++) {
                    printf("%d. Title: %s\n", i+1, albums[i].title);
                    printf("   Artist: %s\n", albums[i].artist);
                    printf("   Genre: %s\n", albums[i].genre);
                    printf("   Year: %s\n\n", albums[i].year);
                }

                break;

            case 3:
                printf("Searching for an album...\n\n");

                printf("Enter the search term: ");
                scanf(" %[^\n]%*c", search_term);

                for (i = 0; i < num_of_albums; i++) {
                    if (strstr(albums[i].title, search_term) != NULL || strstr(albums[i].artist, search_term) != NULL || strstr(albums[i].genre, search_term) != NULL || strstr(albums[i].year, search_term) != NULL) {
                        printf("%d. Title: %s\n", i+1, albums[i].title);
                        printf("   Artist: %s\n", albums[i].artist);
                        printf("   Genre: %s\n", albums[i].genre);
                        printf("   Year: %s\n\n", albums[i].year);
                    }
                }

                break;

            case 4:
                printf("Exiting the program...\n\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}