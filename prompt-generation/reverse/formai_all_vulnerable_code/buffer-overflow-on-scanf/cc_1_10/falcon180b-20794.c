//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 20

struct fortune {
    char *text;
    int length;
};

void generate_fortunes(struct fortune fortunes[NUM_FORTUNES]) {
    fortunes[0] = (struct fortune) {
       .text = "You will have a great day today!",
       .length = 37
    };

    fortunes[1] = (struct fortune) {
       .text = "Success is just around the corner for you.",
       .length = 45
    };

    fortunes[2] = (struct fortune) {
       .text = "You will find love in unexpected places.",
       .length = 43
    };

    // Add more fortunes here...
}

int main() {
    srand(time(NULL));

    struct fortune fortunes[NUM_FORTUNES];
    generate_fortunes(fortunes);

    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose a number between 1 and %d:\n", NUM_FORTUNES);
        scanf("%d", &choice);

        if (choice < 1 || choice > NUM_FORTUNES) {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice < 1 || choice > NUM_FORTUNES);

    printf("\nYour fortune: %s\n", fortunes[choice - 1].text);

    return 0;
}