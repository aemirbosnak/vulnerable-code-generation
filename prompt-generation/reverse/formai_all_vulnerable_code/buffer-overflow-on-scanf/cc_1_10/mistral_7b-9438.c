//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    char message[MAX_SIZE];
    int probability;
} Fortune;

Fortune fortunes[10] = {
    {"The gods are with you today, seek fortune and prosper.", 90},
    {"Fortune favors the bold, go forth and conquer.", 80},
    {"Your hard work will pay off soon.", 70},
    {"The stars align in your favor, good things are coming.", 60},
    {"Your past mistakes do not define your future.", 50},
    {"Be patient, good things come to those who wait.", 40},
    {"Take a chance, you might just succeed.", 30},
    {"You have the power to make your dreams a reality.", 20},
    {"The future is uncertain, but believe in yourself.", 10},
    {"Your journey may be long, but the reward is worth it.", 5}
};

void print_fortune(Fortune fortune) {
    printf("\n%s\n", fortune.message);
}

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    int index;
    Fortune fortune;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");

    char name[MAX_SIZE];
    scanf("%s", name);

    int total_probability = 0;
    for (int i = 0; i < 10; i++) {
        total_probability += fortunes[i].probability;
    }

    index = rand_int(0, total_probability - 1);

    int current_probability = 0;
    for (int i = 0; i < 10; i++) {
        if (current_probability + fortunes[i].probability > index) {
            fortune = fortunes[i];
            break;
        }
        current_probability += fortunes[i].probability;
    }

    print_fortune(fortune);

    return 0;
}