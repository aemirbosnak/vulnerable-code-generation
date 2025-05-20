//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct resistor {
    int r_num;
    double resist;
    struct resistor *next_resistor;
} Resistor;

typedef struct circuit {
    int c_num;
    Resistor *first_resistor;
    double voltage;
    double current;
    double power;
} Circuit;

Resistor *create_resistor(int r_num, double resist) {
    Resistor *res = malloc(sizeof(Resistor));
    res->r_num = r_num;
    res->resist = resist;
    res->next_resistor = NULL;
    return res;
}

void add_resistor(Circuit *circ, int r_num, double resist) {
    Resistor *new_resistor = create_resistor(r_num, resist);
    if (circ->first_resistor == NULL) {
        circ->first_resistor = new_resistor;
    } else {
        Resistor *temp = circ->first_resistor;
        while (temp->next_resistor != NULL) {
            temp = temp->next_resistor;
        }
        temp->next_resistor = new_resistor;
    }
}

void delete_resistor(Circuit *circ, int r_num) {
    Resistor *temp = circ->first_resistor;
    Resistor *prev = NULL;
    while (temp != NULL) {
        if (temp->r_num == r_num) {
            if (prev == NULL) {
                circ->first_resistor = temp->next_resistor;
            } else {
                prev->next_resistor = temp->next_resistor;
            }
            free(temp);
            printf("Resistor %d has been successfully deleted.\n", r_num);
            return;
        }
        prev = temp;
        temp = temp->next_resistor;
    }
    printf("Resistor %d not found.\n", r_num);
}

void calculate_circuit(Circuit *circ) {
    Resistor *temp = circ->first_resistor;
    double total_resistance = 0;
    while (temp != NULL) {
        total_resistance += temp->resist;
        temp = temp->next_resistor;
    }
    circ->current = circ->voltage / total_resistance;
    circ->power = circ->voltage * circ->current;
    printf("\nCircuit %d\n", circ->c_num);
    printf("Total Resistance: %.2lf Ohms\n", total_resistance);
    printf("Current: %.2lf Amperes\n", circ->current);
    printf("Power: %.2lf Watts\n", circ->power);
}

int main() {
    Circuit cir1;
    cir1.c_num = 1;
    cir1.first_resistor = NULL;
    cir1.voltage = 9.0;

    add_resistor(&cir1, 1, 10.0);
    add_resistor(&cir1, 2, 15.0);
    add_resistor(&cir1, 3, 30.0);

    calculate_circuit(&cir1);

    delete_resistor(&cir1, 2);

    calculate_circuit(&cir1);

    return 0;
}