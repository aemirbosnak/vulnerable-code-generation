//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *text;
    int weight;
} Fortune;

Fortune fortunes[] = {
    {"You will have a great day today!", 10},
    {"A new opportunity is coming your way.", 20},
    {"You will meet someone special soon.", 30},
    {"Success is within your reach.", 40},
    {"Your hard work will pay off.", 50},
    {"You will receive good news.", 60},
    {"A pleasant surprise awaits you.", 70},
    {"You will find what you have been looking for.", 80},
    {"You will overcome a challenge.", 90},
    {"Your future is bright.", 100}
};

int main() {
    srand(time(NULL));
    int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    int fortuneIndex;
    char choice;

    do {
        printf("Welcome to the Fortune Teller!\n\n");
        printf("How many fortunes would you like to receive? ");
        scanf("%d", &numFortunes);

        if (numFortunes < 1 || numFortunes > 10) {
            printf("Invalid number of fortunes. Please enter a number between 1 and 10.\n");
        }
    } while (numFortunes < 1 || numFortunes > 10);

    for (int i = 0; i < numFortunes; i++) {
        fortuneIndex = rand() % numFortunes;
        printf("\nYour fortune is:\n%s\n", fortunes[fortuneIndex].text);
        printf("Weight: %d\n\n", fortunes[fortuneIndex].weight);
    }

    printf("Thank you for using the Fortune Teller!\n");
    printf("Press any key to exit...\n");
    scanf("%c", &choice);

    return 0;
}