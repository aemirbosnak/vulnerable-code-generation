//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main()
{
    srand(time(NULL));
    int rnd = rand() % 100;
    char name[100];
    char ship[100];
    char description[100];
    char planet[100];
    char alien[100];
    char choice[100];
    char output[100];
    int i, j, k;
    char *options[] = {"1. Take a deep breath", "2. Look around", "3. Take a nap", "4. Go to the galactic map", "5. Talk to the crew", "6. Leave the ship", "7. Restart the program"};
    int choices[7];

    printf("Welcome to the Procedural Space Adventure Program!\n");
    printf("You are a space explorer on a mission to explore new planets and galaxies.\n");
    printf("Your ship is equipped with advanced technology and a crew of experienced astronauts.\n");
    printf("Your mission is to explore the unknown and make contact with new alien species.\n");
    printf("But be careful, the universe is full of dangers and mysteries.\n");
    printf("Are you ready for this adventure?\n");

    printf("Enter your name:\n");
    fgets(name, sizeof(name), stdin);
    printf("Hello %s, welcome aboard.\n", name);

    printf("Choose a ship:\n");
    printf("1. The Millennium Falcon\n");
    printf("2. The Enterprise\n");
    printf("3. The Discovery\n");
    printf("4. The Nostromo\n");
    printf("5. The Serenity\n");
    printf("6. The TARDIS\n");
    printf("7. The X-Wing\n");
    scanf("%d", &j);

    switch (j)
    {
        case 1:
            printf("You choose the Millennium Falcon.\n");
            break;
        case 2:
            printf("You choose the Enterprise.\n");
            break;
        case 3:
            printf("You choose the Discovery.\n");
            break;
        case 4:
            printf("You choose the Nostromo.\n");
            break;
        case 5:
            printf("You choose the Serenity.\n");
            break;
        case 6:
            printf("You choose the TARDIS.\n");
            break;
        case 7:
            printf("You choose the X-Wing.\n");
            break;
        default:
            printf("Invalid choice, please choose again.\n");
            break;
    }

    printf("Enter your ship's description:\n");
    fgets(description, sizeof(description), stdin);
    printf("Your ship is %s.\n", description);

    printf("Enter the name of your planet:\n");
    fgets(planet, sizeof(planet), stdin);
    printf("You are on %s.\n", planet);

    printf("Enter the name of the alien species:\n");
    fgets(alien, sizeof(alien), stdin);
    printf("You encounter %s.\n", alien);

    printf("Choose an option:\n");
    printf("%s\n", options[rnd]);
    scanf("%s", choice);

    switch (choice[0])
    {
        case '1':
            printf("You take a deep breath and feel the excitement of the unknown.\n");
            break;
        case '2':
            printf("You look around and see a beautiful view of the planet.\n");
            break;
        case '3':
            printf("You take a nap and wake up feeling refreshed.\n");
            break;
        case '4':
            printf("You go to the galactic map and plan your next destination.\n");
            break;
        case '5':
            printf("You talk to the crew and share your experiences.\n");
            break;
        case '6':
            printf("You leave the ship and explore the planet.\n");
            break;
        case '7':
            printf("You restart the program and continue your adventure.\n");
            break;
        default:
            printf("Invalid choice, please choose again.\n");
            break;
    }

    return 0;
}