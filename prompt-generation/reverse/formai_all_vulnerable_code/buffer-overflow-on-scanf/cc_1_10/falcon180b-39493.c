//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 50
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    "You will find true love soon",
    "A great opportunity is coming your way",
    "You will have a successful career",
    "Good health is in your future",
    "You will travel to a new place",
    "Your financial situation will improve",
    "You will have a happy family life",
    "You will make new friends",
    "You will overcome a challenge",
    "Your creativity will be rewarded",
    "You will receive a surprise gift",
    "You will learn a new skill",
    "Your dreams will come true",
    "You will find inner peace",
    "You will accomplish a goal",
    "You will have a lucky day",
    "You will experience personal growth",
    "You will have a fun adventure",
    "You will enjoy good food and drink",
    "You will have a relaxing vacation",
    "You will have a romantic evening",
    "You will have a memorable celebration",
    "You will have a successful project",
    "You will have a positive change in your life",
    "You will have a comfortable home",
    "You will have a good night's sleep",
    "You will have a productive day",
    "You will have a joyful occasion",
    "You will have a peaceful mind",
    "You will have a happy moment",
    "You will have a successful journey",
    "You will have a pleasant surprise",
    "You will have a comfortable trip",
    "You will have a safe journey",
    "You will have a smooth ride",
    "You will have a comfortable flight",
    "You will have a fun trip",
    "You will have a relaxing time",
    "You will have a happy ending"
};

void shuffle(Fortune fortunes[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        j = rand() % n;
        Fortune temp = fortunes[i];
        fortunes[i] = fortunes[j];
        fortunes[j] = temp;
    }
}

int main() {
    int choice;
    char name[20];
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    srand(time(NULL));
    shuffle(fortunes, MAX_FORTUNES);
    do {
        printf("\n%s, your fortune is:\n", name);
        printf("%s\n", fortunes[0].text);
        printf("Would you like to hear another fortune? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    return 0;
}