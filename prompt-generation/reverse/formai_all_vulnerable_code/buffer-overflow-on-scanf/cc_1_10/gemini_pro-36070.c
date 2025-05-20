//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STARS 10000
#define MAX_PLANETS 1000
#define MAX_ALIENS 100

struct star {
    int id;
    char name[20];
    int num_planets;
    struct planet *planets;
};

struct planet {
    int id;
    char name[20];
    int num_aliens;
    struct alien *aliens;
};

struct alien {
    int id;
    char name[20];
    int age;
    char gender;
};

int main() {
    srand(time(NULL));

    struct star stars[MAX_STARS];
    struct planet planets[MAX_PLANETS];
    struct alien aliens[MAX_ALIENS];

    int num_stars, num_planets, num_aliens;

    printf("Enter the number of stars: ");
    scanf("%d", &num_stars);

    for (int i = 0; i < num_stars; i++) {
        printf("Enter the name of star %d: ", i + 1);
        scanf("%s", stars[i].name);

        printf("Enter the number of planets in star %d: ", i + 1);
        scanf("%d", &stars[i].num_planets);

        stars[i].planets = malloc(stars[i].num_planets * sizeof(struct planet));
    }

    for (int i = 0; i < num_stars; i++) {
        for (int j = 0; j < stars[i].num_planets; j++) {
            printf("Enter the name of planet %d in star %d: ", j + 1, i + 1);
            scanf("%s", stars[i].planets[j].name);

            printf("Enter the number of aliens on planet %d in star %d: ", j + 1, i + 1);
            scanf("%d", &stars[i].planets[j].num_aliens);

            stars[i].planets[j].aliens = malloc(stars[i].planets[j].num_aliens * sizeof(struct alien));
        }
    }

    for (int i = 0; i < num_stars; i++) {
        for (int j = 0; j < stars[i].num_planets; j++) {
            for (int k = 0; k < stars[i].planets[j].num_aliens; k++) {
                printf("Enter the name of alien %d on planet %d in star %d: ", k + 1, j + 1, i + 1);
                scanf("%s", stars[i].planets[j].aliens[k].name);

                printf("Enter the age of alien %d on planet %d in star %d: ", k + 1, j + 1, i + 1);
                scanf("%d", &stars[i].planets[j].aliens[k].age);

                printf("Enter the gender of alien %d on planet %d in star %d: ", k + 1, j + 1, i + 1);
                scanf(" %c ", &stars[i].planets[j].aliens[k].gender);
            }
        }
    }

    printf("\n\nThe following is a list of all the aliens in the universe:\n\n");

    for (int i = 0; i < num_stars; i++) {
        for (int j = 0; j < stars[i].num_planets; j++) {
            for (int k = 0; k < stars[i].planets[j].num_aliens; k++) {
                printf("Alien %d on planet %d in star %d:\n", stars[i].planets[j].aliens[k].id, stars[i].planets[j].id, stars[i].id);
                printf("Name: %s\n", stars[i].planets[j].aliens[k].name);
                printf("Age: %d\n", stars[i].planets[j].aliens[k].age);
                printf("Gender: %c\n\n", stars[i].planets[j].aliens[k].gender);
            }
        }
    }

    return 0;
}