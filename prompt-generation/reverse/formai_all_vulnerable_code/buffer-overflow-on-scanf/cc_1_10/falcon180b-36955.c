//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} fortune;

fortune fortunes[MAX_FORTUNES] = {
    {"You will have a long and prosperous life."},
    {"A great adventure awaits you in the future."},
    {"You will find true love and happiness."},
    {"Your hard work will pay off soon."},
    {"A new opportunity will present itself to you."},
    {"You will overcome any obstacle in your path."},
    {"Success is within your reach."},
    {"Your dreams will come true."},
    {"A pleasant surprise is on the horizon."},
    {"You will experience good health and well-being."}
};

void generate_fortune() {
    srand(time(NULL));
    int index = rand() % MAX_FORTUNES;
    printf("%s\n", fortunes[index].text);
}

int main() {
    int choice;

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Press 1 to generate a fortune.\n");
        printf("Press 2 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                generate_fortune();
                break;
            case 2:
                printf("Thank you for using the Automated Fortune Teller!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 2);

    return 0;
}