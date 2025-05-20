//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int num;
    char ans;

    printf("*** Welcome to the Amazing Fortune Teller ***\n");
    printf("I have the power to predict your future!\n");

    do {
        printf("\nThink of a question and I'll give you the answer.\n");
        printf("Enter any number between 1 and 6: ");
        scanf("%d", &num);

        switch(num) {
            case 1:
                printf("\nYour future looks bright!\n");
                break;
            case 2:
                printf("\nHmm... I sense some challenges ahead.\n");
                break;
            case 3:
                printf("\nYou will meet someone special soon.\n");
                break;
            case 4:
                printf("\nBe careful of those around you, they may not have good intentions.\n");
                break;
            case 5:
                printf("\nYour hard work will pay off soon.\n");
                break;
            case 6:
                printf("\nA big change is coming your way!\n");
                break;
            default:
                printf("\nInvalid input.\n");
                break;
        }

        printf("\nWould you like another prediction? (y/n): ");
        scanf(" %c", &ans);
        ans = tolower(ans);

    } while(ans == 'y');

    printf("\nThank you for using the Amazing Fortune Teller!\n");

    return 0;
}