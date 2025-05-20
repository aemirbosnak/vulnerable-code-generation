//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    char symbol[10];
    int atomicNumber;
    float atomicWeight;
    char group;
    char category;
} Element;

Element elements[118];

void loadElements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %f %c %c\n", elements[count].name, elements[count].symbol, &elements[count].atomicNumber, &elements[count].atomicWeight, &elements[count].group, &elements[count].category) == 6) {
        count++;
    }

    fclose(file);
}

void printElement(Element element) {
    printf("%-20s %-10s %d %5.2f %c %c\n", element.name, element.symbol, element.atomicNumber, element.atomicWeight, element.group, element.category);
}

int main() {
    srand(time(NULL));

    loadElements();

    int score = 0;
    int totalQuestions = 10;

    for (int i = 0; i < totalQuestions; i++) {
        int index = rand() % 118;
        Element questionElement = elements[index];

        char correctAnswer[50];
        sprintf(correctAnswer, "%s (%c)", questionElement.name, questionElement.symbol[0]);

        printf("Question %d: %s\n", i+1, questionElement.name);
        char answer[50];
        scanf("%s", answer);

        if (strcmp(answer, correctAnswer) == 0) {
            score++;
        }
    }

    printf("\nYour final score is: %d/%d\n", score, totalQuestions);

    return 0;
}