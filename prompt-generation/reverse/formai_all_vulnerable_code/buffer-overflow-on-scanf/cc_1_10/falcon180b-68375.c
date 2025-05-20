//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
    int length;
} fortune;

fortune fortunes[MAX_FORTUNES] = {
    {"You will meet someone special today. ", 34},
    {"A great opportunity is coming your way. ", 38},
    {"You will receive good news soon. ", 28},
    {"Your hard work will pay off. ", 25},
    {"A friend will need your help. ", 31},
    {"You will experience a small setback. ", 35},
    {"You will have a lucky day. ", 23},
    {"A new adventure awaits you. ", 32},
    {"You will learn something new today. ", 37},
    {"You will overcome a challenge. ", 36}
};

void shuffle(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will reveal your future...\n");

    int choice;
    do {
        printf("Press 1 to get a fortune or 0 to exit:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            shuffle(fortunes, MAX_FORTUNES);

            int index = rand() % MAX_FORTUNES;
            printf("\nYour fortune:\n");
            printf("%s\n", fortunes[index].text);
            printf("Length of fortune: %d\n", fortunes[index].length);
        }
    } while (choice!= 0);

    return 0;
}