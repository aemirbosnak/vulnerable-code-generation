//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *text;
    int len;
} fortune;

fortune fortunes[] = {
    {"You will have good luck today. ", 29},
    {"A new opportunity is coming your way. ", 38},
    {"Someone is thinking of you right now. ", 28},
    {"You will meet someone special soon. ", 31},
    {"Success is just around the corner. ", 33},
    {"A pleasant surprise awaits you. ", 28},
    {"Your hard work will pay off. ", 26},
    {"You will receive a gift today. ", 26},
    {"A friend will need your help. ", 29},
    {"You will have a productive day. ", 29}
};

void print_fortune(fortune f) {
    printf("%s\n", f.text);
}

int main() {
    srand(time(NULL));
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    int choice;

    while (1) {
        printf("Enter the number of fortunes you want to read: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 10) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        for (int i = 0; i < choice; i++) {
            int index = rand() % num_fortunes;
            print_fortune(fortunes[index]);
        }

        printf("Do you want to continue? (y/n): ");
        char cont;
        scanf(" %c", &cont);

        if (cont == 'n') {
            break;
        }
    }

    return 0;
}