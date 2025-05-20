//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_MOVIES 1000
#define MAX_RATINGS 10000

typedef struct Rating {
    int user;
    int movie;
    int rating;
} Rating;

char* users[MAX_USERS];
char* movies[MAX_MOVIES];
Rating ratings[MAX_RATINGS];
int num_users = 0;
int num_movies = 0;
int num_ratings = 0;

int get_user_index(char* user) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i], user) == 0) {
            return i;
        }
    }
    users[num_users++] = user;
    return num_users - 1;
}

int get_movie_index(char* movie) {
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i], movie) == 0) {
            return i;
        }
    }
    movies[num_movies++] = movie;
    return num_movies - 1;
}

void add_rating(char* user, char* movie, int rating) {
    int user_index = get_user_index(user);
    int movie_index = get_movie_index(movie);
    Rating new_rating = { user_index, movie_index, rating };
    ratings[num_ratings++] = new_rating;
}

float get_movie_rating(int movie_index) {
    int sum = 0, count = 0;
    for (int i = 0; i < num_ratings; i++) {
        if (ratings[i].movie == movie_index) {
            sum += ratings[i].rating;
            count++;
        }
    }
    if (count == 0) {
        return 0.0;
    }
    return (float)sum / count;
}

void print_top_rated_movies() {
    int top_rated_movies[MAX_MOVIES];
    int num_top_rated_movies = 0;
    float max_rating = -1.0;
    for (int i = 0; i < num_movies; i++) {
        float rating = get_movie_rating(i);
        if (rating == max_rating) {
            top_rated_movies[num_top_rated_movies++] = i;
        } else if (rating > max_rating) {
            top_rated_movies[0] = i;
            num_top_rated_movies = 1;
            max_rating = rating;
        }
    }
    printf("Top Rated Movies:\n");
    for (int i = 0; i < num_top_rated_movies; i++) {
        printf("%d. %s (%.1f)\n", i + 1, movies[top_rated_movies[i]], max_rating);
    }
}

void save_ratings(char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    for (int i = 0; i < num_ratings; i++) {
        fprintf(file, "%d %d %d\n", ratings[i].user, ratings[i].movie, ratings[i].rating);
    }
    fclose(file);
}

void load_ratings(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    while (!feof(file)) {
        int user, movie, rating;
        fscanf(file, "%d %d %d\n", &user, &movie, &rating);
        if (feof(file)) {
            break;
        }
        char* user_name = users[user];
        char* movie_name = movies[movie];
        add_rating(user_name, movie_name, rating);
    }
    fclose(file);
}

void print_menu() {
    printf("Menu:\n");
    printf("1. Add Rating\n");
    printf("2. Print Top Rated Movies\n");
    printf("3. Save Ratings\n");
    printf("4. Load Ratings\n");
    printf("5. Exit\n");
}

int main() {
    while (1) {
        print_menu();
        int choice;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            char user[100], movie[100];
            int rating;
            printf("Enter User: ");
            scanf("%s", user);
            printf("Enter Movie: ");
            scanf("%s", movie);
            printf("Enter Rating (1-10): ");
            scanf("%d", &rating);
            if (rating >= 1 && rating <= 10) {
                add_rating(user, movie, rating);
            } else {
                printf("Error: Invalid Rating\n");
            }
        } else if (choice == 2) {
            print_top_rated_movies();
        } else if (choice == 3) {
            char filename[100];
            printf("Enter Filename: ");
            scanf("%s", filename);
            save_ratings(filename);
        } else if (choice == 4) {
            char filename[100];
            printf("Enter Filename: ");
            scanf("%s", filename);
            load_ratings(filename);
        } else if (choice == 5) {
            break;
        } else {
            printf("Error: Invalid Choice\n");
        }
    }
    return 0;
}