//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 50

struct fortune {
    char text[80];
    int length;
};

void generate_fortunes() {
    struct fortune fortunes[NUM_FORTUNES];
    int i;

    srand(time(NULL));

    for (i = 0; i < NUM_FORTUNES; i++) {
        fortunes[i].length = rand() % 80 + 1;
        sprintf(fortunes[i].text, "Your future holds %d-%s.", fortunes[i].length, "unknown");
    }
}

void print_fortune(struct fortune fortune) {
    printf("%s\n", fortune.text);
}

int main() {
    struct fortune fortunes[NUM_FORTUNES];
    int choice;

    generate_fortunes();

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please choose a fortune:\n");

    for (int i = 0; i < NUM_FORTUNES; i++) {
        printf("%d. (%d characters)\n", i+1, fortunes[i].length);
    }

    scanf("%d", &choice);

    if (choice >= 1 && choice <= NUM_FORTUNES) {
        print_fortune(fortunes[choice-1]);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}