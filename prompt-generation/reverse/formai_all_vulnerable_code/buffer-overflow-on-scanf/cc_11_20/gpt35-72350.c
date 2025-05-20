//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    char name[20];
    printf("Welcome to Sherlock Holmes' automated fortune teller. What is your name?\n");
    scanf("%s", name);
    printf("Hello, %s. Ask your question and I will predict your future.\n", name);

    // generate a random number for our prediction
    int prediction = rand() % 10 + 1;

    switch (prediction) {
        case 1:
            printf("I see a long and prosperous life ahead of you, %s. Your fortune is bright.\n", name);
            break;
        case 2:
            printf("Danger is lurking around the corner, %s. Be cautious and tread lightly.\n", name);
            break;
        case 3:
            printf("Your heart's desire will soon come true, %s. Keep your eyes peeled for signs.\n", name);
            break;
        case 4:
            printf("A long lost friend or family member will soon reappear in your life, %s. Embrace the reunion.\n", name);
            break;
        case 5:
            printf("Beware of deceitful strangers, %s. Not everyone has your best interests at heart.\n", name);
            break;
        case 6:
            printf("Your luck will turn around soon, %s. The universe has a way of balancing things out.\n", name);
            break;
        case 7:
            printf("A journey is in your near future, %s. Adventure awaits.\n", name);
            break;
        case 8:
            printf("Be mindful of your health, %s. Your body is precious and deserves care.\n", name);
            break;
        case 9:
            printf("Love is in the air, %s. You will soon meet someone who will sweep you off your feet.\n", name);
            break;
        case 10:
            printf("Financial success is in your future, %s. Keep working hard and wise investments will pay off.\n", name);
            break;
        default:
            printf("Hmm, I seem to have misplaced my crystal ball. Try again later, %s.\n", name);
            break;
    }

    return 0;
}