//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];
    char fortune[200];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL));
    int random = rand() % 10;

    switch(random) {
        case 0:
            strcpy(fortune, "You will soon receive good news.");
            break;
        case 1:
            strcpy(fortune, "A new opportunity is coming your way.");
            break;
        case 2:
            strcpy(fortune, "You will find success in your current endeavors.");
            break;
        case 3:
            strcpy(fortune, "Love is in the air for you.");
            break;
        case 4:
            strcpy(fortune, "Financial stability is in your future.");
            break;
        case 5:
            strcpy(fortune, "You will experience a period of personal growth.");
            break;
        case 6:
            strcpy(fortune, "Your hard work will pay off soon.");
            break;
        case 7:
            strcpy(fortune, "A friend will offer you valuable advice.");
            break;
        case 8:
            strcpy(fortune, "You will overcome a challenge and come out stronger.");
            break;
        case 9:
            strcpy(fortune, "An unexpected gift is coming your way.");
            break;
        default:
            strcpy(fortune, "The future is uncertain.");
            break;
    }

    printf("\n%s, your fortune is:\n%s", name, fortune);

    return 0;
}