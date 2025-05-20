//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 1000
#define MAX_NAME_LENGTH 100
#define MAX_GENRE_LENGTH 50

struct movie {
    char name[MAX_NAME_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
    int vote_count;
};

struct movie movies[MAX_MOVIES];
int num_movies = 0;

void add_movie() {
    printf("Enter movie name: ");
    scanf("%s", movies[num_movies].name);

    printf("Enter movie genre: ");
    scanf("%s", movies[num_movies].genre);

    movies[num_movies].rating = 0;
    movies[num_movies].vote_count = 0;

    num_movies++;
}

void rate_movie(int index) {
    printf("Enter rating for movie %s: ", movies[index].name);
    scanf("%d", &movies[index].rating);

    movies[index].vote_count++;
}

void sort_movies() {
    for (int i = 0; i < num_movies - 1; i++) {
        for (int j = i + 1; j < num_movies; j++) {
            if (movies[i].rating < movies[j].rating) {
                struct movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

void print_movies() {
    printf("Movie Name\t\tGenre\t\tRating\t\tVote Count\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s\t\t%s\t\t%d\t\t%d\n", movies[i].name, movies[i].genre, movies[i].rating, movies[i].vote_count);
    }
}

int main() {
    printf("Welcome to the Movie Rating System!\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add movie\n");
        printf("2. Rate movie\n");
        printf("3. Sort movies\n");
        printf("4. Print movies\n");
        printf("0. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1:
            add_movie();
            break;
        case 2:
            printf("Enter movie index: ");
            int index;
            scanf("%d", &index);
            rate_movie(index);
            break;
        case 3:
            sort_movies();
            break;
        case 4:
            print_movies();
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}