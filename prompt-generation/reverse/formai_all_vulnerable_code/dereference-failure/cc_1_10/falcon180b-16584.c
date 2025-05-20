//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

// Struct for holding fortunes
typedef struct {
    char text[80];
    int length;
} fortune;

// Function for loading fortunes from file
void load_fortunes(fortune fortunes[], char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    int count = 0;
    while (fgets(fortunes[count].text, sizeof(fortunes[count].text), fp)!= NULL && count < MAX_FORTUNES) {
        fortunes[count].length = strlen(fortunes[count].text);
        count++;
    }

    fclose(fp);
}

// Function for printing a random fortune
void tell_fortune(fortune fortunes[]) {
    srand(time(NULL));
    int index = rand() % MAX_FORTUNES;

    printf("%s\n", fortunes[index].text);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <number_of_fortunes>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int num_fortunes = atoi(argv[2]);

    fortune fortunes[MAX_FORTUNES];
    load_fortunes(fortunes, filename);

    for (int i = 0; i < num_fortunes; i++) {
        tell_fortune(fortunes);
    }

    return 0;
}