//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
  G,
  PG,
  PG13,
  R,
  NC17
} Rating;

// Define the movie struct
typedef struct {
  char *title;
  Rating rating;
} Movie;

// Define the thread data struct
typedef struct {
  Movie *movie;
  int *rating;
} ThreadData;

// Define the thread function
void *thread_func(void *arg) {
  ThreadData *data = (ThreadData *)arg;

  // Get the movie and rating from the thread data
  Movie *movie = data->movie;
  int *rating = data->rating;

  // Print the movie title and rating
  printf("%s: %d\n", movie->title, *rating);

  // Free the memory allocated for the thread data
  free(data);

  return NULL;
}

int main(int argc, char **argv) {
  // Check if the user specified a movie file
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <movie_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the movie file
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("Error opening movie file");
    return EXIT_FAILURE;
  }

  // Read the number of movies from the file
  int num_movies;
  fscanf(file, "%d\n", &num_movies);

  // Allocate memory for the movies
  Movie *movies = malloc(sizeof(Movie) * num_movies);
  if (movies == NULL) {
    perror("Error allocating memory for movies");
    return EXIT_FAILURE;
  }

  // Read the movies from the file
  for (int i = 0; i < num_movies; i++) {
    // Allocate memory for the movie title
    char *title = malloc(100);
    if (title == NULL) {
      perror("Error allocating memory for movie title");
      return EXIT_FAILURE;
    }

    // Read the movie title from the file
    fscanf(file, "%s\n", title);

    // Allocate memory for the movie rating
    Rating rating;

    // Read the movie rating from the file
    char rating_str[10];
    fscanf(file, "%s\n", rating_str);

    // Convert the movie rating string to an enum
    if (strcmp(rating_str, "G") == 0) {
      rating = G;
    } else if (strcmp(rating_str, "PG") == 0) {
      rating = PG;
    } else if (strcmp(rating_str, "PG13") == 0) {
      rating = PG13;
    } else if (strcmp(rating_str, "R") == 0) {
      rating = R;
    } else if (strcmp(rating_str, "NC17") == 0) {
      rating = NC17;
    } else {
      fprintf(stderr, "Error: Invalid movie rating: %s\n", rating_str);
      return EXIT_FAILURE;
    }

    // Store the movie title and rating in the movie struct
    movies[i].title = title;
    movies[i].rating = rating;
  }

  // Close the movie file
  fclose(file);

  // Create a thread pool
  pthread_t *threads = malloc(sizeof(pthread_t) * num_movies);
  if (threads == NULL) {
    perror("Error allocating memory for threads");
    return EXIT_FAILURE;
  }

  // Create a thread for each movie
  for (int i = 0; i < num_movies; i++) {
    // Allocate memory for the thread data
    ThreadData *data = malloc(sizeof(ThreadData));
    if (data == NULL) {
      perror("Error allocating memory for thread data");
      return EXIT_FAILURE;
    }

    // Initialize the thread data
    data->movie = &movies[i];
    data->rating = malloc(sizeof(int));
    if (data->rating == NULL) {
      perror("Error allocating memory for rating");
      return EXIT_FAILURE;
    }

    // Create the thread
    pthread_create(&threads[i], NULL, thread_func, data);
  }

  // Wait for all threads to complete
  for (int i = 0; i < num_movies; i++) {
    pthread_join(threads[i], NULL);
  }

  // Free the memory allocated for the movies
  for (int i = 0; i < num_movies; i++) {
    free(movies[i].title);
  }
  free(movies);

  // Free the memory allocated for the threads
  free(threads);

  return EXIT_SUCCESS;
}