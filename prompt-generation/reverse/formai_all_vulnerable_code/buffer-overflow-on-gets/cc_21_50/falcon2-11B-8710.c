//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    srand(time(NULL));
    char question[100], answer[100], fortune[100];
    int luck_number = rand() % 100;
    int lucky_color = rand() % 5 + 1;
    int sign_number = rand() % 12 + 1;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your question?\n");
    gets(question);
    printf("Your answer is %s.\n", answer);
    printf("Your fortune is %s.\n", fortune);

    if (strcmp(question, "Will I be lucky today?") == 0) {
        if (luck_number < 10) {
            sprintf(fortune, "You will have good luck today!");
        } else if (luck_number >= 10 && luck_number < 20) {
            sprintf(fortune, "You will have moderate luck today!");
        } else if (luck_number >= 20 && luck_number < 30) {
            sprintf(fortune, "You will have bad luck today!");
        } else if (luck_number >= 30 && luck_number < 40) {
            sprintf(fortune, "You will have good luck today!");
        } else if (luck_number >= 40 && luck_number < 50) {
            sprintf(fortune, "You will have moderate luck today!");
        } else if (luck_number >= 50 && luck_number < 60) {
            sprintf(fortune, "You will have bad luck today!");
        } else if (luck_number >= 60 && luck_number < 70) {
            sprintf(fortune, "You will have good luck today!");
        } else if (luck_number >= 70 && luck_number < 80) {
            sprintf(fortune, "You will have moderate luck today!");
        } else if (luck_number >= 80 && luck_number < 90) {
            sprintf(fortune, "You will have bad luck today!");
        } else if (luck_number >= 90 && luck_number < 100) {
            sprintf(fortune, "You will have good luck today!");
        } else {
            sprintf(fortune, "Your luck is not determined by this fortune teller!");
        }
    } else if (strcmp(question, "What is my lucky color?") == 0) {
        if (lucky_color == 1) {
            sprintf(fortune, "Your lucky color is Red!");
        } else if (lucky_color == 2) {
            sprintf(fortune, "Your lucky color is Orange!");
        } else if (lucky_color == 3) {
            sprintf(fortune, "Your lucky color is Yellow!");
        } else if (lucky_color == 4) {
            sprintf(fortune, "Your lucky color is Green!");
        } else if (lucky_color == 5) {
            sprintf(fortune, "Your lucky color is Blue!");
        } else {
            sprintf(fortune, "Your luck is not determined by this fortune teller!");
        }
    } else if (strcmp(question, "What is my lucky sign?") == 0) {
        if (sign_number == 1) {
            sprintf(fortune, "Your lucky sign is Aries!");
        } else if (sign_number == 2) {
            sprintf(fortune, "Your lucky sign is Taurus!");
        } else if (sign_number == 3) {
            sprintf(fortune, "Your lucky sign is Gemini!");
        } else if (sign_number == 4) {
            sprintf(fortune, "Your lucky sign is Cancer!");
        } else if (sign_number == 5) {
            sprintf(fortune, "Your lucky sign is Leo!");
        } else if (sign_number == 6) {
            sprintf(fortune, "Your lucky sign is Virgo!");
        } else if (sign_number == 7) {
            sprintf(fortune, "Your lucky sign is Libra!");
        } else if (sign_number == 8) {
            sprintf(fortune, "Your lucky sign is Scorpio!");
        } else if (sign_number == 9) {
            sprintf(fortune, "Your lucky sign is Sagittarius!");
        } else if (sign_number == 10) {
            sprintf(fortune, "Your lucky sign is Capricorn!");
        } else if (sign_number == 11) {
            sprintf(fortune, "Your lucky sign is Aquarius!");
        } else if (sign_number == 12) {
            sprintf(fortune, "Your lucky sign is Pisces!");
        } else {
            sprintf(fortune, "Your luck is not determined by this fortune teller!");
        }
    } else {
        sprintf(fortune, "Your luck is not determined by this fortune teller!");
    }

    printf("Your fortune is %s.\n", fortune);

    return 0;
}