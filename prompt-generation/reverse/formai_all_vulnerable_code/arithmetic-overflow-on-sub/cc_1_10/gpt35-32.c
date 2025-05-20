//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void typingTest();
int generateRandomNumber(int n);

int main() {
    int choice;
    printf("\nWelcome to the Typing Speed Test Program!");
    printf("\n\nPress 1 to start the test, Press 0 to exit: ");
    scanf("%d", &choice);

    switch(choice) {
        case 0:
            printf("\nExiting the program. Thank you for using the Typing Speed Test.");
            break;
        case 1:
            typingTest();
            break;
        default:
            printf("\nInvalid choice. Please try again.");
            break;
    }
    return 0;
}

void typingTest() {
    char string[100] = "\nA Quick Brown Fox Jumps Over The Lazy Dog";
    char user_string[100];
    int i;
    int mistakes = 0;
    double time_taken;
    clock_t t;

    printf("\nEnter the following text:- ");
    printf("\n%s", string);

    t = clock();
    fflush(stdout);
    fflush(stdin);

    gets(user_string);

    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;

    for(i = 0; string[i] != '\0' || user_string[i] != '\0'; i++) {
        if(string[i] != user_string[i])
            mistakes++;
    }

    if(mistakes > 0) {
        printf("\nYou made %d mistake(s).\n", mistakes);
    }
    else {
        printf("\nCongratulations! You made no mistakes.\n");
    }

    printf("\nTime taken to complete the test: %0.2f seconds\n", time_taken);
    printf("\nType any key to exit.");
    getchar();
}

int generateRandomNumber(int n) {
    srand(time(NULL));
    return rand() % n;
}