//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80

typedef struct {
    char text[MAX_LENGTH];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    { "You will meet someone special today. ", 34 },
    { "A new opportunity is coming your way. ", 32 },
    { "Your hard work will pay off soon. ", 28 },
    { "You will receive good news in the near future. ", 41 },
    { "A friend will surprise you with a gift. ", 29 },
    { "You will overcome a challenge that has been bothering you. ", 51 },
    { "Your finances will improve in the coming weeks. ", 39 },
    { "You will experience a moment of great joy. ", 25 },
    { "A loved one will reach out to you unexpectedly. ", 37 },
    { "You will discover a new talent or hobby. ", 33 }
};

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_LENGTH];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("Hello, %s! I am here to tell you your fortune.\n", input);

    while (1) {
        printf("Please choose a number between 1 and %d:\n", MAX_FORTUNES);
        for (int i = 0; i < MAX_FORTUNES; i++) {
            printf("%d. %s\n", i + 1, fortunes[i].text);
        }
        scanf("%d", &choice);
        if (choice >= 1 && choice <= MAX_FORTUNES) {
            printf("Your fortune is:\n%s\n", fortunes[choice - 1].text);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        printf("Would you like to try again? (y/n): ");
        scanf(" %c", &input[0]);
        if (input[0]!= 'y') {
            break;
        }
    }

    return 0;
}