//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct Movie {
    char title[50];
    int rating;
};

void print_movie(struct Movie *movie) {
    printf("%s: %d\n", movie->title, movie->rating);
}

void add_movie(struct Movie *movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    printf("Enter movie rating: ");
    scanf("%d", &movie->rating);
}

void edit_movie(struct Movie *movie) {
    printf("Enter new movie title: ");
    scanf("%s", movie->title);
    printf("Enter new movie rating: ");
    scanf("%d", &movie->rating);
}

void delete_movie(struct Movie *movie) {
    free(movie);
}

void print_menu() {
    printf("MENU:\n");
    printf("1. Add new movie\n");
    printf("2. Edit movie\n");
    printf("3. Delete movie\n");
    printf("4. Print movie\n");
    printf("5. Exit\n");
}

int main() {
    struct Movie *movie = NULL;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                movie = malloc(sizeof(struct Movie));
                add_movie(movie);
                break;
            case 2:
                if (movie == NULL) {
                    printf("No movie to edit.\n");
                    break;
                }
                edit_movie(movie);
                break;
            case 3:
                if (movie == NULL) {
                    printf("No movie to delete.\n");
                    break;
                }
                delete_movie(movie);
                break;
            case 4:
                if (movie == NULL) {
                    printf("No movie to print.\n");
                    break;
                }
                print_movie(movie);
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}