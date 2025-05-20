//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Movie structure
typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Function to compare two movies based on their ratings
int compare(const void *a, const void *b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;

    if (movie1->rating > movie2->rating) {
        return 1;
    } else if (movie1->rating < movie2->rating) {
        return -1;
    } else {
        return 0;
    }
}

// Function to read movies from a file
void read_movies(FILE *file, Movie movies[]) {
    int count = 0;

    while (fscanf(file, "%s %s %d %f", movies[count].title, movies[count].director, &movies[count].year, &movies[count].rating) == 4) {
        count++;
    }
}

// Function to write movies to a file
void write_movies(FILE *file, Movie movies[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %d %f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }
}

// Function to sort movies based on their ratings
void sort_movies(Movie movies[], int count) {
    qsort(movies, count, sizeof(Movie), compare);
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[50], output_filename[50];
    Movie movies[100];
    int count = 0;

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    // Open input file
    input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read movies from input file
    read_movies(input_file, movies);

    // Sort movies based on their ratings
    sort_movies(movies, count);

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open output file
    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write sorted movies to output file
    write_movies(output_file, movies, count);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}