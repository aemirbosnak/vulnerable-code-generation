//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 30 // number of fortunes

typedef struct {
    char *text;
    int length;
} Fortune;

Fortune fortunes[NUM_FORTUNES] = {
    {"You will have a successful day. ", 32},
    {"A pleasant surprise awaits you. ", 36},
    {"You will find true love soon. ", 28},
    {"Your hard work will pay off. ", 32},
    {"A new opportunity is coming your way. ", 42},
    {"You will receive good news today. ", 34},
    {"Someone special is thinking of you. ", 38},
    {"You will achieve your goals. ", 28},
    {"You will overcome a challenge. ", 34},
    {"Your future looks bright. ", 28},
    {"You will have a lucky day. ", 26},
    {"You will be blessed with good health. ", 40},
    {"A friend will help you in need. ", 36},
    {"Your creativity will be rewarded. ", 38},
    {"You will have a peaceful day. ", 28},
    {"You will have a happy family life. ", 38},
    {"You will travel to an exotic place. ", 40},
    {"You will have a successful career. ", 36},
    {"You will find your true passion. ", 34},
    {"You will have a fun-filled day. ", 28},
    {"You will be appreciated for your work. ", 40},
    {"You will have a romantic evening. ", 34},
    {"You will have a memorable experience. ", 40},
    {"You will have a relaxing day. ", 28},
    {"You will have a productive day. ", 32},
    {"You will learn something new. ", 28},
    {"You will make someone happy. ", 30},
    {"You will have a positive impact on someone's life. ", 50},
    {"You will have a day full of laughter. ", 36}
};

void tellFortune(int fortuneIndex) {
    printf("Your fortune:\n%s\n", fortunes[fortuneIndex].text);
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int userChoice;

    printf("Welcome to the Automated Fortune Teller!\n\n");

    while (1) {
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &userChoice);

        if (userChoice == 0) {
            break;
        } else if (userChoice >= NUM_FORTUNES) {
            printf("Invalid choice. Please try again.\n");
        } else {
            tellFortune(userChoice);
        }
    }

    return 0;
}