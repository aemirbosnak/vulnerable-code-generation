//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STARS 10
#define MIN_BRIGHTNESS 1
#define MAX_BRIGHTNESS 10

typedef struct {
    int name;
    int brightness;
} Star;

void generate_stars(Star stars[NUM_STARS]);
void print_stars(Star stars[NUM_STARS]);
int get_brightest_star(Star stars[NUM_STARS]);

int main() {
    Star stars[NUM_STARS];
    srand(time(NULL));

    generate_stars(stars);

    int user_bet;
    printf("Welcome to Starry Night, the game where you can bet on which star will shine the brightest!\n");
    printf("Please enter the number of the star you'd like to bet on (1-%d): ", NUM_STARS);
    scanf("%d", &user_bet);

    int winning_star = get_brightest_star(stars);

    if (user_bet == winning_star) {
        printf("Congratulations! You've won the game.\n");
    } else {
        printf("Sorry, the winning star was %d.\n", winning_star);
    }

    print_stars(stars);

    return 0;
}

void generate_stars(Star stars[NUM_STARS]) {
    for (int i = 0; i < NUM_STARS; i++) {
        stars[i].name = i + 1;
        stars[i].brightness = rand() % (MAX_BRIGHTNESS - MIN_BRIGHTNESS + 1) + MIN_BRIGHTNESS;
    }
}

void print_stars(Star stars[NUM_STARS]) {
    printf("\nStarry Night:\n");
    for (int i = 0; i < NUM_STARS; i++) {
        printf("\nStar %d: Brightness %d", stars[i].name, stars[i].brightness);
    }
}

int get_brightest_star(Star stars[NUM_STARS]) {
    int brightest = MIN_BRIGHTNESS;
    int index = 0;

    for (int i = 0; i < NUM_STARS; i++) {
        if (stars[i].brightness > brightest) {
            brightest = stars[i].brightness;
            index = i;
        }
    }

    return stars[index].name;
}