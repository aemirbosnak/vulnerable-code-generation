//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of fortunes
#define NUM_FORTUNES 100

// Define the length of each fortune
#define FORTUNE_LENGTH 80

// Define the fortunes
char *fortunes[NUM_FORTUNES] = {
    "You will have a happy and prosperous life.",
    "A great opportunity will come your way soon.",
    "You will find true love in the near future.",
    "Your hard work will pay off in the end.",
    "You will experience good health and well-being.",
    "Success is within your reach, keep striving for it.",
    "You will be blessed with good fortune and luck.",
    "Your dreams will come true if you believe in them.",
    "You will have a long and fulfilling life.",
    "Your future is bright and full of possibilities."
};

// Function to print a random fortune
void print_fortune() {
    int index = rand() % NUM_FORTUNES;
    printf("%s\n", fortunes[index]);
}

int main() {
    srand(time(NULL));

    int choice;
    char name[20];

    do {
        system("clear");
        printf("Welcome to the Automated Fortune Teller!\n\n");
        printf("Please enter your name: ");
        scanf("%s", name);

        printf("\n%s, I have a fortune for you:\n\n", name);
        print_fortune();

        printf("\nDo you want another fortune? (y/n) ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}