//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#define MAX_PLANETS 10

typedef struct {
    char name[20];
    int distance_from_earth;
} planet;

void print_planets(planet arr[], int size){
    printf("List of planets:\n");
    for(int i=0; i<size; i++){
        printf("%d. %s (Distance from earth: %d light years)\n", i+1, arr[i].name, arr[i].distance_from_earth);
    }
}

void display_message(int code){
    if(code == 1){
        printf("\nMessage from the captain: We have encountered a black hole! Brace for impact!\n");
    }
    else if(code == 2){
        printf("\nMessage from the captain: We have successfully navigated through the asteroid belt. Commence scanning for new planets.\n");
    }
    else{
        printf("\nMessage from the captain: Nothing to report. Keep up the good work!\n");
    }
}

int main()
{
    planet known_planets[MAX_PLANETS] = {
        {"Mercury", 48},
        {"Venus", 162},
        {"Earth", 0},
        {"Mars", 249},
        {"Jupiter", 390},
        {"Saturn", 792},
        {"Uranus", 1725},
        {"Neptune", 2715},
        {"Pluto", 4000},
        {"Kepler-186f", 50000}
    };

    int current_position = 2; // start at earth
    int num_planets = MAX_PLANETS;

    printf("Welcome to the Procedural Space Adventure game.\n");
    printf("You are the captain of a spaceship exploring the galaxy.\n");
    printf("Use the commands below to control your ship:\n");

    printf("\nCOMMANDS:\n");
    printf("1. go <planet name>\n");
    printf("2. stats\n");
    printf("3. help\n");
    printf("4. quit\n");

    printf("\n");

    int running = 1;
    char input[20];
    char command[10];
    char destination[20];

    while(running){
        printf("Enter a command: ");
        scanf("%s", input);

        // split input into command and destination
        sscanf(input, "%s %s", command, destination);

        if(strcmp(command, "go") == 0){
            int planet_found = 0;
            int index = 0;
            for(int i=0; i<num_planets; i++){
                if(strcmp(destination, known_planets[i].name) == 0){
                    planet_found = 1;
                    index = i;
                    break;
                }
            }
            if(planet_found){
                printf("Traveling to %s...\n", known_planets[index].name);
                display_message(rand()%3); // random message from captain
                current_position = index;
            }
            else{
                printf("%s is not a known planet.\n", destination);
            }
        }
        else if(strcmp(command, "stats") == 0){
            printf("Current position: %s\n", known_planets[current_position].name);
            printf("Distance from Earth: %d light years\n", known_planets[current_position].distance_from_earth);
            printf("Number of known planets: %d\n", num_planets);
            print_planets(known_planets, num_planets);
        }
        else if(strcmp(command, "help") == 0){
            printf("\nCOMMANDS:\n");
            printf("1. go <planet name>\n");
            printf("2. stats\n");
            printf("3. help\n");
            printf("4. quit\n");
        }
        else if(strcmp(command, "quit") == 0){
            printf("Quitting program...\n");
            running = 0;
        }
        else{
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}