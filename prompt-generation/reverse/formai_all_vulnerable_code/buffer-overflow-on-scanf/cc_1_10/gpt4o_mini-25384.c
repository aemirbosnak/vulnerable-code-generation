//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: happy
#include <stdio.h>

#define EARTH_GRAVITY 9.81
#define MERCURY_GRAVITY 3.7
#define VENUS_GRAVITY 8.87
#define MARS_GRAVITY 3.71
#define JUPITER_GRAVITY 24.79
#define SATURN_GRAVITY 10.44
#define URANUS_GRAVITY 8.69
#define NEPTUNE_GRAVITY 11.15

void display_planet_info(const char *planet, float gravity) {
    printf("🌌 Welcome to %s 🌌\n", planet);
    printf("Gravity on %s: %.2f m/s²\n\n", planet, gravity);
}

float calculate_weight(float mass, float gravity) {
    return mass * gravity;
}

int main() {
    printf("🎉 Welcome to the Planet Gravity Simulator! 🎉\n\n");

    float mass;
    printf("Please enter your mass in kg: ");
    scanf("%f", &mass);

    if (mass <= 0) {
        printf("🤔 Hmm, your mass doesn't seem right. Let's keep it positive!\n");
        return 1;
    }

    printf("\n🔍 Let's see how much you would weigh on different planets! 🌏\n\n");
    
    display_planet_info("Mercury", MERCURY_GRAVITY);
    float mercury_weight = calculate_weight(mass, MERCURY_GRAVITY);
    printf("Your weight on Mercury: %.2f N\n\n", mercury_weight);

    display_planet_info("Venus", VENUS_GRAVITY);
    float venus_weight = calculate_weight(mass, VENUS_GRAVITY);
    printf("Your weight on Venus: %.2f N\n\n", venus_weight);

    display_planet_info("Earth", EARTH_GRAVITY);
    float earth_weight = calculate_weight(mass, EARTH_GRAVITY);
    printf("Your weight on Earth: %.2f N\n\n", earth_weight);

    display_planet_info("Mars", MARS_GRAVITY);
    float mars_weight = calculate_weight(mass, MARS_GRAVITY);
    printf("Your weight on Mars: %.2f N\n\n", mars_weight);

    display_planet_info("Jupiter", JUPITER_GRAVITY);
    float jupiter_weight = calculate_weight(mass, JUPITER_GRAVITY);
    printf("Your weight on Jupiter: %.2f N\n\n", jupiter_weight);

    display_planet_info("Saturn", SATURN_GRAVITY);
    float saturn_weight = calculate_weight(mass, SATURN_GRAVITY);
    printf("Your weight on Saturn: %.2f N\n\n", saturn_weight);

    display_planet_info("Uranus", URANUS_GRAVITY);
    float uranus_weight = calculate_weight(mass, URANUS_GRAVITY);
    printf("Your weight on Uranus: %.2f N\n\n", uranus_weight);

    display_planet_info("Neptune", NEPTUNE_GRAVITY);
    float neptune_weight = calculate_weight(mass, NEPTUNE_GRAVITY);
    printf("Your weight on Neptune: %.2f N\n\n", neptune_weight);

    printf("💫 Thanks for visiting the Planet Gravity Simulator! 🌠\n");
    printf("Remember, no matter where you are in the universe, you're extraordinary! 🌈\n");

    return 0;
}