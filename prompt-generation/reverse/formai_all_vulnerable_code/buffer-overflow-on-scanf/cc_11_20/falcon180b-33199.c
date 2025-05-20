//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];
    char question[50];
    int random_number;
    char fortune[100];
    char *fortunes[] = {
        "You will have a lucky day today.",
        "A new opportunity is coming your way.",
        "Your hard work will pay off soon.",
        "You will receive good news in the near future.",
        "Someone close to you will surprise you with a gift.",
        "Your love life will take a positive turn.",
        "You will make a new friend in the coming days.",
        "You will find something you thought was lost.",
        "Your financial situation will improve.",
        "You will have a successful trip or journey."
    };

    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller!\n\n");

    printf("Enter your name: ");
    scanf("%s", name);

    printf("\n%s, ask me a question and I will give you a fortune.\n\n", name);
    printf("1. What does the future hold for me?\n");
    printf("2. Will I find love soon?\n");
    printf("3. Will I be successful in my career?\n");
    printf("4. Will I have good luck today?\n");
    printf("5. Will I have a happy family life?\n");
    printf("6. Will I travel to new places?\n");
    printf("7. Will I have good health?\n");
    printf("8. Will I make new friends?\n");
    printf("9. Will I overcome my fears?\n");
    printf("10. Will I achieve my dreams?\n\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("The future holds many surprises for you, %s.\n", name);
            break;
        case 2:
            printf("Love is on the horizon for you, %s.\n", name);
            break;
        case 3:
            printf("Success is within your reach, %s.\n", name);
            break;
        case 4:
            printf("Good luck is coming your way, %s.\n", name);
            break;
        case 5:
            printf("Your family life will be filled with happiness, %s.\n", name);
            break;
        case 6:
            printf("You will travel to new and exciting places, %s.\n", name);
            break;
        case 7:
            printf("Your health will remain strong, %s.\n", name);
            break;
        case 8:
            printf("You will make new and lasting friendships, %s.\n", name);
            break;
        case 9:
            printf("You will conquer your fears and become stronger, %s.\n", name);
            break;
        case 10:
            printf("Your dreams will become a reality, %s.\n", name);
            break;
        default:
            printf("I'm sorry, %s, I cannot predict your future.\n", name);
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}