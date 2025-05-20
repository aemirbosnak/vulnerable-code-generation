//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNE 50
#define MAX_LINE 80
#define NUM_FORTUNES 10

typedef struct {
    char text[MAX_LINE];
    int num;
} Fortune;

Fortune fortunes[NUM_FORTUNES];

void initFortunes() {
    int i;
    for(i = 0; i < NUM_FORTUNES; i++) {
        fortunes[i].num = rand() % NUM_FORTUNES;
    }
}

void printFortune(int num) {
    printf("Your fortune is:\n%s\n", fortunes[num].text);
}

int main() {
    int choice;
    char input[MAX_LINE];
    srand(time(NULL));
    initFortunes();
    do {
        printf("Welcome to the Automated Fortune Teller\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Please enter your name:\n");
                scanf("%s", input);
                printf("Hello, %s. Here is your fortune:\n", input);
                printFortune(fortunes[0].num);
                break;
            case 2:
                printf("Thank you for using the Automated Fortune Teller. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(choice!= 2);
    return 0;
}