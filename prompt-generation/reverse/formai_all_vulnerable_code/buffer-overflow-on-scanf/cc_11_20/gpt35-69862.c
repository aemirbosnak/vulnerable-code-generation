//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <time.h>

int main() {

    char fortune1[100] = "You will soon embark on an exciting adventure!";
    char fortune2[100] = "Your future is looking bright with endless possibilities!";
    char fortune3[100] = "A new opportunity will present itself to you in the near future!";
    char fortune4[100] = "You will need to make an important decision soon, choose wisely!";
    char fortune5[100] = "Your hard work will pay off in the end and lead to great success!";
    char fortune6[100] = "Your intuition will guide you towards great things!";
    char fortune7[100] = "Take a chance and step outside your comfort zone, great things await you!";
    char fortune8[100] = "Your kindness and generosity will come back to you tenfold!";
    char fortune9[100] = "Your positive attitude will attract great opportunities!";
    char fortune10[100] = "You have the ability to overcome any obstacle that comes your way!";
   
    int num;
    printf("Welcome to the Automated Fortune Teller! \n");
    printf("Please choose a number between 1 and 10: ");
    scanf("%d", &num);
   
    srand(time(NULL)); //generates a different random number each time the program is run
   
    switch(num) {
        case 1:
            printf("Your fortune is: %s\n", fortune1);
            break;
        case 2:
            printf("Your fortune is: %s\n", fortune2);
            break;
        case 3:
            printf("Your fortune is: %s\n", fortune3);
            break;
        case 4:
            printf("Your fortune is: %s\n", fortune4);
            break;
        case 5:
            printf("Your fortune is: %s\n", fortune5);
            break;
        case 6:
            printf("Your fortune is: %s\n", fortune6);
            break;
        case 7:
            printf("Your fortune is: %s\n", fortune7);
            break;
        case 8:
            printf("Your fortune is: %s\n", fortune8);
            break;
        case 9:
            printf("Your fortune is: %s\n", fortune9);
            break;
        case 10:
            printf("Your fortune is: %s\n", fortune10);
            break;
        default:
            printf("That is an invalid input. Please choose a number between 1-10.\n");
            break;
    }
   
    return 0;
}