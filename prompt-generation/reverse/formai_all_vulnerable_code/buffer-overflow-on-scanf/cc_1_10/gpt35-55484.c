//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char name[20];
    char answer;
    printf("Welcome to the Automated Fortune Teller program! \n");
    printf("What is your name? \n");
    scanf("%s", &name);
    printf("Hello, %s! Are you excited to know your fortune? (y/n) \n", name);
    scanf(" %c", &answer);
    if (answer == 'y') {
        printf("Great, let's get started! \n");
        printf("I am going to tell you your love fortune for the next three weeks. \n");
        printf("Are you ready? (y/n) \n");
        scanf(" %c", &answer);
        if (answer == 'y') {
            // generate random fortune
            int fortune = rand() % 4;
            if (fortune == 0) {
                printf("During the first week, you will meet someone special who will steal your heart. \n");
                printf("Be open to love and enjoy the moment. \n");
                printf("During week two, you may face some challenges in your relationship. \n");
                printf("Stay true to your feelings and communicate openly with your partner. \n");
                printf("By week three, your relationship will have deepened and you will feel a strong connection with your partner. \n");
                printf("Embrace the love and cherish every moment. \n");
            }
            else if (fortune == 1) {
                printf("During the first week, you may find yourself drawn to someone unexpectedly. \n");
                printf("Follow your heart and don't be afraid to take risks. \n");
                printf("During week two, you may face some uncertainty in your relationship. \n");
                printf("Trust in your feelings and have faith that everything will work out. \n");
                printf("By week three, you will have clarity and feel more confident in your relationship. \n");
                printf("Stay true to yourself and your partner. \n");
            }
            else if (fortune == 2) {
                printf("During the first week, you may have some doubts about your current relationship. \n");
                printf("Take some time to reflect and figure out what you really want. \n");
                printf("During week two, you may realize that you need to have a difficult conversation with your partner. \n");
                printf("Be brave and honest with both yourself and your partner. \n");
                printf("By week three, you will have gone through some ups and downs, but will emerge stronger than ever. \n");
                printf("Trust in your love and keep working towards a brighter future. \n");
            }
            else if (fortune == 3) {
                printf("During the first week, you may encounter some obstacles in your love life. \n");
                printf("Don't let them discourage you and stay true to your feelings. \n");
                printf("During week two, you may need to show some extra care and attention to your partner. \n");
                printf("Small gestures can go a long way in strengthening your relationship. \n");
                printf("By week three, you will feel more emotionally connected with your partner than ever before. \n");
                printf("Continue to love fiercely and your relationship will thrive. \n");
            }
        }
        else {
            printf("That's ok, come back later when you are ready. Goodbye! \n");
        }
    }
    else {
        printf("That's ok, come back later when you are feeling more adventurous. Goodbye! \n");
    }
    return 0;
}