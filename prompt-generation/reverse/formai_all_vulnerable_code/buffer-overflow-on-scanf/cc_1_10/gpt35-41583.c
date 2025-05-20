//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void intro();
void chapterOne();
void chapterTwo();
void chapterThree();
void ending();

// main function
int main()
{
    // display intro
    intro();

    // start chapter one
    chapterOne();

    // start chapter two
    chapterTwo();

    // start chapter three
    chapterThree();

    // display ending
    ending();

    return 0;
}

// function to display introduction
void intro()
{
    printf("\n\nWelcome to Romance Island\n\n");
    printf("You are a traveler on a quest to find true love. You have heard of a magical place called Romance Island where love is in the air and anything is possible.\n\n");

    printf("Press enter to continue...\n");
    getchar(); // wait for user to press enter
}

// function for chapter one
void chapterOne()
{
    char answer[20];

    printf("\n\nChapter One - Love at First Sight\n\n");
    printf("As you approach the island, you see a beautiful woman standing on the shore. She catches your eye and you feel a spark of attraction. You walk up to her and introduce yourself.\n\n");

    printf("\"What's your name?\" you ask.\n");
    scanf("%s", answer);

    printf("\"My name is %s,\" she replies. \"What brings you to Romance Island?\"\n", answer);
    printf("Do you tell her the truth or lie?\n");
    printf("1. Tell her the truth\n");
    printf("2. Lie\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\"I'm here to find true love,\" you say. \"What about you?\"\n");
            printf("\"I'm just visiting the island,\" she says, smiling. \"But perhaps I'll find some romance of my own while I'm here.\"\n");
            break;

        case 2:
            printf("\"Oh, just sightseeing,\" you say. \"What about you?\"\n");
            printf("\"Same here,\" she says, giggling. \"But I wouldn't mind a little romance while I'm here.\"\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            chapterOne();
    }

    printf("Press enter to continue...\n");
    getchar();
}

// function for chapter two
void chapterTwo()
{
    char answer[20];

    printf("\n\nChapter Two - A Romantic Walk on the Beach\n\n");
    printf("You and the woman from the shore take a romantic walk on the beach. The sun is setting and the sky is full of beautiful colors. You feel a connection with her and decide to ask her out on a date.\n\n");

    printf("\"Would you like to go out with me tonight?\" you ask.\n");
    printf("1. Yes\n");
    printf("2. No\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\"Yes, I would love to,\" she says, smiling. \"Where do you want to go?\"\n");
            printf("Do you suggest a romantic dinner or a fun activity?\n");
            printf("1. Romantic dinner\n");
            printf("2. Fun activity\n");

            int choice2;
            scanf("%d", &choice2);

            switch (choice2)
            {
                case 1:
                    printf("\"How about a romantic dinner at the island's fanciest restaurant?\" you suggest.\n");
                    printf("\"That sounds great,\" she says, blushing. \"I'll meet you there at 8pm.\"\n");
                    break;

                case 2:
                    printf("\"How about we go for a fun activity at the amusement park?\" you suggest.\n");
                    printf("\"That sounds like a blast,\" she says, giggling. \"I'll meet you there at 8pm.\"\n");
                    break;

                default:
                    printf("Invalid choice. Please try again.\n");
                    chapterTwo();
            }

            break;

        case 2:
            printf("\"I'm sorry, but I'm not interested,\" she says, frowning. \"Maybe we could just be friends.\"\n");
            printf("Do you accept her offer of friendship or move on?\n");
            printf("1. Accept friendship\n");
            printf("2. Move on\n");

            int choice3;
            scanf("%d", &choice3);

            switch (choice3)
            {
                case 1:
                    printf("\"I would like that,\" you say, smiling. \"Perhaps we could still have dinner as friends?\"\n");
                    printf("\"Of course,\" she says, returning your smile. \"That would be lovely.\"\n");
                    break;

                case 2:
                    printf("\"I understand,\" you say, nodding. \"It was nice meeting you.\"\n");
                    break;

                default:
                    printf("Invalid choice. Please try again.\n");
                    chapterTwo();
            }

            break;

        default:
            printf("Invalid choice. Please try again.\n");
            chapterTwo();
    }

    printf("Press enter to continue...\n");
    getchar();
}

// function for chapter three
void chapterThree()
{
    char answer[20];

    printf("\n\nChapter Three - The Date\n\n");
    printf("You and the woman from the beach have your date. It is a perfect evening and you have a wonderful time together. As it ends, you are left with the decision of whether to kiss her or not.\n\n");

    printf("Do you lean in for a kiss?\n");
    printf("1. Yes\n");
    printf("2. No\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You lean in and kiss her. It is a magical moment and you feel like you have found true love.\n");
            printf("\"I've been waiting for you,\" she says, smiling. \"I think I've found my soulmate.\"\n");
            break;

        case 2:
            printf("You decide not to kiss her. It was a lovely evening, but something is holding you back.\n");
            printf("\"I had a lovely time,\" she says, smiling. \"But I don't think we're meant to be.\"\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            chapterThree();
    }

    printf("Press enter to continue...\n");
    getchar();
}

// function to display ending
void ending()
{
    printf("\n\nCongratulations! You have completed Romance Island and found true love!\n\n");
    printf("Thank you for playing!\n\n");
}