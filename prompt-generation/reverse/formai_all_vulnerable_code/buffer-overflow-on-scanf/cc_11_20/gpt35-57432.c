//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age;
    char question[100];

    printf("Hello there! What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! How old are you?\n", name);
    scanf("%d", &age);
    printf("Very interesting! Now, what is your burning question?\n");
    scanf("%s", question);

    printf("\n");
    printf("Let's see what the future holds for you, %s...\n", name);
    printf(".\n.\n.\n");

    srand(time(0));
    int randomNumber = rand() % 10 + 1;
    if(randomNumber == 1) {
        printf("It is certain.\n");
    }
    else if(randomNumber == 2) {
        printf("Without a doubt.\n");
    }
    else if(randomNumber == 3) {
        printf("Yes, definitely.\n");
    }
    else if(randomNumber == 4) {
        printf("You may rely on it.\n");
    }
    else if(randomNumber == 5) {
        printf("As I see it, yes.\n");
    }
    else if(randomNumber == 6) {
        printf("Most likely.\n");
    }
    else if(randomNumber == 7) {
        printf("Outlook good.\n");
    }
    else if(randomNumber == 8) {
        printf("Yes.\n");
    }
    else if(randomNumber == 9) {
        printf("Signs point to yes.\n");
    }
    else if(randomNumber == 10) {
        printf("Reply hazy, try again.\n");
    }

    printf("\nThank you for using our automated fortune teller, %s! We hope to see you again soon!\n", name);

    return 0;
}