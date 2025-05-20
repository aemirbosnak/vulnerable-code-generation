//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

struct fortune {
    char *text;
    int length;
};

struct fortune fortunes[NUM_FORTUNES] = {
    {"In the wasteland, survival is the ultimate fortune. ", 64},
    {"The radiation may have changed us, but it cannot break our spirit. ", 78},
    {"Even in this desolate world, there is still hope for a better tomorrow. ", 88},
    {"The strongest survive, but the wisest thrive. ", 58},
    {"Every day is a new challenge, every challenge an opportunity for growth. ", 82},
    {"The old world may be gone, but its lessons remain. Learn from them and prosper. ", 94},
    {"In the face of adversity, true character is revealed. Embrace your inner strength. ", 92},
    {"Scavenge what you can, build what you must, and never forget where you came from. ", 102},
    {"Trust in yourself and those closest to you. Together, you can overcome anything. ", 84},
    {"Remember, fortune favors the bold. Take risks and seize opportunities when they arise. ", 98}
};

void print_fortune(struct fortune *fortune) {
    printf("%s\n", fortune->text);
}

int main() {
    srand(time(NULL));

    int choice;
    printf("Welcome to the Automated Fortune Teller.\n");
    printf("In this post-apocalyptic world, guidance is hard to come by.\n");
    printf("But fear not, for I am here to offer you wisdom and insight.\n");
    printf("Select an option:\n");
    printf("1. Get a fortune\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int index = rand() % NUM_FORTUNES;
        print_fortune(&fortunes[index]);
    } else if (choice == 2) {
        printf("Farewell, survivor. May fortune smile upon you in your travels.\n");
    } else {
        printf("Invalid option. Please try again.\n");
    }

    return 0;
}