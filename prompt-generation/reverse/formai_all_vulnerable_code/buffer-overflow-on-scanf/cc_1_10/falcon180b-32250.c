//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune() {
    int random = rand() % 7;
    switch(random) {
        case 0:
            printf("Your future is bright and full of potential.\n");
            break;
        case 1:
            printf("You will find success in your endeavors.\n");
            break;
        case 2:
            printf("Love is in your future.\n");
            break;
        case 3:
            printf("You will face challenges, but you will overcome them.\n");
            break;
        case 4:
            printf("Financial stability is within your reach.\n");
            break;
        case 5:
            printf("You will experience unexpected changes.\n");
            break;
        case 6:
            printf("Your hard work will pay off.\n");
            break;
        default:
            printf("I'm sorry, I cannot predict your future.\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    int choice;
    while(1) {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            fortune();
        } else if(choice == 2) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}