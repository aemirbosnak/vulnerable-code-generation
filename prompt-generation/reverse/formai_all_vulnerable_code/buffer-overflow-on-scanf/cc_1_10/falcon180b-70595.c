//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int fortune = rand() % 10 + 1;
    char fortunes[10][100] = {
        "Your future is bright and full of promise. ",
        "You will find love and happiness in unexpected places. ",
        "A great opportunity will come your way soon. ",
        "You will experience a period of great success and prosperity. ",
        "Your hard work will pay off and bring you great rewards. ",
        "You will overcome any obstacles and achieve your goals. ",
        "A new adventure awaits you, embrace it with open arms. ",
        "You will receive unexpected news that will change your life. ",
        "Your creativity and imagination will take you far. ",
        "You will find peace and contentment in the simple things in life."
    };

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");
    char name[30];
    scanf("%s", name);

    printf("Greetings, %s! I am the Automated Fortune Teller.\n", name);
    printf("I will tell you your future, but first, let's get to know each other.\n");

    printf("What is your favorite color?\n");
    char color[30];
    scanf("%s", color);

    printf("Your favorite color is %s? That's interesting.\n", color);

    printf("What is your favorite food?\n");
    char food[30];
    scanf("%s", food);

    printf("You like to eat %s? That's quite unique.\n", food);

    printf("What is your favorite hobby?\n");
    char hobby[30];
    scanf("%s", hobby);

    printf("You enjoy %s as a hobby? That's fascinating.\n", hobby);

    printf("Now, let's see what the future holds for you.\n");
    printf("Your fortune is: %s\n", fortunes[fortune]);

    return 0;
}