//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_FORTUNE_LENGTH 100

char fortune[MAX_FORTUNE_LENGTH];
char name[MAX_NAME_LENGTH];

void generateFortune() {
    srand(time(NULL));
    int randomIndex = rand() % 5;
    switch(randomIndex) {
        case 0:
            sprintf(fortune, "Your future is bright and full of promise!");
            break;
        case 1:
            sprintf(fortune, "You will soon find love and happiness.");
            break;
        case 2:
            sprintf(fortune, "You have a strong and confident personality.");
            break;
        case 3:
            sprintf(fortune, "Your hard work and dedication will pay off in the future.");
            break;
        case 4:
            sprintf(fortune, "You have a natural talent for creativity and innovation.");
            break;
    }
}

void getName() {
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';
}

int main() {
    printf("Welcome to the Automated Fortune Teller!\n");
    getName();
    printf("Hello, %s!\n", name);
    generateFortune();
    printf("%s\n", fortune);
    printf("Do you want to run the program again? (y/n): ");
    char answer;
    scanf(" %c", &answer);
    if(answer == 'y') {
        main();
    } else {
        printf("Thanks for using the Automated Fortune Teller!\n");
    }
    return 0;
}