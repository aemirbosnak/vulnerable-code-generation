//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOVE 1
#define HEART 2
#define KISS 3

typedef struct {
    int type;
    char name[20];
} gift_t;

gift_t gifts[3] = {
    {LOVE, "Chocolates"},
    {HEART, "Rose"},
    {KISS, "Teddy Bear"}
};

int main() {
    int choice;
    char name[20];

    printf("Welcome to my Heart's Desire!\n");

    do {
        printf("Choose a gift: ");
        scanf("%d", &choice);

        switch (choice) {
            case LOVE:
                printf("You have chosen: %s\n", gifts[0].name);
                break;
            case HEART:
                printf("You have chosen: %s\n", gifts[1].name);
                break;
            case KISS:
                printf("You have chosen: %s\n", gifts[2].name);
                break;
            default:
                printf("Invalid choice. Try again!");
                break;
        }

        printf("Who is the gift for? ");
        fgets(name, 20, stdin);
        printf("I have a special gift for you, %s!", name);

        sleep(1);
    } while (1);

    return 0;
}