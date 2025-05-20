//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Component {
    char type[20];
    float value;
    struct Component* next;
} Component;

Component* head = NULL;

void addComponent(const char* type, float value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    if (!newComponent) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newComponent->type, type);
    newComponent->value = value;
    newComponent->next = head;
    head = newComponent;
    printf("Added %s of value %.2f\n", type, value);
}

void displayCircuit() {
    if (head == NULL) {
        printf("Circuit is empty!\n");
        return;
    }
    printf("Current Circuit Components:\n");
    Component* temp = head;
    while (temp != NULL) {
        printf("Type: %s, Value: %.2f\n", temp->type, temp->value);
        temp = temp->next;
    }
}

void shapeShiftComponent(const char* type, float newValue) {
    Component* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->type, type) == 0) {
            temp->value = newValue;
            printf("Changed %s to new value %.2f\n", type, newValue);
            return;
        }
        temp = temp->next;
    }
    printf("Component of type %s not found!\n", type);
}

void removeComponent(const char* type) {
    Component *temp = head, *prev = NULL;
    while (temp != NULL && strcmp(temp->type, type) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Component of type %s not found!\n", type);
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Removed component of type %s\n", type);
}

void freeCircuit() {
    Component* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Circuit cleaned up!\n");
}

int main() {
    int choice;
    char type[20];
    float value;

    while (1) {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Add Inductor\n");
        printf("4. Display Circuit\n");
        printf("5. Shape Shift Component\n");
        printf("6. Remove Component\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistor value (ohms): ");
                scanf("%f", &value);
                addComponent("Resistor", value);
                break;
            case 2:
                printf("Enter capacitor value (farads): ");
                scanf("%f", &value);
                addComponent("Capacitor", value);
                break;
            case 3:
                printf("Enter inductor value (henrys): ");
                scanf("%f", &value);
                addComponent("Inductor", value);
                break;
            case 4:
                displayCircuit();
                break;
            case 5:
                printf("Enter type to shape shift (Resistor/Capacitor/Inductor): ");
                scanf("%s", type);
                printf("Enter new value: ");
                scanf("%f", &value);
                shapeShiftComponent(type, value);
                break;
            case 6:
                printf("Enter type to remove (Resistor/Capacitor/Inductor): ");
                scanf("%s", type);
                removeComponent(type);
                break;
            case 7:
                freeCircuit();
                printf("Exiting the circuit simulator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}