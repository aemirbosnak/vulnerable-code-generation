//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_LEN 50

struct movie {
    char title[MAX_LEN]; 
    char director[MAX_LEN];
    int year; 
    float rating; 
};

struct movie_list {
    struct movie movies[MAX_MOVIES];
    int num_movies; 
};

void add_movie(struct movie_list *m_list) {
    struct movie new_movie;
    printf("Enter movie title: ");
    fgets(new_movie.title, MAX_LEN, stdin);
    printf("Enter movie director: ");
    fgets(new_movie.director, MAX_LEN, stdin);
    printf("Enter movie release year: ");
    scanf("%d", &new_movie.year);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &new_movie.rating);
    getchar(); 
    m_list->movies[m_list->num_movies++] = new_movie;
    printf("Added movie: %s\n", new_movie.title);
}

void list_movies(struct movie_list m_list) {
    printf("Movie List:\n");
    for (int i = 0; i < m_list.num_movies; i++) {
        printf("%d. %s (%s)  %d  (%.1f/10)\n", i+1, m_list.movies[i].title, m_list.movies[i].director, m_list.movies[i].year, m_list.movies[i].rating);
    }
}

void rate_movie(struct movie_list *m_list) {
    int index;
    float rating;
    printf("Enter the number of the movie to rate: ");
    scanf("%d", &index);
    printf("Enter the new rating: ");
    scanf("%f", &rating);
    getchar(); 
    m_list->movies[index-1].rating = rating;
    printf("Rated \"%s\" %.1f/10\n", m_list->movies[index-1].title, m_list->movies[index-1].rating);
}

void print_menu() {
    printf("\nChoose an option:\n");
    printf("1. Add a movie\n");
    printf("2. List movies\n");
    printf("3. Rate a movie\n");
    printf("4. Quit\n");
}

int main() {
    struct movie_list movie_list = {0};
    int choice = 0;
    while (choice != 4) {
        print_menu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1: 
                add_movie(&movie_list);
                break;
            case 2: 
                list_movies(movie_list);
                break;
            case 3: 
                rate_movie(&movie_list);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default: 
                printf("Invalid option.\n");
        }
    }
    return 0;
}