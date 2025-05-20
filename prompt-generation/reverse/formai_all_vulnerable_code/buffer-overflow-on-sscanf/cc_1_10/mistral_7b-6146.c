//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 200
#define NUM_NAMES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double love_score;
} Person;

void read_data(FILE *file, Person names[NUM_NAMES]) {
    int i = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        char name[MAX_NAME_LENGTH];
        int age;
        double love_score;

        sscanf(line, "%s %d %lf", name, &age, &love_score);

        strcpy(names[i].name, name);
        names[i].age = age;
        names[i].love_score = love_score;
        i++;
    }
}

void calculate_love_scores(Person names[NUM_NAMES]) {
    for (int i = 0; i < NUM_NAMES; i++) {
        for (int j = i + 1; j < NUM_NAMES; j++) {
            if (strcmp(names[i].name, names[j].name) < 0) {
                double temp_score = names[i].love_score;
                names[i].love_score = names[j].love_score;
                names[j].love_score = temp_score;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    Person names[NUM_NAMES];

    if (argc != 2) {
        printf("Usage: %s <data.txt>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    read_data(file, names);
    calculate_love_scores(names);

    printf("LoveMiner Report:\n");
    printf("------------------\n");

    for (int i = 0; i < NUM_NAMES; i++) {
        printf("%s: %.2f\n", names[i].name, names[i].love_score);
    }

    fclose(file);
    return 0;
}