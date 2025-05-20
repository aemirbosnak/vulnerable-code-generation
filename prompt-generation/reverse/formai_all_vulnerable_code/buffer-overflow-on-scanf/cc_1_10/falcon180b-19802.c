//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 50
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet someone special today. ", 33},
    {"A financial opportunity is coming your way. ", 38},
    {"Travel is in your future. ", 20},
    {"Your hard work will pay off soon. ", 30},
    {"A new friendship will blossom. ", 28},
    {"You will receive good news. ", 22},
    {"Love is on the horizon. ", 18},
    {"Success is within reach. ", 25},
    {"A surprise awaits you. ", 20},
    {"Your dreams will come true. ", 24}
};

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_FORTUNE_LENGTH];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("Hello, %s! I am here to tell you your fortune.\n", input);

    while(1) {
        printf("What would you like to know? (1. Love, 2. Money, 3. Travel, 4. Career, 5. Health)\n");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 5) {
            int index = rand() % MAX_FORTUNES;
            printf("\n%s\n", fortunes[index].text);
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("Would you like to ask another question? (y/n)\n");
        scanf(" %c", &input[0]);
        if(tolower(input[0]) == 'n') {
            break;
        }
    }

    printf("\nThank you for using the Automated Fortune Teller, %s!\n", input);
    return 0;
}