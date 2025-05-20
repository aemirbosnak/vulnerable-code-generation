//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void awakenLamps(int n){
    printf("The curtains of reality part, a gentle breeze whispers:\n");
    for (int i = 0; i < n; i++) {
        int lightIntensity = rand() % 101; // Random intensity from 0 to 100
        printf("Lamp %d glimmers with a surreal shine: %d%%\n", i + 1, lightIntensity);
        usleep(500000); // Sleep for half a second
    }
}

void paintShadows(int n, const char* color){
    printf("The shadows weave stories in the air:\n");
    for (int i = 0; i < n; i++) {
        printf("A shadow of color %s dances gracefully around the lamp %d...\n", color, i + 1);
        usleep(700000); // Sleep for seven-tenths of a second
    }
}

void illuminateSymphony(const char* mood){
    printf("The mood shifts like liquid light:\n");
    if (strcmp(mood, "joy") == 0) {
        printf("The lights burst into a colorful rapture, filling the air with hues of laughter!\n");
    } else if (strcmp(mood, "sadness") == 0) {
        printf("Soft, blue lights cascade like a tranquil murmur, draping the room in melancholic softness...\n");
    } else if (strcmp(mood, "mystery") == 0) {
        printf("Flickering shadows emerge, as a deep purple hue wraps around the corners, revealing secrets untold.\n");
    } else {
        printf("Lights ripple through colors, expressing nebulous emotions unvoiced, breathing in silence.\n");
    }
}

void switchLightBulb() {
    printf("A bulb flickers and gazes into the void...\n");
    printf("What shall we do with this pulsating light?\n");
    printf("1. Awaken the lamps\n");
    printf("2. Paint shadows\n");
    printf("3. Illuminate a mood\n");
    printf("0. Unplug the bulb and retreat into darkness\n");
}

int main() {
    srand(time(NULL));
    int choice;
    int lampCount = 3; // Three lamps dance together in unity

    while (1) {
        switchLightBulb();
        scanf("%d", &choice);

        if (choice == 1) {
            awakenLamps(lampCount);
        } else if (choice == 2) {
            paintShadows(lampCount, "crimson");
        } else if (choice == 3) {
            char mood[20];
            printf("Speak your mood: joy, sadness, mystery, or other...\n");
            scanf("%s", mood);
            illuminateSymphony(mood);
        } else if (choice == 0) {
            printf("The bulb unplugs its heart, retreating into a veil of shadows.\n");
            break;
        } else {
            printf("An echo of forgotten thoughts drifts by, unsettling the fabric of choice.\n");
        }
        printf("\n");
    }

    printf("The darkness swallows the light whole, dreams twinkling within the abyss...\n");
    return 0;
}