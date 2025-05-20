//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char name[20];
    int age;
    int random_num;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! How old are you?\n", name);
    scanf("%d", &age);

    srand(time(NULL));
    random_num = rand() % 10;

    if (random_num == 0) {
        printf("%s, your fortune for today is:\n", name);
        printf("You will meet someone special today!\n");
    } else if (random_num == 1) {
        printf("%s, your fortune for today is:\n", name);
        printf("You will receive unexpected good news today!\n");
    } else if (random_num == 2) {
        printf("%s, your fortune for today is:\n", name);
        printf("You should trust your gut feeling today!\n");
    } else if (random_num == 3) {
        printf("%s, your fortune for today is:\n", name);
        printf("A change is coming your way!\n");
    } else if (random_num == 4) {
        printf("%s, your fortune for today is:\n", name);
        printf("Your hard work will pay off today!\n");
    } else if (random_num == 5) {
        printf("%s, your fortune for today is:\n", name);
        printf("Spend time with your loved ones today!\n");
    } else if (random_num == 6) {
        printf("%s, your fortune for today is:\n", name);
        printf("You will have a lucky day today!\n");
    } else if (random_num == 7) {
        printf("%s, your fortune for today is:\n", name);
        printf("Take a chance today, it could lead to something great!\n");
    } else if (random_num == 8) {
        printf("%s, your fortune for today is:\n", name);
        printf("Be open to new opportunities today!\n");
    } else if (random_num == 9) {
        printf("%s, your fortune for today is:\n", name);
        printf("You will learn something new today!\n");
    }

    printf("Thank you for using the Automated Fortune Teller, %s! Have a great day!\n", name);

    return 0;
}