//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 10
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    int atomic_number;
    int group;
    int period;
} Element;

Element elements[MAX_ELEMENTS];
char input_buffer[MAX_NAME_LENGTH];
int num_elements = 0;

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file!\n");
        exit(1);
    }

    char line[MAX_NAME_LENGTH];
    Element element;
    while (fgets(line, MAX_NAME_LENGTH, file)!= NULL) {
        sscanf(line, "%s %s %d %d %d", element.name, element.symbol, &element.atomic_number, &element.group, &element.period);
        strcpy(elements[num_elements].name, element.name);
        strcpy(elements[num_elements].symbol, element.symbol);
        elements[num_elements].atomic_number = element.atomic_number;
        elements[num_elements].group = element.group;
        elements[num_elements].period = element.period;
        num_elements++;
    }

    fclose(file);
}

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    srand(time(NULL));

    load_elements();

    int score = 0;
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        Element element = elements[rand() % num_elements];
        printf("What is the symbol for %s? ", element.name);
        fgets(input_buffer, MAX_NAME_LENGTH, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0';
        if (strcmp(input_buffer, element.symbol) == 0) {
            score++;
            printf("Correct!\n");
        } else {
            attempts++;
            printf("Incorrect. The correct answer is %s.\n", element.symbol);
        }
    }

    printf("Your final score is %d out of %d.\n", score, MAX_ATTEMPTS);

    return 0;
}