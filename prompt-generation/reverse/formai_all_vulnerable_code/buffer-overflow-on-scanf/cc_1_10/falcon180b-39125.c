//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80

typedef struct {
    char text[MAX_LENGTH];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"The future is uncertain, but your path is clear. ", 37},
    {"You will find success in unexpected places. ", 31},
    {"A new opportunity will present itself to you soon. ", 45},
    {"Your hard work will pay off in the end. ", 28},
    {"Love is on the horizon. Keep your heart open. ", 38},
    {"Stay true to yourself and good things will come. ", 35},
    {"You are capable of achieving great things. Believe in yourself. ", 51},
    {"Your dreams are within reach. Don't give up. ", 33},
    {"A positive change is coming your way. Embrace it. ", 41},
    {"You have the power to shape your own destiny. Use it wisely. ", 49}
};

void shuffle(int* deck, int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    srand(time(NULL));
    int numFortunes;
    printf("How many fortunes would you like to receive? ");
    scanf("%d", &numFortunes);

    if (numFortunes > MAX_FORTUNES || numFortunes < 1) {
        printf("Sorry, you must choose between 1 and %d fortunes.\n", MAX_FORTUNES);
        return 1;
    }

    int deck[MAX_FORTUNES];
    for (int i = 0; i < MAX_FORTUNES; i++) {
        deck[i] = i;
    }

    shuffle(deck, MAX_FORTUNES);

    for (int i = 0; i < numFortunes; i++) {
        printf("Your fortune: %s\n", fortunes[deck[i]].text);
    }

    return 0;
}