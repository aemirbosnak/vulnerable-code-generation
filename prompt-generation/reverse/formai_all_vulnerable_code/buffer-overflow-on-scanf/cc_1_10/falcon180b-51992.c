//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int romeoHealth = 100;
    int julietHealth = 100;

    printf("Welcome to Romeo and Juliet: The Game!\n");
    printf("You are Romeo. Your Health: %d\n", romeoHealth);
    printf("Juliet's Health: %d\n", julietHealth);

    while(1) {
        system("clear");
        printf("What would you like to do?\n");
        printf("1. Attack Juliet\n");
        printf("2. Defend\n");
        printf("3. Use a Health Potion\n");
        printf("4. Check Health\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                romeoHealth -= 10;
                julietHealth -= rand() % 21 + 10;
                printf("You attacked Juliet! Your Health: %d\n", romeoHealth);
                printf("Juliet's Health: %d\n", julietHealth);
                break;
            case 2:
                romeoHealth -= 5;
                printf("You defended yourself!\n");
                break;
            case 3:
                romeoHealth += rand() % 21 + 10;
                printf("You used a Health Potion! Your Health: %d\n", romeoHealth);
                break;
            case 4:
                printf("Your Health: %d\n", romeoHealth);
                printf("Juliet's Health: %d\n", julietHealth);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }

        if(romeoHealth <= 0) {
            printf("You have died. Game Over.\n");
            exit(0);
        } else if(julietHealth <= 0) {
            printf("Juliet has died. You win!\n");
            exit(0);
        }
    }

    return 0;
}