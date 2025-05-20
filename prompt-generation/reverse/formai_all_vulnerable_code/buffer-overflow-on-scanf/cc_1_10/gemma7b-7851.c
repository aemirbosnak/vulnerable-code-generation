//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ANSWERS 5

int main()
{
    char name[20];
    int age;
    char sign[20];
    int num;
    char answer[MAX_ANSWERS];

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your sun sign: ");
    scanf("%s", sign);

    srand(time(NULL));
    num = rand() % MAX_ANSWERS;

    switch (num)
    {
        case 0:
            answer[0] = 'A';
            answer[1] = 'B';
            answer[2] = 'C';
            break;
        case 1:
            answer[0] = 'D';
            answer[1] = 'E';
            answer[2] = 'F';
            break;
        case 2:
            answer[0] = 'G';
            answer[1] = 'H';
            answer[2] = 'I';
            break;
        case 3:
            answer[0] = 'J';
            answer[1] = 'K';
            answer[2] = 'L';
            break;
        case 4:
            answer[0] = 'M';
            answer[1] = 'N';
            answer[2] = 'O';
            break;
    }

    printf("Your fortune is: ");
    for (int i = 0; answer[i] != '\0'; i++)
    {
        printf("%c ", answer[i]);
    }

    printf("\n");

    return 0;
}