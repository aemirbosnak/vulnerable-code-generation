//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 10

typedef struct Component {
    char name[20];
    int value; // Can represent resistance, capacitance, etc.
} Component;

void displayGreeting() {
    printf("Welcome to the Wacky Circuit Simulator!\n");
    printf("Where your electrons can freely roam in their chaotic little world!\n");
}

void addComponent(Component *circuit, int *componentCount) {
    if (*componentCount < MAX_COMPONENTS) {
        printf("Enter component name (Resistor, Capacitor, or Diode): ");
        scanf("%s", circuit[*componentCount].name);
        printf("Enter component value (How shocking!): ");
        scanf("%d", &circuit[*componentCount].value);
        (*componentCount)++;
        printf("Component added! We have %d component(s), let's keep it electrifying!\n", *componentCount);
    } else {
        printf("Oops! We’ve exceeded the maximum components! Time to call for backup!\n");
    }
}

void showComponents(Component *circuit, int componentCount) {
    printf("\nHere are all your circuit components:\n");
    for (int i = 0; i < componentCount; i++) {
        printf("%d. %s with value %d ohms/units\n", i + 1, circuit[i].name, circuit[i].value);
    }
    if (componentCount == 0) {
        printf("No components yet! It’s like a desert of circuits here!\n");
    }
}

void simulateCircuit(Component *circuit, int componentCount) {
    printf("\nSimulating circuit...\n\n");
    for (int i = 0; i < componentCount; i++) {
        printf("Current flows through %s: Zap! We have %d units of fun...\n", circuit[i].name, circuit[i].value);
    }
    printf("And the circuit is...on fire! (figuratively)\n\n");
}

void captureNewValue(int *value) {
    printf("Enter a new zesty value for our little electrifying adventure: ");
    scanf("%d", value);
    printf("Aha! The value is now %d! Are you ready for shock and awe?\n", *value);
}

void showGoodbye() {
    printf("Thanks for playing with circuits!\n");
    printf("Remember, if you can't connect to someone, just circuitously find a way!\n");
}

int main() {
    Component circuit[MAX_COMPONENTS];
    int componentCount = 0;
    int userChoice;

    displayGreeting();

    do {
        printf("\nWhat dastardly deed do you wish to perform?\n");
        printf("1. Add a component\n");
        printf("2. Show current components\n");
        printf("3. Simulate circuit\n");
        printf("4. Change a component value\n");
        printf("5. Exit the simulator\n");
        
        printf("Enter your choice (1-5): ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                addComponent(circuit, &componentCount);
                break;
            case 2:
                showComponents(circuit, componentCount);
                break;
            case 3:
                simulateCircuit(circuit, componentCount);
                break;
            case 4:
                if (componentCount > 0) {
                    int index;
                    printf("Which component would you like to spice up? (1 to %d): ", componentCount);
                    scanf("%d", &index);
                    if (index >= 1 && index <= componentCount) {
                        captureNewValue(&circuit[index - 1].value);
                    } else {
                        printf("Uh-oh! Invalid component! We don't have a Time Machine to change the past!\n");
                    }
                } else {
                    printf("No components to change! It's a barren wasteland of circuit components!\n");
                }
                break;
            case 5:
                showGoodbye();
                break;
            default:
                printf("Did you just fry your circuits? Please choose a valid option!\n");
                break;
        }
    } while (userChoice != 5);

    return 0;
}