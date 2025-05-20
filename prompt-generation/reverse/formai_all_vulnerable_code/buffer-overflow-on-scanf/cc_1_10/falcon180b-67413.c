//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void intro();
void getName();
void generateFortune();

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    intro();
    getName();
    generateFortune();
    return 0;
}

void intro() {
    printf("\n\n");
    printf("  _____ _   _ ___ ___ \n");
    printf(" |_   _| | | | __/ __| \n");
    printf("   | | | |_| | |_\__ \\ \n");
    printf("   |_|  \\__, | |___|___/ \n");
    printf("         |___/         \n");
    printf("\n");
    printf("Welcome to the Post-Apocalyptic Fortune Teller!\n");
    printf("We'll tell you your fortune... or what's left of it.\n");
    printf("\n");
}

void getName() {
    char name[20];
    printf("What's your name? ");
    scanf("%s", name);
    printf("\n\n");
    printf("Greetings, %s. We have been expecting you...\n", name);
    printf("\n");
}

void generateFortune() {
    int fortuneNum = rand() % 10;
    switch(fortuneNum) {
        case 0:
            printf("Your future is bleak and full of despair.\n");
            break;
        case 1:
            printf("You will find love in the most unexpected place.\n");
            break;
        case 2:
            printf("Wealth and prosperity are within your reach.\n");
            break;
        case 3:
            printf("A great adventure awaits you.\n");
            break;
        case 4:
            printf("Beware of those who seek to do you harm.\n");
            break;
        case 5:
            printf("You will overcome great obstacles and emerge victorious.\n");
            break;
        case 6:
            printf("A long-lost friend will return to your life.\n");
            break;
        case 7:
            printf("Your dreams will soon become a reality.\n");
            break;
        case 8:
            printf("You will experience great loss, but will find strength in adversity.\n");
            break;
        case 9:
            printf("A new opportunity will present itself to you.\n");
            break;
        default:
            printf("The spirits are confused... your fortune is uncertain.\n");
            break;
    }
}