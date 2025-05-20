//LLAMA2-13B DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main() {
    int i, j, k, l;
    char str[100];
    float num;

    // Ask the user for their name
    printf("What's your name? ");
    fgets(str, 100, stdin);
    printf("Hello, %s!\n", str);

    // Ask the user for their favorite number
    printf("What's your favorite number? ");
    scanf("%f", &num);
    printf("Awesome choice! %f is a great number.\n", num);

    // Ask the user for their lucky number
    printf("What's your lucky number? ");
    scanf("%d", &i);
    printf("Lucky you, %d is a prime number!\n", i);

    // Ask the user for their favorite color
    printf("What's your favorite color? ");
    scanf("%s", str);
    printf("Great choice! %s is a beautiful color.\n", str);

    // Ask the user for their favorite animal
    printf("What's your favorite animal? ");
    scanf("%s", str);
    printf("Aww, %s is so cute!\n", str);

    // Ask the user for their birthday
    printf("When's your birthday? ");
    scanf("%d/%d/%d", &k, &l, &i);
    printf("Happy birthday on %d/%d/%d!\n", k, l, i);

    // Ask the user for their favorite food
    printf("What's your favorite food? ");
    scanf("%s", str);
    printf("Yum, %s sounds delicious!\n", str);

    // Ask the user for their favorite movie
    printf("What's your favorite movie? ");
    scanf("%s", str);
    printf("I love %s too!\n", str);

    // Ask the user for their favorite book
    printf("What's your favorite book? ");
    scanf("%s", str);
    printf("I'm reading %s right now!\n", str);

    // Ask the user for their favorite song
    printf("What's your favorite song? ");
    scanf("%s", str);
    printf("I'm singing %s in the shower!\n", str);

    // Ask the user for their favorite hobby
    printf("What's your favorite hobby? ");
    scanf("%s", str);
    printf("I love %s too!\n", str);

    return 0;
}