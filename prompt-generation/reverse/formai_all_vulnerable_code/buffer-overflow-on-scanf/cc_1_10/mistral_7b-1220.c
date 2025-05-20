//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAKES 100

// Struct for cake information
typedef struct {
    char name[20];
    int flavor_code;
} cake_t;

// Function to print cake information
void print_cake(cake_t cake) {
    printf("%s - %d\n", cake.name, cake.flavor_code);
}

// Function to binary search for a cake
int binary_search(cake_t cakes[], int left, int right, int flavor_code) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (cakes[mid].flavor_code == flavor_code) {
            return mid;
        }

        if (cakes[mid].flavor_code < flavor_code) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    cake_t cakes[MAX_CAKES];
    int num_cakes = 0;
    int user_flavor_code;

    // Generate some cake data
    strcpy(cakes[num_cakes++].name, "Vanilla");
    cakes[num_cakes++].flavor_code = 1;

    strcpy(cakes[num_cakes++].name, "Chocolate");
    cakes[num_cakes++].flavor_code = 2;

    strcpy(cakes[num_cakes++].name, "Strawberry");
    cakes[num_cakes++].flavor_code = 3;

    strcpy(cakes[num_cakes++].name, "Lemon");
    cakes[num_cakes++].flavor_code = 4;

    strcpy(cakes[num_cakes++].name, "Mint");
    cakes[num_cakes++].flavor_code = 5;

    strcpy(cakes[num_cakes++].name, "Cookies & Cream");
    cakes[num_cakes++].flavor_code = 6;

    strcpy(cakes[num_cakes++].name, "Red Velvet");
    cakes[num_cakes++].flavor_code = 7;

    strcpy(cakes[num_cakes++].name, "Carrot");
    cakes[num_cakes++].flavor_code = 8;

    strcpy(cakes[num_cakes++].name, "Chestnut");
    cakes[num_cakes++].flavor_code = 9;

    strcpy(cakes[num_cakes++].name, "Pumpkin");
    cakes[num_cakes++].flavor_code = 10;

    // Ask user for desired cake flavor
    printf("Enter the flavor code of the cake you'd like to find: ");
    scanf("%d", &user_flavor_code);

    // Perform binary search for cake
    int index = binary_search(cakes, 0, num_cakes - 1, user_flavor_code);

    // Print result
    if (index != -1) {
        printf("Cake with flavor %d found at index %d:\n", user_flavor_code, index);
        print_cake(cakes[index]);
    } else {
        printf("Cake with flavor %d not found.\n", user_flavor_code);
    }

    return 0;
}