//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>

int main()
{
    int num,i,j;
    char letter;
    int time;

    printf("Welcome to the typing speed test.\n");

    printf("Please type's' to start the test.\n");
    scanf("%c",&letter);
    if (letter =='s') {
        time = 0;
        while (time < 30) {
            for (i = 0; i < 5; i++) {
                printf("A");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("B");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("C");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("D");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("E");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("F");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("G");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("H");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("I");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("J");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("K");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("L");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("M");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("N");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("O");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("P");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("Q");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("R");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("S");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("T");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("U");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("V");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("W");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("X");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("Y");
                time = time + 1;
            }
            for (j = 0; j < 5; j++) {
                printf("Z");
                time = time + 1;
            }
        }
        printf("Your typing speed is %d words per minute.\n", 60 / time);
    }
    else {
        printf("Please enter's' to start the test.\n");
    }

    return 0;
}