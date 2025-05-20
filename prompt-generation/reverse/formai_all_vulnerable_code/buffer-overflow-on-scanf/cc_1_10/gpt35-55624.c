//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("What is the symbol for the element with atomic number 6?\n");
    char answer1[3];
    scanf("%s", answer1);

    char correct1[3] = "C";
    if (strcmp(answer1, correct1) == 0) {
        printf("Great job! On to the next question.\n\n");
    } else {
        printf("Oops, that's not correct. The answer is C.\n\n");
        return 1;
    }

    printf("What is the atomic number of the element with symbol Cu?\n");
    char answer2[3];
    scanf("%s", answer2);

    char correct2[3] = "29";
    if (strcmp(answer2, correct2) == 0) {
        printf("Awesome! You're doing great.\n\n");
    } else {
        printf("Nope, sorry. The answer is 29.\n\n");
        return 1;
    }

    printf("Which element has the chemical symbol Sn?\n");
    char answer3[12];
    scanf("%s", answer3);

    char correct3[12] = "Tin";
    if (strcmp(answer3, correct3) == 0) {
        printf("You're amazing! Keep it up.\n\n");
    } else {
        printf("Uh oh, wrong answer. The correct answer is Tin.\n\n");
        return 1;
    }

    printf("What is the atomic symbol for sodium?\n");
    char answer4[3];
    scanf("%s", answer4);

    char correct4[3] = "Na";
    if (strcmp(answer4, correct4) == 0) {
        printf("You're crushing it!\n\n");
    } else {
        printf("Sorry, that's incorrect. It's Na.\n\n");
        return 1;
    }

    printf("Last question: What element has the atomic number of 8?\n");
    char answer5[12];
    scanf("%s", answer5);

    char correct5[12] = "Oxygen";
    if (strcmp(answer5, correct5) == 0) {
        printf("You got it! You're a periodic table pro.\n");
    } else {
        printf("Oh no, that's wrong. The answer is Oxygen.\n");
        return 1;
    }

    return 0;
}