//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fortune Teller Function
void fortuneTeller(int num, char* name) {
    srand(time(NULL));
    int randomNum = rand() % num;
    printf("Your fortune for today is: ");
    switch(randomNum) {
        case 0:
            printf("You will have a lucky day!\n");
            break;
        case 1:
            printf("You will meet someone special today.\n");
            break;
        case 2:
            printf("You will receive good news today.\n");
            break;
        case 3:
            printf("You will have a productive day at work.\n");
            break;
        case 4:
            printf("You will have a peaceful day.\n");
            break;
        case 5:
            printf("You will have a surprise encounter today.\n");
            break;
        case 6:
            printf("You will experience a small setback today.\n");
            break;
        case 7:
            printf("You will have a challenging day.\n");
            break;
        case 8:
            printf("You will have an opportunity to learn something new.\n");
            break;
        case 9:
            printf("You will have a day full of creativity.\n");
            break;
        default:
            printf("Sorry, no fortune for you today.\n");
    }
}

int main() {
    int choice;
    char name[50];

    // Welcome Message
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    // Menu
    printf("\nPlease choose a fortune teller:\n");
    printf("1. Crystal Ball\n");
    printf("2. Tarot Cards\n");
    printf("3. Palm Reading\n");
    scanf("%d", &choice);

    // Fortune Telling
    switch(choice) {
        case 1:
            printf("\nThe crystal ball says:\n");
            fortuneTeller(10, name);
            break;
        case 2:
            printf("\nThe tarot cards say:\n");
            fortuneTeller(8, name);
            break;
        case 3:
            printf("\nThe palm reading says:\n");
            fortuneTeller(6, name);
            break;
        default:
            printf("Invalid choice, please try again.\n");
    }

    return 0;
}