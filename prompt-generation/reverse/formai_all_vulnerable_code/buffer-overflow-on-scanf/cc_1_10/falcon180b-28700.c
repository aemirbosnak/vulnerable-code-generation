//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 100

// Function to print a random fortune
void print_fortune(int index) {
    static char fortunes[NUM_FORTUNES][80] = {
        "You will have a successful day.",
        "A new opportunity is coming your way.",
        "Your hard work will pay off soon.",
        "You will receive good news today.",
        "A friend will offer you help when you need it most.",
        "You will find love in unexpected places.",
        "Success is within your reach, keep pushing forward.",
        "Your creativity will be rewarded today.",
        "A financial windfall is on the horizon.",
        "You will have a peaceful and relaxing day."
    };

    printf("%s\n", fortunes[index]);
}

int main() {
    srand(time(NULL));

    int choice;
    char input[80];

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("What would you like to know?\n");
        printf("1. Love\n2. Career\n3. Finance\n4. General\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your love life will be full of surprises today.\n");
                break;
            case 2:
                printf("Your hard work will soon pay off in your career.\n");
                break;
            case 3:
                printf("Financial stability is within your reach.\n");
                break;
            case 4:
                printf("You will have a positive encounter with someone new.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("Would you like another fortune? (y/n): ");
        scanf(" %c", &input[0]);
    } while (toupper(input[0]) == 'Y');

    return 0;
}