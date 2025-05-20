//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINES 10
#define MAX_COLS 5
#define MAX_CHARS 50

struct rule {
    int die1;
    int die2;
    int points;
};

void readRulesFile(const char *filename, struct rule rules[MAX_LINES]);
int rollDice();
void printResults(int die1, int die2, int points);

int main() {
    char filename[MAX_CHARS];
    struct rule rules[MAX_LINES];

    printf("Enter rules file name: ");
    scanf("%s", filename);

    readRulesFile(filename, rules);

    srand(time(NULL));

    for (int i = 0; i < MAX_LINES; i++) {
        int die1 = rules[i].die1;
        int die2 = rules[i].die2;
        int points = rules[i].points;

        printf("\nRule %d:\n", i + 1);
        printf("Rolling %d and %d: ", die1, die2);

        int roll1 = rollDice();
        int roll2 = rollDice();

        printf("Rolled %d and %d\n", roll1, roll2);

        if (roll1 == die1 && roll2 == die2) {
            printResults(roll1, roll2, points);
        }
    }

    return 0;
}

void readRulesFile(const char *filename, struct rule rules[MAX_LINES]) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[MAX_COLS][MAX_CHARS];
    int lineNum = 0;

    while (fgets(line[lineNum], sizeof(line[lineNum]), file) != NULL) {
        sscanf(line[lineNum], "%d%d%d", &rules[lineNum].die1, &rules[lineNum].die2, &rules[lineNum].points);
        lineNum++;
    }

    fclose(file);
}

int rollDice() {
    return rand() % 6 + 1;
}

void printResults(int die1, int die2, int points) {
    printf("You earned %d points!\n", points);
}