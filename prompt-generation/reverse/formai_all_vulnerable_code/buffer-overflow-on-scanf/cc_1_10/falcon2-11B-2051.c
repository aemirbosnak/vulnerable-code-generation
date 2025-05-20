//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_ROWS 10
#define MAX_COLUMNS 5

typedef struct {
    char* bag_id;
    int row;
    int column;
    int weight;
} Bag;

typedef struct {
    int row;
    int column;
} Rows;

typedef struct {
    int column;
    Rows* row_list;
} Columns;

Bag* allocate_bag(int row, int column) {
    Bag* new_bag = (Bag*)malloc(sizeof(Bag));
    new_bag->row = row;
    new_bag->column = column;
    new_bag->bag_id = (char*)malloc(sizeof(char) * 10);
    return new_bag;
}

void print_bag(Bag* bag) {
    printf("Bag ID: %s\n", bag->bag_id);
    printf("Row: %d\n", bag->row);
    printf("Column: %d\n", bag->column);
    printf("Weight: %d\n", bag->weight);
}

void print_all_bags(Bag* bags, int num_bags) {
    for (int i = 0; i < num_bags; i++) {
        print_bag(bags + i);
        printf("\n");
    }
}

int main() {
    Bag* bags = (Bag*)malloc(MAX_BAGS * sizeof(Bag));
    int num_bags = 0;

    while (scanf("%s %d %d %d", bags[num_bags].bag_id, &bags[num_bags].row, &bags[num_bags].column, &bags[num_bags].weight)!= EOF) {
        num_bags++;
    }

    printf("Number of bags: %d\n", num_bags);

    print_all_bags(bags, num_bags);

    return 0;
}