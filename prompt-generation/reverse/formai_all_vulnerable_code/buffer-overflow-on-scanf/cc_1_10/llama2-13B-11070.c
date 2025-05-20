//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define KINGDOM_OF_METRIC 1
#define KINGDOM_OF_IMPERIAL 2
#define KINGDOM_OF_NAUTICAL 3

struct kingdom {
    char name[20];
    double conversion_factor;
};

#define MAX_KINGDOMS 10

struct kingdom kingdoms[MAX_KINGDOMS] = {
    {"Metric", 1.0},
    {"Imperial", 0.328084},
    {"Nautical", 0.36},
};

int main(void) {
    char input[20];
    int user_choice;
    double value;

    printf("Welcome to the Kingdom of Conversions, good sir/madam!\n");
    printf("Choose a kingdom to convert to: \n");
    printf("1. Kingdom of Metric\n");
    printf("2. Kingdom of Imperial\n");
    printf("3. Kingdom of Nautical\n");
    scanf("%d", &user_choice);

    switch (user_choice) {
        case 1:
            printf("Thou hast chosen the Kingdom of Metric!\n");
            break;
        case 2:
            printf("Thou hast chosen the Kingdom of Imperial!\n");
            break;
        case 3:
            printf("Thou hast chosen the Kingdom of Nautical!\n");
            break;
        default:
            printf("Thou hast made a grave mistake, good sir/madam!\n");
            break;
    }

    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    for (int i = 0; i < MAX_KINGDOMS; i++) {
        if (user_choice == kingdoms[i].conversion_factor) {
            printf("In the %s kingdom, the value is: %g\n", kingdoms[i].name, value * kingdoms[i].conversion_factor);
        }
    }

    return 0;
}