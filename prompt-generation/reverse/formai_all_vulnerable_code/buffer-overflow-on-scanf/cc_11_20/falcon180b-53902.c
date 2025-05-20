//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    while (1) {
        printf("\n%s, ask me something and I shall reveal your future!\n", name);
        printf("1. Love life\n2. Career\n3. Health\n4. Wealth\n5. Family\n6. Travel\n7. Education\n8. Luck\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nIn matters of love, %s, you will find happiness soon.\n", name);
                break;
            case 2:
                printf("\nYour career will take off like a rocket, %s!\n", name);
                break;
            case 3:
                printf("\nGood health awaits you, %s.\n", name);
                break;
            case 4:
                printf("\nWealth is in your future, %s.\n", name);
                break;
            case 5:
                printf("\nYour family will bring you great joy, %s.\n", name);
                break;
            case 6:
                printf("\nAdventure awaits you on your travels, %s.\n", name);
                break;
            case 7:
                printf("\nSuccess in education is yours, %s.\n", name);
                break;
            case 8:
                printf("\nLady Luck smiles upon you, %s.\n", name);
                break;
            default:
                printf("\nSorry, %s, I cannot predict that.\n", name);
        }
        printf("\nDo you want to ask another question? (y/n): ");
        char answer;
        scanf("%c", &answer);
        if (answer == 'n') {
            printf("\nThank you for using the Automated Fortune Teller, %s!\n", name);
            break;
        }
    }
    return 0;
}