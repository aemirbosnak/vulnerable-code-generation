//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10
#define MAX_STYLES 4

const char *fortunes[MAX_FORTUNES] = {
    "You will find great success in your endeavors.",
    "A person you admire will soon come into your life.",
    "Trust your instincts; they will lead you to happiness.",
    "Be cautious; a surprise awaits you on the weekend.",
    "A new opportunity is on the horizon.",
    "Your energy will attract positive situations.",
    "Expect the unexpected; fortune favors the bold!",
    "A journey will soon become a part of your life's story.",
    "An old friend will reach out to you soon.",
    "This week, take a leap of faith and embrace change."
};

const char *styles[MAX_STYLES] = {
    "Mystical",
    "Nature-based",
    "Dreamy",
    "Pragmatic"
};

void display_fortune(const char *fortune, const char *style) {
    printf("\n--- Your Fortune ---\n");
    printf("Style: %s\n", style);
    printf("Fortune: %s\n", fortune);
    printf("---------------------\n");
}

int main() {
    srand(time(NULL));
    int userChoice = 0;

    printf("~~~~~~~~~~ Fortune Teller ~~~~~~~~~~\n");
    
    while (1) {
        printf("Select an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Quit\n");
        printf("Choose (1 or 2): ");
        scanf("%d", &userChoice);

        if (userChoice == 1) {
            int fortuneIndex = rand() % MAX_FORTUNES;
            int styleIndex = rand() % MAX_STYLES;

            display_fortune(fortunes[fortuneIndex], styles[styleIndex]);
        } else if (userChoice == 2) {
            printf("Thank you for visiting the Fortune Teller. Farewell!\n");
            break;
        } else {
            printf("Invalid option. Please select 1 or 2.\n");
        }
    }

    return 0;
}