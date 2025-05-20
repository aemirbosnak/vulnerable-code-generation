//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will predict your future in matters of the heart.\n");
    printf("Please choose an option:\n");
    printf("1. Love Life Overview\n");
    printf("2. Compatibility Test\n");
    printf("3. Future Predictions\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("For your love life overview, I need to know your current relationship status.\n");
            printf("1. Single\n");
            printf("2. In a relationship\n");
            int status;
            scanf("%d", &status);

            if(status == 1) {
                printf("As a single person, your love life is full of possibilities.\n");
                printf("You may meet someone special soon, so keep your heart open.\n");
            } else {
                printf("Being in a relationship, your love life is stable.\n");
                printf("However, remember to keep the romance alive with small gestures.\n");
            }
            break;

        case 2:
            printf("For the compatibility test, I need to know your zodiac sign and your partner's zodiac sign.\n");
            char yourSign;
            char partnerSign;

            printf("Enter your zodiac sign (e.g. Aries): ");
            scanf(" %c", &yourSign);

            printf("Enter your partner's zodiac sign (e.g. Taurus): ");
            scanf(" %c", &partnerSign);

            if(yourSign == 'A' && partnerSign == 'T') {
                printf("Aries and Taurus are a great match!\n");
                printf("You balance each other out and have a deep connection.\n");
            } else if(yourSign == 'G' && partnerSign == 'L') {
                printf("Gemini and Leo are a passionate pair!\n");
                printf("You have a strong physical attraction and share similar interests.\n");
            } else {
                printf("I'm sorry, as an AI language model, I do not have knowledge of all zodiac signs.\n");
            }
            break;

        case 3:
            printf("For future predictions, I need to know your birth date.\n");
            int day, month, year;
            printf("Enter your birth date (DD/MM/YYYY): ");
            scanf("%d/%d/%d", &day, &month, &year);

            if(month == 2 && day == 14) {
                printf("Your future is full of love and romance.\n");
                printf("You may find your soulmate soon or strengthen your current relationship.\n");
            } else {
                printf("I'm sorry, as an AI language model, I cannot predict the future with certainty.\n");
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}