//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ada Lovelace
#include <stdio.h>

struct movie {
    char title[50];
    char director[50];
    char rating[10];
};

void display_menu() {
    printf("\n===== Movie Rating System =====\n");
    printf("1. Add a movie\n");
    printf("2. View all movies\n");
    printf("3. Search for a movie\n");
    printf("4. Exit\n");
}

void add_movie(struct movie *movies, int *count) {
    printf("\n===== Add a Movie =====\n");
    printf("Title: ");
    scanf("%s", movies[*count].title);
    printf("Director: ");
    scanf("%s", movies[*count].director);
    printf("Rating (1-10): ");
    scanf("%s", movies[*count].rating);
    (*count)++;
}

void view_movies(struct movie *movies, int count) {
    if (count == 0) {
        printf("\nNo movies to display\n");
        return;
    }
    printf("\n===== List of Movies =====\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Rating: %s\n", movies[i].rating);
        printf("-------------------------\n");
    }
}

void search_movie(struct movie *movies, int count, char query[]) {
    int found = 0;
    printf("\n===== Search Results =====\n");
    for (int i = 0; i < count; i++) {
        if (strstr(movies[i].title, query) != NULL) {
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Rating: %s\n", movies[i].rating);
            printf("-------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No results found for '%s'\n", query);
    }
}

int main() {
    struct movie movies[100];
    int count = 0;
    int choice;
    char query[50];

    printf("\nWelcome to the Movie Rating System!\n");

    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                view_movies(movies, count);
                break;
            case 3:
                printf("\nEnter search query: ");
                scanf("%s", query);
                search_movie(movies, count, query);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}