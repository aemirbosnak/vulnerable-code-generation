//FormAI DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
    char title[50];
    char genre[20];
    int year;
    float rating[MAX_RATINGS];
    int num_ratings;
    float avg_rating;
} movie;

movie movie_list[MAX_MOVIES];
int num_movies = 0;

void add_movie() {
    if (num_movies >= MAX_MOVIES) {
        printf("Error: Maximum number of movies reached.\n");
        return;
    }
    movie m;
    printf("Enter movie title: ");
    fgets(m.title, 50, stdin);
    printf("Enter movie genre: ");
    fgets(m.genre, 20, stdin);
    printf("Enter year released: ");
    scanf("%d", &m.year);
    printf("Enter movie ratings (0 to stop):\n");
    float rating;
    m.num_ratings = 0;
    while (m.num_ratings < MAX_RATINGS) {
        scanf("%f", &rating);
        if (rating == 0) {
            break;
        }
        m.rating[m.num_ratings] = rating;
        m.num_ratings++;
    }
    float total_rating = 0;
    for (int i = 0; i < m.num_ratings; i++) {
        total_rating += m.rating[i];
    }
    m.avg_rating = total_rating / m.num_ratings;
    movie_list[num_movies] = m;
    num_movies++;
}

void print_movie(movie m) {
    printf("%s (%d) - %s - Average rating: %.1f\n", m.title, m.year, m.genre, m.avg_rating);
}

void list_movies() {
    if (num_movies == 0) {
        printf("No movies in database.\n");
        return;
    }
    printf("Movies in database:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie(movie_list[i]);
    }
}

void search_movies() {
    if (num_movies == 0) {
        printf("No movies in database.\n");
        return;
    }
    printf("Enter keyword: ");
    char keyword[20];
    fgets(keyword, 20, stdin);
    printf("Search results:\n");
    for (int i = 0; i < num_movies; i++) {
        if (strstr(movie_list[i].title, keyword) != NULL) {
            print_movie(movie_list[i]);
        }
    }
}

int main() {
    char choice;
    do {
        printf("\n------- C Movie Rating System -------\n");
        printf("1. Add movie\n");
        printf("2. List movies\n");
        printf("3. Search movies\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                add_movie();
                break;
            case '2':
                list_movies();
                break;
            case '3':
                search_movies();
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != '4');
    return 0;
}