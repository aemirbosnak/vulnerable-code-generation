//FormAI DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 1000000

// Structures for holding data
typedef struct {
    int id;
    char name[20];
    int age;
    float salary;
} Person;

typedef struct {
    int id;
    char title[50];
    char genre[20];
    float rating;
} Movie;

// Function prototypes
void read_person_data(Person data[MAX_DATA], int *count);
void read_movie_data(Movie data[MAX_DATA], int *count);
float find_average_salary(Person data[MAX_DATA], int count);
void find_top_rated(Movie data[MAX_DATA], int count, Movie *top_rated);

int main() {
    Person people[MAX_DATA];
    Movie movies[MAX_DATA];
    int person_count = 0, movie_count = 0;
    float average_salary;
    Movie top_rated;

    read_person_data(people, &person_count);
    average_salary = find_average_salary(people, person_count);
    printf("Average salary: %.2f\n", average_salary);

    read_movie_data(movies, &movie_count);
    find_top_rated(movies, movie_count, &top_rated);
    printf("Top rated movie: %s (%s) with a rating of %.2f\n", top_rated.title, top_rated.genre, top_rated.rating);

    return 0;
}

// Function to read in person data from a file
void read_person_data(Person data[MAX_DATA], int *count) {
    FILE *file;
    file = fopen("person_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%d %s %d %f", &data[i].id, data[i].name, &data[i].age, &data[i].salary) != EOF) {
        i++;
    }
    *count = i;

    fclose(file);
}

// Function to read in movie data from a file
void read_movie_data(Movie data[MAX_DATA], int *count) {
    FILE *file;
    file = fopen("movie_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%d %s %s %f", &data[i].id, data[i].title, data[i].genre, &data[i].rating) != EOF) {
        i++;
    }
    *count = i;

    fclose(file);
}

// Function to find the average salary of all people
float find_average_salary(Person data[MAX_DATA], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += data[i].salary;
    }
    return sum / count;
}

// Function to find the top rated movie
void find_top_rated(Movie data[MAX_DATA], int count, Movie *top_rated) {
    *top_rated = data[0];
    for (int i = 1; i < count; i++) {
        if (data[i].rating > top_rated->rating) {
            *top_rated = data[i];
        }
    }
}