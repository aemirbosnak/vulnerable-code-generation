//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: introspective
#include <stdio.h>

int main() {
    char name[20];
    int age;
    char response;
    int score = 0;

    printf("Welcome to the Introspective Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! How old are you?\n", name);
    scanf("%d", &age);

    printf("You find yourself in a dark room with two doors. One leads to the left and the other to the right.\n");
    printf("Which door do you choose? L or R?\n");
    scanf("\n%c", &response);

    if (response == 'L') {
        printf("You chose left. The door opens and you see a mirror.\n");
        printf("You look at yourself in the mirror and contemplate your life choices.\n");
        printf("Do you feel regret about anything in your life? Y or N?\n");
        scanf("\n%c", &response);
        if (response == 'Y') {
            printf("Reflecting on your past is important, but don't let it consume you.\n");
            score += 5;
        }
        else {
            printf("Good, focus on the present and future.\n");
            score += 10;
        }
    }
    else if (response == 'R') {
        printf("You chose right. The door opens and you see a staircase leading down.\n");
        printf("Do you feel adventurous? Y or N?\n");
        scanf("\n%c", &response);
        if (response == 'Y') {
            printf("You descend down the staircase, feeling the thrill of the unknown.\n");
            printf("At the bottom you find a treasure chest. Do you open it? Y or N?\n");
            scanf("\n%c", &response);
            if (response == 'Y') {
                printf("You open the chest and find a wealth of gold and jewels.\n");
                score += 20;
            }
            else {
                printf("You leave the chest alone, but feel a twinge of regret as you ascend back up the staircase.\n");
                score += 5;
            }
        }
        else {
            printf("You decide not to take any risks and head back the way you came.\n");
            score += 10;
        }
    }
    printf("Your adventure is over, %s. Your final score is %d. Thanks for playing!\n", name, score);

    return 0;
}