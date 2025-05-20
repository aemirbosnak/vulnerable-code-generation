//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Define the romantic variables
#define LOVE 100
#define KISS 50
#define HUG 25
#define DATE 10

// Define the romantic functions
int romantic_calculator(int love, int kiss, int hug, int date) {
    int total = love + kiss + hug + date;
    return total;
}

int main() {
    int love = ask_user_for_love();
    int kiss = ask_user_for_kiss();
    int hug = ask_user_for_hug();
    int date = ask_user_for_date();

    int total = romantic_calculator(love, kiss, hug, date);

    printf("Your total romantic score is %d\n", total);

    return 0;
}

int ask_user_for_love() {
    int love;
    printf("How much love do you have in your heart? ");
    scanf("%d", &love);
    return love;
}

int ask_user_for_kiss() {
    int kiss;
    printf("How many kisses have you shared today? ");
    scanf("%d", &kiss);
    return kiss;
}

int ask_user_for_hug() {
    int hug;
    printf("How many hugs have you received today? ");
    scanf("%d", &hug);
    return hug;
}

int ask_user_for_date() {
    int date;
    printf("How many dates have you been on today? ");
    scanf("%d", &date);
    return date;
}