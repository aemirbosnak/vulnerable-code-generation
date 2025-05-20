//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); //seeding random number generator with current time

    int option, prediction; //declaring variables to store menu option and fortune prediction

    printf("Welcome to the Automated Fortune Teller!\n\n");

    do
    {
        printf("Choose an option:\n");
        printf("1. Ask a question\n");
        printf("2. Shake the magic 8 ball\n");
        printf("3. Exit\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter your question: ");
                getchar(); //clearing input buffer
                char question[100];
                fgets(question, sizeof(question), stdin);
                printf("\nThinking...\n\n");
                prediction = rand() % 5; //generating random number between 0-4
                switch(prediction)
                {
                    case 0:
                        printf("It is certain.\n");
                        break;
                    case 1:
                        printf("Without a doubt.\n");
                        break;
                    case 2:
                        printf("Reply hazy, try again.\n");
                        break;
                    case 3:
                        printf("Don't count on it.\n");
                        break;
                    case 4:
                        printf("Outlook not so good.\n");
                        break;
                }
                break;
            case 2:
                printf("\nShaking the magic 8 ball...\n\n");
                prediction = rand() % 20 + 1; //generating random number between 1-20
                switch(prediction)
                {
                    case 1:
                        printf("It is certain.\n");
                        break;
                    case 2:
                        printf("Without a doubt.\n");
                        break;
                    case 3:
                        printf("You may rely on it.\n");
                        break;
                    case 4:
                        printf("Yes, definitely.\n");
                        break;
                    case 5:
                        printf("It is decidedly so.\n");
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
                        printf("Signs point to yes.\n");
                        break;
                    case 10:
                        printf("Ask again later.\n");
                        break;
                    case 11:
                        printf("Better not tell you now.\n");
                        break;
                    case 12:
                        printf("Cannot predict now.\n");
                        break;
                    case 13:
                        printf("Concentrate and ask again.\n");
                        break;
                    case 14:
                        printf("My reply is no.\n");
                        break;
                    case 15:
                        printf("My sources say no.\n");
                        break;
                    case 16:
                        printf("Outlook not so good.\n");
                        break;
                    case 17:
                        printf("Very doubtful.\n");
                        break;
                    case 18:
                        printf("Don't count on it.\n");
                        break;
                    case 19:
                        printf("Signs point to yes.\n");
                        break;
                    case 20:
                        printf("Yes.\n");
                        break;
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }

    }while(option != 3);

    return 0;
}