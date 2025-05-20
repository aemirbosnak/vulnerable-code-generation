//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define DATA_FILE "survivor_data.txt"

struct Survivor {
    char name[MAX_LINE_LENGTH];
    int water_level;
    int food_level;
};

void read_survivor_data(struct Survivor survivors[], int *num_survivors) {
    FILE *file = fopen(DATA_FILE, "r");
    char line[MAX_LINE_LENGTH];
    int i = 0;

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s %d %d", survivors[i].name, &survivors[i].water_level, &survivors[i].food_level);
        (*num_survivors)++;
        i++;
    }

    fclose(file);
}

void print_survivor_data(struct Survivor survivors[], int num_survivors) {
    for (int i = 0; i < num_survivors; i++) {
        printf("%s: Water Level = %d, Food Level = %d\n", survivors[i].name, survivors[i].water_level, survivors[i].food_level);
    }
}

int main() {
    struct Survivor *survivors;
    int num_survivors;

    read_survivor_data(survivors, &num_survivors);

    printf("Post-Apocalyptic Survivor Data:\n");
    print_survivor_data(survivors, num_survivors);

    free(survivors);

    return EXIT_SUCCESS;
}