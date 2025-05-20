//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a fortune
void print_fortune(int fortune_num) {
    switch(fortune_num) {
        case 1:
            printf("You will find love in unexpected places.\n");
            break;
        case 2:
            printf("A financial windfall is headed your way.\n");
            break;
        case 3:
            printf("Your hard work will soon pay off.\n");
            break;
        case 4:
            printf("Travel is in your future.\n");
            break;
        case 5:
            printf("You will experience a major life change.\n");
            break;
        case 6:
            printf("A new friendship will blossom.\n");
            break;
        case 7:
            printf("You will receive good news.\n");
            break;
        case 8:
            printf("A long-lost friend will reappear in your life.\n");
            break;
        case 9:
            printf("You will achieve a personal goal.\n");
            break;
        case 10:
            printf("Your health will improve.\n");
            break;
        default:
            printf("The future is uncertain...\n");
            break;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int num_fortunes;
    printf("How many fortunes would you like to receive? ");
    scanf("%d", &num_fortunes);

    for(int i = 0; i < num_fortunes; i++) {
        int fortune_num = rand_int(1, 10); // Generate a random fortune number
        print_fortune(fortune_num); // Print the fortune
        printf("\n"); // Add a newline for readability
    }

    return 0;
}