//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *text;
    int weight;
} Fortune;

Fortune fortunes[] = {
    {"You will find love soon. ", 10},
    {"A new job opportunity is coming your way. ", 20},
    {"You will receive unexpected money. ", 30},
    {"Travel is in your future. ", 40},
    {"You will experience good health. ", 50},
    {"A friend will need your help. ", 60},
    {"You will have a creative breakthrough. ", 70},
    {"You will face a difficult decision. ", 80},
    {"You will have a lucky day. ", 90},
    {"A loved one will surprise you. ", 100}
};

int main() {
    srand(time(NULL));
    int numFortunes = sizeof(fortunes) / sizeof(Fortune);
    int randomIndex;
    char choice;

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("How many fortunes would you like to hear? ");
        scanf("%d", &numFortunes);
        if (numFortunes < 1 || numFortunes > 10) {
            printf("Invalid number of fortunes. Please try again.\n");
        }
    } while (numFortunes < 1 || numFortunes > 10);

    for (int i = 0; i < numFortunes; i++) {
        randomIndex = rand() % numFortunes;
        printf("%s\n", fortunes[randomIndex].text);
    }

    printf("Thank you for using the Automated Fortune Teller!\n");
    printf("Would you like to hear more fortunes? (y/n) ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        for (int i = 0; i < numFortunes; i++) {
            randomIndex = rand() % numFortunes;
            printf("%s\n", fortunes[randomIndex].text);
        }
        printf("Thank you for using the Automated Fortune Teller!\n");
        printf("Would you like to hear more fortunes? (y/n) ");
        scanf(" %c", &choice);
    }

    return 0;
}