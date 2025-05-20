//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, n, c, flag;
    char ans;
    float ti, speed;

    do {    
        printf("Welcome to the Linux Typing Speed Test!\n\n");
        printf("Please enter the number of characters you want to type: ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Invalid input! Please enter a positive integer.\n\n");
            continue;
        }

        char input[n+1];
        srand(time(NULL));
        for(i=0; i<n; i++) {
            input[i] = 'a' + rand()%26;
        }
        input[n] = '\0';

        printf("\nType the following without mistakes:\n%s\n\n", input);
        ti = time(NULL);

        char test[n+1];
        scanf("%s", test);
        ti = time(NULL) - ti;
        speed = (float) n*60 / (5*ti);

        flag = 1;
        for(i=0; i<n; i++) {
            if(input[i] != test[i]) {
                flag = 0;
                break;
            }
        }

        if(flag) {
            printf("Congratulations! You typed it correctly.\n");
            printf("Your typing speed is %.2f characters per minute.\n", speed);
        } else {
            printf("Sorry, you made mistakes. Try again.\n");
        }

        printf("\nDo you want to try again? (Y/N): ");
        scanf(" %c", &ans);
    } while(ans == 'Y' || ans == 'y');

    printf("\nThanks for using the Linux Typing Speed Test!\n");
    return 0;
}