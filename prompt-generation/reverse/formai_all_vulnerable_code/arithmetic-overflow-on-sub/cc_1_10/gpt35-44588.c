//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 10
#define MAX_TROLLEYS 50
#define MAX_SCREENS 3

// Structs
typedef struct baggage_t {
    int id;
    int weight;
    int origin_flight;
    int destination_flight;
    int arrival_time;
} Baggage;

typedef struct trolley_t {
    int id;
    int capacity;
    Baggage* baggage[MAX_BAGGAGE];
} Trolley;

typedef struct flight_t {
    int id;
    int departure_time;
    int arrival_time;
} Flight;

typedef struct screen_t {
    int id;
    int flight_id;
} Screen;

// Global Variables
Baggage* all_baggage[MAX_BAGGAGE];
Flight* all_flights[MAX_FLIGHTS];
Trolley* all_trolleys[MAX_TROLLEYS];
Screen* all_screens[MAX_SCREENS];
int num_baggage;
int num_flights;
int num_trolleys;
int num_screens;
int current_time;

// Function Prototypes
void generate_baggage();
void generate_flights();
void generate_trolleys();
void generate_screens();
void print_baggage();
void print_flights();
void print_trolleys();
void print_screens();
void move_baggage();
bool check_screen(int flight_id);
void display_screen(int screen_id);
void process_trolley(Trolley* trolley, int screen_id);

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate baggage, flights, trolleys, and screens
    generate_baggage();
    generate_flights();
    generate_trolleys();
    generate_screens();
    
    // Print initial state of system
    printf("Initial state of system:\n\n");
    print_baggage();
    print_flights();
    print_trolleys();
    print_screens();
    
    // Simulate movement of baggage
    while (current_time < all_flights[num_flights-1]->arrival_time) {
        move_baggage();
        current_time++;
    }
    
    // Print final state of system
    printf("Final state of system:\n\n");
    print_baggage();
    print_flights();
    print_trolleys();
    print_screens();
    
    return 0;
}

// Generates random baggage
void generate_baggage() {
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        if (rand() % 2 == 0) {
            // Generate domestic flight baggage
            all_baggage[i] = (Baggage*)malloc(sizeof(Baggage));
            all_baggage[i]->id = i+1;
            all_baggage[i]->weight = (rand() % 30) + 1;
            all_baggage[i]->origin_flight = (rand() % 5) + 1;
            all_baggage[i]->destination_flight = (rand() % 5) + 1;
            while (all_baggage[i]->origin_flight == all_baggage[i]->destination_flight) {
                all_baggage[i]->destination_flight = (rand() % 5) + 1;
            }
            all_baggage[i]->arrival_time = (rand() % (all_flights[all_baggage[i]->destination_flight-1]->arrival_time - all_flights[all_baggage[i]->origin_flight-1]->departure_time)) + all_flights[all_baggage[i]->origin_flight-1]->departure_time;
            num_baggage++;
        } else {
            // Generate international flight baggage
            all_baggage[i] = (Baggage*)malloc(sizeof(Baggage));
            all_baggage[i]->id = i+1;
            all_baggage[i]->weight = (rand() % 50) + 31;
            all_baggage[i]->origin_flight = (rand() % 5) + 6;
            all_baggage[i]->destination_flight = (rand() % 5) + 6;
            while (all_baggage[i]->origin_flight == all_baggage[i]->destination_flight) {
                all_baggage[i]->destination_flight = (rand() % 5) + 6;
            }
            all_baggage[i]->arrival_time = (rand() % (all_flights[all_baggage[i]->destination_flight-1]->arrival_time - all_flights[all_baggage[i]->origin_flight-1]->departure_time)) + all_flights[all_baggage[i]->origin_flight-1]->departure_time;
            num_baggage++;
        }
    }
}

// Generates random flights
void generate_flights() {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        all_flights[i] = (Flight*)malloc(sizeof(Flight));
        all_flights[i]->id = i+1;
        all_flights[i]->departure_time = (rand() % 12) + 6;
        all_flights[i]->arrival_time = (rand() % 12) + 18;
        while (all_flights[i]->arrival_time < all_flights[i]->departure_time) {
            all_flights[i]->arrival_time = (rand() % 12) + 18;
        }
        num_flights++;
    }
}

// Generates trolleys
void generate_trolleys() {
    for (int i = 0; i < MAX_TROLLEYS; i++) {
        all_trolleys[i] = (Trolley*)malloc(sizeof(Trolley));
        all_trolleys[i]->id = i+1;
        all_trolleys[i]->capacity = (rand() % 5) + 1;
        num_trolleys++;
    }
}

// Generates screens
void generate_screens() {
    for (int i = 0; i < MAX_SCREENS; i++) {
        all_screens[i] = (Screen*)malloc(sizeof(Screen));
        all_screens[i]->id = i+1;
        all_screens[i]->flight_id = 0;
        num_screens++;
    }
}

