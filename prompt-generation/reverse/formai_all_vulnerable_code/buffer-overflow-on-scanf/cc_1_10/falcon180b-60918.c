//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the medieval style temperature units
enum {
    FROSTY_MORN,
    CHILLY_DAY,
    WARM_NOON,
    HOT_AFTERNOON,
    SCORCHING_NIGHT
};

// Function to convert modern temperature to medieval style temperature
int modern_to_medieval(double temp) {
    if (temp <= 0) {
        return FROSTY_MORN;
    } else if (temp <= 10) {
        return CHILLY_DAY;
    } else if (temp <= 20) {
        return WARM_NOON;
    } else if (temp <= 30) {
        return HOT_AFTERNOON;
    } else {
        return SCORCHING_NIGHT;
    }
}

// Function to print the medieval style temperature
void print_medieval_temp(int temp) {
    switch (temp) {
        case FROSTY_MORN:
            printf("A frosty morn it is, with temperatures below freezing.\n");
            break;
        case CHILLY_DAY:
            printf("Chilly day ahead, bundle up for temperatures around 10 degrees.\n");
            break;
        case WARM_NOON:
            printf("A warm noon it shall be, with temperatures reaching 20 degrees.\n");
            break;
        case HOT_AFTERNOON:
            printf("An afternoon of sweltering heat, brace yourself for temperatures up to 30 degrees.\n");
            break;
        case SCORCHING_NIGHT:
            printf("A scorching night it will be, with temperatures soaring past 30 degrees.\n");
            break;
    }
}

int main() {
    double modern_temp;
    int medieval_temp;

    // Get modern temperature from user
    printf("Enter the modern temperature: ");
    scanf("%lf", &modern_temp);

    // Convert modern temperature to medieval style temperature
    medieval_temp = modern_to_medieval(modern_temp);

    // Print the medieval style temperature
    print_medieval_temp(medieval_temp);

    return 0;
}