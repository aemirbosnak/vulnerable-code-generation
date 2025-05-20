//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_theory(int length) {
    char *subjects[] = {
        "illuminati",
        "area 51",
        "moon landing",
        "flat earth",
        "chemtrails",
        "lizard people",
        "9/11",
        "haarp",
        "mk ultra",
        "covid-19",
        "5g",
        "qanon"
    };

    char *verbs[] = {
        "controls",
        "is behind",
        "caused",
        "faked",
        "is a hoax",
        "is secretly",
        "was planned by",
        "is manipulating",
        "is responsible for",
        "is spreading",
        "is part of"
    };

    char *objects[] = {
        "the government",
        "the elite",
        "the media",
        "the scientists",
        "the corporations",
        "the aliens",
        "the new world order",
        "the deep state",
        "the cabal",
        "the establishment",
        "the mainstream"
    };

    srand(time(NULL));
    int subject = rand() % 12;
    int verb = rand() % 11;
    int object = rand() % 12;

    printf("New Conspiracy Theory: %s %s %s\n", subjects[subject], verbs[verb], objects[object]);
}

int main() {
    int length;

    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        generate_theory(3);
    }

    return 0;
}