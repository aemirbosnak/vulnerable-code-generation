//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 100

typedef struct {
    char text[MAX_LENGTH];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet someone new today. ", 34},
    {"A great opportunity is coming your way. ", 44},
    {"You will receive unexpected news. ", 32},
    {"Success is within your reach. ", 36},
    {"Your hard work will pay off soon. ", 42},
    {"You will find happiness in the little things. ", 48},
    {"A friend will need your help today. ", 38},
    {"A pleasant surprise awaits you. ", 30},
    {"You will overcome a challenge. ", 40},
    {"A new adventure is on the horizon. ", 46}
};

void tellFortune(int depth) {
    if (depth == 0) {
        return;
    }

    srand(time(NULL));
    int index = rand() % MAX_FORTUNES;

    printf("Your fortune: %s\n", fortunes[index].text);

    tellFortune(depth - 1);
}

int main() {
    int numFortunes;

    printf("How many fortunes would you like to hear? ");
    scanf("%d", &numFortunes);

    for (int i = 0; i < numFortunes; i++) {
        tellFortune(3);
        printf("\n");
    }

    return 0;
}