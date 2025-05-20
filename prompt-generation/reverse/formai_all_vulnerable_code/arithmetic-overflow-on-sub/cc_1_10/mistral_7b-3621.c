//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_STARS 50

typedef struct {
    int num;
    char stars[MAX_STARS];
} starry_night;

void print_stars(int num_stars) {
    int i;
    for (i = 0; i < num_stars; i++) {
        printf("*");
    }
    printf("\n");
}

starry_night create_starry_night(int num) {
    int i;
    starry_night night;

    night.num = num;

    memset(night.stars, ' ', MAX_STARS);

    for (i = 0; i <= num; i++) {
        int stars_in_row = (MAX_STARS * i) / num;
        print_stars(stars_in_row);
        memcpy(night.stars, night.stars + stars_in_row, (MAX_STARS - stars_in_row) * sizeof(char));
    }

    return night;
}

void print_starry_night(starry_night night) {
    int i;
    for (i = 0; i < night.num; i++) {
        printf("%s\n", night.stars);
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    starry_night night = create_starry_night(n);
    printf("\nFactorial of %d:\n", n);
    print_starry_night(night);
    return n * factorial(n - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("\nFactorial: %d\n", factorial(num));
    return 0;
}