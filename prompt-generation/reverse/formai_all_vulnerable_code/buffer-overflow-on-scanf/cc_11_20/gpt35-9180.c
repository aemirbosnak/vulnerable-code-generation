//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("This program will give you a unique fortune based on your input.\n\n");

    char name[30];
    int age;

    printf("What's your name? ");
    scanf("%s", &name);

    printf("Nice to meet you, %s! How old are you? ", name);
    scanf("%d", &age);

    if(age < 18){
        printf("Sorry, you must be at least 18 years old to receive a fortune from this program.");
        return 0;
    }

    printf("\nGreat! Now that we know a little about you, let's begin.\n");
    printf("Ask me a question and I will tell you your fortune!\n");

    char question[100];
    scanf("%s", &question);

    int rand_num = rand() % 10;

    switch(rand_num) {
        case 0:
            printf("\nHmm... I sense that %s.\n", question);
            printf("Your fortune is:\n");
            printf("You will find success in your career, but beware of those who will try to bring you down.\n");
            break;
        case 1:
            printf("\nInteresting question. I sense that %s.\n", question);
            printf("Your fortune is:\n");
            printf("You will meet the love of your life soon, but beware of jealousy in your relationships.\n");
            break;
        case 2:
            printf("\nI sense that you're feeling unsure about %s.\n", question);
            printf("Your fortune is:\n");
            printf("You will face a difficult decision soon, but trust your instincts and everything will work out.\n");
            break;
        case 3:
            printf("\nI see that %s is weighing heavy on your mind.\n", question);
            printf("Your fortune is:\n");
            printf("You will have a long and happy life, but be cautious of risky decisions.\n");
            break;
        case 4:
            printf("\nAh, %s... I see that you may be feeling lost.\n", question);
            printf("Your fortune is:\n");
            printf("You will soon discover your true purpose in life and achieve great things.\n");
            break;
        case 5:
            printf("\nI sense that %s is causing you great stress.\n", question);
            printf("Your fortune is:\n");
            printf("You must confront your fears and overcome them, and you will find great success.\n");
            break;
        case 6:
            printf("\nI sense a great deal of uncertainty surrounding %s.\n", question);
            printf("Your fortune is:\n");
            printf("You will find great peace and happiness in the simple things in life.\n");
            break;
        case 7:
            printf("\nI sense that you may be feeling trapped by %s.\n", question);
            printf("Your fortune is:\n");
            printf("You will break free from your constraints and reach new heights.\n");
            break;
        case 8:
            printf("\nI sense that you may be experiencing some insecurity about %s.\n", question);
            printf("Your fortune is:\n");
            printf("You will overcome your insecurities and find true confidence within yourself.\n");
            break;
        case 9:
            printf("\nI sense that %s is a source of great passion for you.\n", question);
            printf("Your fortune is:\n");
            printf("You will pursue your greatest passions and achieve great success in your endeavors.\n");
            break;
    }

    return 0;
}