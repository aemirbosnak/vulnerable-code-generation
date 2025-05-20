//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

typedef struct {
    char text[80];
    int length;
} fortune;

fortune fortunes[MAX_FORTUNES] = {
    {"You will have good luck today. ", 29},
    {"A new opportunity will come your way. ", 38},
    {"You will meet someone special soon. ", 32},
    {"Your hard work will pay off. ", 27},
    {"A pleasant surprise awaits you. ", 34},
    {"You will receive a gift from someone unexpected. ", 45},
    {"A friend will offer you helpful advice. ", 39},
    {"You will overcome a challenge with ease. ", 37},
    {"You will experience a moment of great joy. ", 36},
    {"Your dreams will come true. ", 28}
};

int main() {
    int choice, random_index;
    char input[80];
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("What would you like to know?\n");
    printf("1. Love life\n");
    printf("2. Career\n");
    printf("3. Health\n");
    printf("4. Wealth\n");
    printf("5. General future\n");
    scanf("%d", &choice);

    random_index = rand() % MAX_FORTUNES;
    printf("\nYour fortune: %s\n", fortunes[random_index].text);

    printf("\nDo you want another fortune? (y/n): ");
    scanf("%s", input);

    if (input[0] == 'y' || input[0] == 'Y') {
        main();
    } else {
        printf("\nThank you for using the Automated Fortune Teller!\n");
    }

    return 0;
}