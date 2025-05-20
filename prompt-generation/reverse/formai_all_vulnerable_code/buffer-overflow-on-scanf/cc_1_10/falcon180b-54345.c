//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

void generate_fortunes(Fortune fortunes[], int count) {
    int i;

    srand(time(NULL));

    for (i = 0; i < count; i++) {
        fortunes[i].text[0] = '\0';

        switch (rand() % 3) {
            case 0:
                strcat(fortunes[i].text, "You will meet a tall, dark stranger. ");
                break;
            case 1:
                strcat(fortunes[i].text, "A great opportunity is coming your way. ");
                break;
            case 2:
                strcat(fortunes[i].text, "Beware of the Ides of March. ");
                break;
        }
    }
}

void print_fortune(Fortune fortune) {
    printf("Your fortune: %s\n", fortune.text);
}

int main(int argc, char *argv[]) {
    Fortune fortunes[MAX_FORTUNES];
    int count;

    printf("Welcome to the Automated Fortune Teller!\n");

    printf("How many fortunes would you like? ");
    scanf("%d", &count);

    if (count > MAX_FORTUNES || count < 1) {
        printf("Sorry, I can only tell up to %d fortunes at a time.\n", MAX_FORTUNES);
        return 1;
    }

    generate_fortunes(fortunes, count);

    printf("Your fortunes:\n");

    for (int i = 0; i < count; i++) {
        print_fortune(fortunes[i]);
    }

    return 0;
}