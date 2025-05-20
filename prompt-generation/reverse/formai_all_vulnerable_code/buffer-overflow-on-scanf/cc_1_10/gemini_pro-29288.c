//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
// A tale of inching hearts and miles apart,
// Where Romeo and Juliet, in units, embark.

#include <stdio.h>
#include <stdlib.h>

// Constants, a guiding light in love's dark night.
#define INCHES_IN_FOOT 12
#define MILES_IN_KILOMETER 0.621371

// Romeo and Juliet, their units ablaze,
// Ready to convert, in this metric maze.

// Romeo, the inch-lover, proclaims his plight,
// While Juliet, in kilometers, takes flight.

int main(void) {
    // A stage set for their metric dance,
    // Where inches to feet and miles to kilometers trance.

    int inches;
    float kilometers;

    printf("Romeo: My love, Juliet, speak your height true,\n");
    printf("In inches fair, so I may know it too.\n");
    scanf("%d", &inches);

    printf("Juliet: Romeo, my knight, in kilometers I stand,\n");
    printf("A figure graceful, as you shall command.\n");
    scanf("%f", &kilometers);

    // Romeo, with eager steps, converts his height,
    // From inches to feet, a wondrous sight.

    int feet = inches / INCHES_IN_FOOT;
    int remaining_inches = inches % INCHES_IN_FOOT;

    printf("Romeo: In feet and inches, my stature I declare,\n");
    printf("%d feet tall, with %d inches to spare.\n", feet, remaining_inches);

    // Juliet, with equal grace, converts her stride,
    // From kilometers to miles, her step with pride.

    float miles = kilometers * MILES_IN_KILOMETER;

    printf("Juliet: In miles I tread, a journey to unfold,\n");
    printf("%.2f miles afar, as true love is told.\n", miles);

    // Their units now aligned, their hearts ablaze,
    // Romeo and Juliet, united in metric gaze.

    printf("Together: In unity we measure, love profound,\n");
    printf("From inches to miles, our love won't be bound.\n");

    return 0;
}