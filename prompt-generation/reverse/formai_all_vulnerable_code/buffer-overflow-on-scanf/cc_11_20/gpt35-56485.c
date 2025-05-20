//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age, lucky_number, fortune;

    printf("Welcome to the Automated Fortune Teller!\n");

    // Get user's name
    printf("What is your name?\n");
    scanf("%s", name);

    // Get user's age
    printf("What is your age?\n");
    scanf("%d", &age);

    // Check user's age
    if (age < 18) {
        printf("Sorry, you must be at least 18 years old to use this fortune teller.\n");
        return 0;
    }

    // Get user's lucky number
    printf("What is your lucky number?\n");
    scanf("%d", &lucky_number);

    // Generate a fortune
    srand(time(NULL));
    fortune = rand() % 10;

    // Output fortune based on lucky number and age
    if (lucky_number == 7) {
        printf("Congratulations, %s! You are very lucky indeed.\n", name);
        switch (fortune) {
            case 0:
                printf("Your future looks bright. Expect a major promotion in the near future.\n");
                break;
            case 1:
                printf("Your future contains much travel. Be sure to pack your bags and explore the world.\n");
                break;
            case 2:
                printf("Your future involves a great romance. Expect to meet someone special very soon.\n");
                break;
            case 3:
                printf("Your future is full of surprises. Expect the unexpected and embrace change.\n");
                break;
            case 4:
                printf("Your future is very successful. Expect to reach the top of your profession.\n");
                break;
            case 5:
                printf("Your future is full of creativity. Expect to make great strides in your artistic endeavors.\n");
                break;
            case 6:
                printf("Your future is full of financial abundance. Expect much prosperity in the coming years.\n");
                break;
            case 7:
                printf("Your future is something you will have to discover yourself. Stay curious and keep exploring.\n");
                break;
            case 8:
                printf("Your future is full of adventure. Expect to take risks and live life to the fullest.\n");
                break;
            case 9:
                printf("Your future contains much happiness. Expect to find joy in the simplest things in life.\n");
                break;
        }
    } else {
        printf("Thanks for using the Automated Fortune Teller, %s! Your luck may improve with time.\n", name);
    }

    return 0;
}