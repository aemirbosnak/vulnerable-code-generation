//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initializing variables
    char name[20];
    int birth_year, ans;
    srand(time(0));
    
    // Welcoming the user
    printf("Hello there! I am the Automated Fortune Teller. What is your name?\n");
    scanf("%s", name);
    printf("\nNice to meet you, %s. What is your birth year?\n", name);
    scanf("%d", &birth_year);
    
    // Generating random number and fortune
    ans = rand() % 5 + 1;
    printf("\nOkay, let me see into the future... ");
    switch(ans) {
        case 1:
            printf("Your future looks bright, %s. You will achieve all your goals.\n", name);
            break;
        case 2:
            printf("You will face some challenges, but ultimately, you will come out on top, %s.\n", name);
            break;
        case 3:
            printf("Beware of new opportunities that may seem too good to be true, %s.\n", name);
            break;
        case 4:
            printf("Your lucky number is 7, %s. Use it wisely.\n", name);
            break;
        case 5:
            printf("Do not take anyone's advice too seriously, %s. Trust your own instincts.\n", name);
            break;
    }
    
    // Determining lucky color based on birth year
    if(birth_year % 5 == 1) {
        printf("Your lucky color is red.\n");
    } else if (birth_year % 5 == 2) {
        printf("Your lucky color is blue.\n");
    } else if (birth_year % 5 == 3) {
        printf("Your lucky color is green.\n");
    } else if (birth_year % 5 == 4) {
        printf("Your lucky color is yellow.\n");
    } else {
        printf("Your lucky color is purple.\n");
    }
    
    // Goodbye message
    printf("Thank you for letting me peek into your future, %s. Good luck!\n", name);
    
    return 0;
}