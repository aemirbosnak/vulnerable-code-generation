//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMS 50
#define MAX_RATINGS 10

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Film;

void print_film(Film *film) {
    printf("Title: %s\n", film->title);
    printf("Ratings:\n");
    for (int i = 0; i < film->num_ratings; i++) {
        printf("%d\n", film->ratings[i]);
    }
}

int main() {
    Film films[MAX_FILMS];
    int num_films = 0;
    char choice;

    do {
        printf("C Movie Rating System\n");
        printf("1. Add a film\n");
        printf("2. Rate a film\n");
        printf("3. Print ratings\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (num_films == MAX_FILMS) {
                printf("Sorry, maximum number of films reached.\n");
            } else {
                printf("Enter film title: ");
                scanf("%s", films[num_films].title);
                films[num_films].num_ratings = 0;
                num_films++;
            }
            break;
        case '2':
            printf("Enter film title: ");
            scanf("%s", films[0].title);
            printf("Enter rating (1-10): ");
            scanf("%d", &films[0].ratings[films[0].num_ratings]);
            films[0].num_ratings++;
            break;
        case '3':
            for (int i = 0; i < num_films; i++) {
                print_film(&films[i]);
            }
            break;
        case '4':
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}