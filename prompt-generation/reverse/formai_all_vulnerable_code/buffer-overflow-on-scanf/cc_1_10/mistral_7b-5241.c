//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

void print_fortune(int index) {
    switch (index) {
        case 0:
            printf("May your day be filled with joy and happiness.\n");
            break;
        case 1:
            printf("May the wind be at your back and the sun on your face.\n");
            break;
        case 2:
            printf("May your dreams come true and your nightmares stay away.\n");
            break;
        case 3:
            printf("May your pockets be full and your heart be light.\n");
            break;
        case 4:
            printf("May the stars shine brightly upon you.\n");
            break;
        case 5:
            printf("May good fortune find you wherever you go.\n");
            break;
        case 6:
            printf("May your life be filled with love and laughter.\n");
            break;
        case 7:
            printf("May the blessings of the universe be upon you.\n");
            break;
        case 8:
            printf("May you always find the strength to overcome any obstacle.\n");
            break;
        case 9:
            printf("May your dreams become reality and your reality become a dream.\n");
            break;
        default:
            printf("Invalid fortune index.\n");
            break;
    }
}

int main(void) {
    int index, random_number;
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller! I'm here to bring a smile to your face.\n");
    printf("Please enter a number between 0 and 9 to receive your fortune:\n");

    scanf("%d", &index);

    if (index < 0 || index > 9) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    print_fortune(index);

    random_number = rand() % 2;

    if (random_number == 0) {
        printf("As a bonus, here's an extra fortune for being so wonderful!\n");
        print_fortune(rand() % NUM_FORTUNES);
    }

    printf("Thank you for using the Automated Fortune Teller. Have a great day!\n");

    return 0;
}