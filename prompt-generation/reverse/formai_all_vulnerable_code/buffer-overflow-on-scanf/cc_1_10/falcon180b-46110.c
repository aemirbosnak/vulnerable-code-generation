//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LEN 80

typedef struct {
    char text[MAX_FORTUNE_LEN];
    int len;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will find happiness in unexpected places."},
    {"A new opportunity will present itself to you soon."},
    {"You will receive good news from a loved one."},
    {"Your hard work will pay off in the near future."},
    {"You will overcome a challenge and come out stronger."},
    {"A kind gesture from a stranger will brighten your day."},
    {"You will be presented with a unique opportunity for growth."},
    {"Your creativity will be recognized and appreciated."},
    {"You will experience a moment of clarity and understanding."},
    {"A past mistake will be forgiven and forgotten."}
};

int numFortunes = sizeof(fortunes) / sizeof(Fortune);

void printFortune(Fortune fortune) {
    printf("%s\n", fortune.text);
}

int main() {
    srand(time(NULL));

    int choice;
    char input[MAX_FORTUNE_LEN];

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Add a fortune\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Your fortune is:\n");
                int fortuneIndex = rand() % numFortunes;
                printFortune(fortunes[fortuneIndex]);
                break;

            case 2:
                printf("Enter your fortune (max %d characters):\n", MAX_FORTUNE_LEN - 1);
                scanf("%s", input);

                if(strlen(input) > MAX_FORTUNE_LEN - 1) {
                    printf("Fortune is too long. Please try again.\n");
                } else {
                    int i;
                    for(i = 0; i < numFortunes; i++) {
                        if(strcmp(fortunes[i].text, input) == 0) {
                            printf("That fortune already exists.\n");
                            break;
                        }
                    }

                    if(i == numFortunes) {
                        printf("Fortune added successfully!\n");
                        strcpy(fortunes[numFortunes - 1].text, input);
                        numFortunes++;
                    }
                }
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 3);

    return 0;
}