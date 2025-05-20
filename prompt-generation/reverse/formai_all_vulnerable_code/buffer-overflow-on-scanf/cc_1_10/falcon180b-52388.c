//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

typedef struct {
    char* text;
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet a tall, dark stranger. ", 32},
    {"A financial opportunity is coming your way. ", 38},
    {"You will experience a great personal growth. ", 39},
    {"A friend in need is a friend indeed. ", 24},
    {"Don't count your chickens before they hatch. ", 34},
    {"All that glitters is not gold. ", 23},
    {"A penny saved is a penny earned. ", 26},
    {"Actions speak louder than words. ", 24},
    {"Absence makes the heart grow fonder. ", 30},
    {"Better late than never. ", 21},
    {"Curiosity killed the cat. ", 24},
    {"Every cloud has a silver lining. ", 31},
    {"Finders keepers, losers weepers. ", 27},
    {"If at first you don't succeed, try, try again. ", 43},
    {"If it ain't broke, don't fix it. ", 27},
    {"In for a penny, in for a pound. ", 28},
    {"It's always darkest before the dawn. ", 32},
    {"Knowledge is power. ", 18},
    {"Laughter is the best medicine. ", 26},
    {"Necessity is the mother of invention. ", 37},
    {"Never judge a book by its cover. ", 30},
    {"Patience is a virtue. ", 21},
    {"Practice makes perfect. ", 21},
    {"Rome wasn't built in a day. ", 28},
    {"The early bird catches the worm. ", 28},
    {"The grass is always greener on the other side. ", 41},
    {"The squeaky wheel gets the grease. ", 29},
    {"There's no place like home. ", 22},
    {"Time heals all wounds. ", 20},
    {"What goes around comes around. ", 28},
    {"When in Rome, do as the Romans do. ", 33},
    {"You can't have your cake and eat it too. ", 32},
    {"You can lead a horse to water, but you can't make it drink. ", 45},
    {"You can't make an omelette without breaking eggs. ", 38},
    {"You can't teach an old dog new tricks. ", 30},
    {"You reap what you sow. ", 18},
    {"You scratch my back and I'll scratch yours. ", 37},
    {"You snooze, you lose. ", 18},
    {"Your guess is as good as mine. ", 28},
};

void shuffle(Fortune* array, int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        Fortune temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    int numFortunes;
    printf("How many fortunes would you like to receive? ");
    scanf("%d", &numFortunes);

    if (numFortunes > MAX_FORTUNES || numFortunes < 1) {
        printf("Invalid number of fortunes.\n");
        return 1;
    }

    shuffle(fortunes, MAX_FORTUNES);

    for (int i = 0; i < numFortunes; i++) {
        printf("%s\n", fortunes[i].text);
    }

    return 0;
}