//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define NUM_CATEGORIES 10

struct fortune {
    char text[80];
    int category;
};

void load_fortunes(struct fortune fortunes[MAX_FORTUNES]) {
    FILE *fp;
    char filename[50];
    int i = 0;

    sprintf(filename, "fortunes_%d.txt", rand() % NUM_CATEGORIES + 1);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error loading fortunes.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d\n", fortunes[i].text, &fortunes[i].category)!= EOF) {
        i++;
        if (i >= MAX_FORTUNES) break;
    }

    fclose(fp);
}

void tell_fortune(struct fortune fortunes[MAX_FORTUNES]) {
    int choice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please choose a category:\n");
    for (int i = 1; i <= NUM_CATEGORIES; i++) {
        printf("%d. %s\n", i, "Category ");
    }
    scanf("%d", &choice);

    srand(time(NULL));
    int index = rand() % MAX_FORTUNES;

    while (fortunes[index].category!= choice) {
        index = rand() % MAX_FORTUNES;
    }

    printf("Your fortune:\n%s\n", fortunes[index].text);
}

int main() {
    struct fortune fortunes[MAX_FORTUNES];

    load_fortunes(fortunes);
    tell_fortune(fortunes);

    return 0;
}