//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100

typedef struct {
    int type;
    int pins[2];
} Component;

int main() {
    int num_components, i;
    Component components[MAX_COMPONENTS];

    printf("Enter number of components: ");
    scanf("%d", &num_components);

    for (i = 0; i < num_components; i++) {
        printf("Enter type of component (1 for resistor, 2 for capacitor, 3 for inductor): ");
        scanf("%d", &components[i].type);

        switch (components[i].type) {
            case 1:
                printf("Enter resistance in ohms: ");
                scanf("%d", &components[i].pins[0]);
                components[i].pins[1] = 0;
                break;
            case 2:
                printf("Enter capacitance in farads: ");
                scanf("%d", &components[i].pins[0]);
                components[i].pins[1] = 0;
                break;
            case 3:
                printf("Enter inductance in henries: ");
                scanf("%d", &components[i].pins[0]);
                components[i].pins[1] = 0;
                break;
        }
    }

    printf("Enter input voltage: ");
    scanf("%d", &components[0].pins[1]);

    printf("Enter output node: ");
    scanf("%d", &components[num_components - 1].pins[1]);

    for (i = 0; i < num_components; i++) {
        switch (components[i].type) {
            case 1:
                components[i].pins[1] = components[i].pins[0] * (components[num_components - 1].pins[1] - components[i].pins[1]) / (components[num_components - 1].pins[1]);
                break;
            case 2:
                components[i].pins[1] = (components[num_components - 1].pins[1]) * (components[i].pins[0] / components[num_components - 1].pins[0]);
                break;
            case 3:
                components[i].pins[1] = (components[num_components - 1].pins[1]) * (components[i].pins[0] / components[num_components - 1].pins[0]);
                break;
        }
    }

    printf("Output voltage: %d\n", components[num_components - 1].pins[1]);

    return 0;
}