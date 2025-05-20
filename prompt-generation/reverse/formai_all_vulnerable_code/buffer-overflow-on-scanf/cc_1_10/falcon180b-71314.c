//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    char future[100];
    char choice;
    int age;
    int lucky_number;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Hello, %s! I am the Automated Fortune Teller, and I am here to tell you your future.\n", name);

    while(1) {
        printf("\nWhat would you like to know about your future?\n");
        printf("1. Career\n2. Love life\n3. Health\n4. Wealth\n5. Travel\n");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("\nYour career is looking bright! You will soon receive a promotion or a new job offer.\n");
                break;
            case '2':
                printf("\nYour love life is about to take an exciting turn. Keep your eyes open for a new romantic partner.\n");
                break;
            case '3':
                printf("\nYour health will remain stable, but it is important to continue taking care of yourself.\n");
                break;
            case '4':
                printf("\nYour wealth will increase, but it is important to be wise with your finances.\n");
                break;
            case '5':
                printf("\nYou will have the opportunity to travel to a new and exciting destination.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        printf("\nWould you like to ask another question? (y/n): ");
        scanf(" %c", &choice);

        if(choice == 'n') {
            break;
        }
    }

    printf("\nThank you for using the Automated Fortune Teller! Have a great day, %s!\n", name);
    return 0;
}