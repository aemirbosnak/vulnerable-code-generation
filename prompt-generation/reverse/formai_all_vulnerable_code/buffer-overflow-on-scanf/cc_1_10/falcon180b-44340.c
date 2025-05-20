//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80

typedef struct {
    char text[MAX_LENGTH];
    int length;
    int id;
} fortune;

fortune fortunes[MAX_FORTUNES] = {
    {"You will meet a tall, dark stranger. ", 32, 1},
    {"A great adventure awaits you. ", 28, 2},
    {"You will come into a large sum of money. ", 37, 3},
    {"Beware of a friend who is not what they seem. ", 45, 4},
    {"Your hard work will pay off soon. ", 31, 5},
    {"You will find love in unexpected places. ", 36, 6},
    {"A new opportunity will present itself to you. ", 43, 7},
    {"You will experience a great personal growth. ", 41, 8},
    {"A long-lost friend will return to your life. ", 39, 9},
    {"Your dreams will become a reality. ", 30, 10}
};

void tell_fortune(int id) {
    srand(time(NULL));
    int index = rand() % MAX_FORTUNES;
    while (index == id) {
        index = rand() % MAX_FORTUNES;
    }
    printf("Your fortune: %s\n", fortunes[index].text);
}

int main() {
    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Tell my fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("What is your lucky number? ");
            int id;
            scanf("%d", &id);
            tell_fortune(id);
            break;
        case 2:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 2);
    return 0;
}