//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

struct fortune {
    char text[80];
    int length;
};

struct fortune fortunes[MAX_FORTUNES] = {
    {"The future is uncertain, but your path will become clear. ", 60},
    {"You will find success in unexpected places. ", 50},
    {"A new opportunity awaits you, seize it with both hands. ", 70},
    {"Your hard work will pay off soon, keep pushing forward. ", 80},
    {"Someone close to you needs your help, be there for them. ", 90},
    {"A change is coming, embrace it with an open mind. ", 60},
    {"Trust your instincts, they will guide you to the right decision. ", 70},
    {"Believe in yourself and your abilities, you are capable of great things. ", 80},
    {"Take a chance, sometimes the biggest risks lead to the greatest rewards. ", 90},
    {"Don't be afraid to ask for help when you need it, strength comes from vulnerability. ", 100}
};

void print_fortune(struct fortune *fortune) {
    printf("%s\n", fortune->text);
}

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
            printf("Your love life is about to take an exciting turn.\n");
            break;
        case 2:
            printf("Financial abundance is on its way to you.\n");
            break;
        case 3:
            printf("Success in your career is within reach.\n");
            break;
        case 4:
            printf("Your health will improve greatly in the near future.\n");
            break;
        case 5:
            printf("A new opportunity will present itself to you soon.\n");
            break;
        default:
            printf("I'm sorry, I cannot predict that kind of fortune.\n");
            return 1;
    }

    int fortune_index = rand() % MAX_FORTUNES;
    print_fortune(&fortunes[fortune_index]);

    return 0;
}