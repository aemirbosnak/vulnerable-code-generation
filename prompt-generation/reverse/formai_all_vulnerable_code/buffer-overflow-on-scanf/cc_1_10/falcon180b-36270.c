//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 512

struct fortune {
    char text[MAX_FORTUNE_LENGTH];
};

struct fortune fortunes[MAX_FORTUNES] = {
    {"You will have good luck today."},
    {"A new opportunity will come your way."},
    {"You will meet someone special soon."},
    {"Your hard work will pay off."},
    {"A pleasant surprise is in store for you."},
    {"You will receive a gift from someone unexpected."},
    {"You will find success in your current project."},
    {"You will be offered a promotion at work."},
    {"You will hear good news from a loved one."},
    {"You will discover a hidden talent."}
};

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_FORTUNE_LENGTH];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("Hello, %s! I am here to tell you your fortune.\n", input);

    while (1) {
        printf("Please choose a fortune:\n");
        for (int i = 0; i < MAX_FORTUNES; i++) {
            printf("%d. %s\n", i+1, fortunes[i].text);
        }
        scanf("%d", &choice);

        if (choice >= 1 && choice <= MAX_FORTUNES) {
            printf("Your fortune: %s\n", fortunes[choice-1].text);
            break;
        } else {
            printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}