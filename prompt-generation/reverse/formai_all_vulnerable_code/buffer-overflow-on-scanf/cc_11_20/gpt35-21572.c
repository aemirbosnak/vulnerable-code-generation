//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[50];
    int age, lucky_num, fortune_num, love_num;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("My name is Romeo, what's your name?\n");
    scanf("%[^\n]%*c", name);

    printf("A pleasure to meet you, %s! How old are you?\n", name);
    scanf("%d", &age);

    printf("Ah, a young and vibrant soul at %d years old. Tell me, what is your lucky number?\n", age);
    scanf("%d", &lucky_num);

    printf("Hmm, interesting. And what is your favorite number?\n");
    scanf("%d", &love_num);

    srand(time(NULL));
    fortune_num = rand() % 10 + 1;

    printf("\nAh, %s, let the stars and planets align... your fortune for today is...\n\n", name);

    switch(fortune_num) {
        case 1:
            printf("A bright and prosperous future awaits you if you follow your heart, %s. Trust in your instincts and success will follow.\n", name);
            break;
        case 2:
            printf("Beware of those who try to deceive you, %s. Keep a watchful eye and stay true to yourself, and you will come out on top.\n", name);
            break;
        case 3:
            printf("Your lucky number, %d, will bring you great fortune in the near future, %s. Keep an open mind and heart.\n", lucky_num, name);
            break;
        case 4:
            printf("Fear not, for love is on the horizon for you, %s. Your favorite number, %d, will play a key role in this new romance.\n", name, love_num);
            break;
        case 5:
            printf("A change in scenery may be just what you need, %s. Take a leap of faith and explore new horizons, and you will be rewarded.\n", name);
            break;
        case 6:
            printf("A great opportunity is coming your way, %s, and it will be up to you to seize it. Stay focused and determined, and you will prevail.\n", name);
            break;
        case 7:
            printf("Your journey may have some obstacles, %s, but do not let them discourage you. Stay true to your beliefs and you will succeed.\n", name);
            break;
        case 8:
            printf("Your future looks bright, %s, and your lucky number, %d, will play a big part in this success. Be open to new experiences and opportunities.\n", name, lucky_num);
            break;
        case 9:
            printf("A creative endeavor may be just what you need to reignite your passion, %s. Let your artistic side shine, and success will come naturally.\n", name);
            break;
        case 10:
            printf("Be cautious with your words, %s, for they hold great power. Choose them wisely and speak from the heart, and you will be rewarded.\n", name);
            break;
    }
    return 0;
}