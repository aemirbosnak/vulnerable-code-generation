//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char name[20], choice[10];
    int age, money = 100, result;

    printf("Welcome to the Cyberpunk Adventure Game.\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello %s, please enter your age: ", name);
    scanf("%d", &age);

    printf("\n\nYou are a hacker in the year 2077.\n");
    printf("You found a job online that pays $5000,\n");
    printf("but it requires you to hack into a famous corporation.\n");
    printf("The job seems too good to be true.\n");
    printf("Do you want to take the job? (yes/no): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        printf("\nYou accepted the job and got the payment.\n");
        money += 5000;
        printf("You currently have $%d.\n", money);

        printf("\nYou decide to spend some money on a high-tech gadget,\n");
        printf("that can hack into any security system.\n");
        printf("The gadget costs $1000, do you want to buy it? (yes/no): ");
        scanf("%s", choice);

        if (strcmp(choice, "yes") == 0) {
            printf("\nYou bought the gadget and now have $%d left.\n", money-1000);
            printf("You feel invincible with your new gadget.\n");
            printf("You decide to use it to hack into the police department.\n");
            printf("You manage to get access to their confidential files,\n");
            printf("and find out that they are after you.\n");
            printf("What do you do? (run/fight): ");
            scanf("%s", choice);

            if (strcmp(choice, "run") == 0) {
                printf("\nYou run away but got chased by several police drones.\n");
                printf("You manage to use your gadget to hack into the drones,\n");
                printf("and crashed them into each other.\n");
                result = 1;
            } else {
                printf("\nYou engage in a fight with the police officers.\n");
                printf("Unfortunately, your gadget malfunctioned and you got caught.\n");
                result = 0;
            }

        } else {
            printf("\nYou decided not to buy the gadget and keep the money.\n");
            printf("You feel confident in your hacking skills,\n");
            printf("so you decide to hack into the corporation without it.\n");
            printf("You succeeded without any problem and got double the payment!\n");
            printf("You currently have $%d.\n", money+10000);
            result = 1;
        }

    } else {
        printf("\nYou declined the job and went to a bar.\n");
        printf("You met a group of hackers who showed you their latest hack.\n");
        printf("They hacked into a bank and stole millions of dollars.\n");
        printf("Do you want to join them? (yes/no): ");
        scanf("%s", choice);

        if (strcmp(choice, "yes") == 0) {
            printf("\nYou joined the group and successfully stole $10 million.\n");
            printf("You currently have $%d, and can live the rest of your life peacefully.\n", money+10000000);
            result = 1;
        } else {
            printf("\nYou declined the offer and went home.\n");
            printf("You watched the news and found out that the corporation you rejected the job from,\n");
            printf("has been exposed for their illegal activities and got shut down.\n");
            printf("You regret not taking the job and missed out on the opportunity to expose them.\n");
            result = 0;
        }
    }

    if (result == 1) {
        printf("\n\nCongratulations %s, you have won the game!\n", name);
    } else {
        printf("\n\nSorry %s, you have lost the game.\n", name);
    }

    return 0;
}