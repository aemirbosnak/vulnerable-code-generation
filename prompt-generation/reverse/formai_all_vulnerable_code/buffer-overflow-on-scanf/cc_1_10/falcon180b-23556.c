//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_conspiracy_theory() {
    char *subjects[] = {
        "aliens",
        "government",
        "chemtrails",
        "9/11",
        "moon landing",
        "illuminati",
        "flat earth",
        "covid-19",
        "area 51",
        "bigfoot"
    };
    char *verbs[] = {
        "control",
        "hide",
        "manipulate",
        "cover up",
        "plan",
        "orchestrate",
        "create",
        "engineer",
        "spread",
        "conceal"
    };
    char *objects[] = {
        "the truth",
        "the masses",
        "public opinion",
        "the media",
        "the narrative",
        "the world",
        "reality",
        "the population",
        "the facts",
        "the evidence"
    };
    char theory[100];
    sprintf(theory, "%s is %s %s", subjects[rand() % 10], verbs[rand() % 10], objects[rand() % 10]);
    printf("Conspiracy Theory: %s\n", theory);
}

int main() {
    srand(time(NULL));
    int num_theories;
    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &num_theories);
    for (int i = 0; i < num_theories; i++) {
        generate_conspiracy_theory();
    }
    return 0;
}