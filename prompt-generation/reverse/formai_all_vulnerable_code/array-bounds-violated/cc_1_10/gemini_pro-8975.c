//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time periods
enum TimePeriod {
    PREHISTORIC,
    ANCIENT,
    MEDIEVAL,
    RENAISSANCE,
    MODERN,
    FUTURE
};

// Define the events that can happen in each time period
char *events[][10] = {
    {"Hunting", "Gathering", "Firemaking", "Toolmaking", "Cave painting", "Domestication", "Agriculture", "Pottery", "Weaving", "Metalworking"},
    {"Writing", "Mathematics", "Astronomy", "Architecture", "Engineering", "Philosophy", "Religion", "Law", "Warfare", "Trade"},
    {"Feudalism", "Chivalry", "Crusades", "Castles", "Cathedrals", "Universities", "Printing", "Gunpowder", "Exploration", "Reformation"},
    {"Humanism", "Science", "Art", "Music", "Literature", "Exploration", "Colonization", "Industrialization", "Enlightenment", "Revolutions"},
    {"Industrialization", "Urbanization", "Technology", "Science", "Medicine", "Transportation", "Communication", "Globalization", "Information age", "Space exploration"},
    {"Artificial intelligence", "Nanotechnology", "Bioengineering", "Climate change", "Space colonization", "Virtual reality", "Augmented reality", "Immortality", "Singularity", "Interstellar travel"}
};

// Define the probabilities of each event happening
float probabilities[][10] = {
    {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
    {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
    {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
    {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
    {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
    {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1}
};

// Get a random number between 0 and 1
float get_random_number() {
    return (float)rand() / (float)RAND_MAX;
}

// Get a random time period
enum TimePeriod get_random_time_period() {
    float random_number = get_random_number();
    for (enum TimePeriod time_period = PREHISTORIC; time_period <= FUTURE; time_period++) {
        if (random_number < probabilities[time_period][0]) {
            return time_period;
        }
        for (int i = 1; i < 10; i++) {
            if (random_number >= probabilities[time_period][i - 1] && random_number < probabilities[time_period][i]) {
                return time_period;
            }
        }
    }
    return -1; // This should never happen
}

// Get a random event for a given time period
char *get_random_event(enum TimePeriod time_period) {
    float random_number = get_random_number();
    for (int i = 0; i < 10; i++) {
        if (random_number < probabilities[time_period][i]) {
            return events[time_period][i];
        }
    }
    return "Unknown event"; // This should never happen
}

// Simulate a time travel experience
void simulate_time_travel() {
    // Get a random time period
    enum TimePeriod time_period = get_random_time_period();

    // Get a random event for the time period
    char *event = get_random_event(time_period);

    // Print the time period and event
    printf("You have traveled to the %s time period.\n", time_period);
    printf("You are experiencing the %s event.\n", event);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Simulate a time travel experience
    simulate_time_travel();

    return 0;
}