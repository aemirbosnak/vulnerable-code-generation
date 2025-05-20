//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age;
    time_t t;
    srand(time(NULL));

    printf("Welcome, my dear visitor. Would you like me to reveal your fortune?\n");
    scanf("%s", name);

    printf("Ah, %s, your name holds secrets. May I ask you how old you are?\n", name);
    scanf("%d", &age);

    t = time(NULL);
    int num = rand() % 10;

    switch (num)
    {
        case 0:
            printf("Your stars dance with the moon, bringing prosperity and love.\n");
            break;
        case 1:
            printf("Beware, my dear %s, fate has a cruel hand for you today.\n", name);
            break;
        case 2:
            printf("Your future is bright, filled with happiness and success.\n");
            break;
        case 3:
            printf("Love is in the air, my dear %s. Prepare for a whirlwind romance.\n", name);
            break;
        case 4:
            printf("May your wealth grow like the tides, my dear %s.\n", name);
            break;
        case 5:
            printf("A journey awaits you, my dear %s. Prepare for adventure.\n", name);
            break;
        case 6:
            printf("Your wisdom will guide you through troubled times, %s.\n", name);
            break;
        case 7:
            printf("A new beginning is yours, %s. Let go of the past.\n", name);
            break;
        case 8:
            printf("Beware of hidden enemies, my dear %s. They may try to bring you down.\n", name);
            break;
        case 9:
            printf("Your spirit guides you, my dear %s. Trust in your intuition.\n", name);
            break;
    }

    printf("May your fortune be ever bright, %s. Thank you for visiting me.\n", name);

    return 0;
}