//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

void generate_fortunes(Fortune fortunes[MAX_FORTUNES]) {
    int i;
    for (i = 0; i < MAX_FORTUNES; i++) {
        fortunes[i].text[0] = '\0';
    }
}

void print_fortune(const Fortune *fortune) {
    if (fortune->text[0] == '\0') {
        printf("Sorry, no fortune available.\n");
    } else {
        printf("%s\n", fortune->text);
    }
}

int main() {
    Fortune fortunes[MAX_FORTUNES];
    generate_fortunes(fortunes);

    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            srand(time(NULL));
            int index = rand() % MAX_FORTUNES;
            print_fortune(&fortunes[index]);
            break;

        case 2:
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (choice!= 2);

    return 0;
}