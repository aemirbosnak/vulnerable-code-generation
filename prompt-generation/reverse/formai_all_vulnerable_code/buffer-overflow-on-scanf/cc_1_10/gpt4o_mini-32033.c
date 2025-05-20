//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 5
#define MAX_LOCATIONS 10

typedef struct {
    int location_id;
    int treasure_amount;
    int visited;
} Location;

typedef struct {
    char name[30];
    int total_treasure;
    int current_location;
} Player;

void initialize_locations(Location locations[], int num_locations);
void display_locations(Location locations[], int num_locations);
void greedy_treasure_hunt(Player *player, Location locations[], int num_locations);

int main() {
    int num_locations = MAX_LOCATIONS;
    Location locations[MAX_LOCATIONS];
    Player players[MAX_PLAYERS];
    int num_players;

    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    
    // Input player names and initialize player data
    for (int i = 0; i < num_players; i++) {
        printf("Enter name of Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].total_treasure = 0;
        players[i].current_location = 0; // All players start at location 0
    }

    initialize_locations(locations, num_locations);
    display_locations(locations, num_locations);
    
    // Each player takes turns collecting treasure
    for (int i = 0; i < num_players; i++) {
        printf("\n%s's turn to collect treasure:\n", players[i].name);
        greedy_treasure_hunt(&players[i], locations, num_locations);
        printf("%s collected a total of %d treasure.\n", players[i].name, players[i].total_treasure);
    }
    
    printf("\nFinal Results:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d treasure collected.\n", players[i].name, players[i].total_treasure);
    }

    return 0;
}

void initialize_locations(Location locations[], int num_locations) {
    for (int i = 0; i < num_locations; i++) {
        locations[i].location_id = i + 1;
        // Randomizing treasure amounts between 10 to 100
        locations[i].treasure_amount = rand() % 91 + 10;
        locations[i].visited = 0; // Mark all locations as unvisited
    }
}

void display_locations(Location locations[], int num_locations) {
    printf("\nAvailable Locations and Treasures:\n");
    for (int i = 0; i < num_locations; i++) {
        printf("Location %d: %d treasure\n", locations[i].location_id, locations[i].treasure_amount);
    }
}

void greedy_treasure_hunt(Player *player, Location locations[], int num_locations) {
    for (int i = 0; i < num_locations; i++) {
        // Look for the maximum treasure location not visited yet
        int max_treasure_index = -1;
        for (int j = 0; j < num_locations; j++) {
            if (!locations[j].visited && (max_treasure_index == -1 || 
                locations[j].treasure_amount > locations[max_treasure_index].treasure_amount)) {
                max_treasure_index = j;
            }
        }

        // If we find a valid location with treasure, collect it
        if (max_treasure_index != -1) {
            player->total_treasure += locations[max_treasure_index].treasure_amount;
            locations[max_treasure_index].visited = 1; // Mark that location as visited
            printf("%s collected %d treasure from Location %d.\n", player->name, 
                   locations[max_treasure_index].treasure_amount, 
                   locations[max_treasure_index].location_id);
        } else {
            break; // All locations visited
        }
    }
}