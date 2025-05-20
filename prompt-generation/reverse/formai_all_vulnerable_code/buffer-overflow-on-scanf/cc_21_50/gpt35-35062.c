//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int user_choice;
    printf("Welcome to the automated fortune teller!\n\n");
    
    printf("Please choose a number from the following options:\n");
    printf("1. Love\n");
    printf("2. Career\n");
    printf("3. Health\n");
    printf("4. Finances\n\n");
    
    scanf("%d", &user_choice);
    
    if (user_choice < 1 || user_choice > 4) {
        printf("Invalid choice. Please choose a number between 1 and 4.\n");
        return 1;
    }
    
    srand(time(NULL));
    int random_choice = rand() % 4 + 1;
    
    switch(user_choice) {
        case 1: {
            switch(random_choice) {
                case 1: printf("It looks like your love life will be full of adventure in the coming months!\n"); break;
                case 2: printf("Things may be rocky at first, but true love will prevail.\n"); break;
                case 3: printf("Your next relationship will be with someone who shares similar interests and goals as you.\n"); break;
                case 4: printf("Your romantic life will bring you surprises and excitement, be ready for anything!\n"); break;
            }
            break;
        }
        case 2: {
            switch(random_choice) {
                case 1: printf("Your hard work and dedication will pay off in your career, keep pushing forward!\n"); break;
                case 2: printf("Opportunities are on the horizon, be prepared to take advantage of them.\n"); break;
                case 3: printf("Your leadership skills will be put to the test, but you will come out ahead.\n"); break;
                case 4: printf("Your coworkers and superiors will recognize your contributions, keep up the good work!\n"); break;
            }
            break;
        }
        case 3: {
            switch(random_choice) {
                case 1: printf("It's important to prioritize your health in the coming months, make time for self-care.\n"); break;
                case 2: printf("A new exercise or diet plan will lead to great results, keep going!\n"); break;
                case 3: printf("Listen to your body and take breaks when necessary, your health should always come first.\n"); break;
                case 4: printf("Your positive attitude and determination will lead to a healthy and happy lifestyle.\n"); break;
            }
            break;
        }
        case 4: {
            switch(random_choice) {
                case 1: printf("Your financial situation looks stable and you can expect some extra income in the near future.\n"); break;
                case 2: printf("Beware of overspending and be sure to budget wisely, but don't be afraid to treat yourself every once in a while.\n"); break;
                case 3: printf("Consider new ways to increase your income, like taking on a side job or investing.\n"); break;
                case 4: printf("Your financial success will come from smart investments and decision-making. Trust your instincts!\n"); break;
            }
            break;
        }
    }
    
    printf("\nThank you for using the automated fortune teller!");
    return 0;
}