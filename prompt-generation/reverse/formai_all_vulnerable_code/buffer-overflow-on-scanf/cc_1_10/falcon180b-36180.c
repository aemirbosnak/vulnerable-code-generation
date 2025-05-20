//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
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

        switch (rand() % 4) {
            case 0:
                strcat(fortunes[i].text, "You will meet someone new today. ");
                break;
            case 1:
                strcat(fortunes[i].text, "A financial opportunity is coming your way. ");
                break;
            case 2:
                strcat(fortunes[i].text, "You will receive good news soon. ");
                break;
            case 3:
                strcat(fortunes[i].text, "Beware of making hasty decisions today. ");
                break;
        }
    }
}

void print_fortune(Fortune fortune) {
    printf("Your fortune: %s\n", fortune.text);
}

int main() {
    Fortune fortunes[MAX_FORTUNES];
    int count;

    printf("How many fortunes would you like to generate? ");
    scanf("%d", &count);

    if (count > MAX_FORTUNES || count <= 0) {
        printf("Invalid number of fortunes.\n");
        return 1;
    }

    generate_fortunes(fortunes, count);

    printf("Your fortunes:\n");

    for (int i = 0; i < count; i++) {
        print_fortune(fortunes[i]);
    }

    return 0;
}