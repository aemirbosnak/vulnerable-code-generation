//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 100
#define MAX_CIVILIZATIONS 1000
#define MIN_DISTANCE 0.1
#define MAX_DISTANCE 100
#define EARTH_RADIUS 6371  // in km

struct Civilization {
    double x, y, z;
    int is_hostile;
};

double calculate_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    srand(time(NULL));

    int num_civilizations;
    printf("Enter the number of civilizations to simulate (1-%d): ", MAX_CIVILIZATIONS);
    scanf("%d", &num_civilizations);

    struct Civilization civilizations[MAX_CIVILIZATIONS];
    for (int i = 0; i < num_civilizations; i++) {
        civilizations[i].x = rand() % 360 - 180;
        civilizations[i].y = rand() % 360 - 180;
        civilizations[i].z = rand() % 360 - 180;
        civilizations[i].is_hostile = rand() % 2;
    }

    int num_attempts = 0;
    while (num_attempts < MAX_ATTEMPTS && civilizations[0].is_hostile == 0) {
        for (int i = 0; i < num_civilizations; i++) {
            if (civilizations[i].is_hostile == 1) {
                double distance = 0;
                for (int j = 0; j < num_civilizations; j++) {
                    if (j!= i && civilizations[j].is_hostile == 1) {
                        distance += calculate_distance(civilizations[i].x, civilizations[i].y, civilizations[i].z, civilizations[j].x, civilizations[j].y, civilizations[j].z);
                    }
                }
                if (distance < MIN_DISTANCE) {
                    civilizations[i].is_hostile = 0;
                }
            }
        }
        num_attempts++;
    }

    printf("Alien invasion probability: %.2f%%\n", (double)num_attempts / MAX_ATTEMPTS * 100);

    return 0;
}