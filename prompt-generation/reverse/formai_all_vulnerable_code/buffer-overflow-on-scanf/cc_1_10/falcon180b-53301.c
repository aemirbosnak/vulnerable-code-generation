//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_LENGHT 80

typedef struct {
    char text[MAX_LENGHT];
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will find true love within the next year"},
    {"A great opportunity is coming your way"},
    {"You will have a successful career"},
    {"You will travel to an exotic location soon"},
    {"Your financial situation will improve"},
    {"You will overcome a challenge and come out stronger"},
    {"You will make a new friend who will have a positive influence on your life"},
    {"You will receive unexpected good news"},
    {"You will have a breakthrough in your personal growth"},
    {"You will experience a moment of pure happiness"}
};

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_LENGHT];

    printf("Welcome to the Automated Fortune Teller\n");

    while(1) {
        printf("\n");
        printf("Please enter your name: ");
        scanf("%s", input);

        if(strcmp(input, "exit") == 0) {
            break;
        }

        printf("\n");
        printf("Hello %s, what would you like to know about your future?\n", input);
        printf("1. Love\n");
        printf("2. Career\n");
        printf("3. Travel\n");
        printf("4. Finance\n");
        printf("5. Personal Growth\n");
        printf("6. General\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n");
                printf("In matters of love, your future holds...\n");
                printf("%s\n", fortunes[rand() % MAX_FORTUNES].text);
                break;
            case 2:
                printf("\n");
                printf("In your career, your future holds...\n");
                printf("%s\n", fortunes[rand() % MAX_FORTUNES].text);
                break;
            case 3:
                printf("\n");
                printf("In terms of travel, your future holds...\n");
                printf("%s\n", fortunes[rand() % MAX_FORTUNES].text);
                break;
            case 4:
                printf("\n");
                printf("In terms of finance, your future holds...\n");
                printf("%s\n", fortunes[rand() % MAX_FORTUNES].text);
                break;
            case 5:
                printf("\n");
                printf("In terms of personal growth, your future holds...\n");
                printf("%s\n", fortunes[rand() % MAX_FORTUNES].text);
                break;
            case 6:
                printf("\n");
                printf("Your general fortune is...\n");
                printf("%s\n", fortunes[rand() % MAX_FORTUNES].text);
                break;
            default:
                printf("\n");
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}