//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"Your future is bright"},
    {"You will have good luck today"},
    {"You will meet someone special soon"},
    {"You will find success in your endeavors"},
    {"You will receive unexpected news"},
    {"Your hard work will pay off"},
    {"You will experience a change in your life"},
    {"You will overcome obstacles"},
    {"You will achieve your goals"},
    {"You will be blessed with good health"}
};

int main() {
    srand(time(NULL));
    int numFortunes = rand() % MAX_FORTUNES;
    Fortune *selectedFortunes = malloc(numFortunes * sizeof(Fortune));

    int i;
    for (i = 0; i < numFortunes; i++) {
        int j;
        for (j = 0; j < MAX_FORTUNES; j++) {
            if (strcmp(fortunes[j].text, "")!= 0) {
                strcpy(selectedFortunes[i].text, fortunes[j].text);
                fortunes[j].text[0] = '\0';
                break;
            }
        }
    }

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will tell you %d fortunes:\n", numFortunes);

    int k;
    for (k = 0; k < numFortunes; k++) {
        printf("%s\n", selectedFortunes[k].text);
    }

    free(selectedFortunes);
    return 0;
}