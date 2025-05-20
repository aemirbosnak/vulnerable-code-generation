//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_fortune(int num) {
    switch (num) {
        case 1:
            printf("A wonderful day lies ahead for you!\n");
            break;
        case 2:
            printf("You will meet someone special today!\n");
            break;
        case 3:
            printf("Great things are coming your way!\n");
            break;
        case 4:
            printf("Your hard work will pay off soon!\n");
            break;
        case 5:
            printf("A surprise is waiting for you!\n");
            break;
        case 6:
            printf("New opportunities will arise for you!\n");
            break;
        case 7:
            printf("Your dreams will come true!\n");
            break;
        case 8:
            printf("It's your lucky day!\n");
            break;
        default:
            printf("Sorry, I cannot predict your future right now.\n");
            break;
    }
}

int main() {
    // greeting message
    printf("Welcome to the Automated Fortune Teller! Let's find out what the future has in store for you.\n");

    // prompt for user's name
    char name[20];
    printf("What is your name?\n");
    scanf("%s", name);

    // generate a seed for the random number generator based on the current time
    srand(time(NULL));

    // generate a random number between 1 and 8
    int num = rand() % 8 + 1;

    // print out the user's fortune
    printf("%s, your fortune today is:\n", name);
    print_fortune(num);

    // closing message
    printf("Thank you for using the Automated Fortune Teller. Goodbye!\n");

    return 0;
}