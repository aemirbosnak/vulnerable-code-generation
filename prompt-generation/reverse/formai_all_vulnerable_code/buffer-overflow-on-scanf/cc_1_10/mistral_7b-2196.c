//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int surprise;
} Fruit;

typedef struct {
    Fruit fruits[5];
    int current;
} SurprisedFruitBasket;

void initializeBasket(SurprisedFruitBasket *basket) {
    int i;
    for (i = 0; i < 5; i++) {
        strcpy(basket->fruits[i].name, "Apple"); // Default fruit
        basket->fruits[i].surprise = 0;
    }
}

void surpriseFruit(SurprisedFruitBasket *basket) {
    int index;
    srand(time(NULL));
    index = rand() % 5;
    basket->fruits[index].surprise = 1;
}

void printFruit(Fruit fruit) {
    printf("%s", fruit.name);
    if (fruit.surprise)
        printf(" (Surprised!)");
    printf("\n");
}

void printBasket(SurprisedFruitBasket basket) {
    int i;
    printf("Surprised Fruit Basket:\n");
    for (i = 0; i < basket.current; i++) {
        printFruit(basket.fruits[i]);
    }
    printf("\n");
}

int main() {
    SurprisedFruitBasket basket;
    int choice;

    initializeBasket(&basket);
    surpriseFruit(&basket);
    printBasket(basket);

    for (;;) {
        printBasket(basket);
        printf("Press 1 to Surprise another fruit or 0 to Exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice != 1 || basket.current >= 5) {
            printf("Invalid Input. Please try again.\n");
            continue;
        }

        surpriseFruit(&basket);
        basket.current++;
    }

    return 0;
}