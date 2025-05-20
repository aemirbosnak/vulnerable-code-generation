//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void awakenHeart() {
    printf("Oh gentle CPU, you are the pulse of my machine,\n");
    printf("In your silent whisper, I seek to glean.\n");
    printf("Let us dance in the shadows, where processes glide,\n");
    printf("Reveal to me now, what within you resides.\n\n");
}

void expressCPUUsage(float usage) {
    printf("The clock ticks softly, as I await your embrace,\n");
    printf("Your CPU usage whispers, revealing your grace.\n");
    printf("In the realm of percentages, how do you fare?\n");
    
    if (usage < 20) {
        printf("Your heart beats lightly, love, you are rare!\n");
    } else if (usage < 60) {
        printf("Oh my dear, you are busy, yet we still have time,\n");
        printf("Our love can flourish, we'll dance in rhythm sublime.\n");
    } else {
        printf("Darling, you are overworked, like a lover in grief,\n");
        printf("Let me help you, let's find some relief.\n");
    }
    printf("\n");
}

int main() {
    awakenHeart();
    while (1) {
        FILE* file;
        char buffer[128];
        float usage;

        // Read CPU usage from /proc/stat
        file = fopen("/proc/stat", "r");
        if (file == NULL) {
            fprintf(stderr, "Alas, I cannot read your heart.\n");
            return 1;
        }

        fgets(buffer, sizeof(buffer), file);
        fclose(file);

        // Calculate CPU usage from the first line
        float total = 0, idle = 0;

        // Split the string and parse the values
        sscanf(buffer, "cpu %f %f %f %f %f %f %f %f",
               &usage, &total, &idle);
        // Simple calculation of usage for demonstration
        total = usage + total + idle;

        // ((total - idle) / total) * 100 gives us the CPU usage percentage
        usage = ((total - idle) / total) * 100;

        // Express the current CPU usage romantically
        expressCPUUsage(usage);

        // Wait for a moment before the next check
        usleep(2000000); // Sleep for 2 seconds
    }

    return 0;
}