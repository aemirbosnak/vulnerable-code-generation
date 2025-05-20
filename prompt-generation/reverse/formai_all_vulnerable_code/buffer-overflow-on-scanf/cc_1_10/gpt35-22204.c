//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void intro();
void menu();
void start_game();
void planet1();
void planet2();
void planet3();

int main(){
    intro();
    menu();
    return 0;
}

void intro(){
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are the captain of the spaceship, travelling across the galaxy in search of new planets to explore.\n");
    printf("But be warned, the challenges you face may be dangerous, and the choices you make will determine your fate.\n");
    printf("So, let's begin our journey!\n\n");
    printf("Press any key to continue...");
    getchar();
    system("clear");
}

void menu(){
    int choice;
    printf("What do you want to do?\n");
    printf("1. Start game\n");
    printf("2. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            start_game();
            break;
        case 2:
            printf("\nThanks for playing! Goodbye.");
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n\n");
            menu();
    }
}

void start_game(){
    int planet_choice;
    printf("You are currently at a space station. Which planet do you want to explore?\n");
    printf("1. Gorgon\n");
    printf("2. Xanthe\n");
    printf("3. Zephyr\n");
    printf("Enter your choice: ");
    scanf("%d", &planet_choice);
    printf("\n");

    switch(planet_choice){
        case 1:
            planet1();
            break;
        case 2:
            planet2();
            break;
        case 3:
            planet3();
            break;
        default:
            printf("\nInvalid choice. Please try again.\n\n");
            start_game();
    }
}

