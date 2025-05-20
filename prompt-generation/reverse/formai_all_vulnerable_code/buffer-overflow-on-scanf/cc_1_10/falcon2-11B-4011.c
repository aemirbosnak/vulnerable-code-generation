//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct Movie {
    char* title;
    int rating;
    char* genre;
    char* year;
};

void display_menu() {
    printf("1. Add Movie\n2. Remove Movie\n3. Display Movies\n4. Search Movie\n5. Update Rating\n6. Exit\n");
}

int main() {
    int choice;
    struct Movie movies[10];
    int num_movies = 0;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Movie new_movie;
                printf("Enter movie title: ");
                scanf("%s", new_movie.title);
                printf("Enter movie rating: ");
                scanf("%d", &new_movie.rating);
                printf("Enter movie genre: ");
                scanf("%s", new_movie.genre);
                printf("Enter movie year: ");
                scanf("%s", new_movie.year);
                movies[num_movies++] = new_movie;
                break;
            }
            case 2: {
                int index;
                printf("Enter index of movie to remove: ");
                scanf("%d", &index);
                if (index >= 0 && index < num_movies) {
                    for (int i = index; i < num_movies - 1; i++) {
                        movies[i] = movies[i + 1];
                    }
                    num_movies--;
                    break;
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }
            case 3: {
                int index;
                printf("Enter index of movie to display: ");
                scanf("%d", &index);
                if (index >= 0 && index < num_movies) {
                    for (int i = 0; i < index; i++) {
                        printf("%s | %d | %s | %s\n", movies[i].title, movies[i].rating, movies[i].genre, movies[i].year);
                    }
                    break;
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }
            case 4: {
                char* search_string;
                int index;
                printf("Enter movie to search: ");
                scanf("%s", search_string);
                for (int i = 0; i < num_movies; i++) {
                    if (strcmp(search_string, movies[i].title) == 0) {
                        printf("Found movie: %s\n", movies[i].title);
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    printf("Movie not found.\n");
                } else {
                    printf("Movie found at index %d.\n", index);
                }
                break;
            }
            case 5: {
                int index;
                printf("Enter index of movie to update: ");
                scanf("%d", &index);
                if (index >= 0 && index < num_movies) {
                    printf("Enter new rating: ");
                    scanf("%d", &movies[index].rating);
                    break;
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }
            case 6: {
                exit(0);
            }
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}