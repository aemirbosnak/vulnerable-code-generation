//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80

typedef struct {
    char text[MAX_LENGTH];
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet a tall, dark stranger. ", 34},
    {"A long-lost friend will return to your life. ", 37},
    {"You will find unexpected happiness in the near future. ", 47},
    {"A financial windfall is coming your way. ", 28},
    {"Your hard work will pay off soon. ", 27},
    {"You will receive good news from a loved one. ", 35},
    {"A new opportunity will present itself to you. ", 39},
    {"You will overcome a challenge that has been troubling you. ", 51},
    {"Your creativity will be unleashed in a new project. ", 42},
    {"You will experience a moment of clarity that will change your life. ", 56}
};

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_LENGTH];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("Hello, %s! I am here to tell you your fortune.\n", input);

    while(1) {
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            int index = rand() % MAX_FORTUNES;
            printf("\nYour fortune is:\n%s\n", fortunes[index].text);
        } else if(choice == 2) {
            printf("Thank you for using the Automated Fortune Teller! Goodbye, %s!\n", input);
            return 0;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}