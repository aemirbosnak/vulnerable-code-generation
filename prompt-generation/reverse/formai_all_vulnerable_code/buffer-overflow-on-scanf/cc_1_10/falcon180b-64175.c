//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

struct Fortune {
    char *text;
    int length;
};

void generateFortune() {
    const char *fortunes[] = {
        "You will have a great day today!",
        "Success is just around the corner for you.",
        "You will meet someone special soon.",
        "Your hard work will pay off in the end.",
        "A new opportunity is coming your way.",
        "You are destined for greatness.",
        "Your future is looking bright.",
        "You will accomplish great things in life.",
        "You are a shining star, keep shining bright.",
        "You have the power to achieve anything you desire."
    };

    int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    int randomIndex = rand() % numFortunes;

    printf("Your fortune is: %s\n", fortunes[randomIndex]);
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                generateFortune();
                break;
            case 2:
                printf("Thank you for using the Automated Fortune Teller!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\nPress enter to continue...\n");
        getchar();
    } while (choice!= 2);

    return 0;
}