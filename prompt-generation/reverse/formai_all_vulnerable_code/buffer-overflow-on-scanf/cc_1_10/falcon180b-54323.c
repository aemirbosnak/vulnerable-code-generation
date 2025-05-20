//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ALIENS 1000

// Struct to hold alien data
typedef struct {
    int num_aliens;
    int invasion_probability;
    int invasion_year;
} AlienData;

// Function to generate random alien data
AlienData generate_alien_data() {
    AlienData data;
    data.num_aliens = rand() % MAX_NUM_ALIENS + 1;
    data.invasion_probability = rand() % 100;
    data.invasion_year = rand() % 100 + 1;
    return data;
}

// Function to print alien data
void print_alien_data(AlienData data) {
    printf("Number of aliens: %d\n", data.num_aliens);
    printf("Invasion probability: %d%%\n", data.invasion_probability);
    printf("Invasion year: %d\n", data.invasion_year);
}

// Function to simulate alien invasions
void simulate_invasion(int num_simulations, int num_years) {
    srand(time(NULL));
    int num_invasions = 0;
    for (int i = 0; i < num_simulations; i++) {
        AlienData alien_data = generate_alien_data();
        int invasion_probability = alien_data.invasion_probability;
        int invasion_year = alien_data.invasion_year;
        int num_aliens = alien_data.num_aliens;
        int year = 1;
        while (year <= num_years) {
            if (rand() % 100 <= invasion_probability) {
                printf("Invasion in year %d by %d aliens!\n", year, num_aliens);
                num_invasions++;
                break;
            }
            year++;
        }
    }
    printf("Total number of invasions: %d\n", num_invasions);
}

int main() {
    int num_simulations;
    printf("Enter number of simulations: ");
    scanf("%d", &num_simulations);
    int num_years;
    printf("Enter number of years to simulate: ");
    scanf("%d", &num_years);
    simulate_invasion(num_simulations, num_years);
    return 0;
}