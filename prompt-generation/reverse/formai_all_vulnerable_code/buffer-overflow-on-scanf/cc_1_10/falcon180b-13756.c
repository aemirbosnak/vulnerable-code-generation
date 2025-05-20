//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNE 100

typedef struct {
    char text[80];
    int length;
} FORTUNE;

FORTUNE fortunes[MAX_FORTUNE] = {
    {"The future is uncertain, but your path is clear. ", 41},
    {"You will have good luck in the coming days. ", 35},
    {"A new opportunity will present itself to you soon. ", 49},
    {"Beware of false friends and deceitful tongues. ", 45},
    {"Your hard work will pay off in unexpected ways. ", 47},
    {"You will find love where you least expect it. ", 39},
    {"A journey awaits you, both physical and spiritual. ", 51},
    {"Do not be afraid to take risks, for they will lead to success. ", 57},
    {"The answer you seek lies within your own heart. ", 45},
    {"A change is coming, embrace it with open arms. ", 39}
};

int main(void) {
    srand(time(NULL));
    int choice;
    char input[80];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("Hello, %s! I am here to guide you through life's mysteries.\n", input);
    printf("Ask me anything and I shall reveal your future.\n");

    while(1) {
        printf("\nWhat would you like to know?\n");
        printf("1. Love\n2. Wealth\n3. Health\n4. Happiness\n5. Other\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("You seek answers about love...\n");
        } else if(choice == 2) {
            printf("You seek answers about wealth...\n");
        } else if(choice == 3) {
            printf("You seek answers about health...\n");
        } else if(choice == 4) {
            printf("You seek answers about happiness...\n");
        } else {
            printf("You seek answers about other things...\n");
        }

        int fortuneIndex = rand() % MAX_FORTUNE;
        FORTUNE* currentFortune = &fortunes[fortuneIndex];

        printf("\n%s\n", currentFortune->text);
        printf("Your fortune is %d characters long.\n", currentFortune->length);

        char response[80];
        printf("\nDo you want another fortune? (y/n): ");
        scanf("%s", response);

        if(response[0]!= 'y') {
            break;
        }
    }

    return 0;
}