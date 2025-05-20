//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 50
#define MAX_LENGTH 80

// Fortune structure
typedef struct {
    char text[MAX_LENGTH];
    char category[MAX_LENGTH];
} Fortune;

// Function prototypes
void generateFortune(Fortune* fortune);
void printFortune(Fortune* fortune);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the fortune
    Fortune fortune = { 0 };

    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateFortune(&fortune);
                printFortune(&fortune);
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 2);

    return 0;
}

// Generates a random fortune
void generateFortune(Fortune* fortune) {
    const char* categories[] = {
        "Love",
        "Money",
        "Health",
        "Career",
        "Travel"
    };

    const char* fortunes[] = {
        "You will find true love in the most unexpected place.",
        "A financial windfall is headed your way.",
        "Your health will improve greatly in the coming days.",
        "A promotion or new job opportunity is on the horizon.",
        "An exciting adventure awaits you in the near future."
    };

    fortune->category[0] = '\0';
    fortune->text[0] = '\0';

    int categoryIndex = rand() % (sizeof(categories) / sizeof(categories[0]));
    strcpy(fortune->category, categories[categoryIndex]);

    int fortuneIndex = rand() % (sizeof(fortunes) / sizeof(fortunes[0]));
    strcat(fortune->text, fortunes[fortuneIndex]);
    strcat(fortune->text, " ");
    strcat(fortune->text, categories[categoryIndex]);
}

// Prints the fortune
void printFortune(Fortune* fortune) {
    printf("Your fortune:\n");
    printf("%s\n", fortune->text);
}