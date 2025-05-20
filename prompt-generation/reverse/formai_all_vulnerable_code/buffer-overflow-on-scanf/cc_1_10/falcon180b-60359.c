//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will have good luck today!"},
    {"Your future is bright and full of possibilities."},
    {"A new opportunity will present itself to you soon."},
    {"You will find happiness in unexpected places."},
    {"Success is within your reach, keep working hard!"},
    {"Your dreams will come true if you believe in them."},
    {"Don't give up, better days are ahead."},
    {"You are capable of achieving great things."},
    {"Trust your instincts and follow your heart."},
    {"Believe in yourself and all that you are."}
};

int main() {
    srand(time(NULL));

    int choice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What kind of fortune would you like?\n");
    printf("1. Love\n");
    printf("2. Money\n");
    printf("3. Career\n");
    printf("4. Health\n");
    printf("5. General\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Your love life will be filled with passion and romance.\n");
            break;
        case 2:
            printf("Wealth and prosperity are in your future.\n");
            break;
        case 3:
            printf("Success and advancement await you in your career.\n");
            break;
        case 4:
            printf("You will enjoy good health and vitality.\n");
            break;
        case 5:
            printf("You will have a positive and fulfilling life.\n");
            break;
        default:
            printf("Sorry, I cannot predict that kind of fortune.\n");
            break;
    }

    return 0;
}