//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[] = {
    {"You will have good luck today."},
    {"A new opportunity will come your way."},
    {"You will receive a pleasant surprise."},
    {"Success is in your future."},
    {"Your hard work will pay off soon."},
    {"Love is on the horizon."},
    {"You will experience a positive change."},
    {"A friend will offer you help when you need it most."},
    {"You will find happiness in unexpected places."},
    {"Your dreams will come true if you believe in yourself."}
};

int main() {
    srand(time(NULL));
    int num_fortunes = sizeof(fortunes) / sizeof(Fortune);
    int random_index;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What would you like your fortune to be about?\n");
    printf("1. Love\n");
    printf("2. Career\n");
    printf("3. Health\n");
    printf("4. General\n");

    int topic;
    scanf("%d", &topic);

    switch (topic) {
        case 1:
            printf("Your love fortune:\n");
            break;
        case 2:
            printf("Your career fortune:\n");
            break;
        case 3:
            printf("Your health fortune:\n");
            break;
        case 4:
            printf("Your general fortune:\n");
            break;
        default:
            printf("Invalid topic.\n");
            return 1;
    }

    random_index = rand() % num_fortunes;
    printf("%s\n", fortunes[random_index].text);

    return 0;
}