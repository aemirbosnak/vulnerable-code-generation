//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANDOM 1000000

//function to generate a random number
int generateRandom() {
    return rand() % MAX_RANDOM;
}

//function to calculate the probability of an alien invasion
int calculateProbability(int numSightings, int numAbductions, int numCrashes) {
    int probability = 0;

    probability += numSightings * 10;
    probability += numAbductions * 50;
    probability += numCrashes * 100;

    return probability;
}

//function to print the results
void printResults(int probability) {
    if (probability < 50) {
        printf("The probability of an alien invasion is low.\n");
    } else if (probability >= 50 && probability < 100) {
        printf("The probability of an alien invasion is moderate.\n");
    } else {
        printf("The probability of an alien invasion is high.\n");
    }
}

int main() {
    int numSightings, numAbductions, numCrashes;
    int probability;

    //get user input for number of sightings, abductions, and crashes
    printf("Enter the number of UFO sightings: ");
    scanf("%d", &numSightings);
    printf("Enter the number of reported abductions: ");
    scanf("%d", &numAbductions);
    printf("Enter the number of reported crashes: ");
    scanf("%d", &numCrashes);

    //calculate the probability of an alien invasion
    probability = calculateProbability(numSightings, numAbductions, numCrashes);

    //print the results
    printResults(probability);

    return 0;
}