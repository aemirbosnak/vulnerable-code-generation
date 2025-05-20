//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct fortune {
    char *text;
    int length;
};

void generate_fortune(char *dest, int max_length) {
    struct fortune fortunes[] = {
        {"You will meet someone special today. ", 38},
        {"A new opportunity will come your way. ", 39},
        {"Good luck will follow you throughout the day. ", 43},
        {"You will receive unexpected news. ", 34},
        {"Your hard work will pay off soon. ", 37},
        {"A friend will need your help. ", 31},
        {"You will have a pleasant surprise. ", 36},
        {"Someone is thinking about you right now. ", 45},
        {"Success is within your reach. ", 31},
        {"You will overcome a challenge today. ", 39}
    };

    srand(time(NULL));
    int index = rand() % 10;
    strncpy(dest, fortunes[index].text, max_length);
}

int main() {
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);

    printf("\nHello, %s! I am the Automated Fortune Teller.\n", name);
    printf("I can predict your future with amazing accuracy.\n");
    printf("Just ask me a question and I will provide you with an answer.\n");

    while (1) {
        printf("\nAsk me a question: ");
        char question[100];
        scanf("%s", question);

        if (strcmp(question, "quit") == 0) {
            break;
        }

        char fortune[80];
        generate_fortune(fortune, sizeof(fortune));
        printf("\n%s\n", fortune);
    }

    return 0;
}