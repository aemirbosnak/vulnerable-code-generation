//FormAI DATASET v1.0 Category: Movie Rating System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Structures
struct movie_rating {
    char title[50];
    char genre[20];
    int year;
    float rating;
};

struct critic_rating {
    char name[50];
    float rating;
};

// Function prototypes
void add_movie_rating(struct movie_rating*);
void add_critic_rating(struct movie_rating*, struct critic_rating*);
void print_movie_ratings(struct movie_rating*, int);
void print_critic_ratings(struct movie_rating*, struct critic_rating*, int);
void print_top_rated_movies(struct movie_rating*, int);

// Main function
int main() {
    int num_movies, num_critics;

    // Ask user for number of movies and critics
    printf("How many movies do you want to rate?\n");
    scanf("%d", &num_movies);
    printf("How many critics do you want to rate these movies?\n");
    scanf("%d", &num_critics);

    // Create movie rating array
    struct movie_rating* movie_ratings = (struct movie_rating*) malloc(num_movies * sizeof(struct movie_rating));

    // Create critic rating array
    struct critic_rating* critic_ratings = (struct critic_rating*) malloc(num_critics * sizeof(struct critic_rating));

    // Add movie ratings
    add_movie_rating(movie_ratings);

    // Add critic ratings
    add_critic_rating(movie_ratings, critic_ratings);

    // Print movie ratings
    printf("\n");
    print_movie_ratings(movie_ratings, num_movies);

    // Print critic ratings
    printf("\n");
    print_critic_ratings(movie_ratings, critic_ratings, num_critics);

    // Print top rated movies
    printf("\nTop rated movies:\n");
    print_top_rated_movies(movie_ratings, num_movies);

    // Free memory
    free(movie_ratings);
    free(critic_ratings);

    return 0;
}

// Function to add movie ratings
void add_movie_rating(struct movie_rating* movie_ratings) {
    for(int i=0; i < sizeof(*movie_ratings); i++) {
        // Get movie title
        printf("Enter title of movie %d:\n", i+1);
        scanf(" %[^\n]%*c", movie_ratings[i].title);
        
        // Get movie genre
        printf("Enter genre of movie %d:\n", i+1);
        scanf(" %[^\n]%*c", movie_ratings[i].genre);
        
        // Get movie year
        printf("Enter year of movie %d:\n", i+1);
        scanf("%d", &movie_ratings[i].year);
        
        // Get movie rating
        printf("Enter rating of movie %d (out of 10):\n", i+1);
        scanf("%f", &movie_ratings[i].rating);
    }
}

// Function to add critic ratings
void add_critic_rating(struct movie_rating* movie_ratings, struct critic_rating* critic_ratings) {
    for(int i=0; i < sizeof(*critic_ratings); i++) {
        // Get critic name
        printf("Enter name of critic %d:\n", i+1);
        scanf(" %[^\n]%*c", critic_ratings[i].name);

        // Get movie rating for each movie
        for(int j=0; j < sizeof(*movie_ratings); j++) {
            printf("Enter %s's rating for %s:\n", critic_ratings[i].name, movie_ratings[j].title);
            float rating;
            scanf("%f", &rating);
            critic_ratings[i].rating += rating;
        }

        // Calculate average rating for critic
        critic_ratings[i].rating /= sizeof(*movie_ratings);
    }
}

// Function to print movie ratings
void print_movie_ratings(struct movie_rating* movie_ratings, int num_movies) {
    printf("Movie Ratings:\n");
    for(int i=0; i < num_movies; i++) {
        printf("%d. %s (%s), %d | Rating: %.1f/10\n", i+1, movie_ratings[i].title, movie_ratings[i].genre, movie_ratings[i].year, movie_ratings[i].rating);
    }
}

// Function to print critic ratings
void print_critic_ratings(struct movie_rating* movie_ratings, struct critic_rating* critic_ratings, int num_critics) {
    printf("Critic Ratings:\n");
    for(int i=0; i < num_critics; i++) {
        printf("%d. %s, %.1f/10\n", i+1, critic_ratings[i].name, critic_ratings[i].rating);
        for(int j=0; j < sizeof(*movie_ratings); j++) {
            printf("\t%s: %.1f/10\n", movie_ratings[j].title, critic_ratings[i].rating);
        }
    }
}

// Function to print top rated movies
void print_top_rated_movies(struct movie_rating* movie_ratings, int num_movies) {
    struct movie_rating top_rated_movies[num_movies];
    for(int i=0; i < num_movies; i++) {
        top_rated_movies[i] = movie_ratings[i];
    }

    // Sort movies by rating in descending order
    for(int i=0; i < num_movies; i++) {
        for(int j=i+1; j < num_movies; j++) {
            if(top_rated_movies[i].rating < top_rated_movies[j].rating) {
                struct movie_rating temp = top_rated_movies[i];
                top_rated_movies[i] = top_rated_movies[j];
                top_rated_movies[j] = temp;
            }
        }
    }

    // Print top 3 rated movies
    for(int i=0; i < 3; i++) {
        printf("%d. %s (%s), %d | Rating: %.1f/10\n", i+1, top_rated_movies[i].title, top_rated_movies[i].genre, top_rated_movies[i].year, top_rated_movies[i].rating);
    }
}