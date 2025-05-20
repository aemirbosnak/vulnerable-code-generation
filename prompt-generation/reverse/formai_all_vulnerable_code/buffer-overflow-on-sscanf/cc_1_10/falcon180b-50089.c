//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

// Structure for a fortune
typedef struct {
    char text[80];
    char category[20];
} Fortune;

// Function to load fortunes from a file
int loadFortunes(Fortune fortunes[]) {
    FILE *fp;
    char line[100];
    int count = 0;

    fp = fopen("fortunes.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open fortunes file.\n");
        return 0;
    }

    while (fgets(line, 100, fp)!= NULL) {
        if (count >= MAX_FORTUNES) {
            printf("Error: Too many fortunes in file.\n");
            fclose(fp);
            return 0;
        }

        sscanf(line, "%s %s", fortunes[count].text, fortunes[count].category);
        count++;
    }

    fclose(fp);
    return count;
}

// Function to display a random fortune
void tellFortune(Fortune fortunes[], int count) {
    int index;

    srand(time(NULL));
    index = rand() % count;

    printf("Your fortune: %s\n", fortunes[index].text);
}

int main() {
    Fortune fortunes[MAX_FORTUNES];
    int count;

    // Load fortunes from file
    count = loadFortunes(fortunes);
    if (count <= 0) {
        return 1;
    }

    // Tell a random fortune
    tellFortune(fortunes, count);

    return 0;
}