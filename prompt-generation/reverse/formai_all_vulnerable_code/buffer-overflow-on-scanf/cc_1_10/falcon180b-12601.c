//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];
    int age;
    int lucky_number;
    int future_partner_initial;
    int num_kids;
    char partner_name[20];
    int partner_age;
    char kids_name[20][20];
    int i;

    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);
    printf("Hello, %s! I'm here to tell you your fortune.\n", name);
    printf("What would you like to know?\n");
    printf("1. Your lucky number\n");
    printf("2. Your future partner's initial\n");
    printf("3. How many kids you'll have\n");
    printf("4. Your future partner's name\n");
    printf("5. Your future partner's age\n");
    printf("6. Your kids' names\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            lucky_number = rand() % 100;
            printf("Your lucky number is %d!\n", lucky_number);
            break;
        case 2:
            future_partner_initial = rand() % 26 + 'A';
            printf("Your future partner's initial is %c!\n", future_partner_initial);
            break;
        case 3:
            num_kids = rand() % 5 + 1;
            printf("You'll have %d kids!\n", num_kids);
            break;
        case 4:
            for(i = 0; i < 20; i++) {
                partner_name[i] = rand() % 26 + 'A';
            }
            partner_name[i] = '\0';
            printf("Your future partner's name is %s!\n", partner_name);
            break;
        case 5:
            partner_age = rand() % 50 + 20;
            printf("Your future partner is %d years old!\n", partner_age);
            break;
        case 6:
            for(i = 0; i < num_kids; i++) {
                kids_name[i][0] = rand() % 26 + 'A';
            }
            kids_name[i][0] = '\0';
            printf("Your kids' names are:\n");
            for(i = 0; i < num_kids; i++) {
                printf("%s\n", kids_name[i]);
            }
            break;
        default:
            printf("Sorry, I can't predict that.\n");
    }

    return 0;
}