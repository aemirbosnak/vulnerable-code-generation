//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void predictFortune(int num);

int main() {
    char name[MAX];
    int fortuneNum;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL));
    fortuneNum = rand() % 10 + 1;

    printf("\nHello %s, your fortune number is: %d\n", name, fortuneNum);
    predictFortune(fortuneNum);

    return 0;
}

void predictFortune(int num) {
    switch (num) {
        case 1:
            printf("\nYour future holds new beginnings and opportunities.\n");
            break;
        case 2:
            printf("\nYou will experience happiness and joy in your life.\n");
            break;
        case 3:
            printf("\nPrepare for a period of growth and expansion.\n");
            break;
        case 4:
            printf("\nYour creativity and artistic abilities will shine.\n");
            break;
        case 5:
            printf("\nYou will encounter challenges, but you will overcome them.\n");
            break;
        case 6:
            printf("\nLove and romance are in your future.\n");
            break;
        case 7:
            printf("\nYou will be blessed with good luck and prosperity.\n");
            break;
        case 8:
            printf("\nYour intelligence and wisdom will lead you to success.\n");
            break;
        case 9:
            printf("\nYou will make important discoveries and gain new insights.\n");
            break;
        case 10:
            printf("\nYour future is filled with surprises and excitement.\n");
            break;
        default:
            printf("\nSorry, an error occurred.\n");
    }
}