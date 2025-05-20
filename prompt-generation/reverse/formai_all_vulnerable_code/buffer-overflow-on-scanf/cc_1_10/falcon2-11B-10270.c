//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 100

typedef struct {
    char* name;
    int weight;
} Bag;

Bag* create_bag(char* name, int weight) {
    Bag* new_bag = malloc(sizeof(Bag));
    if (new_bag == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    new_bag->name = name;
    new_bag->weight = weight;
    return new_bag;
}

void print_bag_info(Bag* bag) {
    printf("%s: %d\n", bag->name, bag->weight);
}

int main() {
    Bag* bags[MAX_BAGS];

    int num_bags = 0;
    int choice;
    while (1) {
        printf("Enter number of bags to create (0 to quit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        for (int i = 0; i < choice; i++) {
            char* name;
            int weight;
            printf("Enter bag name and weight: ");
            scanf("%s%d", &name, &weight);

            Bag* new_bag = create_bag(name, weight);
            bags[num_bags++] = new_bag;
        }
    }

    for (int i = 0; i < num_bags; i++) {
        print_bag_info(bags[i]);
    }

    return 0;
}