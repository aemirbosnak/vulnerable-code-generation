//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 100

struct fortune {
    char text[MAX_FORTUNE_LENGTH];
    bool used;
};

void init_fortunes(struct fortune fortunes[MAX_FORTUNES]) {
    FILE *file = fopen("fortunes.txt", "r");
    if (file == NULL) {
        printf("Error: could not open fortunes file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", fortunes[count].text)!= EOF && count < MAX_FORTUNES) {
        fortunes[count].used = false;
        count++;
    }

    fclose(file);
}

void shuffle_fortunes(struct fortune fortunes[MAX_FORTUNES]) {
    srand(time(NULL));

    for (int i = 0; i < MAX_FORTUNES; i++) {
        int j = rand() % MAX_FORTUNES;
        struct fortune temp = fortunes[i];
        fortunes[i] = fortunes[j];
        fortunes[j] = temp;
    }
}

void print_fortune(struct fortune fortune) {
    printf("%s\n", fortune.text);
}

int main() {
    struct fortune fortunes[MAX_FORTUNES];
    init_fortunes(fortunes);
    shuffle_fortunes(fortunes);

    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int index = 0;
            while (fortunes[index].used) {
                index = rand() % MAX_FORTUNES;
            }
            fortunes[index].used = true;
            print_fortune(fortunes[index]);
        }
    } while (choice!= 2);

    return 0;
}