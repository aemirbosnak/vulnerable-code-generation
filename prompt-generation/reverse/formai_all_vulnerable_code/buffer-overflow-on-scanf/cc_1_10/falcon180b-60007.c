//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTS 100

typedef struct {
    char text[100];
    int value;
} fortune;

fortune fortunes[MAX_FORTS] = {
    {"You will meet a tall, dark stranger.", 1},
    {"A financial windfall is in your future.", 2},
    {"Beware of a friend who is not what they seem.", 3},
    {"Your hard work will pay off soon.", 4},
    {"A new opportunity will present itself to you.", 5},
    {"You will experience a great personal loss.", 6},
    {"Someone close to you will betray your trust.", 7},
    {"You will find love in an unexpected place.", 8},
    {"Your health will improve dramatically.", 9},
    {"A long-lost relative will contact you.", 10}
};

int main() {
    int choice;
    srand(time(NULL));

    printf("Welcome to Sherlock Holmes' Automated Fortune Teller!\n\n");
    printf("Please choose a category:\n");
    printf("1. Love\n2. Wealth\n3. Health\n4. Betrayal\n5. Opportunity\n6. Loss\n");
    scanf("%d", &choice);

    printf("\nYour fortune is:\n");
    switch(choice) {
        case 1:
            printf("%s\n", fortunes[rand() % MAX_FORTS].text);
            break;
        case 2:
            printf("%s\n", fortunes[rand() % MAX_FORTS].text);
            break;
        case 3:
            printf("%s\n", fortunes[rand() % MAX_FORTS].text);
            break;
        case 4:
            printf("%s\n", fortunes[rand() % MAX_FORTS].text);
            break;
        case 5:
            printf("%s\n", fortunes[rand() % MAX_FORTS].text);
            break;
        case 6:
            printf("%s\n", fortunes[rand() % MAX_FORTS].text);
            break;
        default:
            printf("Sorry, that category is not available.\n");
            break;
    }

    return 0;
}