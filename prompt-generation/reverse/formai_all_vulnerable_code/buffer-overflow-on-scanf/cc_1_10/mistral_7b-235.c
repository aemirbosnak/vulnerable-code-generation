//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MONTHS 12
#define MAX_FORTUNES 5
#define FORTUNE_LENGTH 80

typedef struct {
    int month;
    char fortune[FORTUNE_LENGTH];
} Fortune;

void initFortunes(Fortune fortunes[]) {
    const char *fortunesStr[] = {
        "May the force be with you!",
        "The best is yet to come!",
        "Your hard work will pay off!",
        "Good things come to those who wait!",
        "You are in control of your destiny!",
        "Take risks and seize opportunities!",
        "Your creativity will bring you success!",
        "Good luck and prosperity will find you!",
        "Stay focused and you will achieve your goals!",
        "Your positive attitude will bring good fortune!",
        "Trust in yourself and your abilities!",
        "Embrace change and grow stronger!"
    };

    for (int i = 0; i < MONTHS; i++) {
        fortunes[i].month = i + 1;
        strcpy(fortunes[i].fortune, fortunesStr[i]);
    }
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    Fortune fortunes[MONTHS];

    initFortunes(fortunes);

    int month, fortuneIndex;
    printf("Enter your birth month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > MONTHS) {
        printf("Invalid month! Please enter a number between 1 and 12.\n");
        return 1;
    }

    fortuneIndex = getRandomNumber(0, MAX_FORTUNES - 1);

    printf("\nYour fortune for the month of %d (%d):\n", month, month - 1);
    printf("%s\n", fortunes[(month - 1) % MONTHS].fortune);
    printf("\nYour bonus fortune for today:\n%s\n", fortunes[fortuneIndex].fortune);

    return 0;
}