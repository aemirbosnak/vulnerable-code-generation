//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80

typedef struct {
    char text[MAX_LENGTH];
    int length;
} fortune;

fortune fortunes[MAX_FORTUNES] = {
    {"You will meet a tall, dark stranger."},
    {"A great adventure awaits you in the near future."},
    {"You will come into a large sum of money."},
    {"A new love interest is on the horizon."},
    {"Beware of false friends and deceitful people."},
    {"Your hard work will pay off soon."},
    {"You will receive unexpected news from afar."},
    {"A long-lost friend will reenter your life."},
    {"Success is within your reach if you stay focused."},
    {"You will experience a major life change in the coming months."}
};

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_LENGTH];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", input);

    printf("\nHello, %s! I am here to tell you your fortune.\n", input);
    printf("Please choose a number between 1 and %d:\n", MAX_FORTUNES);

    for (int i = 0; i < MAX_FORTUNES; i++) {
        printf("%d. %s\n", i + 1, fortunes[i].text);
    }

    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_FORTUNES) {
        printf("\nInvalid choice! Please try again.\n");
        return 1;
    }

    printf("\nYour fortune is:\n");
    printf("%s\n", fortunes[choice - 1].text);

    return 0;
}