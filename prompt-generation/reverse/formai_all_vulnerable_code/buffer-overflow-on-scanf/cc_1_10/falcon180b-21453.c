//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
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
    {"The future is uncertain, but you'll make it through. ", 46},
    {"You will soon receive good news from an unexpected source. ", 56},
    {"Success is within your reach, but you must be patient. ", 58},
    {"A new opportunity will present itself to you. ", 45},
    {"You will overcome any obstacles in your path. ", 48},
    {"You will find happiness in unexpected places. ", 49},
    {"Your hard work will pay off in the end. ", 41},
    {"You are capable of achieving great things. ", 42},
    {"Believe in yourself and you will succeed. ", 40},
    {"Your future is bright and full of possibilities. ", 52}
};

void generateFortune(char* fortuneText) {
    int i = rand() % MAX_FORTUNES;
    strcpy(fortuneText, fortunes[i].text);
}

int main() {
    char name[MAX_LENGTH];
    printf("What is your name? ");
    scanf("%s", name);

    printf("\nHello, %s! I am the Automated Fortune Teller.\n", name);

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);

    if (tm->tm_hour >= 18 || tm->tm_hour < 6) {
        printf("\nIt is late at night/early in the morning. Let me tell you your fortune.\n");
    } else {
        printf("\nIt is daytime. Let me tell you your fortune.\n");
    }

    char fortuneText[MAX_LENGTH];
    generateFortune(fortuneText);

    printf("\n%s\n", fortuneText);

    return 0;
}