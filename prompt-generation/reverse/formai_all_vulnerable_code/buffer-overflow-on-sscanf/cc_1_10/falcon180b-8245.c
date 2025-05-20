//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

struct fortune {
    char text[80];
    char category[20];
};

void read_fortunes(struct fortune fortunes[]) {
    FILE *file;
    char line[100];
    int count = 0;

    file = fopen("fortunes.txt", "r");
    if (file == NULL) {
        printf("Error reading fortunes file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (count >= MAX_FORTUNES) {
            printf("Warning: Maximum number of fortunes reached.\n");
            break;
        }

        sscanf(line, "%s %s", fortunes[count].text, fortunes[count].category);
        count++;
    }

    fclose(file);
}

void print_fortune(struct fortune fortune) {
    printf("%s (%s)\n", fortune.text, fortune.category);
}

int main() {
    struct fortune fortunes[MAX_FORTUNES];

    read_fortunes(fortunes);

    srand(time(NULL));

    int choice = rand() % MAX_FORTUNES;

    print_fortune(fortunes[choice]);

    return 0;
}