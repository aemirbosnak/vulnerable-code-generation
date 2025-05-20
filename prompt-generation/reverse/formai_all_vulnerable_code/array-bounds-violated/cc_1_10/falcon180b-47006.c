//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_FORTUNE_LENGTH 80
#define NUM_FORTUNES 100

typedef struct {
    char fortune[MAX_FORTUNE_LENGTH];
    float probability;
} Fortune;

Fortune fortunes[NUM_FORTUNES];

void generate_fortunes() {
    srand(time(NULL));

    for (int i = 0; i < NUM_FORTUNES; i++) {
        fortunes[i].probability = rand() % 100;
        int fortune_length = (int) (log(fortunes[i].probability) / log(1 - 0.01));
        if (fortune_length > MAX_FORTUNE_LENGTH) {
            fortune_length = MAX_FORTUNE_LENGTH;
        }
        for (int j = 0; j < fortune_length; j++) {
            char c = 'a' + rand() % 26;
            fortunes[i].fortune[j] = c;
        }
        fortunes[i].fortune[fortune_length] = '\0';
    }
}

int main() {
    generate_fortunes();

    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose a number between 1 and %d:\n", NUM_FORTUNES);
        scanf("%d", &choice);

        if (choice < 1 || choice > NUM_FORTUNES) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > NUM_FORTUNES);

    printf("Your fortune is:\n%s\n", fortunes[choice - 1].fortune);

    return 0;
}