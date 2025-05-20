//Code Llama-13B DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char fortune[MAX_FORTUNE_LENGTH];
} Fortune;

void print_fortune(Fortune fortune) {
    printf("Your fortune is: %s\n", fortune.fortune);
}

void ask_for_name(char name[MAX_NAME_LENGTH]) {
    printf("What is your name? ");
    scanf("%s", name);
}

void generate_fortune(Fortune fortune) {
    srand(time(NULL));
    int index = rand() % 4;
    switch (index) {
        case 0:
            strcpy(fortune.fortune, "You will have a great day today!");
            break;
        case 1:
            strcpy(fortune.fortune, "You will meet a new friend today!");
            break;
        case 2:
            strcpy(fortune.fortune, "You will have good luck in love today!");
            break;
        case 3:
            strcpy(fortune.fortune, "You will have a successful career today!");
            break;
    }
}

int main() {
    Fortune fortune;
    char name[MAX_NAME_LENGTH];

    ask_for_name(name);
    generate_fortune(fortune);

    printf("Hello, %s! Here is your fortune:\n", name);
    print_fortune(fortune);

    return 0;
}