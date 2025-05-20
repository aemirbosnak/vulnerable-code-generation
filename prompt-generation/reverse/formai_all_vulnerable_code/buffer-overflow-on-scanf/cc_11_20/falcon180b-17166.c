//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, rand_num;
    char name[20];
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    srand(time(0));
    rand_num = rand() % 10;
    
    switch(rand_num) {
        case 0:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will have a day filled with happiness and joy.\n");
            break;
        case 1:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will encounter an old friend today.\n");
            break;
        case 2:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will receive good news from a loved one.\n");
            break;
        case 3:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will have a successful day at work.\n");
            break;
        case 4:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will find something you have been looking for.\n");
            break;
        case 5:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will have a peaceful and relaxing day.\n");
            break;
        case 6:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will be faced with a difficult decision.\n");
            break;
        case 7:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will have a surprise encounter with someone.\n");
            break;
        case 8:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will have a productive day and accomplish much.\n");
            break;
        case 9:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("You will have a day filled with love and romance.\n");
            break;
        default:
            printf("\n%s, your fortune is as follows:\n", name);
            printf("Your day will be filled with unexpected surprises.\n");
            break;
    }
    return 0;
}