void planet1(){
    int event_num;
    printf("Welcome to Gorgon, a planet with an atmosphere toxic to humans.\n\n");

    srand(time(NULL));
    event_num = rand() % 3;

    switch(event_num){
        case 0:
            printf("As you explore the planet, you come across a group of aliens. They seem peaceful and offer to share their knowledge with you. Do you accept?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int alien_choice;
            scanf("%d", &alien_choice);
            if(alien_choice == 1){
                printf("\nThe aliens teach you about a rare mineral found only on this planet. They give you coordinates for a large deposit of this mineral and tell you it is very valuable.\n");
                printf("You found what you were looking for. Congratulations!\n");
            }
            else{
                printf("\nThe aliens seem disappointed by your choice, but they understand. They give you a map of the planet and wish you luck on your journey.\n");
                printf("You continue exploring the planet...\n");
            }
            break;

        case 1:
            printf("As you explore the planet, your spaceship's scanner picks up a strange energy signature. You determine that it is coming from an underground tunnel system. Do you investigate?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int tunnel_choice;
            scanf("%d", &tunnel_choice);
            if(tunnel_choice == 1){
                printf("\nYou follow the tunnel system and discover an ancient underground city. The city is filled with valuable artifacts, and you manage to collect some of them before leaving. You found what you were looking for. Congratulations!\n");
            }
            else{
                printf("\nYou decide not to risk it and leave the planet, but you can't shake the feeling that you missed something important.\n");
            }
            break;

        case 2:
            printf("As you explore the planet, you come across a dangerous creature. It looks like it has not seen humans before and may attack. Do you fight it or try to run?\n");
            printf("1. Fight\n");
            printf("2. Run\n");
            int creature_choice;
            scanf("%d", &creature_choice);
            if(creature_choice == 1){
                printf("\nYou engage in combat with the creature and manage to defeat it. It drops a rare crystal which you can sell for a large amount of money. You found what you were looking for. Congratulations!\n");
            }
            else{
                printf("\nYou manage to run away, but you realize later that you dropped an important piece of equipment during your escape. You head back to retrieve it, but it is too late. You lost valuable time and resources.\n");
            }
            break;
    }
}

void planet2(){
    int event_num;
    printf("Welcome to Xanthe, a planet covered in vast forests.\n\n");

    srand(time(NULL));
    event_num = rand() % 3;

    switch(event_num){
        case 0:
            printf("As you explore the planet, you come across a tribe of intelligent creatures. They are suspicious of humans and ask you to prove your worthiness to interact with them. Do you do as they ask?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int tribe_choice;
            scanf("%d", &tribe_choice);
            if(tribe_choice == 1){
                printf("\nThey ask you to perform a ritual dance which is sacred to them. You perform it perfectly and earn their respect. They allow you to study their culture and give you access to areas which are off-limits to outsiders. You found what you were looking for. Congratulations!\n");
            }
            else{
                printf("The tribe refuse to interact with you, and you are forced to leave the planet without achieving your goals.\n");
            }
            break;

        case 1:
            printf("As you explore the planet, a sudden storm hits the forest you are in. Do you hide under a tree or attempt to find a shelter?\n");
            printf("1. Hide under a tree\n");
            printf("2. Attempt to find a shelter\n");
            int storm_choice;
            scanf("%d", &storm_choice);
            if(storm_choice == 1){
                printf("\nThe tree you took shelter under was struck by lightning, and you are badly injured. You manage to make it back to your spaceship, but you are forced to leave the planet without achieving your goals.\n");
            }
            else{
                printf("\nYou manage to find an abandoned building and take shelter. The building turns out to be a research center which contains valuable information which you can sell. You found what you were looking for. Congratulations!\n");
            }
            break;

        case 2:
            printf("As you explore the planet, you come across an abandoned temple. Do you investigate it?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int temple_choice;
            scanf("%d", &temple_choice);
            if(temple_choice == 1){
                printf("\nYou explore the temple and discover an ancient artifact. The artifact turns out to be a powerful energy source which you can use to power your ship, making it faster and more efficient. You found what you were looking for. Congratulations!\n");
            }
            else{
                printf("\nYou decide to leave the planet, but you regret it later when you find out that the temple contained something very valuable. You can't help but wonder what you missed.\n");
            }
            break;
    }
}

void planet3(){
    int event_num;
    printf("Welcome to Zephyr, a planet characterized by its unpredictable weather patterns.\n\n");

    srand(time(NULL));
    event_num = rand() % 3;

    switch(event_num){
        case 0:
            printf("As you explore the planet, you come across a group of travelers who are trying to find their way to the nearest space station. Do you offer them a ride?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int traveler_choice;
            scanf("%d", &traveler_choice);
            if(traveler_choice == 1){
                printf("\nThe travelers are grateful for your help and offer to pay you for your services. You accept, and they pay you a large sum of money. You found what you were looking for. Congratulations!\n");
            }
            else{
                printf("\nYou leave the travelers to their own devices, and later on, find out that they were attacked by a band of space pirates. You feel bad about not helping them, but at least you are safe.\n");
            }
            break;

        case 1:
            printf("As you explore the planet, you notice a large group of animals migrating across the plains. Do you observe them or try to hunt them?\n");
            printf("1. Observe\n");
            printf("2. Hunt\n");
            int animal_choice;
            scanf("%d", &animal_choice);
            if(animal_choice == 1){
                printf("\nYou observe the animals, and learn about their migratory patterns. You manage to sell this information to a research team, earning a lot of money. You found what you were looking for. Congratulations!\n");
            }
            else{
                printf("\nYou try to hunt the animals, but they overpower you. You realize later that they were protected by the planet's government, and you are charged with breaking their laws. You had to pay a fine and leave the planet empty-handed.\n");
            }
            break;

        case 2:
            printf("As you explore the planet, a sudden tornado hits the area. Do you attempt to fly your ship out of the planet's atmosphere or try to land it and wait out the storm?\n");
            printf("1. Fly out\n");
            printf("2. Wait it out\n");
            int tornado_choice;
            scanf("%d", &tornado_choice);
            if(tornado_choice == 1){
                printf("\nYou successfully fly your ship out of the planet's atmosphere and avoid the tornado. You find a new planet to explore and start your journey anew.\n");
            }
            else{
                printf("\nYou land your ship and wait out the tornado. Though you are unharmed, your ship suffers from some mechanical damage. You lose valuable time and resources as you try to fix it.\n");
            }
            break;
    }
}