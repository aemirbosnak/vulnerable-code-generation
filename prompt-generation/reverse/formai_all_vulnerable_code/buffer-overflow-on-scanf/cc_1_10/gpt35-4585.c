//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void intro();
void partOne();
void partTwo();
void partThree();
void partFour();
void partFive();
void partSix();
void gameOver();

// Global variables
char playerName[20];
int health = 100;
int potionCount = 3;

int main()
{
    intro();
    partOne();
    partTwo();
    partThree();
    partFour();
    partFive();
    partSix();
    gameOver();

    return 0;
}

void intro()
{
    printf("Welcome to Romeo and Juliet Adventure Game!\n\n");
    printf("Enter your name: ");
    scanf("%s", playerName);
    printf("\nHello %s, you are about to embark on a dangerous journey!\n\n", playerName);
    printf("You are playing the role of Romeo, a young man from the Montague family who is deeply in love with Juliet, a beautiful young woman from the Capulet family.\n\n");
    printf("Your goal is to find a way to be with Juliet, despite the ongoing feud between the two families.\n\n");
    printf("Good luck, %s!\n\n", playerName);
}

void partOne()
{
    char choice;
    printf("PART ONE: A Night Time Rendezvous\n\n");
    printf("You sneak into the Capulet's garden at night to meet Juliet. You see her waiting for you beneath her balcony. What do you do?\n\n");
    printf("A) Whisper to Juliet that you love her in a soft voice.\n");
    printf("B) Climb up to the balcony and declare your love loudly.\n");
    printf("C) Wait and observe Juliet from a hidden spot.\n");
    printf("Enter your choice (A/B/C): ");
    scanf(" %c", &choice);
    switch (choice) {
        case 'A':
            printf("\nYou whisper to Juliet that you love her in a soft voice. She blushes and tells you that she loves you too. You both promise to find a way to be together despite the feud between the Montagues and Capulets.\n\n");
            break;
        case 'B':
            printf("\nYou climb up to the balcony and declare your love loudly. Suddenly, two Capulet guards appear from behind the bushes and attempt to catch you. You have a choice to either fight or flee. Choose wisely.\n\n");
            printf("A) Fight the guards.\n");
            printf("B) Flee and hide in the garden.\n");
            printf("Enter your choice (A/B): ");
            scanf(" %c", &choice);
            if (choice == 'A') {
                printf("\nYou fight the guards bravely, but they overpower you and leave you wounded. You manage to escape, but you lose 30 health points.\n\n");
                health -= 30;
            } else {
                printf("\nYou manage to escape from the guards by hiding in the garden. You wait for some time and then safely leave the garden.\n\n");
            }
            break;
        case 'C':
            printf("\nYou wait and observe Juliet from a hidden spot. Suddenly, two Capulet guards appear from behind the bushes and start patrolling the area. You have a choice to either wait or sneak past them. Choose wisely.\n\n");
            printf("A) Wait for the guards to leave.\n");
            printf("B) Sneak past the guards.\n");
            printf("Enter your choice (A/B): ");
            scanf(" %c", &choice);
            if (choice == 'A') {
                printf("\nYou wait for a while, but the guards seem to be in no hurry to leave. You decide to sneak past them instead. You manage to sneak past the guards and meet Juliet beneath her balcony.\n\n");
            } else {
                printf("\nYou attempt to sneak past the guards, but they catch you and leave you wounded. You manage to escape, but you lose 20 health points.\n\n");
                health -= 20;
            }
            break;
        default:
            printf("\nInvalid choice. Please enter A, B or C.\n\n");
            partOne();
            return;
    }
}

