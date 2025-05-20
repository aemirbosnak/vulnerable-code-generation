//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a random fortune
void print_fortune() {
    int fortune_index = rand_range(0, 5);
    switch (fortune_index) {
        case 0:
            printf("You will find true love in the near future.\n");
            break;
        case 1:
            printf("A great opportunity will present itself to you soon.\n");
            break;
        case 2:
            printf("Your hard work will pay off in the coming days.\n");
            break;
        case 3:
            printf("Beware of a deceitful friend who may betray you.\n");
            break;
        case 4:
            printf("You will experience a small setback, but it will lead to greater success.\n");
            break;
        case 5:
            printf("A long-lost relative will reach out to you unexpectedly.\n");
            break;
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int choice;
    while (1) {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Press 1 to receive a fortune or 0 to exit.\n");
        scanf("%d", &choice);
        if (choice == 0) {
            printf("Thank you for using the Automated Fortune Teller. Goodbye!\n");
            return 0;
        }
        print_fortune();
        printf("Would you like another fortune? (y/n)\n");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'n') {
            printf("Thank you for using the Automated Fortune Teller. Goodbye!\n");
            return 0;
        }
    }
    return 0;
}