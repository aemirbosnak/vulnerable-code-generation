//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet a tall, dark stranger."},
    {"A financial windfall is in your future."},
    {"Beware of false friends and flatterers."},
    {"You will travel to exotic places."},
    {"A new love interest is on the horizon."},
    {"Success is within your grasp."},
    {"Your hard work will pay off soon."},
    {"A pleasant surprise awaits you."},
    {"You will receive good news from a friend."},
    {"A change of scenery would do you good."}
};

void generate_fortune(char* fortune_text, int fortune_length) {
    srand(time(NULL));
    int i = 0;
    while (i < fortune_length) {
        int random_index = rand() % MAX_FORTUNES;
        strncat(fortune_text, fortunes[random_index].text, MAX_FORTUNE_LENGTH - i - 1);
        i += strlen(fortunes[random_index].text);
    }
    fortune_text[fortune_length - 1] = '\0';
}

int main() {
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);

    tolower(name);

    Fortune* fortune = NULL;

    for (int i = 0; i < MAX_FORTUNES; i++) {
        if (strstr(fortunes[i].text, name)) {
            fortune = &fortunes[i];
            break;
        }
    }

    if (fortune == NULL) {
        printf("Sorry, there is no fortune for you today.\n");
        return 1;
    }

    char fortune_text[MAX_FORTUNE_LENGTH];
    generate_fortune(fortune_text, strlen(fortune->text));

    printf("\n%s, your fortune is:\n%s\n", name, fortune_text);

    return 0;
}