//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROMANCE 100

void start() {
    int romantic_level = 50;
    int action;

    while (1) {
        printf("What romantic action would you like to take?\n");
        printf("1. Write a love letter\n");
        printf("2. Take a romantic walk\n");
        printf("3. Surprise your partner with a gift\n");
        printf("4. Plan a romantic dinner\n");
        printf("5. Leave a love note\n");

        scanf("%d", &action);

        switch (action) {
            case 1:
                romantic_level += 10;
                printf("You wrote a love letter and increased your romance level by 10 points!\n");
                break;
            case 2:
                romantic_level += 5;
                printf("You took a romantic walk and increased your romance level by 5 points!\n");
                break;
            case 3:
                romantic_level += 15;
                printf("You surprised your partner with a gift and increased your romance level by 15 points!\n");
                break;
            case 4:
                romantic_level += 20;
                printf("You planned a romantic dinner and increased your romance level by 20 points!\n");
                break;
            case 5:
                romantic_level += 10;
                printf("You left a love note and increased your romance level by 10 points!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }

        printf("Your current romance level is %d.\n", romantic_level);

        sleep(1);
    }
}

int main() {
    start();

    return 0;
}