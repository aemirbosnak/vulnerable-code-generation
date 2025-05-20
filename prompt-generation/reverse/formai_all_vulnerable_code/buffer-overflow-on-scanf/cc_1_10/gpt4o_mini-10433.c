//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>

// Function to calculate the alien invasion probability
float probability_of_invasion(int ufo_sightings, int secrecy_level, int public_interest) {
    // Calculate base probability from UFO sightings (scale 0-1)
    float base_probability = ufo_sightings / 100.0;
    
    // Incorporating government secrecy into the calculation (scale inversely)
    float secrecy_factor = (10 - secrecy_level) / 10.0;
    
    // Incorporating public interest into the calculation (scale 0-1)
    float interest_factor = public_interest / 10.0;

    // Combined probability formula
    float invasion_probability = base_probability * secrecy_factor * interest_factor;

    // Ensure the probability is capped between 0 and 1
    if (invasion_probability > 1.0) {
        invasion_probability = 1.0;
    } else if (invasion_probability < 0.0) {
        invasion_probability = 0.0;
    }

    return invasion_probability * 100; // Convert to percentage
}

int main() {
    int ufo_sightings;
    int secrecy_level; // Scale from 0 (very secret) to 10 (very transparent)
    int public_interest; // Scale from 0 (no interest) to 10 (high interest)
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("================================================\n");
    
    printf("Please enter the number of UFO sightings (0 - 100): ");
    scanf("%d", &ufo_sightings);
    
    // Validate UFO sightings input
    while(ufo_sightings < 0 || ufo_sightings > 100) {
        printf("Invalid input! Please enter a valid number of UFO sightings (0 - 100): ");
        scanf("%d", &ufo_sightings);
    }
    
    printf("On a scale from 0 to 10, how secretive is your government about UFOs? (0 = very secret, 10 = very transparent): ");
    scanf("%d", &secrecy_level);
    
    // Validate secrecy level input
    while(secrecy_level < 0 || secrecy_level > 10) {
        printf("Invalid input! Please enter a valid secrecy level (0 - 10): ");
        scanf("%d", &secrecy_level);
    }
    
    printf("On a scale from 0 to 10, how much public interest is there in extraterrestrial life? (0 = no interest, 10 = high interest): ");
    scanf("%d", &public_interest);
    
    // Validate public interest input
    while(public_interest < 0 || public_interest > 10) {
        printf("Invalid input! Please enter a valid public interest level (0 - 10): ");
        scanf("%d", &public_interest);
    }
    
    // Calculate the probability
    float invasion_probability = probability_of_invasion(ufo_sightings, secrecy_level, public_interest);
    
    // Output the result
    printf("================================================\n");
    printf("Based on your input:\n");
    printf("UFO Sightings: %d\n", ufo_sightings);
    printf("Government Secrecy Level: %d\n", secrecy_level);
    printf("Public Interest Level: %d\n", public_interest);
    printf("The probability of an alien invasion is: %.2f%%\n", invasion_probability);
    printf("================================================\n");
    
    return 0;
}