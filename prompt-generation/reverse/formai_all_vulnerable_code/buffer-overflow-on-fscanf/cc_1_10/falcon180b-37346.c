//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 100

// structure to hold fortunes
typedef struct {
    char text[80];
} fortune;

// function prototypes
void loadFortunes(fortune fortunes[]);
void printFortune(fortune fortune);

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    // load the fortunes
    fortune fortunes[NUM_FORTUNES];
    loadFortunes(fortunes);

    // print a random fortune
    int index = rand() % NUM_FORTUNES;
    printFortune(fortunes[index]);

    return 0;
}

// load the fortunes from a file
void loadFortunes(fortune fortunes[]) {
    FILE *fp = fopen("fortunes.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open fortunes file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s", fortunes[i].text)!= EOF) {
        i++;
    }

    fclose(fp);
}

// print a random fortune
void printFortune(fortune fortune) {
    printf("In the post-apocalyptic wasteland, %s.\n", fortune.text);
}