//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 100

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a fortune
void print_fortune(int fortune_num) {
    char *fortunes[] = {
        "You will find great success in your endeavors.",
        "A new opportunity will present itself to you soon.",
        "Your hard work will pay off in the near future.",
        "A friend will offer you valuable advice.",
        "You will experience a moment of clarity that will guide you towards your goals.",
        "A small setback will lead to a greater triumph.",
        "You will receive unexpected good news.",
        "Your creativity will be at an all-time high today.",
        "A chance encounter will lead to a new friendship or romance.",
        "You will discover a hidden talent or skill."
    };

    printf("Fortune #%d: %s\n", fortune_num, fortunes[fortune_num]);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int fortune_num;
    char choice;

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Press 'q' to quit or any other key to receive a fortune:\n");
        scanf(" %c", &choice);

        if (choice == 'q' || choice == 'Q') {
            break;
        }

        fortune_num = rand_range(0, NUM_FORTUNES - 1);
        print_fortune(fortune_num);
    } while (1);

    return 0;
}