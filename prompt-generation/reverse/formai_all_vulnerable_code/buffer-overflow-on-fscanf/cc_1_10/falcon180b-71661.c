//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 10
#define MAX_QUESTIONS 5

typedef struct {
    char name[50];
    char symbol[10];
    int atomic_number;
    int group;
    int period;
    char category[20];
    char description[100];
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d %s %s", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period, elements[count].category, elements[count].description)!= EOF) {
        count++;
    }

    fclose(file);
}

void shuffle_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    load_elements();
    int attempts = 0;
    int score = 0;
    int questions_answered = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Welcome to the Periodic Table Quiz!\n");
        printf("You have %d attempts left.\n", MAX_ATTEMPTS - attempts);

        shuffle_array(elements, MAX_ELEMENTS);

        int questions_to_ask = rand() % MAX_QUESTIONS + 1;
        printf("You will be asked %d questions.\n", questions_to_ask);

        for (int i = 0; i < questions_to_ask; i++) {
            int index = rand() % MAX_ELEMENTS;
            printf("Question %d: %s\n", i + 1, elements[index].name);

            char answer[50];
            scanf("%s", answer);

            if (strcmp(answer, elements[index].name) == 0) {
                score++;
                printf("Correct!\n");
            } else {
                printf("Incorrect. The correct answer is %s.\n", elements[index].name);
            }

            questions_answered++;
        }

        if (questions_answered == 0) {
            printf("You did not answer any questions correctly.\n");
        } else {
            printf("You answered %d out of %d questions correctly.\n", score, questions_answered);
        }

        attempts++;
    }

    return 0;
}