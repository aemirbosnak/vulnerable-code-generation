//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int rating;
    char genre[100];
} Movie;

int main() {
    Movie movies[5];
    int i, n;
    char choice;

    // Create some movies
    for (i = 0; i < 5; i++) {
        printf("Enter movie name: ");
        fgets(movies[i].name, sizeof(movies[i].name), stdin);
        fgets(movies[i].genre, sizeof(movies[i].genre), stdin);
        printf("Enter rating (0-10): ");
        scanf("%d", &movies[i].rating);
    }

    // Display the movies and ask for user input
    printf("\nMovies:\n");
    for (i = 0; i < 5; i++) {
        printf("%s (%d) %s\n", movies[i].name, movies[i].rating, movies[i].genre);
    }

    while (1) {
        printf("\nWhat would you like to do? (l)ist, (r)ate, (a)dd, (q)uit: ");
        scanf("%c", &choice);

        if (choice == 'l') {
            // List all movies
            for (i = 0; i < 5; i++) {
                printf("%s (%d) %s\n", movies[i].name, movies[i].rating, movies[i].genre);
            }
        } else if (choice == 'r') {
            // Ask for movie name and update its rating
            printf("Enter movie name: ");
            fgets(movies[i].name, sizeof(movies[i].name), stdin);
            printf("Enter new rating: ");
            scanf("%d", &movies[i].rating);
        } else if (choice == 'a') {
            // Add a new movie
            printf("Enter movie name: ");
            fgets(movies[i].name, sizeof(movies[i].name), stdin);
            printf("Enter rating (0-10): ");
            scanf("%d", &movies[i].rating);
            printf("Enter genre: ");
            fgets(movies[i].genre, sizeof(movies[i].genre), stdin);
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}