void partTwo() {
    char choice;
    printf("PART TWO: A Secret Marriage\n\n");
    printf("You and Juliet decide to get married in secret. You approach Friar Laurence, a Franciscan monk, and ask him to marry you both. He agrees to help you, but warns you that this decision might have dire consequences.\n\n");
    printf("A) Go ahead with the marriage.\n");
    printf("B) Think twice and reconsider the decision.\n");
    printf("Enter your choice (A/B): ");
    scanf(" %c", &choice);
    if (choice == 'B') {
        printf("\nYou reconsider the decision and decide to take some time to think it over. You visit Friar Laurence again later and tell him that you have changed your mind. He advices you to work towards ending the feud between the Montagues and Capulets peacefully so that you can be with Juliet legally and safely.\n\n");
        return;
    } else if (choice != 'A') {
        printf("\nInvalid choice. Please enter A or B.\n\n");
        partTwo();
        return;
    }
    printf("\nYou go ahead with the marriage. Friar Laurence marries you and Juliet in secret. Just as you are about to leave, Juliet's cousin Tybalt spots you and challenges you to a duel. You have a choice to either fight or flee. Choose wisely.\n\n");
    printf("A) Fight Tybalt.\n");
    printf("B) Flee from the scene.\n");
    printf("Enter your choice (A/B): ");
    scanf(" %c", &choice);
    if (choice == 'A') {
        printf("\nYou engage in a fierce sword fight with Tybalt. You manage to win, but not before Tybalt mortally wounds your friend Mercutio, who was trying to help you. You lose 40 health points and one of your potions.\n\n");
        health -= 40;
        potionCount--;
    } else if (choice == 'B') {
        printf("\nYou try to flee from the scene, but Tybalt catches up to you. He demands to know why you are running away. You try to explain to him that you are married to Juliet and that you don't want to fight him. Tybalt gets angry and attacks you. You have no choice but to engage in a sword fight. You manage to injure Tybalt, but not before you lose 20 health points and one of your potions.\n\n");
        health -= 20;
        potionCount--;
    } else {
        printf("\nInvalid choice. Please enter A or B.\n\n");
        partTwo();
        return;
    }
}

void partThree()
{
    char choice;
    printf("PART THREE: A Banishment\n\n");
    printf("As a result of the duel, you are banished from Verona. You know that you have to leave, but you don't want to leave Juliet behind. You visit her one last time to say goodbye.\n\n");
    printf("A) Tell Juliet that you will always love her and leave.\n");
    printf("B) Ask Juliet to come with you and leave Verona forever.\n");
    printf("Enter your choice (A/B): ");
    scanf(" %c", &choice);
    switch (choice) {
        case 'A':
            printf("\nYou tell Juliet that you will always love her and leave. As you are leaving, you hear her weeping. It's one of the hardest moments of your life, but you know it's for the best.\n\n");
            break;
        case 'B':
            printf("\nYou ask Juliet to come with you and leave Verona forever. She agrees and you both start making plans to leave. However, you soon realize that leaving Verona is not going to be easy. You have to deal with a lot of obstacles and dangers. It's a long and difficult journey.\n\n");
            printf("Your health level is critical. You have to use one of your potions to replenish your health. You have %d potions left.\n\n", potionCount);
            health += 50;
            potionCount--;
            break;
        default:
            printf("\nInvalid choice. Please enter A or B.\n\n");
            partThree();
            return;
    }
}

void partFour()
{
    char choice;
    printf("PART FOUR: A Poisoned Cup\n\n");
    printf("After a few days of traveling, you and Juliet stop at a small inn for some rest and refreshment. As you are drinking, you suddenly realize that the drink is poisoned. You are horrified and look around to see who might have done it. You soon discover that the innkeeper is in league with the Capulets and that he has poisoned your drink. You are left with no choice.\n\n");
    printf("A) Try to fight the innkeeper and his men.\n");
    printf("B) Drink the poison and be with Juliet in death.\n");
    printf("Enter your choice (A/B): ");
    scanf(" %c", &choice);
    switch (choice) {
        case 'A':
            printf("\nYou try to fight the innkeeper and his men. You manage to defeat some of them, but you are outnumbered. The innkeeper himself manages to escape, but not before he stabs Juliet in the back, killing her instantly. You are left heartbroken and in despair.\n\n");
            gameOver();
            return;
        case 'B':
            printf("\nYou choose to drink the poison and be with Juliet in death. You both drink from the cup and soon start feeling the effects of the poison. You hold each other tightly as your vision dims and you feel the life leaving your body. Your love for each other was strong enough to overcome even death. You die in each other's arms.\n\n");
            gameOver();
            return;
        default:
            printf("\nInvalid choice. Please enter A or B.\n\n");
            partFour();
            return;
    }
}

