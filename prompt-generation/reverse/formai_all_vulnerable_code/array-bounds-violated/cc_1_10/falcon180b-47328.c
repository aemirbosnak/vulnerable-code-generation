//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *text;
    int weight;
} Fortune;

Fortune fortunes[] = {
    {"You will find love in unexpected places. ", 10},
    {"A financial windfall is coming your way. ", 20},
    {"Your hard work will soon pay off. ", 30},
    {"Travel is in your future. ", 40},
    {"A new opportunity will present itself to you. ", 50},
    {"You will experience a period of great creativity. ", 60},
    {"A friend will offer you valuable advice. ", 70},
    {"You will overcome a challenge that has been bothering you. ", 80},
    {"Someone from your past will reenter your life. ", 90},
    {"You will receive a surprise gift. ", 100}
};

int main() {
    srand(time(NULL));
    int numFortunes = sizeof(fortunes) / sizeof(Fortune);
    int fortuneIndex;
    char choice;
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("How many fortunes would you like to hear? ");
    scanf("%d", &numFortunes);
    
    for (int i = 0; i < numFortunes; i++) {
        fortuneIndex = rand() % numFortunes;
        printf("\n%s\n", fortunes[fortuneIndex].text);
    }
    
    printf("\nWould you like to hear another fortune? (y/n) ");
    scanf(" %c", &choice);
    
    while (choice == 'y' || choice == 'Y') {
        fortuneIndex = rand() % numFortunes;
        printf("\n%s\n", fortunes[fortuneIndex].text);
        
        printf("\nWould you like to hear another fortune? (y/n) ");
        scanf(" %c", &choice);
    }
    
    return 0;
}