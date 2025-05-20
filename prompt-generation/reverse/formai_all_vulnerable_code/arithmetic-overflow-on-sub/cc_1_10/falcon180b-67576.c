//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_BAG_SIZE 50
#define MAX_BAGGAGE_CARTS 20

typedef struct {
    int bag_size;
    int cart_num;
} Bag;

void generate_bags(Bag bags[], int num_bags) {
    srand(time(NULL));
    for (int i = 0; i < num_bags; i++) {
        bags[i].bag_size = rand() % MAX_BAG_SIZE + 1;
    }
}

void print_bags(Bag bags[], int num_bags) {
    for (int i = 0; i < num_bags; i++) {
        printf("Bag %d: %d\n", i+1, bags[i].bag_size);
    }
}

void sort_bags(Bag bags[], int num_bags) {
    for (int i = 0; i < num_bags-1; i++) {
        for (int j = i+1; j < num_bags; j++) {
            if (bags[i].bag_size > bags[j].bag_size) {
                Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
}

int main() {
    Bag bags[MAX_BAGS];
    int num_bags, num_carts;

    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);

    generate_bags(bags, num_bags);
    print_bags(bags, num_bags);

    sort_bags(bags, num_bags);
    printf("\nSorted by size:\n");
    print_bags(bags, num_bags);

    return 0;
}