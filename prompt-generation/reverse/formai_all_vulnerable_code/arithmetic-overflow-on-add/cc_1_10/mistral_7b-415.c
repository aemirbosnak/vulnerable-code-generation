//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BAGS 100
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int weight;
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int num_bags;
} Airport;

void load_bags(Airport* airport) {
    int i;
    for (i = 0; i < MAX_BAGS && scanf("%s %d", airport->bags[i].name, &airport->bags[i].weight) == 2; ++i) {
        ++airport->num_bags;
    }
}

void print_bags(const Airport* airport) {
    int i;
    puts("In the royal hall of Castle C:");
    for (i = 0; i < airport->num_bags; ++i) {
        printf("%s: %d lbs.\n", airport->bags[i].name, airport->bags[i].weight);
    }
}

void sort_bags(Airport* airport) {
    int i, j, temp_index;
    Bag temp;

    for (i = 0; i < airport->num_bags - 1; ++i) {
        for (j = 0; j < airport->num_bags - i - 1; ++j) {
            if (airport->bags[j].weight > airport->bags[j + 1].weight) {
                temp_index = j;
                temp = airport->bags[j];
                airport->bags[j] = airport->bags[j + 1];
                airport->bags[j + 1] = temp;
            }
        }
    }
}

int main() {
    Airport castle_c;

    puts("Welcome, noble knight, to Castle C's baggage handling!");

    load_bags(&castle_c);

    sort_bags(&castle_c);

    print_bags(&castle_c);

    puts("The bags are now sorted by weight. Your journey may now commence!");

    return 0;
}