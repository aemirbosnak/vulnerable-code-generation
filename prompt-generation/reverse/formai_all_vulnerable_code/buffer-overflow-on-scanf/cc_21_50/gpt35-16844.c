//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char userName[20];
    int userAge;
    char userQuestion[100];
    char answer;
    srand(time(NULL));
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");
    scanf("%s", userName);
    
    printf("What is your age?\n");
    scanf("%d", &userAge);
    
    if (userAge < 18) {
        printf("I'm sorry %s, but you must be at least 18 years old to use this program.\n", userName);
        return 0;
    }
    
    printf("Hello, %s! What question do you want me to answer? (Enter your question)\n", userName);
    scanf("%s", userQuestion);
    
    printf("You asked: %s\n", userQuestion);
    printf("Thinking...\n");
    
    switch (rand() % 20 + 1) {
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
        case 11:
            printf("Reply hazy, try again.\n");
            break;
        case 12:
            printf("Ask again later.\n");
            break;
        case 13:
            printf("Better not tell you now.\n");
            break;
        case 14:
            printf("Cannot predict now.\n");
            break;
        case 15:
            printf("Concentrate and ask again.\n");
            break;
        case 16:
            printf("Don't count on it.\n");
            break;
        case 17:
            printf("Outlook not so good.\n");
            break;
        case 18:
            printf("My sources say no.\n");
            break;
        case 19:
            printf("Very doubtful.\n");
            break;
        case 20:
            printf("Chances aren't good.\n");
            break;
    }
    
    return 0;
}