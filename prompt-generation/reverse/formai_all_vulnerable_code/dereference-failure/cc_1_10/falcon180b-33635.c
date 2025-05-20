//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the hash of a string
unsigned int hash(char* str) {
    unsigned int hash = 0;
    int i = 0;

    while (str[i]) {
        hash += str[i];
        i++;
    }

    return hash % 100000;
}

typedef struct {
    char* title;
    char* director;
    int year;
    unsigned int hash;
} movie;

// Function to compare two movies
int compare_movies(const void* a, const void* b) {
    movie* movie1 = (movie*)a;
    movie* movie2 = (movie*)b;

    if (movie1->hash < movie2->hash)
        return -1;
    else if (movie1->hash > movie2->hash)
        return 1;
    else
        return 0;
}

// Function to print the list of movies
void print_movies(movie movies[], int count) {
    qsort(movies, count, sizeof(movie), compare_movies);

    for (int i = 0; i < count; i++) {
        printf("%s (%d) - %s\n", movies[i].title, movies[i].year, movies[i].director);
    }
}

// Function to read the list of movies from a file
int read_movies(FILE* file, movie movies[], int max_count) {
    char line[1024];
    int count = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (count >= max_count) {
            printf("Maximum number of movies reached.\n");
            break;
        }

        char* title = strtok(line, " \t\r\n");
        char* director = strtok(NULL, " \t\r\n");
        int year = atoi(strtok(NULL, " \t\r\n"));

        if (title == NULL || director == NULL || year == 0) {
            printf("Invalid movie data.\n");
            continue;
        }

        movies[count].title = strdup(title);
        movies[count].director = strdup(director);
        movies[count].year = year;
        movies[count].hash = hash(movies[count].title);

        count++;
    }

    return count;
}

int main() {
    movie movies[1000];
    int count = 0;

    // Read the list of movies from a file
    FILE* file = fopen("movies.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    count = read_movies(file, movies, sizeof(movies) / sizeof(movie));
    fclose(file);

    // Print the list of movies
    print_movies(movies, count);

    return 0;
}