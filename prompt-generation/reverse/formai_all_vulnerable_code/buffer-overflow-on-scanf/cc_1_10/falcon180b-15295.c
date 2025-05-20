//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a random fortune cookie message
void print_fortune(void) {
    const char* fortunes[] = {
        "You will have a successful day.",
        "A pleasant surprise awaits you.",
        "Your hard work will pay off soon.",
        "You will find love in unexpected places.",
        "A new opportunity is coming your way.",
        "You will receive good news today.",
        "Your future is looking bright.",
        "You will overcome any obstacles in your path.",
        "A friend will offer you valuable advice.",
        "You will experience great happiness in your life."
    };

    int fortune_index = rand_int(0, 9);
    printf("Your fortune cookie says: %s\n", fortunes[fortune_index]);
}

int main(void) {
    srand(time(NULL));

    int choice;
    do {
        printf("Welcome to the Retro Fortune Teller!\n");
        printf("What would you like to do?\n");
        printf("1. Get a fortune cookie\n");
        printf("2. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_fortune();
                break;
            case 2:
                printf("Thank you for using the Retro Fortune Teller!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 2);

    return 0;
}