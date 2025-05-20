//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    char name[100];
    int age;
    char question[100];

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("What is your name?\n");
    fgets(name, sizeof(name), stdin);

    printf("Nice to meet you, %s!\n", name);

    printf("How old are you?\n");
    scanf("%d", &age);
    getchar();

    printf("Okay, let's get started! What's your burning question?\n");
    fgets(question, sizeof(question), stdin);

    printf("\n\nConsulting the spirits...\n\n");

    int random_num = rand() % 10 + 1; // generate random number between 1 and 10

    switch(random_num)
    {
        case 1:
            printf("%s, the answer to your question is yes.\n", name);
            break;

        case 2:
            printf("%s, the answer to your question is no.\n", name);
            break;

        case 3:
            printf("%s, the spirits are telling me that the future is murky and uncertain - try asking again later.\n", name);
            break;

        case 4:
            printf("%s, the answer to your question is definitely yes!\n", name);
            break;

        case 5:
            printf("%s, the spirits are telling me that it's best not to know the answer to that question.\n", name);
            break;

        case 6:
            printf("%s, the answer to your question is maybe.\n", name);
            break;

        case 7:
            printf("%s, the spirits are warning you to be careful - the answer to your question is not what it seems.\n", name);
            break;

        case 8:
            printf("%s, the answer to your question is most likely yes.\n", name);
            break;

        case 9:
            printf("%s, the spirits are telling me that the answer to your question is hidden - keep searching!\n", name);
            break;

        case 10:
            printf("%s, the answer to your question is no, but don't worry - something better is coming your way!\n", name);
            break;
    }

    printf("\nThanks for playing, %s! We hope you have a great day.\n", name);
    return 0;
}