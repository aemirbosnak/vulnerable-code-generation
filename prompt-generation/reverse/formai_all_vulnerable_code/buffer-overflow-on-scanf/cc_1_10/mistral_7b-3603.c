//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#define MAX_MOVIES 100
#define MAX_RATINGS 10
#define MAX_NAME_LENGTH 50

struct movie {
    char title[MAX_NAME_LENGTH];
    int ratings[MAX_RATINGS];
    int num_ratings;
};

void print_menu();
void get_movie_input(struct movie* movie);
void print_movie_stats(struct movie movie);

int main() {
    struct movie movies[MAX_MOVIES];
    int choice = 0;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                get_movie_input(movies);
                break;
            case 2: {
                int movie_index = 0;
                char title[MAX_NAME_LENGTH];
                printf("Enter movie title: ");
                scanf("%s", title);

                for (int i = 0; i < MAX_MOVIES; i++) {
                    if (strcmp(movies[i].title, title) == 0) {
                        movie_index = i;
                        break;
                    }
                }

                if (movie_index == MAX_MOVIES) {
                    printf("Movie not found.\n");
                    continue;
                }

                print_movie_stats(movies[movie_index]);
                break;
            }
            case 0:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void print_menu() {
    printf("\nMovie Rating System\n");
    printf("1. Add movie\n");
    printf("2. View movie stats\n");
    printf("3. Exit\n");
}

void get_movie_input(struct movie* movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);

    movie->num_ratings = 0;

    for (int i = 0; i < MAX_RATINGS && movie->num_ratings < MAX_RATINGS; i++) {
        printf("Enter rating %d for %s: ", i + 1, movie->title);
        scanf("%d", &(movie->ratings[i]));
        movie->num_ratings++;
    }
}

void print_movie_stats(struct movie movie) {
    float avg_rating = 0.0;

    for (int i = 0; i < movie.num_ratings; i++) {
        avg_rating += (float)movie.ratings[i] / movie.num_ratings;
    }

    printf("Movie: %s\n", movie.title);
    printf("Average rating: %.1f\n", avg_rating);
}