// Prints all baggage
void print_baggage() {
    printf("Baggage:\n");
    for (int i = 0; i < num_baggage; i++) {
        printf("ID: %d | Weight: %d kg | Origin Flight: %d | Destination Flight: %d | Arrival Time: %d\n", all_baggage[i]->id, all_baggage[i]->weight, all_baggage[i]->origin_flight, all_baggage[i]->destination_flight, all_baggage[i]->arrival_time);
    }
    printf("\n");
}

// Prints all flights
void print_flights() {
    printf("Flights:\n");
    for (int i = 0; i < num_flights; i++) {
        printf("ID: %d | Departure Time: %d | Arrival Time: %d\n", all_flights[i]->id, all_flights[i]->departure_time, all_flights[i]->arrival_time);
    }
    printf("\n");
}

// Prints all trolleys
void print_trolleys() {
    printf("Trolleys:\n");
    for (int i = 0; i < num_trolleys; i++) {
        printf("ID: %d | Capacity: %d\n", all_trolleys[i]->id, all_trolleys[i]->capacity);
        printf("Contents: ");
        for (int j = 0; j < all_trolleys[i]->capacity; j++) {
            if (all_trolleys[i]->baggage[j] != NULL) {
                printf("%d ", all_trolleys[i]->baggage[j]->id);
            } else {
                printf("- ");
            }
        }
        printf("\n\n");
    }
}

// Prints all screens
void print_screens() {
    printf("Screens:\n");
    for (int i = 0; i < num_screens; i++) {
        printf("ID: %d | Flight ID: %d\n", all_screens[i]->id, all_screens[i]->flight_id);
    }
    printf("\n");
}

// Moves baggage from origin to destination flights
void move_baggage() {
    // Check if any baggage has arrived at its destination
    for (int i = 0; i < num_baggage; i++) {
        if (all_baggage[i]->arrival_time == current_time) {
            // Find an empty screen
            bool found_screen = false;
            int screen_id;
            for (int j = 0; j < num_screens; j++) {
                if (all_screens[j]->flight_id == 0) {
                    screen_id = j+1;
                    found_screen = true;
                    break;
                }
            }
            
            // Process baggage if an empty screen is found
            if (found_screen) {
                display_screen(screen_id);
                all_screens[screen_id-1]->flight_id = all_baggage[i]->destination_flight;
                for (int j = 0; j < num_trolleys; j++) {
                    if (all_trolleys[j]->capacity > 0) {
                        process_trolley(all_trolleys[j], screen_id);
                        break;
                    }
                }
                free(all_baggage[i]);
                all_baggage[i] = NULL;
            }
        }
    }
    
    // Load baggage onto trolleys
    for (int i = 0; i < num_trolleys; i++) {
        if (all_trolleys[i]->capacity > 0) {
            int remaining_capacity = all_trolleys[i]->capacity;
            for (int j = 0; j < num_baggage; j++) {
                if (all_baggage[j] != NULL && all_baggage[j]->origin_flight == all_screens[0]->flight_id) {
                    all_trolleys[i]->baggage[all_trolleys[i]->capacity - remaining_capacity] = all_baggage[j];
                    remaining_capacity--;
                    all_baggage[j] = NULL;
                }
                if (remaining_capacity == 0) {
                    break;
                }
            }
        }
    }
}

// Check if screen is displaying given flight_id
bool check_screen(int flight_id) {
    for (int i = 0; i < num_screens; i++) {
        if (all_screens[i]->flight_id == flight_id) {
            return true;
        }
    }
    return false;
}

// Update the given screen to display the corresponding flight
void display_screen(int screen_id) {
    bool flight_assigned = false;
    for (int i = 0; i < num_trolleys; i++) {
        for (int j = 0; j < all_trolleys[i]->capacity; j++) {
            if (all_trolleys[i]->baggage[j] != NULL && !flight_assigned) {
                all_screens[screen_id-1]->flight_id = all_trolleys[i]->baggage[j]->destination_flight;
                all_trolleys[i]->baggage[j] = NULL;
                flight_assigned = true;
                break;
            }
        }
        if (flight_assigned) {
            break;
        }
    }
}

// Process the contents of the given trolley for the given screen
void process_trolley(Trolley* trolley, int screen_id) {
    bool contents_loaded = false;
    for (int i = 0; i < trolley->capacity; i++) {
        if (trolley->baggage[i] != NULL && !contents_loaded) {
            // Display screen
            display_screen(screen_id);
            
            // Remove baggage from trolley
            free(trolley->baggage[i]);
            trolley->baggage[i] = NULL;
            contents_loaded = true;
            break;
        }
    }
}