//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

typedef struct {
    char text[80];
    int length;
} fortune;

fortune fortunes[MAX_FORTUNES] = {
    {"You will meet a tall, dark stranger. ", 37},
    {"A financial opportunity is coming your way. ", 42},
    {"Beware of a friend who is not what they seem. ", 48},
    {"Travel is in your future. ", 27},
    {"You will receive an unexpected gift. ", 31},
    {"Someone from your past will reenter your life. ", 45},
    {"A new love interest is on the horizon. ", 36},
    {"Success is within reach if you stay focused. ", 44},
    {"A change in career may be beneficial. ", 39},
    {"Your hard work will pay off soon. ", 32}
};

void shuffle(int deck[], int n) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        j = rand() % n;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    int choice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please choose an option:\n");
    printf("1. Get a fortune\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int deck[MAX_FORTUNES];
        for (int i = 0; i < MAX_FORTUNES; i++) {
            deck[i] = i;
        }
        shuffle(deck, MAX_FORTUNES);
        int index = deck[0];
        printf("\nYour fortune: %s\n", fortunes[index].text);
    } else if (choice == 2) {
        printf("Thank you for using the Automated Fortune Teller!\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}