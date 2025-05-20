//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>

// defining the struct for the movie rating system
typedef struct movie_rating {
  int id;
  char name[50];
  float rating;
} movie_rating;

// function to read the movie details from user
void read_movie_details(movie_rating *movie) {
  printf("Enter movie id: ");
  scanf("%d", &movie->id);
  printf("Enter movie name: ");
  scanf(" %[^\n]s", movie->name);
  printf("Enter movie rating (out of 10): ");
  scanf("%f", &movie->rating);
}

// function to print the movie details
void print_movie_details(movie_rating *movie) {
  printf("%d. %s: %.2f/10\n", movie->id, movie->name, movie->rating);
}

// function to update the movie rating
void update_movie_rating(movie_rating *movie, float new_rating) {
  movie->rating = new_rating;
}

int main() {
  int option, num_movies = 0;
  float new_rating;
  movie_rating movies[50];

  do {
    printf("\nMENU\n");
    printf("1. Add a new movie\n");
    printf("2. Print all movies\n");
    printf("3. Update movie rating\n");
    printf("4. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        // add a new movie
        read_movie_details(&movies[num_movies]);
        num_movies++;
        break;
      case 2:
        // print all movies
        printf("\nMOVIE RATING SYSTEM\n");
        for (int i = 0; i < num_movies; i++) {
          print_movie_details(&movies[i]);
        }
        break;
      case 3:
        // update movie rating
        printf("Enter movie id to update rating: ");
        int id_to_update;
        scanf("%d", &id_to_update);
        printf("Enter new movie rating (out of 10): ");
        scanf("%f", &new_rating);
        for (int i = 0; i < num_movies; i++) {
          if (movies[i].id == id_to_update) {
            update_movie_rating(&movies[i], new_rating);
            printf("Movie rating updated successfully!\n");
            break;
          }
        }
        break;
      case 4:
        // exit
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid option!\n");
        break;
    }

  } while(option != 4);

  return 0;
}