//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80

typedef struct {
    char text[MAX_LENGTH];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet your soulmate in a coffee shop. "},
    {"Your love life will be full of surprises. "},
    {"You will have a romantic getaway with your partner. "},
    {"Your crush will confess their feelings for you. "},
    {"You will experience a deep connection with someone special. "},
    {"You will receive a heartfelt love letter. "},
    {"You will have a passionate encounter with your significant other. "},
    {"You will feel butterflies in your stomach around someone new. "},
    {"You will have a beautiful wedding with your true love. "},
    {"You will rekindle a past romance. "}
};

void generate_random_number(int *number) {
    *number = rand() % MAX_FORTUNES;
}

void print_fortune(Fortune fortune) {
    printf("%s\n", fortune.text);
}

int main() {
    srand(time(NULL));

    int choice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will provide you with a romantic fortune.\n");
    printf("Press 1 to generate a fortune or 0 to exit.\n");
    scanf("%d", &choice);

    while (choice!= 0) {
        generate_random_number(&choice);
        print_fortune(fortunes[choice]);
        printf("\n");
        printf("Press any key to continue...\n");
        getchar();
        system("clear");
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("I will provide you with a romantic fortune.\n");
        printf("Press 1 to generate a fortune or 0 to exit.\n");
        scanf("%d", &choice);
    }

    return 0;
}