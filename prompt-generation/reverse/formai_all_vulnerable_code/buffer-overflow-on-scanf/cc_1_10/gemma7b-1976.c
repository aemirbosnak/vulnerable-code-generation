//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DETECTED_INGRESS_POINTS 10

typedef struct IntrusionDetectionPoint {
    int x;
    int y;
    char flag;
} IntrusionDetectionPoint;

IntrusionDetectionPoint intrusionDetectionPoints[MAX_DETECTED_INGRESS_POINTS];

int main() {
    int i;
    char input[256];
    int detected_incess_points = 0;

    // Initialize intrusion detection points
    for (i = 0; i < MAX_DETECTED_INGRESS_POINTS; i++) {
        intrusionDetectionPoints[i].x = -1;
        intrusionDetectionPoints[i].y = -1;
        intrusionDetectionPoints[i].flag = 'N';
    }

    // Listen for commands
    printf("Enter command (add/remove/check): ");
    scanf("%s", input);

    // Add an intrusion detection point
    if (strcmp(input, "add") == 0) {
        printf("Enter point coordinates (x, y): ");
        scanf("%d %d", &intrusionDetectionPoints[detected_incess_points].x, &intrusionDetectionPoints[detected_incess_points].y);
        intrusionDetectionPoints[detected_incess_points].flag = 'Y';
        detected_incess_points++;
    }

    // Remove an intrusion detection point
    else if (strcmp(input, "remove") == 0) {
        printf("Enter point coordinates (x, y): ");
        scanf("%d %d", &intrusionDetectionPoints[detected_incess_points].x, &intrusionDetectionPoints[detected_incess_points].y);
        intrusionDetectionPoints[detected_incess_points].flag = 'R';
        detected_incess_points--;
    }

    // Check for intrusion
    else if (strcmp(input, "check") == 0) {
        printf("Enter point coordinates (x, y): ");
        scanf("%d %d", &intrusionDetectionPoints[detected_incess_points].x, &intrusionDetectionPoints[detected_incess_points].y);

        for (i = 0; i < detected_incess_points; i++) {
            if (intrusionDetectionPoints[i].x == intrusionDetectionPoints[detected_incess_points].x && intrusionDetectionPoints[i].y == intrusionDetectionPoints[detected_incess_points].y) {
                if (intrusionDetectionPoints[i].flag == 'Y') {
                    printf("Intrusion detected!\n");
                }
            }
        }
    }

    return 0;
}