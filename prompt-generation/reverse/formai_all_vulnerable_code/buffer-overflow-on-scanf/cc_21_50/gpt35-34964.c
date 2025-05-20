//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[50];
    int age;
    int number;
    char answer;
    
    printf("Welcome to the Automated Fortune Teller.\n");
    printf("What is your name?\n");
    scanf("%s", &name);
    printf("Nice to meet you, %s. How old are you?\n", name);
    scanf("%d", &age);
    printf("Thank you, %s. Let's begin.\n", name);
    
    srand(time(0)); // Generate random number every time
    number = rand() % 10 + 1; // Random number between 1 and 10
    
    printf("Think of a yes or no question and press enter to reveal your fate.\n");
    while(getchar() != '\n');
    
    switch(number) {
        case 1:
            printf("It is certain.\n");
            break;
        case 2:
            printf("It is decidedly so.\n");
            break;
        case 3:
            printf("Without a doubt.\n");
            break;
        case 4:
            printf("Yes - definitely.\n");
            break;
        case 5:
            printf("You may rely on it.\n");
            break;
        case 6:
            printf("As I see it, yes.\n");
            break;
        case 7:
            printf("Most likely.\n");
            break;
        case 8:
            printf("Outlook good.\n");
            break;
        case 9:
            printf("Yes.\n");
            break;
        case 10:
            printf("Signs point to yes.\n");
            break;
    }
    
    printf("Would you like another question? (Y/N)\n");
    scanf(" %c", &answer);
    while(answer == 'Y' || answer == 'y') {
        number = rand() % 10 + 1;
        printf("Think of a question and press enter.\n");
        while(getchar() != '\n');
        switch(number) {
            case 1:
                printf("Reply hazy, try again.\n");
                break;
            case 2:
                printf("Ask again later.\n");
                break;
            case 3:
                printf("Better not tell you now.\n");
                break;
            case 4:
                printf("Cannot predict now.\n");
                break;
            case 5:
                printf("Concentrate and ask again.\n");
                break;
            case 6:
                printf("Don't count on it.\n");
                break;
            case 7:
                printf("Outlook not so good.\n");
                break;
            case 8:
                printf("My sources say no.\n");
                break;
            case 9:
                printf("Very doubtful.\n");
                break;
            case 10:
                printf("My reply is no.\n");
                break;
        }
        printf("Would you like another question? (Y/N)\n");
        scanf(" %c", &answer);
    }
    
    printf("Thank you for playing, %s. Goodbye!\n", name);
    
    return 0;
}