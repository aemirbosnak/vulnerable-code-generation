//FormAI DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to turn on/off the lights
void controlLights(int n, int status[]) {
    int i, light;
    char action[10];

    for (i = 0; i < n; i++) {
        printf("Enter the name of light number %d: ", i + 1);
        scanf("%s", action);

        // Convert the input string to lowercase
        // to make comparison easier
        for (int j = 0; action[j]; j++) {
            action[j] = tolower(action[j]);
        }

        printf("Enter the status of light number %d (1 for on, 0 for off): ", i + 1);
        scanf("%d", &status[i]);

        // Control the light
        if (strcmp(action, "on") == 0) {
            status[i] = 1;
        } else if (strcmp(action, "off") == 0) {
            status[i] = 0;
        }
    }

    printf("\n");

    // Print the current status of the lights
    for (i = 0; i < n; i++) {
        if (status[i] == 1) {
            printf("Light number %d is on\n", i + 1);
        } else {
            printf("Light number %d is off\n", i + 1);
        }
    }
}

int main() {
    int n, i;
    int *status;

    printf("Enter the number of lights: ");
    scanf("%d", &n);

    // Allocate memory dynamically for status array
    status = (int *) malloc(n * sizeof(int));

    if (status == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    controlLights(n, status);

    // Deallocate the memory allocated
    free(status);

    return 0;
}