void partFive()
{
    char choice;
    printf("PART FIVE: The Aftermath\n\n");
    printf("The news of your deaths spreads quickly. The Capulets and the Montagues are shocked and saddened. They realize the foolishness of their feud and pledge to end it. A monument is erected in your honor and the families reconcile.\n\n");
    printf("Years later, it's said that a new flower grows in Verona. It's a symbol of love and forgiveness, and it's called 'Romeo and Juliet'.\n\n");
    printf("Congratulations, %s! You have completed %s: Romeo and Juliet Adventure Game!\n\n", playerName, playerName);
    printf("Do you want to play again?\n");
    printf("A) Yes.\n");
    printf("B) No.\n");
    printf("Enter your choice (A/B): ");
    scanf(" %c", &choice);
    if (choice == 'A') {
        printf("\nRestarting the game...\n\n");
        health = 100;
        potionCount = 3;
        main();
    } else if (choice != 'B') {
        printf("\nInvalid choice. Please enter A or B.\n\n");
        partFive();
        return;
    }
}

void partSix()
{
    char choice;
    printf("PART SIX: The Journey\n\n");
    printf("As you continue your journey, you encounter various obstacles and challenges. You have to be careful and use your wits to survive.\n\n");
    printf("You come across a fork in the road. You have a choice to make. Choose wisely.\n\n");
    printf("A) Take the left fork.\n");
    printf("B) Take the right fork.\n");
    printf("Enter your choice (A/B): ");
    scanf(" %c", &choice);
    if (choice == 'B') {
        printf("\nYou take the right fork. It's a quiet and peaceful path, but it's also longer and more winding. You walk for hours before you finally reach the next town. Your health level is critical. You have to use one of your potions to replenish your health. You have %d potions left.\n\n", potionCount);
        health += 50;
        potionCount--;
    } else if (choice != 'A') {
        printf("\nInvalid choice. Please enter A or B.\n\n");
        partSix();
        return;
    }
    printf("You arrive at the next town and stop at a local tavern for some refreshments. You notice a shady-looking character staring at you from a distance. What do you do?\n\n");
    printf("A) Ignore the character.\n");
    printf("B) Confront the character.\n");
    printf("Enter your choice (A/B): ");
    scanf(" %c", &choice);
    switch (choice) {
        case 'A':
            printf("\nYou ignore the character and have a drink with your wife. Everything seems fine, until you suddenly realize that your drink has been poisoned. You collapse to the ground and see the shady-looking character escape. You have failed.\n\n");
            gameOver();
            return;
        case 'B':
            printf("\nYou confront the character and demand to know why he was staring at you. He reveals that he is an agent of the Prince of Verona, who has heard about your plight and wants to help you. He gives you information about a secret passage that will take you to safety. You thank him and leave.\n\n");
            break;
        default:
            printf("\nInvalid choice. Please enter A or B.\n\n");
            partSix();
            return;
    }
}

void gameOver()
{
    printf("Game over, %s! You have failed.\n\n", playerName);
    printf("Do you want to try again?\n");
    printf("A) Yes.\n");
    printf("B) No.\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'A') {
        printf("\nRestarting the game...\n\n");
        health = 100;
        potionCount = 3;
        main();
    } else if (choice != 'B') {
        printf("\nInvalid choice. Please enter A or B.\n\n");
        gameOver();
        return;
    }
}