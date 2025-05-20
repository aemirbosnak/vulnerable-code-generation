//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80

typedef struct {
    char text[MAX_LENGTH];
    int weight;
} fortune;

void load_fortunes(fortune* fortunes) {
    FILE* file = fopen("fortunes.txt", "r");
    if (file == NULL) {
        printf("Error loading fortunes.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %d\n", fortunes[count].text, &fortunes[count].weight) == 2) {
        count++;
        if (count >= MAX_FORTUNES) {
            break;
        }
    }

    fclose(file);
}

void print_fortune(fortune* fortunes, int index) {
    if (index >= 0 && index < MAX_FORTUNES) {
        printf("%s\n", fortunes[index].text);
    } else {
        printf("Invalid fortune.\n");
    }
}

int main() {
    srand(time(NULL));

    fortune fortunes[MAX_FORTUNES];
    load_fortunes(fortunes);

    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int index = rand() % MAX_FORTUNES;
            print_fortune(fortunes, index);
        }

    } while (choice!= 2);

    return 0;
}