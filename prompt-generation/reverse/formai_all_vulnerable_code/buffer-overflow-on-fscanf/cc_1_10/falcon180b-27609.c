//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 50

struct fortune {
    char text[100];
};

void init_fortunes() {
    FILE *f;
    int i = 0;
    struct fortune fortunes[NUM_FORTUNES];

    f = fopen("fortunes.txt", "r");
    if (!f) {
        printf("Error: could not open fortunes file.\n");
        exit(1);
    }

    while (fscanf(f, "%s", fortunes[i].text)!= EOF && i < NUM_FORTUNES) {
        i++;
    }

    fclose(f);
}

void print_fortune(struct fortune fortune) {
    printf("%s\n", fortune.text);
}

int main() {
    srand(time(NULL));

    struct fortune fortunes[NUM_FORTUNES];
    init_fortunes();

    int choice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please choose a category:\n");
    printf("1. Love\n2. Money\n3. Health\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Your love fortune:\n");
            print_fortune(fortunes[rand() % NUM_FORTUNES]);
            break;
        case 2:
            printf("Your money fortune:\n");
            print_fortune(fortunes[rand() % NUM_FORTUNES]);
            break;
        case 3:
            printf("Your health fortune:\n");
            print_fortune(fortunes[rand() % NUM_FORTUNES]);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}