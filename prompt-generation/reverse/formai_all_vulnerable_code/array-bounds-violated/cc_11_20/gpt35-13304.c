//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Please enter your name: ");
    char name[50];
    fgets(name, 50, stdin);
    name[strlen(name)-1] = '\0';
    printf("Hello %s, please think of a question and concentrate on it.\n", name);

    printf("Press any key to continue...\n");
    getchar();

    printf("Calculating your fortune...\n");

    int fortune = rand() % 10;
    switch(fortune) {
        case 0:
            printf("The future is uncertain. Your path is yours to make.\n");
            break;
        case 1:
            printf("The apocalypse brought chaos, but you will find order in the end.\n");
            break;
        case 2:
            printf("The darkness lingers, but there is always a light to be found.\n");
            break;
        case 3:
            printf("Danger lurks in every corner, but your intuition will guide you.\n");
            break;
        case 4:
            printf("The world is in shambles, but you will emerge stronger than before.\n");
            break;
        case 5:
            printf("The end of the world also means new beginnings. Embrace the change.\n");
            break;
        case 6:
            printf("The past is gone, but the future holds a better fate.\n");
            break;
        case 7:
            printf("Opportunities may be scarce, but they exist for those who seek them.\n");
            break;
        case 8:
            printf("Your fate is intertwined with others. Trust in your relationships.\n");
            break;
        case 9:
            printf("The end of the world may seem bleak, but there is still hope to be found.\n");
            break;
        default:
            printf("Something went wrong. Please try again.\n");
            break;
    }

    printf("\nThank you for using the Automated Fortune Teller. Good luck on your journey, %s.\n", name);

    return 0;
}