//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

struct fortune {
    char text[80];
    struct fortune *next;
};

void init_fortunes(void) {
    FILE *fp;
    char line[80];
    struct fortune *head = NULL;

    fp = fopen("fortunes.txt", "r");
    if (fp == NULL) {
        printf("Error: cannot open fortunes file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        struct fortune *new_fortune = malloc(sizeof(struct fortune));
        strcpy(new_fortune->text, line);
        new_fortune->next = head;
        head = new_fortune;
    }

    fclose(fp);
}

void tell_fortune(struct fortune *fortunes) {
    char choice;
    int index;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will tell you your fortune.\n");

    srand(time(NULL));
    index = rand() % MAX_FORTUNES;

    fortunes = fortunes->next;
    for (int i = 0; i < index; i++) {
        fortunes = fortunes->next;
    }

    printf("%s\n", fortunes->text);

    printf("Do you want to hear another fortune? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        tell_fortune(fortunes);
    }
}

int main(void) {
    struct fortune *fortunes = NULL;

    init_fortunes();
    tell_fortune(fortunes);

    return 0;
}