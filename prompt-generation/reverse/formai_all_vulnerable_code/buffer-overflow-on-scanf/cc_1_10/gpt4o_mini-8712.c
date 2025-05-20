//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_ALIENS 1000
#define MAX_VIRUS_STRAINS 20

typedef struct {
    char name[50];
    int population;
    int alien_attack_probability; // percentage between 0-100
    int defenses; // Strength of city's defenses (1-10)
    int infected_population; // If infected by virus
    int created_aliens; // Alien to population ratio after attack
} City;

typedef struct {
    char name[50];
    float lethality; // Lethality percentage of the virus (0.0 to 1.0)
} Virus;

City cities[MAX_CITIES];
Virus viruses[MAX_VIRUS_STRAINS];
int city_count = 0;
int virus_count = 0;

void add_city();
void add_virus();
void simulate_invasion();
void report();
float calculate_infection_probability(City city, Virus virus);
int generate_random(int min, int max);
void display_menu();
void flush_input();

int main() {
    srand(time(NULL));
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);
        flush_input();

        switch (choice) {
            case 1:
                add_city();
                break;
            case 2:
                add_virus();
                break;
            case 3:
                simulate_invasion();
                break;
            case 4:
                report();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void display_menu() {
    printf("\nAlien Invasion Probability Calculator\n");
    printf("1. Add a City\n");
    printf("2. Add a Virus Strain\n");
    printf("3. Simulate an Invasion\n");
    printf("4. Report Outcomes\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void flush_input() {
    while (getchar() != '\n');
}

void add_city() {
    if (city_count >= MAX_CITIES) {
        printf("Maximum number of cities reached.\n");
        return;
    }
    
    printf("Enter city name: ");
    fgets(cities[city_count].name, sizeof(cities[city_count].name), stdin);
    cities[city_count].name[strcspn(cities[city_count].name, "\n")] = 0; // Remove new line character

    printf("Enter city population: ");
    scanf("%d", &cities[city_count].population);
    
    printf("Enter alien attack probability (0-100): ");
    scanf("%d", &cities[city_count].alien_attack_probability);
    
    printf("Enter city's defenses (1-10): ");
    scanf("%d", &cities[city_count].defenses);
    
    cities[city_count].infected_population = 0;
    cities[city_count].created_aliens = 0;

    city_count++;
    printf("City %s added successfully!\n", cities[city_count - 1].name);
}

void add_virus() {
    if (virus_count >= MAX_VIRUS_STRAINS) {
        printf("Maximum number of virus strains reached.\n");
        return;
    }

    printf("Enter virus name: ");
    fgets(viruses[virus_count].name, sizeof(viruses[virus_count].name), stdin);
    viruses[virus_count].name[strcspn(viruses[virus_count].name, "\n")] = 0; // Remove new line character

    printf("Enter virus lethality (0.0 - 1.0): ");
    scanf("%f", &viruses[virus_count].lethality);

    virus_count++;
    printf("Virus %s added successfully!\n", viruses[virus_count - 1].name);
}

void simulate_invasion() {
    if (city_count == 0 || virus_count == 0) {
        printf("Please add cities and viruses before simulating an invasion.\n");
        return;
    }

    for (int i = 0; i < city_count; i++) {
        if (generate_random(1, 100) <= cities[i].alien_attack_probability) {
            printf("City %s is under alien attack!\n", cities[i].name);
            for (int j = 0; j < virus_count; j++) {
                float infection_probability = calculate_infection_probability(cities[i], viruses[j]);
                if (generate_random(1, 100) <= infection_probability * 100) {
                    cities[i].infected_population = cities[i].population * viruses[j].lethality;
                    cities[i].created_aliens = cities[i].infected_population / 100; // For simplicity ratio
                    printf("City %s has %d infected by %s virus leading to %d aliens created.\n", 
                        cities[i].name, cities[i].infected_population, viruses[j].name, cities[i].created_aliens);
                }
            }
        } else {
            printf("City %s is safe from alien attack.\n", cities[i].name);
        }
    }
}

float calculate_infection_probability(City city, Virus virus) {
    return (float)(city.defenses - (city.alien_attack_probability / 10.0)) * (1.0 - virus.lethality);
}

int generate_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void report() {
    printf("\n--- Report ---\n");
    for (int i = 0; i < city_count; i++) {
        printf("City: %s | Population: %d | Infected: %d | Aliens Created: %d\n", 
            cities[i].name, cities[i].population, cities[i].infected_population, cities[i].created_aliens);
    }
}