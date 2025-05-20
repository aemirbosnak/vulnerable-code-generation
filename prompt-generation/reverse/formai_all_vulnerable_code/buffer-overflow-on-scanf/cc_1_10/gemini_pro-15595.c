//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 32
#define MAX_FORTUNE_LENGTH 256

struct fortune {
    char *text;
    int length;
};

struct fortune_teller {
    char *name;
    int num_fortunes;
    struct fortune *fortunes;
};

struct fortune_teller *create_fortune_teller(char *name, int num_fortunes, struct fortune *fortunes) {
    struct fortune_teller *teller = malloc(sizeof(struct fortune_teller));
    teller->name = malloc(strlen(name) + 1);
    strcpy(teller->name, name);
    teller->num_fortunes = num_fortunes;
    teller->fortunes = fortunes;
    return teller;
}

void destroy_fortune_teller(struct fortune_teller *teller) {
    free(teller->name);
    for (int i = 0; i < teller->num_fortunes; i++) {
        free(teller->fortunes[i].text);
    }
    free(teller->fortunes);
    free(teller);
}

struct fortune get_random_fortune(struct fortune_teller *teller) {
    int index = rand() % teller->num_fortunes;
    return teller->fortunes[index];
}

void print_fortune(struct fortune fortune) {
    printf("%s\n", fortune.text);
}

int main() {
    srand(time(NULL));

    struct fortune fortunes[] = {
        { "You will have a long and happy life.", 28 },
        { "You will be rich and famous.", 21 },
        { "You will find true love.", 19 },
        { "You will travel the world.", 20 },
        { "You will make a difference in the world.", 33 },
    };

    struct fortune_teller teller = { "Donald Knuth", 5, fortunes };

    char name[MAX_NAME_LENGTH];
    printf("What is your name? ");
    scanf("%s", name);

    struct fortune fortune = get_random_fortune(&teller);
    printf("Hello, %s. Your fortune is: ", name);
    print_fortune(fortune);

    destroy_fortune_teller(&teller);

    return 0;
}