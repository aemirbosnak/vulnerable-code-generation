//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"In matters of the heart, trust your intuition."},
    {"Love is like a rose, beautiful but with thorns."},
    {"Your soulmate is closer than you think."},
    {"A new romance is on the horizon."},
    {"The one you love is thinking of you right now."},
    {"Your heart will guide you to true love."},
    {"Love is a journey, not a destination."},
    {"Follow your heart and it will lead you to happiness."},
    {"The future of your love life is bright."},
    {"Believe in love and it will find you."}
};

void generate_fortune(Fortune* fortune) {
    srand(time(NULL));
    int index = rand() % MAX_FORTUNES;
    strcpy(fortune->text, fortunes[index].text);
    fortune->length = strlen(fortune->text);
}

int main() {
    setbuf(stdout, NULL);

    puts("Welcome to the Automated Fortune Teller!");

    char name[20];
    printf("What is your name? ");
    scanf("%s", name);

    printf("\n%s, I have a special message for you:\n", name);

    Fortune fortune;
    generate_fortune(&fortune);

    printf("%s\n", fortune.text);

    return 0;
}