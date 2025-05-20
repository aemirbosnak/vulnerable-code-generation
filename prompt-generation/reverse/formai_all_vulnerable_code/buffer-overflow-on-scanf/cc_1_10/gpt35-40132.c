//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage();
int generateRandomNumber(int lower, int upper);
char* getFortune(int num);
void printFortune(char* fortune);

int main() {
    welcomeMessage();

    int lower = 1, upper = 10, num = 0;
    char* fortune;

    while(num != 7){
        printf("\nEnter a number between 1 and 10 to receive your fortune: ");
        scanf("%d", &num);

        if(num < 1 || num > 10) {
            printf("Invalid input, please enter a number between 1 and 10.\n");
            continue;
        }

        // Generate a random number between 1 and 10 for the fortune
        int randomNum = generateRandomNumber(lower, upper);

        // Get the fortune based on the random number generated
        fortune = getFortune(randomNum);

        // Print the fortune to the user
        printFortune(fortune);
    }

    printf("\nGoodbye!");

    return 0;
}

void welcomeMessage() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter a number between 1 and 10 to receive your fortune.\n");
}

int generateRandomNumber(int lower, int upper) {
    // Seed the random number generator with the current time
    srand(time(NULL));
    return (rand() % (upper - lower + 1)) + lower;
}

char* getFortune(int num) {
    char* fortune;

    switch(num) {
        case 1:
            fortune = "You will receive good news soon!";
            break;
        case 2:
            fortune = "Your future looks bright!";
            break;
        case 3:
            fortune = "Expect a surprise today!";
            break;
        case 4:
            fortune = "Stay focused on your goals!";
            break;
        case 5:
            fortune = "Be prepared for a difficult situation!";
            break;
        case 6:
            fortune = "Look for opportunities to learn something new!";
            break;
        case 7:
            fortune = "Your lucky number is 7!";
            break;
        case 8:
            fortune = "Make time for self-care today!";
            break;
        case 9:
            fortune = "A friend will reach out to you for help!";
            break;
        case 10:
            fortune = "Take some time to appreciate the beauty around you!";
            break;
    }

    return fortune;
}

void printFortune(char* fortune) {
    printf("Your fortune is: %s\n", fortune);
}