//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define PERIODIC_TABLE_SIZE 118

typedef struct {
    int atomic_number;
    char *name;
    char *symbol;
    double atomic_mass;
    int group;
    int period;
} Element;

Element periodic_table[PERIODIC_TABLE_SIZE];

void initialize_periodic_table() {
    // Initialize the periodic table with data from a file.
    FILE *fp = fopen("periodic_table.csv", "r");
    if (fp == NULL) {
        perror("Error opening periodic table file");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        Element element;
        sscanf(line, "%d,%[^,],%[^,],%lf,%d,%d", &element.atomic_number, element.name, element.symbol, &element.atomic_mass, &element.group, &element.period);
        periodic_table[element.atomic_number - 1] = element;
    }

    fclose(fp);
}

void print_periodic_table() {
    // Print the periodic table in a tabular format.
    printf("%-5s %-15s %-5s %-10s %-5s %-5s\n", "Number", "Name", "Symbol", "Atomic Mass", "Group", "Period");
    for (int i = 0; i < PERIODIC_TABLE_SIZE; i++) {
        Element element = periodic_table[i];
        printf("%-5d %-15s %-5s %-10.3f %-5d %-5d\n", element.atomic_number, element.name, element.symbol, element.atomic_mass, element.group, element.period);
    }
}

void quiz_periodic_table() {
    // Quiz the user on the periodic table.
    int score = 0;
    for (int i = 0; i < PERIODIC_TABLE_SIZE; i++) {
        Element element = periodic_table[i];
        char answer[1024];
        printf("What is the name of element %d? ", element.atomic_number);
        scanf("%s", answer);
        if (strcmp(answer, element.name) == 0) {
            score++;
        }
    }

    printf("Your score is %d out of %d.\n", score, PERIODIC_TABLE_SIZE);
}

int main() {
    // Initialize the periodic table.
    initialize_periodic_table();

    // Print the periodic table.
    print_periodic_table();

    // Quiz the user on the periodic table.
    quiz_periodic_table();

    return 0;
}