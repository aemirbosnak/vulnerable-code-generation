//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 12
#define SEED 131415
#define MASK (1 << 24)

unsigned int next_random() {
    unsigned int x = SEED;
    x = x * 16807 % MASK;
    return x;
}

const char *fortunes[TABLE_SIZE] = {
    "The future is bright and full of opportunity.",
    "Prepare yourself for a year of growth and change.",
    "Your hard work will pay off in unexpected ways.",
    "Love will bring you joy and happiness.",
    "Success and prosperity will come your way.",
    "Challenges will test your strength and resilience.",
    "Be open to new experiences and possibilities.",
    "Trust your intuition and make bold decisions.",
    "Your creativity and innovation will shine.",
    "Good luck will come in unexpected ways.",
    "Your perseverance will be rewarded.",
    "The stars are aligned in your favor."
};

int main() {
    unsigned int rnd;
    int month;

    srand((unsigned int)time(NULL));

    printf("Enter your birth month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }

    rnd = next_random();

    // Use the lower 4 bits of the random number to index the fortune table
    printf("Your fortune for the month of %s:\n", month < 10 ? ("0" + month) : ("" + month));
    printf("%s\n", fortunes[rnd & 15]);

    return 0;
}