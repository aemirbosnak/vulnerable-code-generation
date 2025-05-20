//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    char choice;
    int randNum;
    char fortune[100];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Press any key to begin...\n");
    scanf("%c", &choice);

    srand(time(NULL));
    randNum = rand() % 10;

    switch(randNum) {
        case 0:
            strcpy(fortune, "Your future is bright and full of success!");
            break;
        case 1:
            strcpy(fortune, "You will face challenges, but you will overcome them.");
            break;
        case 2:
            strcpy(fortune, "Love is in your future, be open to new possibilities.");
            break;
        case 3:
            strcpy(fortune, "Financial stability is on the horizon, stay focused on your goals.");
            break;
        case 4:
            strcpy(fortune, "Travel opportunities are coming your way, embrace new experiences.");
            break;
        case 5:
            strcpy(fortune, "You will find inner peace and happiness in the coming days.");
            break;
        case 6:
            strcpy(fortune, "A new job or career opportunity is on the horizon, be prepared to seize it.");
            break;
        case 7:
            strcpy(fortune, "Your health will improve, keep up with healthy habits.");
            break;
        case 8:
            strcpy(fortune, "You will experience personal growth and self-discovery.");
            break;
        case 9:
            strcpy(fortune, "Good luck is coming your way, be ready to take advantage of it.");
            break;
    }

    printf("Your fortune:\n%s\n", fortune);

    printf("Press any key to exit...\n");
    scanf("%c", &choice);
}