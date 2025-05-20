//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet someone special today."},
    {"A great opportunity is coming your way."},
    {"You will receive good news soon."},
    {"Your hard work will pay off."},
    {"A friend will need your help."},
    {"You will experience a pleasant surprise."},
    {"Success is within your reach."},
    {"You will overcome a challenge."},
    {"A new adventure awaits you."},
    {"You will learn something valuable."},
    {"You will achieve your goals."},
    {"You will find what you have been searching for."},
    {"You will have a lucky day."},
    {"You will be rewarded for your efforts."},
    {"You will have a positive encounter."},
    {"You will discover a hidden talent."},
    {"You will receive a gift."},
    {"You will make a new friend."},
    {"You will have a peaceful day."},
    {"You will have a productive day."},
    {"You will have a fun day."},
    {"You will have a relaxing day."},
    {"You will have a creative day."},
    {"You will have a romantic day."},
    {"You will have a successful day."},
    {"You will have a happy day."}
};

int main() {
    srand(time(NULL));
    int fortuneIndex;
    char choice;

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Enter 'q' to quit or any other key to continue:\n");
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        }

        fortuneIndex = rand() % MAX_FORTUNES;
        printf("\nYour fortune is:\n%s\n", fortunes[fortuneIndex].text);

        printf("Press enter to get another fortune or 'q' to quit:\n");
        scanf(" %c", &choice);
    } while (choice!= 'q');

    return 0;
}