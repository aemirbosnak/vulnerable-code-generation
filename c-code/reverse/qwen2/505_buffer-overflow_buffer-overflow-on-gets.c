#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[100], date[20], authCode[20];
    int alienStrength;
    float probability;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter today's date (DD-MM-YYYY): ");
    scanf("%s", date);

    printf("Enter the authorization code: ");
    scanf("%s", authCode);

    if (strcmp(authCode, "XKCD408") != 0) {
        printf("Authorization denied.\n");
        return 1;
    }

    printf("Enter the alien type strength (1-10): ");
    scanf("%d", &alienStrength);

    srand(time(0));
    int randomNumber = rand() % 100 + 1;

    if (randomNumber <= 50) {
        probability = ((float)alienStrength / 10) * 0.3;
    } else {
        probability = ((float)alienStrength / 10) * 0.7;
    }

    printf("Alien Invasion Risk Assessment:\n");
    printf("Name: %s\n", name);
    printf("Date: %s\n", date);
    printf("Alien Strength: %d\n", alienStrength);
    printf("Probability of Invasion: %.2f%%\n", probability * 100);

    return 0;
}
