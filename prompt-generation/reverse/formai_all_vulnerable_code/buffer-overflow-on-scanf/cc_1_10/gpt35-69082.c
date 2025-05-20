//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main() {
    char name[20];
    int age;
    int luckyNum;
    char answer[50];
    time_t t;
    srand((unsigned) time(&t));
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I am your personal fortune teller, and I will be asking you a series of questions to predict your future.\n");

    printf("What is your name?\n");
    scanf("%s", name);

    printf("How old are you %s?\n", name);
    scanf("%d", &age);

    printf("Lastly, what is your lucky number?\n");
    scanf("%d", &luckyNum);

    printf("Thank you for answering my questions, %s.\n", name);
    printf("Now, let me consult the spirits to see your future...\n");

    //delay for dramatic effect
    for(int i = 0; i < 3; i++) {
        printf(". ");
        fflush(stdout);
        sleep(1);
    }

    printf("The spirits have spoken, and your future is clear.\n");

    //randomly generate fortune
    int fortuneNum = rand() % 5;
    char fortune[5][50] = {"You will find true love in the near future.\n", 
                            "A great opportunity will come your way, do not pass it up.\n",
                            "Stay away from dangerous activities, they will only cause trouble.\n",
                            "Your hard work will pay off, and success is in your near future.\n",
                            "Watch out for unexpected obstacles, they may slow you down.\n"};
    printf("Your fortune is: %s", fortune[fortuneNum]);

    printf("Would you like to know more about your fortune? (yes or no)\n");
    scanf("%s", answer);

    if(strcmp(answer, "yes") == 0) {
        printf("The spirits have given me more insight into your fortune.\n");
        printf("Your lucky number, %d, will play an important role in your future.\n", luckyNum);
        printf("Additionally, you will face many challenges in life, but with persistence and determination, you will overcome them.\n");
        printf("Lastly, remember that love and family are the most important things in life, cherish them always.\n");
    } else {
        printf("Thank you for using the Automated Fortune Teller. Best of luck to you, %s!\n", name);
    }

    return 0;
}