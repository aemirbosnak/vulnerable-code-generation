//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 1000

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[MAX_FORTUNES];
int numFortunes;

void readFortunes(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_FORTUNE_LENGTH];
    while (fgets(line, MAX_FORTUNE_LENGTH, file)!= NULL) {
        fortunes[numFortunes++] = (Fortune) {.text = line };
    }

    fclose(file);
}

void generateFortune() {
    srand(time(NULL));
    int index = rand() % numFortunes;
    printf("%s\n", fortunes[index].text);
}

int main() {
    char filename[MAX_FORTUNE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    readFortunes(filename);

    while (1) {
        printf("Press enter to generate a fortune\n");
        getchar();
        generateFortune();
    }

    return 0;
}