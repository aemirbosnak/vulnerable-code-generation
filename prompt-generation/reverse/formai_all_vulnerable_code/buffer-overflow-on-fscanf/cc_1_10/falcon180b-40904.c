//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 118 // Total number of elements in the periodic table

struct element {
    char name[20];
    char symbol[3];
    int atomic_number;
    int atomic_weight;
};

void generate_table(struct element table[]) {
    FILE *file;
    file = fopen("periodic_table.txt", "r");

    if(file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    int i = 0;
    while(fscanf(file, "%s %s %d %d", table[i].name, table[i].symbol, &table[i].atomic_number, &table[i].atomic_weight)!= EOF) {
        i++;
    }

    fclose(file);
}

void shuffle_array(struct element arr[], int n) {
    srand(time(0));
    for(int i = 0; i < n; i++) {
        int j = rand() % n;
        struct element temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    struct element table[SIZE];
    generate_table(table);
    shuffle_array(table, SIZE);

    int score = 0;
    int num_questions = 10;

    for(int i = 0; i < num_questions; i++) {
        int random_index = rand() % SIZE;
        printf("Question %d:\n", i+1);
        printf("Name: %s\n", table[random_index].name);
        printf("Symbol: %s\n", table[random_index].symbol);
        printf("Atomic Number: %d\n", table[random_index].atomic_number);
        printf("Atomic Weight: %d\n", table[random_index].atomic_weight);

        char input[50];
        scanf("%s", input);

        if(strcmp(input, table[random_index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("Your final score is: %d out of %d\n", score, num_questions);

    return 0;
}