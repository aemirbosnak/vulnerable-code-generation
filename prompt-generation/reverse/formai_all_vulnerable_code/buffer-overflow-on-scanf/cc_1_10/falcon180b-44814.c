//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_fortune() {
    int fortune_number = rand() % 12;
    switch(fortune_number) {
        case 0:
            printf("You will have a great day today!\n");
            break;
        case 1:
            printf("Success is just around the corner.\n");
            break;
        case 2:
            printf("You will meet someone special soon.\n");
            break;
        case 3:
            printf("Your hard work will pay off.\n");
            break;
        case 4:
            printf("You will receive unexpected good news.\n");
            break;
        case 5:
            printf("You will have a romantic encounter.\n");
            break;
        case 6:
            printf("You will find something you lost.\n");
            break;
        case 7:
            printf("You will overcome a challenge.\n");
            break;
        case 8:
            printf("You will experience a new adventure.\n");
            break;
        case 9:
            printf("You will receive a gift.\n");
            break;
        case 10:
            printf("You will have a pleasant surprise.\n");
            break;
        case 11:
            printf("You will achieve a personal goal.\n");
            break;
        default:
            printf("Sorry, no fortune for you today.\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    int user_choice;
    while(1) {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &user_choice);
        if(user_choice == 1) {
            generate_fortune();
        } else if(user_choice == 2) {
            printf("Thank you for using the Automated Fortune Teller!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}