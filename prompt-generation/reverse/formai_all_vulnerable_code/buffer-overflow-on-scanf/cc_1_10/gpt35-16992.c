//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void intro();
int getOption();
void planet1();
void planet2();
void planet3();
void planet4();

int main()
{
    srand(time(NULL)); // set seed for random number generator

    intro(); // call function to display introduction

    int choice;
    do
    {
        choice = getOption(); // call function to get user's choice

        // call function corresponding to user's choice
        switch (choice)
        {
            case 1:
                planet1();
                break;
            case 2:
                planet2();
                break;
            case 3:
                planet3();
                break;
            case 4:
                planet4();
                break;
            case 5:
                printf("\nExiting space adventure game...");
                break;
            default:
                printf("\nInvalid choice.");
                break;
        }

    } while (choice != 5); // loop until user chooses to exit

    return 0;
}

// function to display introduction
void intro()
{
    printf("Welcome to the Interstellar Space Adventure Game!\n\n");
    printf("You are the captain of the spaceship Odyssey, and your mission is to explore four planets in the Alpha Centauri system.\n");
    printf("Each planet is unique and has its own challenges and rewards.\n\n");
    printf("Choose your planet wisely, and may the force be with you!\n\n");
}

// function to get user's choice
int getOption()
{
    printf("Choose your planet:\n");
    printf("1. Planet A\n");
    printf("2. Planet B\n");
    printf("3. Planet C\n");
    printf("4. Planet D\n");
    printf("5. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// function for planet A
void planet1()
{
    printf("\nYou have arrived at Planet A.\n");
    printf("This planet has a toxic atmosphere and extreme temperatures.\n");
    printf("You must wear a special suit to survive on this planet.\n\n");

    int randNum = rand() % 100 + 1; // generate random number between 1 and 100

    if (randNum >= 50)
    {
        printf("Congratulations! You have found a rare mineral on this planet.\n");
        printf("This mineral is worth a fortune and will make you rich!\n\n");
    }
    else
    {
        printf("Uh oh, your spaceship has been damaged by the toxic atmosphere!\n");
        printf("You must repair your spaceship before you can continue your mission.\n\n");
    }
}

// function for planet B
void planet2()
{
    printf("\nYou have arrived at Planet B.\n");
    printf("This planet is covered in dense forests and has various species of wildlife.\n");
    printf("You must be careful not to disturb the natural balance of this planet.\n\n");

    int randNum = rand() % 100 + 1; // generate random number between 1 and 100

    if (randNum >= 50)
    {
        printf("Congratulations! You have made contact with a peaceful alien race.\n");
        printf("They have gifted you with advanced technology to assist in your space exploration.\n\n");
    }
    else
    {
        printf("Uh oh, your spaceship has been attacked by hostile creatures!\n");
        printf("You must defend yourself and repair your spaceship before you can continue your mission.\n\n");
    }
}

// function for planet C
void planet3()
{
    printf("\nYou have arrived at Planet C.\n");
    printf("This planet is a barren wasteland with no signs of life.\n");
    printf("However, it is rich in resources and minerals.\n\n");

    int randNum = rand() % 100 + 1; // generate random number between 1 and 100

    if (randNum >= 50)
    {
        printf("Congratulations! You have found a rare resource deposit.\n");
        printf("This resource is highly sought after and will greatly benefit your space exploration.\n\n");
    }
    else
    {
        printf("Uh oh, your spaceship has been damaged by a high-speed meteorite!\n");
        printf("You must repair your spaceship before you can continue your mission.\n\n");
    }
}

// function for planet D
void planet4()
{
    printf("\nYou have arrived at Planet D.\n");
    printf("This planet has a highly advanced civilization with their own space program.\n");
    printf("You must establish communication and diplomacy with this civilization.\n\n");

    int randNum = rand() % 100 + 1; // generate random number between 1 and 100

    if (randNum >= 50)
    {
        printf("Congratulations! You have successfully established communication with the alien civilization.\n");
        printf("They have shared their knowledge and technology, and have invited you to their home planet.\n");
        printf("You have completed your mission and have made history!\n\n");
    }
    else
    {
        printf("Uh oh, the alien civilization does not take kindly to outsiders.\n");
        printf("You must defect their attacks and make a quick exit before it's too late!\n\n");
    }
}