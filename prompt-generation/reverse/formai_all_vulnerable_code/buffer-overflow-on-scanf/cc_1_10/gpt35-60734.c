//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void intro();
void start();
void levelOne();
void levelTwo();
void levelThree();
void gameOver();
void win();

int main()
{
    intro();
    start();
    return 0;
}

void intro()
{
    printf("Welcome to the Cyber City. You are a rogue hacker looking to take down the evil corporation, Zentek.\n");
    printf("Your objective is to infiltrate Zentek's headquarters and destroy their mainframe.\n");
    printf("The game features three levels, each with its own set of challenges.\n");
    printf("Good luck!\n");
}

void start()
{
    char choice;
    printf("\nYou find yourself on the outskirts of Cyber City. What do you want to do?\n");
    printf("a. Enter the city\n");
    printf("b. Turn back and leave\n");
    printf("Choice: ");
    scanf(" %c", &choice);
    if (choice == 'a')
    {
        levelOne();
    }
    else if (choice == 'b')
    {
        printf("\nYou coward. Game over.\n");
        exit(0);
    }
    else
    {
        printf("\nInvalid choice. Try again.\n");
        start();
    }
}

void levelOne()
{
    char password[10];
    printf("\nYou have entered the city. As you walk through the streets, you see Zentek's headquarters in the distance.\n");
    printf("In order to access their mainframe, you'll need to know the password.\n");
    printf("Hint: It's a four-letter word that means 'to seize'.\n");
    printf("Password: ");
    scanf("%s", password);
    if (strcmp(password, "grab") == 0)
    {
        printf("\nPassword accepted. Access granted.\n");
        levelTwo();
    }
    else
    {
        printf("\nIncorrect password. Try again.\n");
        levelOne();
    }
}

void levelTwo()
{
    char choice;
    printf("\nYou have entered Zentek's headquarters. What do you want to do?\n");
    printf("a. Take the elevator to the mainframe room\n");
    printf("b. Sneak around and search for information\n");
    printf("Choice: ");
    scanf(" %c", &choice);
    if (choice == 'a')
    {
        printf("\nAs you enter the elevator, you hear a voice say 'Access denied'.\n");
        printf("The room has been sealed off. You'll need to find another way.\n");
        levelTwo();
    }
    else if (choice == 'b')
    {
        printf("\nYou start searching through the desks and computers in the office. As you read through the files, you find out about Zentek's secret project: Project X.\n");
        printf("It's a cyber weapon that they plan to launch in 24 hours. You must stop them before it's too late.\n");
        levelThree();
    }
    else
    {
        printf("\nInvalid choice. Try again.\n");
        levelTwo();
    }
}

void levelThree()
{
    char code[6];
    printf("\nYou must now hack into Zentek's security system to gain access to the mainframe room.\n");
    printf("There's a keypad with a six-digit code. You'll have to guess the code.\n");
    printf("Clue: It's a date that marks the beginning of the Cyber War.\n");
    printf("Code: ");
    scanf("%s", code);
    if (strcmp(code, "07071988") == 0)
    {
        printf("\nCode accepted. Access granted.\n");
        printf("You find the mainframe and destroy it with one blow. Zentek's Project X is no more. You are a hero.\n");
        win();
    }
    else
    {
        printf("\nIncorrect code. Try again.\n");
        levelThree();
    }
}

void gameOver()
{
    printf("\nYou failed in your mission. Zentek has launched Project X. The world is now a cyber dystopia.\n");
    exit(0);
}

void win()
{
    printf("\nCongratulations! You have saved the world from Zentek's evil plan. You are the hero of the Cyber City.\n");
    exit(0);
}