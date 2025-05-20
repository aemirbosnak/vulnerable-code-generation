//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *text;
    int weight;
} Fortune;

Fortune fortunes[] = {
    {"You will have a great day today!", 10},
    {"Success is just around the corner.", 20},
    {"You will meet someone special soon.", 30},
    {"Travel is in your future.", 40},
    {"A financial windfall is coming your way.", 50},
    {"Your hard work will pay off.", 60},
    {"You will overcome any obstacles in your path.", 70},
    {"Good health and happiness are in your future.", 80},
    {"You will receive unexpected news.", 90},
    {"Your dreams will come true.", 100}
};

void shuffle(Fortune *fortunes, int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        Fortune temp = fortunes[i];
        fortunes[i] = fortunes[j];
        fortunes[j] = temp;
    }
}

int main() {
    srand(time(NULL));
    Fortune fortunes[] = {
        {"You will have a great day today!", 10},
        {"Success is just around the corner.", 20},
        {"You will meet someone special soon.", 30},
        {"Travel is in your future.", 40},
        {"A financial windfall is coming your way.", 50},
        {"Your hard work will pay off.", 60},
        {"You will overcome any obstacles in your path.", 70},
        {"Good health and happiness are in your future.", 80},
        {"You will receive unexpected news.", 90},
        {"Your dreams will come true.", 100}
    };
    int numFortunes = sizeof(fortunes) / sizeof(Fortune);
    shuffle(fortunes, numFortunes);
    int userChoice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Choose a number between 1 and %d:\n", numFortunes);
    scanf("%d", &userChoice);
    if (userChoice < 1 || userChoice > numFortunes) {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }
    printf("\nYour fortune is:\n%s\n", fortunes[userChoice - 1].text);
    return 0;
}