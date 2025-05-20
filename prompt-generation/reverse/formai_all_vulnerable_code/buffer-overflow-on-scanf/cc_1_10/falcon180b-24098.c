//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 100

struct fortune {
    char text[MAX_LENGTH];
    int length;
};

struct fortune fortunes[MAX_FORTUNES] = {
    {"You will have good luck today. ", 28},
    {"A new opportunity is coming your way. ", 38},
    {"You will receive a surprise gift. ", 24},
    {"Success is within your reach. ", 25},
    {"Your hard work will pay off soon. ", 31},
    {"Love is in the air. ", 17},
    {"Travel is in your future. ", 23},
    {"A friend will offer you help. ", 28},
    {"You will overcome a challenge. ", 29},
    {"Believe in yourself and you will succeed. ", 39}
};

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_LENGTH];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What's your name? ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    printf("Hello, %s! I am here to tell you your fortune.\n", input);
    printf("Please choose a number between 1 and 9.\n");

    scanf("%d", &choice);

    if (choice < 1 || choice > 9) {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }

    printf("\nYour fortune is:\n%s\n", fortunes[choice - 1].text);

    return 0;
}