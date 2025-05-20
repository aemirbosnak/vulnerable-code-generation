//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[MAX_FORTUNES];
int numFortunes;

void readFortunes(char *filename) {
    FILE *fp;
    char line[MAX_FORTUNE_LENGTH];
    int i = 0;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_FORTUNE_LENGTH, fp)!= NULL) {
        if (i >= MAX_FORTUNES) {
            printf("Error: too many fortunes in file '%s'\n", filename);
            exit(1);
        }
        strcpy(fortunes[i].text, line);
        i++;
    }

    numFortunes = i;
    fclose(fp);
}

void shuffleFortunes() {
    int i, j;
    for (i = 0; i < numFortunes; i++) {
        j = rand() % numFortunes;
        Fortune temp = fortunes[i];
        fortunes[i] = fortunes[j];
        fortunes[j] = temp;
    }
}

void printFortune(int index) {
    printf("%s\n", fortunes[index].text);
}

int main() {
    char filename[MAX_FORTUNE_LENGTH];
    int choice;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter the name of the file containing the fortunes:\n");
    scanf("%s", filename);

    readFortunes(filename);
    shuffleFortunes();

    do {
        printf("\nPress 1 to get a random fortune, or 0 to quit:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int index = rand() % numFortunes;
            printFortune(index);
        }
    } while (choice!= 0);

    return 0;
}