//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRUITS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Fruit;

void read_data(Fruit fruits[], int *count) {
    FILE *file = fopen("fruits.csv", "r");
    if (file == NULL) {
        printf("Oops! Can't find the fruits file! 🎉 Please check if fruits.csv exists.\n");
        exit(1);
    }

    printf("📜 Reading fruit data from file...\n");
    while (fscanf(file, "%[^,],%f\n", fruits[*count].name, &fruits[*count].price) != EOF) {
        (*count)++;
        if (*count >= MAX_FRUITS) {
            printf("Whoa! We've got too many fruits! 🍍 Max is %d\n", MAX_FRUITS);
            break;
        }
    }
    fclose(file);
    printf("🎊 Successfully read %d fruits data!\n", *count);
}

void display_fruits(Fruit fruits[], int count) {
    printf("\n🍏 Fruit List:\n");
    for (int i = 0; i < count; i++) {
        printf("🌟 %s: $%.2f\n", fruits[i].name, fruits[i].price);
    }
}

void calculate_average_price(Fruit fruits[], int count) {
    if (count == 0) {
        printf("No fruits to calculate the average price! 🌼\n");
        return;
    }

    float total_price = 0;
    for (int i = 0; i < count; i++) {
        total_price += fruits[i].price;
    }

    float average_price = total_price / count;
    printf("\n💰 The average price of fruits is: $%.2f\n", average_price);
}

void find_most_expensive_fruit(Fruit fruits[], int count) {
    if (count == 0) {
        printf("No fruits to find the most expensive one! 🍭\n");
        return;
    }

    Fruit most_expensive = fruits[0];
    for (int i = 1; i < count; i++) {
        if (fruits[i].price > most_expensive.price) {
            most_expensive = fruits[i];
        }
    }
    printf("🏆 The most expensive fruit is: %s at $%.2f\n", most_expensive.name, most_expensive.price);
}

void find_cheapest_fruit(Fruit fruits[], int count) {
    if (count == 0) {
        printf("No fruits to find the cheapest one! 🍬\n");
        return;
    }

    Fruit cheapest = fruits[0];
    for (int i = 1; i < count; i++) {
        if (fruits[i].price < cheapest.price) {
            cheapest = fruits[i];
        }
    }
    printf("🥇 The cheapest fruit is: %s at $%.2f\n", cheapest.name, cheapest.price);
}

int main() {
    Fruit fruits[MAX_FRUITS];
    int count = 0;

    read_data(fruits, &count);
    display_fruits(fruits, count);
    calculate_average_price(fruits, count);
    find_most_expensive_fruit(fruits, count);
    find_cheapest_fruit(fruits, count);

    printf("\n✨ Thanks for using the Fruit Price Data Miner! Enjoy your fruits! 🍉🍊🍓\n");
    return 0;
}