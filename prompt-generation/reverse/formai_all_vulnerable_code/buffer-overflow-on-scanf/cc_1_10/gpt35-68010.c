//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char choice[80];
    printf("Welcome to Romeo and Juliet: Text-Based Adventure Game\n");
    printf("You are Romeo, the son of Montague, and you are in love with Juliet, the daughter of your family's sworn enemy, the Capulets.\n");
    printf("You have a letter from Juliet inviting you to meet her in secret.\n");
    printf("Do you accept the invitation? (Yes/No)\n");
    scanf("%s", choice);

    if (strcmp(choice, "Yes") == 0) {
        printf("You arrive at the secret meeting place, but before you can see Juliet, you are confronted by Tybalt, Juliet's cousin and a Capulet.\n");
        printf("He challenges you to a duel. What do you do? (Fight/Run)\n");
        scanf("%s", choice);

        if (strcmp(choice, "Fight") == 0) {
            printf("You and Tybalt draw your swords and begin to fight. The fight is intense, but you manage to defeat Tybalt.\n");
            printf("As you stand over the lifeless body of Tybalt, you hear the approach of the Prince and the guards. You know you must run.\n");
            printf("You run to the church to see Friar Lawrence, hoping he can help you and Juliet.\n");
            printf("Do you tell him the truth about killing Tybalt? (Yes/No)\n");
            scanf("%s", choice);

            if (strcmp(choice, "Yes") == 0) {
                printf("You confess to Friar Lawrence that you killed Tybalt in self-defense. He helps you and Juliet to devise a plan to escape Verona.\n");
                printf("You and Juliet are married in secret, and you plan to leave Verona the next day.\n");
                printf("But as you are leaving, you encounter one final obstacle – the Capulet and Montague families, who have come to a truce in light of the tragic events.\n");
                printf("What do you do? (Stay/Leave)\n");
                scanf("%s", choice);

                if (strcmp(choice, "Stay") == 0) {
                    printf("You and Juliet choose to stay and try to make peace between the families. Your love story inspires both the Capulets and the Montagues to end their feud and live in peace.\n");
                    printf("Congratulations! You have successfully completed the game!\n");
                    return 0;
                } else {
                    printf("You and Juliet leave Verona and start a new life together. You are happy, but you both know you can never return to Verona.\n");
                    printf("Congratulations! You have successfully completed the game!\n");
                    return 0;
                }
            } else {
                printf("You lie to Friar Lawrence about killing Tybalt, but he can see through your lies. He helps you and Juliet to devise a plan to fake Juliet's death and escape Verona.\n");
                printf("The plan goes awry, and both you and Juliet end up taking your own lives, unable to live without each other.\n");
                printf("Sorry, you have lost the game. Better luck next time!\n");
                return 0;
            }
        } else {
            printf("You choose to run from Tybalt. However, he catches up to you and kills you.\n");
            printf("Sorry, you have lost the game. Better luck next time!\n");
            return 0;
        }
    } else {
        printf("You choose not to accept Juliet's invitation. However, you cannot stop thinking about her and decide to visit her anyway.\n");
        printf("As you try to climb the wall to her balcony, you fall and injure yourself. The guards catch you and take you to the Prince.\n");
        printf("The Prince orders you to leave Verona and never return.\n");
        printf("Sorry, you have lost the game. Better luck next time!\n");
        return 0;
    }
}