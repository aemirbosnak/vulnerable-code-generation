//FormAI DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

struct movie {
    char title[50];
    int ratings[MAX_RATINGS];
    float avg_rating;
    int num_ratings;
};

typedef struct movie Movie;

void add_movie(Movie* movies, int* num_movies);
void add_rating(Movie* movies, int num_movies);
void display_movies(Movie* movies, int num_movies);
void display_ratings(Movie* movies, int num_movies);
void sort_movies(Movie* movies, int num_movies);

int main() {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    int choice;

    while(1) {
        printf("C Movie Rating System\n");
        printf("----------------------------------\n");
        printf("1. Add a movie\n");
        printf("2. Add a rating\n");
        printf("3. Display movie list\n");
        printf("4. Display movie ratings\n");
        printf("5. Sort movie list\n");
        printf("6. Quit\n");
        printf("----------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                add_rating(movies, num_movies);
                break;
            case 3:
                display_movies(movies, num_movies);
                break;
            case 4:
                display_ratings(movies, num_movies);
                break;
            case 5:
                sort_movies(movies, num_movies);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void add_movie(Movie* movies, int* num_movies) {
    if(*num_movies == MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return;
    }

    Movie new_movie;

    printf("Enter title: ");
    scanf("%s", new_movie.title);

    new_movie.num_ratings = 0;
    new_movie.avg_rating = 0;

    movies[*num_movies] = new_movie;

    (*num_movies)++;

    printf("Movie added successfully.\n");
}

void add_rating(Movie* movies, int num_movies) {
    char movie_title[50];
    int rating;
    int found = 0;

    printf("Enter movie title: ");
    scanf("%s", movie_title);

    for(int i = 0; i < num_movies; i++) {
        if(strcmp(movies[i].title, movie_title) == 0) {
            printf("Enter rating (1-5): ");
            scanf("%d", &rating);

            if(rating >= 1 && rating <= 5) {
                movies[i].ratings[movies[i].num_ratings] = rating;
                movies[i].num_ratings++;
                found = 1;

                float sum = 0;

                for(int j = 0; j < movies[i].num_ratings; j++) {
                    sum += movies[i].ratings[j];
                }

                movies[i].avg_rating = sum / movies[i].num_ratings;

                printf("Rating added successfully.\n");

                break;
            }
            else {
                printf("Invalid rating. Please try again.\n");
                break;
            }
        }
    }

    if(!found) {
        printf("Movie not found. Please try again.\n");
    }
}

void display_movies(Movie* movies, int num_movies) {
    if(num_movies == 0) {
        printf("No movies found.\n");
        return;
    }

    printf("Movie List:\n");

    for(int i = 0; i < num_movies; i++) {
        printf("%d. %s\n", i+1, movies[i].title);
    }
}

void display_ratings(Movie* movies, int num_movies) {
    char movie_title[50];
    int found = 0;

    printf("Enter movie title: ");
    scanf("%s", movie_title);

    for(int i = 0; i < num_movies; i++) {
        if(strcmp(movies[i].title, movie_title) == 0) {
            printf("Ratings for %s:\n", movie_title);

            for(int j = 0; j < movies[i].num_ratings; j++) {
                printf("%d ", movies[i].ratings[j]);
            }

            printf("\n");
            printf("Average rating: %0.2f\n", movies[i].avg_rating);

            found = 1;

            break;
        }
    }

    if(!found) {
        printf("Movie not found. Please try again.\n");
    }
}

void sort_movies(Movie* movies, int num_movies) {
    int i, j, k;
    Movie temp;

    for(i = 0; i < num_movies - 1; i++) {
        k = i;

        for(j = i + 1; j < num_movies; j++) {
            if(strcmp(movies[j].title, movies[k].title) < 0) {
                k = j;
            }
        }

        if(k != i) {
            temp = movies[i];
            movies[i] = movies[k];
            movies[k] = temp;
        }
    }

    printf("Movie list sorted successfully.\n");
}