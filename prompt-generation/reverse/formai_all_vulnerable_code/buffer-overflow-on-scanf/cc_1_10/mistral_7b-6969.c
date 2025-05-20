//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BAGS 50
#define MIN_WEIGHT 5
#define MAX_WEIGHT 50
#define MIN_DIM_X 10
#define MAX_DIM_X 30
#define MIN_DIM_Y 10
#define MAX_DIM_Y 30
#define MIN_DIM_Z 5
#define MAX_DIM_Z 20
typedef struct {
    int id;
    char type[10];
    int weight;
    int dim_x;
    int dim_y;
    int dim_z;
} Baggage;
void print_baggage(Baggage bag) {
    printf("Baggage ID: %d, Type: %s, Weight: %dkg, Dimensions: (%d, %d, %d)\n", bag.id, bag.type, bag.weight/1000.0, bag.dim_x, bag.dim_y, bag.dim_z);
}
void add_baggage(Baggage bags[], int* count, Baggage new_bag) {
    if (*count < MAX_BAGS) {
        (*count)++;
        bags[*count - 1] = new_bag;
    } else {
        printf("Error: Maximum number of bags reached.\n");
    }
}
int main() {
    Baggage bags[MAX_BAGS];
    int count = 0;
    while (1) {
        char type[10];
        int weight, dim_x, dim_y, dim_z;
        printf("Enter baggage type: ");
        scanf("%s", type);
        printf("Enter baggage weight(kg): ");
        scanf("%d", &weight);
        printf("Enter baggage dimensions(width, height, length): ");
        scanf("%d%d%d", &dim_x, &dim_y, &dim_z);
        if (weight < MIN_WEIGHT || weight > MAX_WEIGHT || dim_x < MIN_DIM_X || dim_x > MAX_DIM_X || dim_y < MIN_DIM_Y || dim_y > MAX_DIM_Y || dim_z < MIN_DIM_Z || dim_z > MAX_DIM_Z) {
            printf("Error: Baggage dimensions or weight is not valid.\n");
            continue;
        }
        Baggage new_bag = {0};
        strcpy(new_bag.type, type);
        new_bag.weight = weight;
        new_bag.dim_x = dim_x;
        new_bag.dim_y = dim_y;
        new_bag.dim_z = dim_z;
        add_baggage(bags, &count, new_bag);
        if (count > 0) {
            printf("Baggage added successfully.\n");
            print_baggage(new_bag);
        }
        printf("Do you want to add another baggage? (y/n): ");
        char answer;
        scanf("%c", &answer);
        if (answer == 'n') {
            break;
        }
    }
    printf("Total number of baggage added: %d\n", count);
    return 0;
}