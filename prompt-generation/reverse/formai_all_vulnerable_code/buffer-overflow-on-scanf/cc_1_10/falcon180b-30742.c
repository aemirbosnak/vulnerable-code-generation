//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet a tall, dark stranger."},
    {"A financial windfall is in your future."},
    {"Beware of false friends."},
    {"You will travel to exotic places."},
    {"A new love is on the horizon."},
    {"Your hard work will pay off soon."},
    {"You will experience a great personal growth."},
    {"A surprise gift is coming your way."},
    {"You will overcome a difficult challenge."},
    {"A long-lost friend will reappear in your life."},
    {"You will receive unexpected good news."},
    {"A change in career is imminent."},
    {"You will find inner peace and contentment."},
    {"You will discover a hidden talent."},
    {"Your creativity will be rewarded."},
    {"You will have a lucky streak."},
    {"A secret will be revealed to you."},
    {"A dream you've had will come true."},
    {"You will make a new friend."},
    {"You will reconnect with an old friend."},
    {"You will experience a spiritual awakening."},
    {"You will find true love."},
    {"You will have a successful business venture."},
    {"You will achieve a lifelong goal."},
    {"You will learn a valuable lesson."},
    {"You will have a memorable adventure."},
    {"You will be recognized for your achievements."},
    {"You will have a happy and fulfilling life."}
};

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_FORTUNE_LENGTH];

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please enter your name: ");
        scanf("%s", input);
        printf("Hello, %s! I am here to tell you your fortune.\n", input);
        printf("Please choose a number between 1 and %d:\n", MAX_FORTUNES - 1);
        scanf("%d", &choice);
        if (choice >= 1 && choice <= MAX_FORTUNES - 1) {
            printf("Your fortune is:\n%s\n", fortunes[choice].text);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        printf("Would you like to try again? (y/n): ");
        scanf(" %c", &input[0]);
    } while (input[0] == 'y' || input[0] == 'Y');

    return 0;
}