//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *text;
    int weight;
} Fortune;

Fortune fortunes[] = {
    {"Your future is looking bright. ", 10},
    {"You will find love in unexpected places. ", 20},
    {"A new opportunity is coming your way. ", 30},
    {"You will experience financial success. ", 40},
    {"Travel is in your near future. ", 50},
    {"You will overcome challenges and achieve greatness. ", 60},
    {"Your hard work will pay off soon. ", 70},
    {"You will receive good news from a friend or family member. ", 80},
    {"Your creativity will be recognized and appreciated. ", 90},
    {"You will make a positive impact on someone's life. ", 100}
};

int main() {
    srand(time(NULL));
    int numFortunes = sizeof(fortunes) / sizeof(Fortune);
    Fortune selectedFortune;

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);

    printf("\n%s, your fortune awaits!\n\n", name);

    int totalWeight = 0;
    for (int i = 0; i < numFortunes; i++) {
        totalWeight += fortunes[i].weight;
    }

    int randomIndex = rand() % totalWeight;

    for (int i = 0; i < numFortunes; i++) {
        if (randomIndex >= fortunes[i].weight && randomIndex < (fortunes[i].weight + fortunes[i + 1].weight)) {
            selectedFortune = fortunes[i];
            break;
        }
    }

    printf("\n%s,\n", name);
    printf("%s\n", selectedFortune.text);

    return 0;
}